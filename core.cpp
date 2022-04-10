#include "core.h"


unsigned int width, height;
bool bPadding, bIsInitialized;
std::vector<Layer> layers;

// Width
unsigned int getWidth () {
    return width;
}
void setWidth (unsigned int inp) {
    width = inp;
}

// Height
unsigned int getHeight () {
    return height;
}
void setHeight (unsigned int inp) {
    height = inp;
}

// bPadding
bool getbPadding () {
    return bPadding;
}
void setbPadding (bool inp) {
    bPadding = inp;
}

// bIsInitialized
bool getbIsInitialized () {
    return bIsInitialized;
}
void setbIsInitialized (bool inp) {
    bIsInitialized = inp;
}

// Layers
std::vector<Layer> getLayers () {
    return layers;
}
void setLayers (std::vector<Layer> inp) {
    layers = inp;
}

void initialize (unsigned int widthInp, unsigned int heightInp, bool doPadding) { // initializes the whole screen - that is
    bPadding = doPadding;                                                         // Sets all the necessary bools, variables and sets up the layers
    width = widthInp;
    height = heightInp;

    ScreenChar tempScreenChar('.');
    Layer tempLayer(tempScreenChar);

    layers.push_back(tempLayer);

    bIsInitialized = true;
}

void drawAllLayers () {
    Layer tempLayerToDraw(ScreenChar(' '));

    for (int i = 0; i < layers.size(); i++) {
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                ScreenChar* currentChar = &(layers.at(i).layer.at(y).at(x));
                ScreenChar* currentTempChar = &tempLayerToDraw.layer.at(y).at(x);
                (*currentTempChar).backColor = (*currentChar).backColor;
                (*currentTempChar).foreColor = (*currentChar).foreColor;

                if ((*currentChar).ch != ' ') {
                    (*currentTempChar).ch = (*currentChar).ch;
                }
            }
        }
    }

    tempLayerToDraw.drawLayer();
}

void createLayer (ScreenChar sch) {
    layers.push_back(Layer(sch));
}