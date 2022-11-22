#include <iostream>
#include <iomanip>
#include <fstream>
#include "sculptor.h"

Sculptor::Sculptor(int _nx, int _ny, int _nz)
{
    nx = _nx;
    ny = _ny;
    nz = _nz;

    v = new Voxel**[nx];

    for (int i = 0; i < nx; i++)
    {
        v[i] = new Voxel*[ny];
        for (int j = 0; j < ny; j++) {
            v[i][j] = new Voxel[nz];
        }
    }


    for (int i = 0; i < nx; i++)
    {
        for (int j = 0; j < ny; j++)
        {
            for (int k = 0; k < nz; k++)
            {
                v[i][j][k].isOn=false;
            }
        }
    }

}

Sculptor::~Sculptor()
{
    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            delete[] v[i][j];
        }
        delete[] v[i];
    }

    delete[] v;

    nx = 0;
    ny = 0;
    nz = 0;
}

void Sculptor::setColor(float r, float g, float b, float a)
{
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

void Sculptor::putVoxel(int x, int y, int z)
{
    v[x][y][z].isOn = true;
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;
}

void Sculptor::cutVoxel(int x, int y, int z)
{
    v[x][y][z].isOn =false;
}

void Sculptor::writeOFF(const char* filename)
{
    std::ofstream file;

    int nv = 0;
    int nf = 0;


    file.open(filename);

    if(!file.is_open()){
        exit(1);
    }

    file << "OFF" << std::endl;

    for (int px = 0; px < nx; px++)
    {
        for (int py = 0; py < ny; py++)
        {
            for (int pz = 0; pz < nz; pz++)
            {
                if (v[px][py][pz].isOn)
                {
                    nv += 8;
                    nf += 6;
                }
            }
        }
    }

    file << nv << ' ' << nf << ' ' << 0 << std::endl;

    file << std::fixed;
    file << std::setprecision(2);

    for (int i = 0; i < nx; i++)
    {
        for (int j = 0; j < ny; j++)
        {
            for (int k = 0; k < nz; k++)
            {
                if (v[i][j][k].isOn)
                {
                    file << (i - 0.5) << ' ' << (j + 0.5) << ' ' << (k - 0.5) << std::endl;
                    file << (i - 0.5) << ' ' << (j - 0.5) << ' ' << (k - 0.5) << std::endl;
                    file << (i + 0.5) << ' ' << (j - 0.5) << ' ' << (k - 0.5) << std::endl;
                    file << (i + 0.5) << ' ' << (j + 0.5) << ' ' << (k - 0.5) << std::endl;
                    file << (i - 0.5) << ' ' << (j + 0.5) << ' ' << (k + 0.5) << std::endl;
                    file << (i - 0.5) << ' ' << (j - 0.5) << ' ' << (k + 0.5) << std::endl;
                    file << (i + 0.5) << ' ' << (j - 0.5) << ' ' << (k + 0.5) << std::endl;
                    file << (i + 0.5) << ' ' << (j + 0.5) << ' ' << (k + 0.5) << std::endl;
                }
            }
        }
    }

    int count = 0;
    for (int i = 0; i < nx; i++)
    {
        for (int j = 0; j < ny; j++)
        {
            for (int k = 0; k < nz; k++)
            {
                if (v[i][j][k].isOn)
                {
                    float red = v[i][j][k].r;
                    float green = v[i][j][k].g;
                    float blue = v[i][j][k].b;
                    float alpha = v[i][j][k].a;

                    file << 4 << ' ' << count + 0 << ' ' << count + 3 << ' ' << count + 2 << ' ' << count + 1 << ' ';
                    file << red << ' ' << green << ' ' << blue << ' ' << alpha<< std::endl;

                    file << 4 << ' ' << count + 4 << ' ' << count + 5 << ' ' << count + 6 << ' ' << count + 7 << ' ';
                    file << red << ' ' << green << ' ' << blue << ' ' << alpha << std::endl;

                    file << 4 << ' ' << count + 0 << ' ' << count + 1 << ' ' << count + 5 << ' ' << count + 4 << ' ';
                    file << red << ' ' << green << ' ' << blue << ' ' << alpha << std::endl;

                    file << 4 << ' ' << count + 0 << ' ' << count + 4 << ' ' << count + 7 << ' ' << count + 3 << ' ';
                    file << red << ' ' << green << ' ' << blue << ' ' << alpha << std::endl;

                    file << 4 << ' ' << count + 3 << ' ' << count + 7 << ' ' << count + 6 << ' ' << count + 2 << ' ';
                    file << red << ' ' << green << ' ' << blue << ' ' << alpha << std::endl;

                    file << 4 << ' ' << count + 1 << ' ' << count + 2 << ' ' << count + 6 << ' ' << count + 5 << ' ';
                    file << red << ' ' << green << ' ' << blue << ' ' << alpha << std::endl;



                    count += 8;
                }
            }
        }
    }

    file.close();
    std::cout <<"Arquivo criado!" << std::endl;
}
