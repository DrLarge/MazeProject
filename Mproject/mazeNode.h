//
// Created by legen on 2/3/2024.
//

#ifndef MAZEPROJECT_MAZENODE_H
#define MAZEPROJECT_MAZENODE_H
#include <vector>
#include "mazeEdge.h"
using namespace std;
class mazeNode{
public:
    vector<mazeEdge> fromEdge;
    vector<mazeEdge> toEdge;
    int get_id();
    void set_id(int num);
    char get_color();
    void set_color(char letter);
private:
    int id;
    char color;
};
#endif //MAZEPROJECT_MAZENODE_H
