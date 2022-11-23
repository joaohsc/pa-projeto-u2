#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H

#include "sculptor.h"
/**
 *  @brief a classe da figura geométrica representa o objeto no topo da herança
 *  @details na classe definimos os métodos utilizados para configurar a forma e cor
 */
class FiguraGeometrica{
    protected:
        float r,g,b,a;
    public:
        virtual ~FiguraGeometrica(){}
        virtual void draw(Sculptor &s)=0;
};

#endif // FIGURAGEOMETRICA_H
