#include <iostream>
#include "sculptor.h"
using namespace std;

int main()
{
    Sculptor canva(41,41,41);

    canva.setColor(0,0,1,1);

    canva.putEllipsoid(20,20,20,5,10,5);

    canva.cutEllipsoid(20,20,20,4,9,4);

    canva.cutBox(15,25,21,31,15,25);

    canva.cutVoxel(20,20,15);
    canva.cutVoxel(15,20,20);
    canva.cutVoxel(20,20,25);
    canva.cutVoxel(25,20,20);



    canva.putSphere(20,10,20,5);
    canva.cutSphere(20,13,20,3);

    canva.putBox(19,22,0,6,19,22);

    canva.putBox(18,23,0,2,18,23);

    canva.putVoxel(23,0,20);
    canva.putVoxel(17,0,20);
    canva.putVoxel(20,0,17);
    canva.putVoxel(20,0,23);







    canva.writeOFF("canva.off");

    return 0;
}
