//
// Created by legen on 2/3/2024.
//

#ifndef MAZEPROJECT_MAZEGRAPH_H
#define MAZEPROJECT_MAZEGRAPH_H
#include <vector>
using namespace std;
class mazeGraph{
public:
    vector<mazeGraph> fromNodes;
    vector<mazeGraph> toNodes;
    int get_lucky();
    int get_rocket();
    char get_color();
    void set_color(char letter);
    void set_lucky(int num);
    void set_rocket(int num);
    mazeGraph(int l, int r);
    int path = 0;

private:
    int lucky = 0;
    int rocket = 0;
    char color = 'w';
};
#endif //MAZEPROJECT_MAZEGRAPH_H
