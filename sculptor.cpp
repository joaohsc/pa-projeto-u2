#include <iostream>
#include <fstream>
#include "sculptor.h"

Sculptor::Sculptor(int _nx, int _ny, int _nz)
{
    nx = _nx;
    ny = _ny;
    nz = _nz;

    v = new Voxel**[nx];
    v[0] = new Voxel*[nx*ny];
    v[0][0] = new Voxel[nx*ny*nz];

    for(int i=1; i<nz; i++)
    {
        v[i] = v[i-1] + ny;
    }

    for(int i=1; i<nz*ny; i++)
    {
        v[0][i] = v[0][i-1] + nx;
    }
}

Sculptor::~Sculptor()
{
    delete [] v[0][0];
    delete [] v[0];
    delete [] v;
}

void Sculptor::setColor(float _r, float _g, float _b, float _a)
{
    r = _r;
    g = _g;
    b = _b;
    a = _a;
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

void Sculptor:: putBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    for (int k = z0; k < z1; k++)
    {
        for (int j = y0; j < y1; j++)
        {
            for (int i = x0; i < x1; i++)
            {
                putVoxel(i,j,k);
            }
        }
    }
}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    for (int i = x0; i < x1; i++)
    {
        for (int j = y0; j < y1; j++)
        {
            for (int k = z0; k < z1; k++)
            {
                cutVoxel(i,j,k);
            }
        }
    }
}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    double equation;

    for (int k = 0; k <= nz; k++)
    {
        for (int j = 0; j <= ny; j++)
        {
            for (int i = 0; i <= nx; i++)
            {
                int p1= i - xcenter;
                int p2= j - ycenter;
                int p3= k - zcenter;
                equation = (p1*p1) + (p2*p2) + (p3*p3);
                if (equation <= radius*radius)
                {
                    putVoxel(i,j,k);
                }
            }
        }
    }
}
void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius)
{


    for (int k = 0; k <= nz; k++)
    {
        for (int j = 0; j <= ny; j++)
        {
            for (int i = 0; i <= nx; i++)
            {
                int p1= i - xcenter;
                int p2= j - ycenter;
                int p3= k - zcenter;

                if ((p1*p1) + (p2*p2) + (p3*p3) <= radius*radius)
                {
                    cutVoxel(i,j,k);
                }
            }
        }
    }
}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    for (int k = 0; k <= nz; k++)
    {
        for (int j = 0; j <= ny; j++)
        {
            for (int i = 0; i <= nx; i++)
            {
                int p1= i - xcenter;
                int p2= j - ycenter;
                int p3= k - zcenter;

                double conta = ((p1*p1)/(rx*rx)) + ((p2*p2)/(ry*ry)) + ((p3*p3) / (rz*rz));
                if (conta <= 1)
                {
                    putVoxel(i,j,k);
                }
            }
        }
    }
}


void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    for (int k = 0; k <= nz; k++)
    {
        for (int j = 0; j <= ny; j++)
        {
            for (int i = 0; i <= nx; i++)
            {
                int p1= i - xcenter;
                int p2= j - ycenter;
                int p3= k - zcenter;

                double conta = ((p1*p1)/(rx*rx)) + ((p2*p2)/(ry*ry)) + ((p3*p3) / (rz*rz));
                if (conta <= 1)
                {
                    putVoxel(i,j,k);
                }
            }
        }
    }
}

void Sculptor::writeOFF(const char* filename)
{
    std::ofstream file;

    int nv = 0;
    int nf = 0;


    file.open(filename);

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
                    float red = v[i][j][k].r*255;
                    float green = v[i][j][k].g*255;
                    float blue = v[i][j][k].b*255;
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
