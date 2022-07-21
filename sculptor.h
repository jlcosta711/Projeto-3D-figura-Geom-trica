#ifndef SCULPTOR_H
#define SCULPTOR_H

struct Voxel{
    float r, g, b, a;
    bool isOn;
};



class Sculptor
{
protected:
    Voxel ***v; // Matrix 3D
    int nx,ny,nz; // Dimensões
    float r,g,b,a; // Propriedades do Voxel
    float fix;

public:
    Sculptor(int nx1, int ny1, int nz1);
    ~Sculptor();
    void setColor(float r1, float g1, float b1, float alpha);
    void putVoxel(int x, int y, int z);
    void cutVoxel(int x, int y, int z);
    int getx();
    int gety();
    int getz();
    void writeOFF(char *filename);

};
#endif // SCULPTOR_H