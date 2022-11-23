
#ifndef CUTVOXEL_H
#define CUTVOXEL_H

#include "figurageometrica.h"
#include "sculptor.h"
/**
 *  @brief a classe cut remove um voxel
 *  @details na classe definimos as propriedades que serão removidas
 */
class cutVoxel : public FiguraGeometrica
{
    private:
        int x, y, z;
    public:
        /**
         *  @brief o construtor montar o objeto atribuindo os parâmetros
         *  @param x representa o eixo X
         *  @param y representa o eixo Y
         *  @param z representa o eixo Z
         */
        cutVoxel(int x, int y, int z);
        ~cutVoxel();
        void draw(Sculptor &s);
};

#endif // CUTVOXEL_H
