#pragma once
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cmath>
#include<chrono>
#include<thread>

#ifndef __GNUC__
#define CLEAR "cls"
#endif
#ifdef __GNUC__
#define CLEAR "clear"
#endif

#define SLEEP(TIME) std::this_thread::sleep_for(std::chrono::milliseconds(TIME));
#define SWAP(A,B) A = A+B; B = A - B; A = A- B;
/*
        idea => use print to buffer storage for better printing
*/
void clear();
class drawpad {
    char** dp;
    int sizex, sizey;
    int color;
public:
    drawpad();
    drawpad(int x, int y);
    //      drawPad(std::ifstream fileread);
    void shiftX(int x);     // shifts the drawpad x units to the right
    void shiftXR(int x);    // shifts the drawpad x units to the right however, it doesn't cut off any extra overflow, instead it comes back to left side
    void shiftY(int y);         // shifts the drawpad y units down.
    void shiftYR(int y);        // shifts the drawpad y units up however, it doesn't cut off any extra overflow, instead it comes back from down
    void erasePad();                                                    //erases the drawing pad.
    void drawline(int, int, int, int);                  //draws line from the first 2 coordinates to the last 2 coordinates
    void drawcircle(int x, int y, int r);               //draws a circle of radius r, with center at x,y
    void drawcircle(int x, int y, int r, char c);   //draws a circle of radius r, with center at x,y with a border given by character 'c';
        void loadFromFile(std::string file_name);               //loads the drawing from the given file into the drawpad.
        void loadFromFile(std::string file_name, int topx, int topy); //loads the drawing from the given file with the top left of the drawing at topx, topy coordinates
    void display();
    ~drawpad()
    {
        for (int i = 0; i < sizex; i++)
        {
            delete[] dp[i];
        }
        delete[] dp;
    }
    friend void mergeDisplay(drawpad* d, int n);

    //accessors
    int xmax() { return sizex; }
    int ymax() { return sizey; }
};
