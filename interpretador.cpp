#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "putvoxel.h"
#include "putbox.h"
#include "putsphere.h"
#include "putellipsoid.h"
#include "cutvoxel.h"
#include "cutbox.h"
#include "cutsphere.h"
#include "cutellipsoid.h"

using namespace std;
#include "interpretador.h"

Interpretador::Interpretador()
{
}

vector<FiguraGeometrica*> Interpretador:: anl(string filename){

    vector<FiguraGeometrica*> figuras; // onde será armazenado os desenhos
    ifstream arqv;
    string stng,pp;
    stringstream ss;

    arqv.open(filename.c_str());

    if(!arqv.is_open()){
        exit(0);
    }

    while(getline(arqv,stng)){

    ss.clear();
    ss.str(stng);
    ss >> pp;
    cout << pp << " ";

    if(pp.compare("dim")==0){
        ss >> dimx >> dimy >> dimz;
    }
    else if(pp.compare("putvoxel")==0){
        int x_,y_,z_;
        ss >> x_ >> y_ >> z_ >> r >> g >> b >> a;
        figuras.push_back(new putVoxel(x_, y_, z_, r, g, b, a));
    }
    else if(pp.compare("cutvoxel")==0){
        int x_, y_, z_;
        ss >> x_ >> y_ >> z_;
        figuras.push_back(new cutVoxel(x_,y_,z_));
    }
    else if(pp.compare("putbox")==0){
        int x0; int x1; int y0; int y1; int z0; int z1;
        ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
        
        figuras.push_back(new putBox(x0,x1,y0, y1, z0,z1, r, g, b, a));
    }
    else if(pp.compare("cutbox")==0){
        int x0; int x1; int y0; int y1; int z0; int z1;
        ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
        figuras.push_back(new cutBox(x0,x1,y0, y1, z0,z1));
    }
    else if(pp.compare("putsphere")==0){
        int xcenter; int ycenter; int zcenter; int radius;
        ss >> xcenter >> ycenter >> zcenter >> radius >> r >> g >> b >> a;
        figuras.push_back(new putSphere(xcenter, ycenter, zcenter, radius, r, g, b, a));
    }
    else if(pp.compare("cutsphere")==0){
        int xcenter; int ycenter; int zcenter; int radius;
        ss >> xcenter >> ycenter >> zcenter >> radius;
        figuras.push_back(new cutSphere(xcenter, ycenter, zcenter, radius));
    }
    else if(pp.compare("putellipsoid")==0){
        int xcenter, ycenter, zcenter, rx, ry, rz;
        ss >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz >> r >> g >> b >> a;
        figuras.push_back(new putEllipsoid(xcenter,ycenter,zcenter,rx,ry,rz, r, g, b, a));
    }
    else if(pp.compare("cutellipsoid")==0){
        int xcenter_, ycenter_, zcenter_, rx_, ry_, rz_;
        ss >> xcenter_ >> ycenter_ >> zcenter_ >> rx_ >> ry_ >> rz_;
        figuras.push_back(new cutEllipsoid(xcenter_,ycenter_,zcenter_,rx_,ry_,rz_));
    }
    }

    arqv.close();
    return(figuras);
}

int Interpretador::getdimx()
{
    return dimx;
}

int Interpretador::getdimy()
{
    return dimy;
}

int Interpretador::getdimz()
{
    return dimz;
}