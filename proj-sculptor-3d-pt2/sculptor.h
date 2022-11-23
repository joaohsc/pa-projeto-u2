#include "voxel.h"

#ifndef SCULPTOR_H
#define SCULPTOR_H
/**
 *  @brief a classe sculptor monta os voxels em uma matriz 3d
 *  @details na classe definimos os métodos utilizados para configurar a forma e cor da figura 3d
 */

class Sculptor {
private:
    Voxel ***v; // 3D matrix
    int nx,ny,nz; // Dimensions
    float r,g,b,a; // Current drawing color
public:
    /**
     *  @brief o construtor faz a alocação dinâmica do "v"
     *  @param nx representa o eixo X
     *  @param ny representa o eixo Y
     *  @param nz representa o eixo Z
     */
    Sculptor(int _nx, int _ny, int _nz);
    /**
     *  @brief o destrutor libera espaço alocado
     */
    ~Sculptor();
    /**
     *  @brief setColor é o método para definir qual a cor do voxel no formato RGBA
     *  @param r representa a cor vermelho no formato RGBA
     *  @param g representa a cor verde no formato RGBA
     *  @param b representa a cor azul no formato RGBA
     *  @param a representa a transparência no formato RGBA
     */
    void setColor(float r, float g, float b, float a);
    /**
     *  @brief putVoxel adiciona um voxel nos eixos configurados
     *  @param x representa o eixo X
     *  @param y representa o eixo Y
     *  @param z representa o eixo Z
     */
    void putVoxel(int x, int y, int z);
    /**
     *  @brief cutVoxel remove um voxel nos eixos configurados
     *  @param x representa o eixo X
     *  @param y representa o eixo Y
     *  @param z representa o eixo Z
     */
    void cutVoxel(int x, int y, int z);
    /**
     *  @brief writeOFF é um método que cria/edita um documento em formato .OFF
     */
    void writeOFF(const char* filename);
    int getNx();
    int getNy();
    int getNz();
};

#endif // SCULPTOR_H
