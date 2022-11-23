#ifndef PUTSPHERE_H
#define PUTSPHERE_H

#include "figurageometrica.h"
/**
 *  @brief a classe put adiciona voxel no formato de esfera
 *  @details na classe definimos os métodos utilizados para configurar a forma e cor
 */
class putSphere : public FiguraGeometrica {
protected:
    int xcenter,  ycenter, zcenter,  radius; //POSIÇÃO
public:
    /**
     *  @brief o construtor montar o objeto atribuindo os parâmetros
     *  @param xcenter representa o eixo central X
     *  @param ycenter representa o eixo central Y
     *  @param zcenter representa o eixo central Z
     *  @param radius é o raio da esfera
     *  @param r representa a cor vermelho no formato RGBA
     *  @param g representa a cor verde no formato RGBA
     *  @param b representa a cor azul no formato RGBA
     *  @param a representa a transparência no formato RGBA
     */
    putSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float a);
    ~putSphere();
    void draw(Sculptor &s);

};

#endif // PUTBOX_H
