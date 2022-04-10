#pragma once

#include <vector>
#include <cstdio>

unsigned int getWidth();
void setWidth();

unsigned int getHeight();
void setHeight ();

bool getbPadding ();
void setbPadding ();

bool getbIsInitialized ();
void setbIsInitialized ();


class ScreenChar {
    public:
        char ch;
        int foreColor, backColor;

        ScreenChar (char chInp, int foreColorInp = 7, int backColorInp = 0) {
            ch = chInp;
            if (foreColorInp<=7) {
                foreColor = 30+foreColorInp;
            }
            else {
                foreColor = 82+foreColorInp;
            }

            if (backColorInp<=7) {
                backColor = 40+backColorInp;
            }
            else {
                backColor = 92+backColorInp;
            }
        }
};

class Position {
    public:
        unsigned int x;
        unsigned int y;
    
    public:
        Position (unsigned int xInp, unsigned int yInp) {
            x = xInp;
            y = yInp;
        }
};

class Layer {
    public:
        std::vector<std::vector<ScreenChar>> layer;

        Layer (ScreenChar charToFill) {
            for (int y = 0; y < getHeight(); y++) { // goes through every x and y cell and adds it into the layer which is a 2D vector
                std::vector<ScreenChar> row;
                for (int x = 0; x < getWidth(); x++) {
                    row.push_back(charToFill);
                }
                layer.push_back(row);
            }
        }

        void putCharAt (Position pos, ScreenChar sch) { // changes one character on a layer
            layer.at(pos.y).at(pos.x) = sch;
        }

        void drawLayer () {
            for (int y = 0; y < getHeight(); y++) {
                for (int x = 0; x < getWidth(); x++) {
                    ScreenChar* currentChar = &(layer.at(y).at(x));
                    if (getbPadding() && x != getWidth()-1) { printf("\033[%u;%um%c \033[0m", (*currentChar).backColor, (*currentChar).foreColor, (*currentChar).ch); }
                    else { printf("\033[%u;%um%c\033[0m", (*currentChar).backColor, (*currentChar).foreColor, (*currentChar).ch); }
                }
                printf("\n");
            }
        }
};


std::vector<Layer> getLayers ();
void setLayers (std::vector<Layer> inp);


void initialize (unsigned int widthInp, unsigned int heightInp, bool doPadding = false);
void drawAllLayers ();
void createLayer (ScreenChar sch);