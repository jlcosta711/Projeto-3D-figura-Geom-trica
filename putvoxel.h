#ifndef PUTVOXEL_H
#define PUTVOXEL_H
#include "figurageometrica.h"
#include "sculptor.h"

class putVoxel: public FiguraGeometrica{
int x0,y0,z0;

public:
 putVoxel(int x0, int y0, int z0, float r, float g, float b, float a);
~putVoxel(){};
void draw(Sculptor &t);
};
#endif
