//
// Created by legen on 2/3/2024.
//

#ifndef MAZEPROJECT_MAZEEDGE_H
#define MAZEPROJECT_MAZEEDGE_H
class mazeEdge{
public:
    int get_start();
    int get_end();
    char get_color();
    void set_start(int num);
    void set_end(int num);
    void set_color(char letter);
    mazeEdge(int s, int e, char c);

private:
    int start = 0;
    int end = 0;
    char color = 'w';
};
#endif //MAZEPROJECT_MAZEEDGE_H
