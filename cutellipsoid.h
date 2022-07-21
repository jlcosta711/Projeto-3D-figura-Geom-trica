#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H
#include "figurageometrica.h"


class cutEllipsoid: public FiguraGeometrica{
int xcenter_,ycenter_,zcenter_,rx_,ry_,rz_;
float r, g, b, a;
public:
 cutEllipsoid(int xcenter_, int ycenter_, int zcenter_, int rx_, int ry_, int rz_);
~cutEllipsoid(){};
void draw(Sculptor &t);
};
#endif