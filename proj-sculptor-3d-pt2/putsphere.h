#ifndef PUTSPHERE_H
#define PUTSPHERE_H

#include "figurageometrica.h"

class putSphere : public FiguraGeometrica {
protected:
    int xcenter,  ycenter, zcenter,  radius; //POSIÇÃO
public:
    putSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float a);
    ~putSphere();
    void draw(Sculptor &s);

};

#endif // PUTBOX_H
