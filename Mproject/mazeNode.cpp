//
// Created by legen on 2/3/2024.
//
#include "mazeEdge.h"
#include "mazeNode.h"

int mazeNode::get_id() {
    return id;
}

void mazeNode::set_id(int num) {
    id = num;
}

char mazeNode::get_color() {
    return color;
}

void mazeNode::set_color(char letter) {
    color = letter;
}
