#include "cutsphere.h"
#include <iostream>
#include <cmath>

cutSphere::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
    this->xcenter=xcenter;
    this->ycenter=ycenter;
    this->zcenter=zcenter;
    this->radius=radius;
}
cutSphere::~cutSphere(){

}

void cutSphere:: draw(Sculptor &s){
    for (int i = 0; i < s.getNx(); i++) {
        for (int j = 0; j < s.getNy(); j++) {
            for (int k = 0; k < s.getNz(); k++) {
                int p1= i - xcenter;
                int p2= j - ycenter;
                int p3= k - zcenter;

                float equation = ((p1*p1) + (p2*p2) + (p3*p3));

                if (equation <= radius*radius)
                {
                    s.cutVoxel(i,j,k);
                }
            }
        }
    }
}
