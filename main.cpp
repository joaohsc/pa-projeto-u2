#include <iostream>
#include "sculptor.h"
using namespace std;

int main()
{
    Sculptor canva(41,41,41);

    canva.setColor(0,0,1,1);

    canva.putVoxel(0,0,0);
    canva.putVoxel(1,1,1);

    canva.putBox(2,4,2,4,2,4);

    canva.putSphere(20,20,20,10);

    canva.putEllipsoid(13,13,13,6,6,6);

    canva.writeOFF("canva.off");

    return 0;
}
