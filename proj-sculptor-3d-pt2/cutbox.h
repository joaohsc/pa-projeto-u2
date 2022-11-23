#ifndef CUTBOX_H
#define CUTBOX_H

#include "figurageometrica.h"
/**
 *  @brief a classe cut remove um voxel no formato de box
 *  @details na classe definimos as propriedades que serão removidas
 */
class cutBox : public FiguraGeometrica {
protected:
    int x0, x1,  y0, y1, z0, z1; //POSIÇÃO
public:
    /**
     *  @brief o construtor montar o objeto atribuindo os parâmetros
     *  @param x0 representa o eixo inicial de X
     *  @param y0 representa o eixo inicial de Y
     *  @param z0 representa o eixo inicial de Z
     *  @param x1 representa o eixo final de X
     *  @param y1 representa o eixo final de Y
     *  @param z1 representa o eixo final de Z
     **/
    cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
    ~cutBox();
    void draw(Sculptor &s);

};
#endif // CUTBOX_H
