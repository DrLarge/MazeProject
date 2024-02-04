//
// Created by legen on 2/3/2024.
//
#include "mazeGraph.h"

int mazeGraph::get_lucky() {
    return lucky;
}

int mazeGraph::get_rocket() {
    return rocket;
}

void mazeGraph::set_lucky(int num) {
    lucky = num;
}

void mazeGraph::set_rocket(int num) {
    rocket = num;
}

mazeGraph::mazeGraph(int r, int l) {
    lucky = l;
    rocket = r;
    color = 'w';
}


char mazeGraph::get_color() {
    return color;
}

void mazeGraph::set_color(char letter) {
    color = letter;
}

