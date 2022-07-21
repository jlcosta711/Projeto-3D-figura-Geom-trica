#include "cutvoxel.h"

cutVoxel::cutVoxel(int x0, int y0, int z0)
{
  this->x0=x0; 
  this->y0=y0; 
  this->z0=z0;
}

void cutVoxel::draw(Sculptor &t)
{
    t.cutVoxel(x0,y0,z0);
}