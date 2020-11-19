#include "Sculptor.h" // Header onde está declarada a classe Sculptor
#include <iostream>   // Header de entrada e saida de dados
#include <cstdlib>    // Header usado para o exit
#include <cmath>      // Header usado para operações matematicas
#include <fstream>    // Header usado na funcao writeoff

using namespace std;

// Construtor da classe
Sculptor::Sculptor(int _nx, int _ny, int _nz){
    nx = _nx;
    ny = _ny;
    nz = _nz;
    if (_nx <= 0 || _ny <= 0 || _nz <= 0){
        _nx = _ny = _nz = 0;
    }
// Alocaçao da matriz 3d
    v = new Voxel **[_nz];
    if ( v == NULL){
        cout << "Erro de alocação" << endl;
        exit(1) ;
    }
    v[0] = new Voxel*[_nz*_ny];
    if (v[0] == NULL){
        cout << "Erro de alocação" << endl;
        exit(1) ;
    }
    v[0][0] = new Voxel[_nx*_ny*_nz];
    if (v[0][0] == NULL){
        cout << "Erro de alocação" << endl;
        exit(1) ;
    }

    for (int i = 1; i < _nz; i++){
        v[i] = v[i-1] + _nz;
    }

    for (int j = 1; j < (_nz*_ny); j++){
        v[0][j] = v[0][j-1] + _nx;

    }
}
// Destrutor da classe
Sculptor::~Sculptor(){

// Liberando a memoria alocada
    delete [] v[0][0];
    delete [] v[0];
    delete [] v;
}

// Define a cor atual do desenho
void Sculptor::setColor(float _r, float _g, float _b, float alpha){
    if(r < 0 || r > 1 || g < 0 || g > 1 || b < 0 || b > 1 || alpha < 0 || alpha > 1){
        cout << "Dimensao errada na funcao setColor" << endl;
        exit(1);
    }
      r = _r;
      g = _g;
      b = _b;
      a = alpha;

}

// Ativa o voxel em uma posição (x,y,z) e faz isOn = true
void Sculptor::putVoxel(int x, int y, int z){
    // Verificacao das dimensoes
    if(x < 0 || x > nx ||  y < 0 || y > ny || z < 0 || z > nz){
        cout << "Dimensao errada na função putVoxel" << endl;
    }
    else{
    v[x][y][z].isOn = true;
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;
    }
}

// Desativa o voxel em uma posição (x,y,z) e faz isOn = false
void Sculptor::cutVoxel(int x, int y, int z){
    // Verificacao das dimensoes
    if(x < 0 || x > nx ||  y < 0 || y > ny || z < 0 || z > nz){
        cout << "Dimensao errada na função cutVoxel" << endl;
    }
    else{
    v[x][y][z].isOn = false;
    }
}

// Ativa todos os voxels em um intervalo e os atribui a cor atual do desenho
void Sculptor::putBox(int x0, int y0, int z0, int x1, int y1, int z1){
    // Verificacao das dimensoes
    if (x0 < 0 || x0 > nx || x1 < 0 || x1 > nx || y0 < 0 || y0 > ny || y1 < 0 || y1 > ny || z0 < 0 || z0 > nz || z1 < 0 || z1 > nz ){
        cout << "Dimensao errada na funcao putBox" << endl;
        exit(1);
    }
    else{
        for(int i = x0; i < x1; i++){
            for(int j = y0; j < y1; j++){
                for(int k = z0; k < z1; k++){
                    v[i][j][k].isOn = true;
                    v[i][j][k].r = r;
                    v[i][j][k].g = g;
                    v[i][j][k].b = b;
                    v[i][j][k].a = a;
                } // for k
            } // for j
        } // for i
    } // else
} // putBox

// Desativa todos os voxels em um intervalo e os atribui a cor atual do desenho
void Sculptor::cutBox(int x0, int y0, int z0, int x1, int y1, int z1){
    // Verificacao das dimensoes
    if (x0 < 0 || x0 > nx || x1 < 0 || x1 > nx || y0 < 0 || y0 > ny || y1 < 0 || y1 > ny || z0 < 0 || z0 > nz || z1 < 0 || z1 > nz ){
        cout << "Dimensao errada na funcao cutBox" << endl;
        exit(1);
    }
    else{
        for(int i = x0; i <= x1; i++){
            for(int j = y0; j <= y1; j++){
                for(int k = z0; k <= z1; k++){
                v[i][j][k].isOn = false;
                } // for k
            } // for j
        } // for i
    } // else
} // cutBox

