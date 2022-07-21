#ifndef PUTSPHERE_H
#define PUTSPHERE_H
#include "figurageometrica.h"
#include "sculptor.h"

class putSphere: public FiguraGeometrica{
int xcenter, ycenter, zcenter, radius;
float r, g, b, a;

public:
 putSphere(int xcenter, int ycenter, int zcenter, int radius,float r, float g, float b, float a);
~putSphere(){};
void draw(Sculptor &t);
};
#endif