#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "mazeEdge.h"
#include "mazeNode.h"
#include "mazeGraph.h"
#include "intPair.h"
#include <queue>
#include <algorithm>
using namespace std;

mazeGraph make_graph(mazeNode maze[], mazeGraph g, vector<intPair> ancestors);
bool find(const vector<intPair>& list, intPair p);
vector<string> print_path(vector<mazeGraph> g, int shortest, vector<string> paths);
mazeGraph bfs(mazeGraph g, queue<mazeGraph> enqueue);
string iterate(mazeGraph g, string path);
bool compareFunction (string a, string b){return a<b;}
int main() {
    string line;
    ifstream myFile("test.txt");

    // handling first line of the file
    getline(myFile,line);
    string lineSubStr;
    int i = 0;

    while(line[i] != ' '){
        lineSubStr += line[i];
        i++;
    }
    int nodeNum = stoi(lineSubStr);
    lineSubStr = "";
    i++;

    while (i < line.size()){
        lineSubStr += line[i];
        i++;
    }
    int loopNum = stoi(lineSubStr);
    i = 0; // in case of future use


    // handle second line
    mazeNode maze[nodeNum];
    getline(myFile,line);
    int count = 1;
    while(i < line.size()){
        if(line[i] !=' '){
            maze[count-1].set_color(line[i]);
            maze[count-1].set_id(count);
            count++;
        }
        i++;
    }
    i = 0;

    //handle third line
    getline(myFile,line);
    lineSubStr = "";

    while(line[i] != ' '){
        lineSubStr += line[i];
        i++;
    }
    int rocket = stoi(lineSubStr);
    lineSubStr = "";
    i++;

    while (i < line.size()){
        lineSubStr += line[i];
        i++;
    }
    int lucky = stoi(lineSubStr);
    i = 0;

    // handle every other line
    for(int j = 0; j < loopNum; j++){

        int node1 = 0;
        int node2 = 0;
        char col = 'w';

        string newLine;
        getline(myFile,newLine);
        i = 0;
        lineSubStr = "";
        while(newLine[i] != ' '){
            lineSubStr += newLine[i];
            i++;
        }

        node1 = stoi(lineSubStr);
        lineSubStr = "";
        i++;

        while (i < newLine.size()){
            lineSubStr += newLine[i];
            i++;
        }
        node2 = stoi(lineSubStr);
        i--;
        col = newLine[i];

        // putting all the information into the maze.
        auto* edge = new mazeEdge(node1, node2, col);
        maze[node1-1].fromEdge.push_back(*edge);
        maze[node2-1].toEdge.push_back(*edge);
    }
    myFile.close();// I have read in all I need from the file
    vector<intPair> ancestors;
    mazeGraph graph = make_graph(maze,mazeGraph(rocket,lucky),ancestors);
    queue<mazeGraph> enqueue;


    vector<mazeGraph> terminalNodes;

    // bfs search, encoded from pseudocode from canvas. Has to be here or it does not work
    enqueue.push(graph);
    while(!enqueue.empty()){
        mazeGraph node = enqueue.front();
        for(mazeGraph x: node.fromNodes){
            if(x.get_color() == 'w'){
                x.set_color('g');
                x.path = node.path + 1;
                x.toNodes.push_back(node);
                enqueue.push(x);
                if(x.get_rocket() == 8 || x.get_lucky() == 8){
                    terminalNodes.push_back(x);
                }
            }
        }
        enqueue.pop();
        node.set_color('b');
    }
    int shortPath = terminalNodes.at(0).path;
    for(mazeGraph x : terminalNodes){
        if(x.path < shortPath){
            shortPath = x.path;
        }
    }
    vector<string> path_description;
    path_description = print_path(terminalNodes, shortPath, path_description);
    sort(path_description.begin(),path_description.end(),compareFunction);
    cout << path_description.at(0);


    return 0;
}

mazeGraph make_graph(mazeNode maze[], mazeGraph g, vector<intPair> ancestors){
    ancestors.push_back(intPair(g.get_rocket(), g.get_lucky()));
    for(mazeEdge x: maze[g.get_rocket()-1].fromEdge) {
        if (x.get_color() == maze[g.get_lucky() - 1].get_color()) {
            if(!find(ancestors, intPair(x.get_end(), g.get_lucky()))){
                auto* node = new mazeGraph(x.get_end(), g.get_lucky());
                bool descendant = false;
                for(mazeGraph z: g.fromNodes){
                    if((node->get_lucky() == z.get_lucky() && node->get_rocket() == z.get_rocket()) || (node->get_rocket() == z.get_lucky() && node->get_lucky() == z.get_rocket())){
                        descendant = true;
                    }
                }
                if(!descendant){
                    g.fromNodes.push_back(make_graph(maze,*node, ancestors));
                }
            }
        }
    }
    for(mazeEdge z: maze[g.get_lucky()-1].fromEdge){
        if(z.get_color() == maze[g.get_rocket()-1].get_color()){
            if(!find(ancestors, intPair(g.get_rocket(), z.get_end()))){
                auto* node = new mazeGraph(g.get_rocket(), z.get_end());
                bool descendant = false;
                for(mazeGraph x: g.fromNodes){
                    if((x.get_lucky() == node->get_lucky() && x.get_rocket() == node->get_rocket()) || (x.get_lucky() == node->get_rocket() && x.get_rocket() == node->get_lucky())){
                        descendant = true;
                    }
                }
                if(!descendant){
                    g.fromNodes.push_back(make_graph(maze, *node, ancestors));
                }
            }
        }
    }
    return g;
}

bool find(const vector<intPair>& list, intPair p){
    for(intPair x: list){
        if((x.get_a() == p.get_a() && x.get_b() == p.get_b()) || (x.get_a() == p.get_b() && x.get_b() == p.get_a())){
            return true;
        }
    }
    return false;
}
 vector<string> print_path(vector<mazeGraph> g, int shortest, vector<string> paths){
    for(mazeGraph x: g){
        if(x.path == shortest){
            string path;
            path = iterate(x,path);
            paths.push_back(path);
        }
    }
    return paths;
}
string iterate(mazeGraph g, string path){
    if(g.toNodes.size()>0){
        if(g.get_rocket() == g.toNodes.at(0).get_rocket()){
            path =  iterate(g.toNodes.at(0), path) + "L" + to_string(g.get_lucky());
        }else{
            path =  iterate(g.toNodes.at(0), path) +"R" + to_string(g.get_rocket());
        }
        return path;
    }else{
        path = "R" + to_string(g.get_rocket()) + "L" + to_string(g.get_lucky());
        return path;
    }
}


