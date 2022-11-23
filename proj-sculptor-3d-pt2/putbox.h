#ifndef PUTBOX_H
#define PUTBOX_H

#include "figurageometrica.h"
#include "sculptor.h"

/**
 *  @brief a classe put adiciona voxel no formato de box
 *  @details na classe definimos os métodos utilizados para configurar a forma e cor
 */

class putbox : public FiguraGeometrica {
    int x0, x1, y0, y1, z0, z1;
public:
    /**
     *  @brief o construtor montar o objeto atribuindo os parâmetros
     *  @param x0 representa o eixo inicial de X
     *  @param y0 representa o eixo inicial de Y
     *  @param z0 representa o eixo inicial de Z
     *  @param x1 representa o eixo final de X
     *  @param y1 representa o eixo final de Y
     *  @param z1 representa o eixo final de Z
     *  @param r representa a cor vermelho no formato RGBA
     *  @param g representa a cor verde no formato RGBA
     *  @param b representa a cor azul no formato RGBA
     *  @param a representa a transparência no formato RGBA
     **/
    putbox(int x0, int x1, int y0, int y1, int z0, int z1, float r, float g, float b, float a);
    ~putbox();
    void draw(Sculptor &s);
};

#endif // PUTBOX_H
