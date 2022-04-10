#include "core.h"

#include <cstdio>

void putCharAtLayer (Position pos, ScreenChar sch, unsigned int layerIndex) {
    std::vector<Layer> layers = getLayers();
    layers.at(layerIndex).putCharAt(pos, sch);
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