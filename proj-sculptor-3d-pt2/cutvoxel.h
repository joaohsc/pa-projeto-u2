
#ifndef CUTVOXEL_H
#define CUTVOXEL_H

#include "figurageometrica.h"
#include "sculptor.h"

class cutVoxel : public FiguraGeometrica
{
    private:
        int x, y, z;
    public:
        cutVoxel(int x, int y, int z);
        ~cutVoxel();
        void draw(Sculptor &s);
};

#endif // CUTVOXEL_H
