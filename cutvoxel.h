#ifndef CUTVOXEL_H
#define CUTVOXEL_H

#include "figurageometrica.h"

class cutVoxel:public FiguraGeometrica
{
    int x0; int y0; int z0;
public:
    cutVoxel(int x0, int y0, int z0);
    ~cutVoxel(){};
    void draw(Sculptor &t);
};

#endif // CUTVOXEL_H