// Ativa todos os voxels que atendem a equação da esfera e os atribui a cor atual do desenho
void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){
    if( xcenter < 0 || xcenter > nx || ycenter < 0 || ycenter > ny || zcenter < 0 || zcenter > nz || radius < 0 || (xcenter + radius) > nx
        || (ycenter + radius) > ny || (zcenter + radius) > nz){
    cout << "Dimensao errada na funcao putSphere" << endl;
    exit(1);
    }
    else{
        // Variavel para a distancia da esfera com relação aos voxels do desenho
        float dist;
        for(int i = 0; i <= nx; i++){
            for(int j = 0; j <= ny; j++){
                for(int k = 0; k <= nz; k++){
                    // Eq da esfera
                    dist = sqrt( pow(i - xcenter, 2) +  pow(j - ycenter ,2) + pow(k - zcenter ,2));
                    if (dist <= radius){
                        v[i][j][k].r = r;
                        v[i][j][k].g = g;
                        v[i][j][k].b = b;
                        v[i][j][k].a = a;
                        v[i][j][k].isOn = true;
                    } // if
                } // for k
            } // for j
        } // for i
    } // else
} // putSphere

// Desativa os voxels que atendem a equação da esfera
void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
    // Verificação das dimensões
    if( xcenter < 0 || xcenter > nx || ycenter < 0 || ycenter > ny || zcenter < 0 || zcenter > nz || radius < 0 || (xcenter + radius) > nx
        || (ycenter + radius) > ny || (zcenter + radius) > nz){
    cout << "Dimensao errada na funcao cutSphere" << endl;
    exit(1);
    }
    else{
    // Variavel para a distancia da esfera com relação aos voxels do desenho
    float dist;
        for(int i = 0; i <= nx; i++){
            for(int j = 0; j <= ny; j++){
                for(int k = 0; k <= nz; k++){
                    // Eq da esfera
                    dist = sqrt( pow(i - xcenter, 2) +  pow(j - ycenter ,2) + pow(k - zcenter ,2));
                    if (dist <= radius){
                        v[i][j][k].isOn = false;
                    } // if
                } // for k
            } // for j
        } // for i
    } // else
} // cutSphere

// Cria voxels que atendem a equação da elipsóide e os atribui a cor do desenho
void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    // Verificacao das dimensões
    if( xcenter < 0 || xcenter > nx || ycenter < 0 || ycenter > ny || zcenter < 0 || zcenter > nz || (xcenter + rx) > nx
       || (ycenter + ry) > ny || (zcenter + rz) > nz || rx < 0 || ry < 0 || rz < 0){
    cout << "Dimensao errada na funcao putEllipsoid" << endl;
    exit(1);
    }
    else{
            // Variavel para a distancia da esfera com relação aos voxels do desenho
            float dist;
            for(int i = xcenter - rx; i < xcenter + rx; i++){
                for(int j = ycenter - ry; j < ycenter + ry; j++){
                    for(int k = zcenter - rz; k < zcenter + rz; k++){
                          // Eq da elipsóide
                         dist = (float)pow((i - xcenter ) ,2)/ pow(rx, 2) +  (float)pow((j - ycenter ) ,2)/ pow(ry, 2) +
                        (float)pow((k - zcenter ) ,2)/ pow(rz, 2);
                        if ((dist <= 1.0)){
                            v[i][j][k].r = r;
                            v[i][j][k].g = g;
                            v[i][j][k].b = b;
                            v[i][j][k].a = a;
                            v[i][j][k].isOn = true;
                    } // if
                } // for k
            } // for j
        } // for i
    } // else
} // putEllipsoid

// Desativa uma sequencia de voxels que atendem a equação da elipsóide
void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    // Verificação das dimensões
    if( xcenter < 0 || xcenter > nx || ycenter < 0 || ycenter > ny || zcenter < 0 || zcenter > nz || (xcenter + rx) > nx
       || (ycenter + ry) > ny || (zcenter + rz) > nz || rx < 0 || ry < 0 || rz < 0){
    cout << "Dimensao errada na funcao cutEllipsoid" << endl;
    exit(1);
    }
    else{
            // Variavel para a distancia da esfera com relação aos voxels do desenho
            float dist;
            for(int i = xcenter - rx; i < xcenter + rx; i++){
                for(int j = ycenter - ry; j < ycenter + ry; j++){
                    for(int k = zcenter - rz; k < zcenter + rz; k++){
                        if(i >= 0 && i < nx && j >= 0 && j < ny && k >= 0 && k < nz){
                          // Eq da elipsóide
                         dist = (float)pow((i - xcenter ) ,2)/ pow(rx, 2) +  (float)pow((j - ycenter ) ,2)/ pow(ry, 2) +
                        (float)pow((k - zcenter ) ,2)/ pow(rz, 2);;
                        }
                        if ((dist <= 1.0)){
                           v[i][j][k].isOn = false;
                    } // if
                } // for k
            } // for j
        } // for i
    } // else
} // cutEllipsoid

