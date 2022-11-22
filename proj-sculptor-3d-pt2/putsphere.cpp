#include "putsphere.h"
#include <iostream>
#include <cmath>

putSphere::putSphere(int xcenter, int ycenter, int zcenter, int radius,float r, float g, float b, float a){
    this->xcenter=xcenter;
    this->ycenter=ycenter;
    this->zcenter=zcenter;
    this->radius=radius;
    this->r=r;
    this->g=g;
    this->b=b;
    this->a=a;
}
putSphere::~putSphere(){

}

void putSphere:: draw(Sculptor &s){


    s.setColor(r,g,b,a);

    for (int i = 0; i < (xcenter+radius); i++) {
        for (int j = 0; j < (ycenter+radius); j++) {
            for (int k = 0; k < (zcenter+radius); k++) {
                int p1= i - xcenter;
                int p2= j - ycenter;
                int p3= k - zcenter;
                float equation = ((p1*p1) + (p2*p2) + (p3*p3));

                if (equation <= radius*radius)
                {
                    s.putVoxel(i,j,k);
                }
            }
        }
    }
}


