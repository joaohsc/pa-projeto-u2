#ifndef PUTVOXEL_H
#define PUTVOXEL_H

#include "figurageometrica.h"
#include "sculptor.h"

class putVoxel : public FiguraGeometrica
{
private:
    int x, y, z;
public:
    putVoxel(int x, int y, int z, float r,float g,float b,float a);
    ~putVoxel();
    void draw(Sculptor &s);
};

#endif // PUTVOXEL_H
