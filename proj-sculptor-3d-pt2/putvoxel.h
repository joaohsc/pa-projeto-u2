#ifndef PUTVOXEL_H
#define PUTVOXEL_H

#include "figurageometrica.h"
#include "sculptor.h"
/**
 *  @brief a classe put adiciona um voxel
 *  @details na classe definimos os métodos utilizados para configurar a forma e cor
 */
class putVoxel : public FiguraGeometrica
{
private:
    int x, y, z;
public:
    /**
     *  @brief o construtor montar o objeto atribuindo os parâmetros
     *  @param x representa o eixo X
     *  @param y representa o eixo Y
     *  @param z representa o eixo Z
     *  @param r representa a cor vermelho no formato RGBA
     *  @param g representa a cor verde no formato RGBA
     *  @param b representa a cor azul no formato RGBA
     *  @param a representa a transparência no formato RGBA
     */
    putVoxel(int x, int y, int z, float r,float g,float b,float a);
    ~putVoxel();
    void draw(Sculptor &s);
};

#endif // PUTVOXEL_H
