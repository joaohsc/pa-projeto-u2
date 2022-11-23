#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H

#include "figurageometrica.h"
/**
 *  @brief a classe cut remove um voxel no formato de elipsoide
 *  @details na classe definimos as propriedades que serão removidas
 */
class cutEllipsoid : public FiguraGeometrica {
protected:
    int xcenter,ycenter, zcenter, rx, ry, rz; //POSIÇÃO
public:
    /**
     *  @brief o construtor montar o objeto atribuindo os parâmetros
     *  @param xcenter representa o eixo central X
     *  @param ycenter representa o eixo central Y
     *  @param zcenter representa o eixo central Z
     *  @param rx representa o raio no eixo X
     *  @param ry representa o raio no eixo Y
     *  @param rz representa o raio no eixo Z
     */
    cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx,int ry, int rz);
    ~cutEllipsoid();
    void draw(Sculptor &s);

};

#endif // CUTELLIPSOID_H