// Função que grava o arquivo OFF
void Sculptor::writeOFF(char *filename){

    // Variaveis para o número de vertices, faces e arestas
    int nv = 0;
    int nf = 0;

    // Variaveis aux para face de cada voxel
    int Faux = 0;

    // Classe de fluxo que permite operação em arquivos
    ofstream aux;

    // Abertura/ criação de arquivo OFF
    aux.open(filename);

    // Verificação se o arquivo OFF foi aberto
    if( aux.is_open()){
        cout << "Arquivo OFF aberto com sucesso\n" << endl;
    }
    else{
        cout << "Abertura de arquivo OFF falhou\n" << endl;
        exit(1);
    }
    // Primeira linha do arquivo. Palavra obrigatóŕia em arquivos OFF
    aux << "OFF" << endl;

    // Contagem de vertices e faces, que serao incluidos na escultura
    for( int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){
                if(v[i][j][k].isOn ){
                    nv = nv + 8;
                    nf = nf + 6;
                } // if
            } // for k
        } // for j
    } // for i

    // 2 linha do arquivo OFF, mostrando a quantidade de vertices, faces e arestas
    aux<< nv << " " << nf << " " << 0 << endl;

    // Criando as dimensoes dos vertices da figura, para cada voxel ativo, o voxel tem dimensão igual a 1
     for( int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){
                if(v[i][j][k].isOn){
                    aux << i - 0.5 << " " << j + 0.5 << " " << k - 0.5 << endl;
                    aux << i - 0.5 << " " << j - 0.5 << " " << k - 0.5 << endl;
                    aux << i + 0.5 << " " << j - 0.5 << " " << k - 0.5 << endl;
                    aux << i + 0.5 << " " << j + 0.5 << " " << k - 0.5 << endl;
                    aux << i - 0.5 << " " << j + 0.5 << " " << k + 0.5 << endl;
                    aux << i - 0.5 << " " << j - 0.5 << " " << k + 0.5 << endl;
                    aux << i + 0.5 << " " << j - 0.5 << " " << k + 0.5 << endl;
                    aux << i + 0.5 << " " << j + 0.5 << " " << k + 0.5 << endl;
                } // if
            } // for k
        } // for j
     } // for i

    // Criando as dimensões das faces e atribuindo as cores, para cada voxel ativo
     for( int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){
                if(v[i][j][k].isOn){
                        aux << 4 <<" "<< Faux + 0 <<" "<< Faux + 3 <<" "<< Faux + 2 <<" "<< Faux + 1 <<" "<<
                        v[i][j][k].r <<" "<< v[i][j][k].g <<" "<< v[i][j][k].b <<" "<< v[i][j][k].a << endl;
                        aux<< 4 <<" "<< Faux + 4 <<" "<< Faux + 5 <<" "<< Faux + 6 <<" "<< Faux + 7 <<" "<<
                        v[i][j][k].r <<" "<< v[i][j][k].g <<" "<< v[i][j][k].b <<" "<< v[i][j][k].a << endl;
                        aux<< 4 <<" "<< Faux + 0 <<" "<< Faux + 1 <<" "<< Faux + 5 <<" "<< Faux + 4 <<" "<<
                        v[i][j][k].r <<" "<< v[i][j][k].g <<" "<< v[i][j][k].b <<" "<< v[i][j][k].a << endl;
                        aux<< 4 <<" "<< Faux + 0 <<" "<< Faux + 4 <<" "<< Faux + 7 <<" "<< Faux + 3 <<" "<<
                        v[i][j][k].r <<" "<< v[i][j][k].g <<" "<< v[i][j][k].b <<" "<< v[i][j][k].a << endl;
                        aux<< 4 <<" "<< Faux + 3 <<" "<< Faux + 7 <<" "<< Faux + 6 <<" "<< Faux + 2 <<" "<<
                        v[i][j][k].r <<" "<< v[i][j][k].g <<" "<< v[i][j][k].b <<" "<< v[i][j][k].a << endl;
                        aux<< 4 <<" "<< Faux + 1 <<" "<< Faux + 2 <<" "<< Faux + 6 <<" "<< Faux + 5 <<" "<<
                        v[i][j][k].r <<" "<< v[i][j][k].g <<" "<< v[i][j][k].b <<" "<< v[i][j][k].a << endl;
                        Faux = Faux + 8;
                } // if
            } // for k
        } // for j
     } // for i

    // Salvando arquivo
    if(aux.is_open()){
        cout << "Arquivo OFF salvo com sucesso" << endl;
    }

    // Fechando o arquivo
    aux.close();

}

