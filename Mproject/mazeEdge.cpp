//
// Created by legen on 2/3/2024.
//
#include "mazeEdge.h"
#include <iostream>

int mazeEdge::get_start() {
    return start;
}

int mazeEdge::get_end() {
    return end;
}

char mazeEdge::get_color() {
    return color;
}

void mazeEdge::set_start(int num) {
    start = num;

}

void mazeEdge::set_end(int num) {
    end = num;
}

void mazeEdge::set_color(char letter) {
    color = letter;
}

mazeEdge::mazeEdge(int s, int e, char c) {
    start = s;
    end = e;
    color = c;

}
