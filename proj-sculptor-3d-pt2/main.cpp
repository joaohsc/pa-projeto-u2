#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <string>
#include "figurageometrica.h"
#include "putbox.h"
#include "putvoxel.h"
#include "putsphere.h"
#include "putellipsoid.h"
#include "cutbox.h"
#include "cutvoxel.h"
#include "cutsphere.h"
#include "cutellipsoid.h"
#include "sculptor.h"
using namespace std;

int main()
{
    //FiguraGeometrica *pf;
    Sculptor *scp;


    std::vector<FiguraGeometrica*> figs;
    std::vector<FiguraGeometrica*>::iterator itf;

    std::ifstream fin;

    fin.open("C:/Users/johnny/Documents/develop-proj/sculptor-3d-repo/sculptor-3d-cpp/proj-sculptor-3d-pt2/caneca.txt");

    if(!fin.is_open()){
        std::cout << "nao abriu arquivo figura\n";
        exit(EXIT_FAILURE);
    }

    std::string s;
    float r, g, b, a;
    int dx, dy,dz;
    while(fin.good()){
        // processa a linha
        fin >> s;
        if(!fin.good())
            break;
        std::cout << "leu " << s << std::endl;
        if (s.compare("dim") == 0)
        {
            fin >> dx >> dy >> dz;
        }
        else if(s.compare("putvoxel")==0)
        {
            int x, y, z;
            fin >> x >> y >> z >> r >> g >> b >> a;
            figs.push_back(new putVoxel(x,y,z,r,g,b,a));
        }
        else if(s.compare("cutvoxel")==0)
        {
            int x, y, z;
            fin >> x >> y >> z;
            figs.push_back(new cutVoxel(x,y,z));
        }
        else if(s.compare("putbox")==0){
            int x0, y0, z0, x1, y1,z1;
            fin >> x0 >> y0 >> z0 >> x1 >> y1 >> z1;
            fin >> r >> g >> b >> a;

            figs.push_back(new putbox(x0,y0,z0,x1,y1,z1,r,g,b,a));
        }
        else if(s.compare("cutbox")==0)
        {
            int x0,x1,y0,y1,z0,z1;
            fin >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 ;
            figs.push_back(new cutBox(x0,x1,y0,y1,z0,z1));
        }
        else if(s.compare("putsphere")==0)
        {
            int xcenter, ycenter, zcenter, radius;
            fin >> xcenter >> ycenter >> zcenter >> radius >> r >> g >> b >> a;
            figs.push_back(new putSphere(xcenter,ycenter,zcenter,radius,r,g,b,a));
        }
        else if(s.compare("cutsphere")==0)
        {
            int xcenter, ycenter, zcenter, radius;
            fin >> xcenter >> ycenter >> zcenter >> radius;
            figs.push_back(new cutSphere(xcenter,ycenter,zcenter,radius));
        }
        else if(s.compare("putellipsoid")==0)
        {
            int xcenter, ycenter, zcenter, rx, ry, rz;
            fin >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz >> r >> g >> b >> a;
            figs.push_back(new putEllipsoid(xcenter,ycenter,zcenter,rx,ry,rz,r,g,b,a));
        }
        else if(s.compare("cutellipsoid")==0)
        {
            int xcenter, ycenter, zcenter, rx, ry, rz;
            fin >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz;
            figs.push_back(new cutEllipsoid(xcenter,ycenter,zcenter,rx,ry,rz));
        }
    }

    scp= new Sculptor(dx, dy, dz);

    for(auto it: figs){
        it->draw(*scp);
    }

    scp->writeOFF((char*) "caneca.off");

    for(itf = figs.begin(); itf!=figs.end(); itf++){
        delete *itf;
    }

    return 0;
}
