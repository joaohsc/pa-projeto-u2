#include "cutvoxel.h"

cutVoxel::cutVoxel(int x, int y, int z)
{
    this -> x = x;
    this -> y = y;
    this -> z = z;
}

cutVoxel::~cutVoxel()
{
}

void cutVoxel::draw(Sculptor &s)
{
    s.cutVoxel(x,y,z);
}
