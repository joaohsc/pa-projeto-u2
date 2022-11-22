#include "putellipsoid.h"
#include <iostream>
#include <cmath>

putEllipsoid::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx,int ry, int rz,float r, float g, float b, float a){
    this->xcenter=xcenter;
    this->ycenter=ycenter;
    this->zcenter=zcenter;
    this->rx=rx;
    this->ry=ry;
    this->rz=rz;
    this->r=r;
    this->g=g;
    this->b=b;
    this->a=a;

}
putEllipsoid::~putEllipsoid(){

}
void putEllipsoid::draw(Sculptor &s){

    s.setColor(r,g,b,a);

    for (int i = 0; i < s.getNx(); i++) {
        for (int j = 0; j < s.getNy(); j++) {
            for (int k = 0; k < s.getNz(); k++) {
                int p1= i - xcenter;
                int p2= j - ycenter;
                int p3= k - zcenter;

                float conta = ((float)(p1*p1)/(rx*rx)) + ((float)(p2*p2)/(ry*ry)) + ((float)(p3*p3) / (rz*rz));
                if (conta <= 1)
                {
                    s.putVoxel(i,j,k);
                }
            }
        }
    }
}
