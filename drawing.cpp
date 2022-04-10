#include "core.h"

#include <cstdio>
#include <ctime>
#include <exception>

void putCharAtLayer (Position pos, ScreenChar sch, unsigned int layerIndex) {
    std::vector<Layer> layers = getLayers();
    try {
        layers.at(layerIndex).putCharAt(pos, sch);
    }
    catch (const std::exception e) {
        char* str;
        std::snprintf(str, 1000, "Index %i is not an index to any existing layer", layerIndex);
        logError(str);
    }
    setLayers(layers);
}

void drawRectangleAtLayer (Position pos1, Position pos2, ScreenChar sch, unsigned int layerIndex) {
    std::vector<Layer> layers = getLayers();

    for (int y = pos1.y; y <= pos2.y; y++) {
        for (int x = pos1.x; x <= pos2.x; x++) {
            putCharAtLayer(Position(x, y), sch, layerIndex);
        }
    }    
}