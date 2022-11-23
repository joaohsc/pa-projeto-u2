#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H

#include "figurageometrica.h"
/**
 *  @brief a classe put adiciona voxel no formato de elipsoide
 *  @details na classe definimos os métodos utilizados para configurar a forma e cor
 */
class putEllipsoid : public FiguraGeometrica {
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
   *  @param r representa a cor vermelho no formato RGBA
   *  @param g representa a cor verde no formato RGBA
   *  @param b representa a cor azul no formato RGBA
   *  @param a representa a transparência no formato RGBA
   */
  putEllipsoid(int xcenter, int ycenter, int zcenter, int rx,int ry, int rz,float r, float g, float b, float a);
  ~putEllipsoid();
  void draw(Sculptor &s);

};

#endif // PUTELLIPSOID_H
