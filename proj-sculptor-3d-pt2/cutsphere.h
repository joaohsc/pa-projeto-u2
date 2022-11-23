#ifndef CUTSPHERE_H
#define CUTSPHERE_H

#include "figurageometrica.h"
/**
 *  @brief a classe cut remove um voxel no formato de esfera
 *  @details na classe definimos as propriedades que serão removidas
 */
class cutSphere : public FiguraGeometrica {
protected:
    int xcenter,  ycenter, zcenter,  radius; //POSIÇÃO
public:
    /**
     *  @brief o construtor montar o objeto atribuindo os parâmetros
     *  @param xcenter representa o eixo central X
     *  @param ycenter representa o eixo central Y
     *  @param zcenter representa o eixo central Z
     *  @param radius é o raio da esfera
     */
    cutSphere(int xcenter, int ycenter, int zcenter, int radius);
    ~cutSphere();
    void draw(Sculptor &s);

};

#endif //CUTBOX_H
