#include "sculptor.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;

Sculptor::Sculptor(int nx, int ny, int nz){
    this->nx = nx;
    this->ny = ny;
    this->nz = nz;
    fix = 0.5;
    r = 0.5;
    g = 0.5; 
    b = 0.5;
    a = 0.5;

    // Alocação dinâmica da matriz 3d
    v = new Voxel**[nx];
     for (int i =0; i<nx; i++){
      v[i] = new Voxel*[ny];

     for (int j =0; j<ny; j++){
       v[i][j]= new Voxel[nz];
      }
    }
}

Sculptor::~Sculptor(){
    for(int i = 0; i < nx; i++){
        for (int j = 0; j < ny; j++){
               delete[] v[i][j];
            }
        }
        for (int i=0; i <nx; i++){
            delete[] v[i];
        }

        delete[] v;

        nx = 0;
        ny = 0;
        nz = 0;
}

void Sculptor::setColor(float r1, float g1, float b1, float alpha) // define a cor e transparência de cada voxel
{
    r = r1;
    g = g1;
    b = b1;
    a = alpha;
}

void Sculptor::putVoxel(int x, int y, int z){
    v[x][y][z].isOn = true;
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;

}

void Sculptor::cutVoxel(int x, int y, int z){
    v[x][y][z].isOn = false;
}

int Sculptor::getx(){
    return nx;
}
int Sculptor::gety(){
    return ny;
}
int Sculptor::getz(){
    return nz;
}
void Sculptor::writeOFF(char *filename){

  ofstream fout;
  fout.open(filename);
  int quantvox=0;
  int ref;
  fout << "OFF\n";
 // Confere todos os voxel e analisa os que devem ser exibidos no .off
 for (int i = 0; i < nx; i++){
      for (int j = 0; j <ny; j++){
           for (int k = 0; k <nz; k++){
                if(v[i][j][k].isOn == true){
                quantvox++;
                }
           }
       }
  }
   fout<<quantvox * 8<<" "<<quantvox * 6 << " " << "0" << "\n";//Mostra a quantidade total de vertices, faces e arestas

  for (int a = 0; a < nx; a++){
      for (int b = 0; b < ny; b++){
           for (int c = 0; c < nz; c++){
                if(v[a][b][c].isOn == true){
                fout << a - fix << " " << b + fix << " " << c - fix << "\n" << flush;
                fout << a - fix << " " << b - fix << " " << c - fix << "\n" << flush;
                fout << a + fix << " " << b - fix << " " << c - fix << "\n" << flush;
                fout << a + fix << " " << b + fix << " " << c - fix << "\n" << flush;
                fout << a - fix << " " << b + fix << " " << c + fix << "\n" << flush;
                fout << a - fix << " " << b - fix << " " << c + fix << "\n" << flush;
                fout << a + fix << " " << b - fix << " " << c + fix << "\n" << flush;
                fout << a + fix << " " << b + fix << " " << c + fix << "\n" << flush;
                }
           }
      }
  }

  quantvox = 0;

  //Descrever cada voxel
  for (int a= 0; a<nx; a++){
      for (int b = 0; b<ny; b++){
           for (int c= 0; c<nz; c++){
                if(v[a][b][c].isOn == true){
                ref = quantvox * 8;
                fout << fixed; 


                //Montar linha que realiza a construção das faces a partir do vertices e mostrar as propriedades rgba do voxel
                fout << "4" << " " << 0+ref << " " << 3+ref << " " << 2+ref << " " << 1+ref << " ";
                fout << setprecision(2)<<v[a][b][c].r << " " << setprecision(2)<<v[a][b][c].g <<" " << setprecision(2)<<v[a][b][c].b << " " << setprecision(2) << v[a][b][c].a << "\n";

               fout << "4" << " " << 4+ref << " " << 5+ref << " " << 6+ref << " " << 7+ref << " ";
                fout << setprecision(2)<<v[a][b][c].r << " " << setprecision(2)<<v[a][b][c].g <<" " << setprecision(2)<<v[a][b][c].b << " " << setprecision(2) << v[a][b][c].a << "\n";

                fout << "4" << " " << 0+ref << " " << 1+ref << " " << 5+ref << " " << 4+ref << " ";
                fout << setprecision(2)<<v[a][b][c].r << " " << setprecision(2)<<v[a][b][c].g <<" " << setprecision(2)<<v[a][b][c].b << " " << setprecision(2) << v[a][b][c].a << "\n";

                fout << "4" << " " << 0+ref << " " << 4+ref << " " << 7+ref << " " << 3+ref << " ";
                fout << setprecision(2)<<v[a][b][c].r << " " << setprecision(2)<<v[a][b][c].g <<" " << setprecision(2)<<v[a][b][c].b << " " << setprecision(2) << v[a][b][c].a << "\n";

                fout << "4" << " " << 3+ref << " " << 7+ref << " " << 6+ref << " " << 2+ref << " ";
                fout << setprecision(2)<<v[a][b][c].r << " " << setprecision(2)<<v[a][b][c].g <<" " << setprecision(2)<<v[a][b][c].b << " " << setprecision(2) << v[a][b][c].a << "\n";

                fout << "4" << " " << 1+ref << " " << 2+ref << " " << 6+ref << " " << 5+ref << " ";
                fout << setprecision(2)<<v[a][b][c].r << " " << setprecision(2)<<v[a][b][c].g <<" " << setprecision(2)<<v[a][b][c].b << " " << setprecision(2) << v[a][b][c].a << "\n";

                quantvox = quantvox + 1;
                }
           }
       }
  }
  fout.close();
} 