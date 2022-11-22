#ifndef PUTBOX_H
#define PUTBOX_H

#include "figurageometrica.h"
#include "sculptor.h"

class putbox : public FiguraGeometrica {
    int x0, x1, y0, y1, z0, z1;
public:
    putbox(int x0, int x1, int y0, int y1, int z0, int z1, float r, float g, float b, float a);
    ~putbox();
    void draw(Sculptor &s);
};

#endif // PUTBOX_H
