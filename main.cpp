#include <iostream>
#include "Sculptor.h"

using namespace std;

// Exemplo para teste com as funções declaradas
// Aguardar o programa informar a mensagem que o arquivo foi salvo



int main(){
  Sculptor ex(60,60,60);
    // cor areia (chao)
    ex.setColor(0.976,0.819,0.6,1.0);
    ex.putBox(0,0,0,59,59,59);
    ex.cutBox(0,0,1,58,58,58);
    ex.putVoxel(40,41,2);
    ex.putBox(41,40,1,45,41,2);
    ex.putBox(41,42,1,45,43,2);
    ex.putVoxel(45,41,2);
    // cor sol
    ex.setColor(1.0,0.894,0.215,1.0);
    ex.putSphere(4,44,55,5);
    // cor mar
    ex.setColor(0.023,0.258,0.658,1.0);
    ex.putBox(0,0,0,26,44,1);
    ex.putEllipsoid(13,22,2,1,15,2);
    ex.cutVoxel(12,22,2);
    // cor branca
    ex.setColor(1.0,1.0,1.0,0);
    ex.putBox(14,12,3,15,30,4);
    // cor areia (morro)
    ex.setColor(0.976,0.819,0.6,1.0);
    ex.putBox(0,45,1,59,59,20);
    ex.cutBox(0,45,2,58,46,19);
    ex.cutBox(0,46,6,58,47,19);
    ex.cutBox(0,47,7,58,48,19);
    ex.cutBox(0,48,10,58,49,19);
    ex.cutBox(0,49,12,58,50,19);
    ex.cutBox(0,50,15,58,51,19);
    ex.cutBox(0,51,16,58,52,19);
    ex.cutBox(0,52,17,58,53,19);
    ex.cutBox(0,53,18,58,54,19);
    ex.cutBox(0,54,19,58,55,19);
    // cor verde (morro)
    ex.setColor(0.243,0.356,0.250,1.0);
    ex.putBox(0,45,2,50,46,3);
    ex.putBox(0,46,3,50,47,6);
    ex.putBox(0,47,6,51,48,7);
    ex.putBox(0,48,7,52,49,10);
    ex.putBox(0,49,10,53,50,12);
    ex.putBox(0,50,12,54,51,15);
    ex.putBox(0,51,15,55,52,16);
    ex.putBox(0,52,16,56,53,17);
    ex.putBox(0,53,17,57,54,18);
    ex.putBox(0,54,18,58,55,19);
    ex.putBox(0,55,19,59,56,20);
    ex.cutBox(23,45,2,35,46,3);
    ex.cutBox(23,46,3,35,47,6);
    ex.cutBox(22,47,6,36,48,7);
    ex.cutBox(22,48,7,35,49,10);
    ex.cutBox(23,49,10,36,50,12);
    ex.cutBox(22,50,12,36,51,15);
    ex.cutBox(21,51,15,37,52,16);
    ex.cutBox(20,52,16,38,53,17);
    ex.cutBox(20,53,17,39,54,18);
    ex.cutBox(21,54,18,38,55,19);
    ex.cutBox(21,55,19,39,56,20);
    ex.cutBox(5,55,19,10,56,20);
    ex.putBox(0,56,20,10,57,21);
    ex.putBox(48,56,20,57,57,21);
    // cor cinza (passarela)
    ex.setColor(0.862,0.862,0.862,1.0);
    ex.putBox(55,0,5,59,45,6);
    // cor tijolo (passarela)
    ex.setColor(0.862,0.333,0.223,1.0);
    ex.putEllipsoid(57,2,4,1,1,1);
    ex.putBox(57,2,1,58,3,3);
    ex.putEllipsoid(57,12,4,1,1,1);
    ex.putBox(57,12,1,58,13,3);
    ex.putEllipsoid(57,22,4,1,1,1);
    ex.putBox(57,22,1,58,23,3);
    ex.putEllipsoid(57,32,4,1,1,1);
    ex.putBox(57,32,1,58,33,3);
    ex.putEllipsoid(57,42,4,1,1,1);
    ex.putBox(57,42,1,58,43,3);
    // cor marrom (escada)
    ex.setColor(0.792,0.643,0.447,1.0);
    ex.putBox(54,15,4,56,18,5);
    ex.putBox(53,15,3,55,18,4);
    ex.putBox(52,15,2,54,18,3);
    ex.putBox(51,15,1,53,18,2);
    // cor branca (barracas)
    ex.setColor(1.0,1.0,1.0,1.0);
    ex.putBox(47,4,1,48,5,7);
    ex.putBox(45,3,3,50,7,4);
    ex.putBox(47,25,1,48,26,7);
    ex.putBox(45,24,3,50,28,4);
    // cor verde (barracas)
    ex.setColor(0.435,0.6,0.250,1.0);
    ex.putBox(44,3,7,51,7,8);
    ex.putBox(44,24,7,51,28,8);
    // cor branca (nuvens)
    ex.setColor(1.0,1.0,1.0,1.0);
    ex.putEllipsoid(4,40,42,2,5,2);
    ex.putEllipsoid(25,30,42,2,5,2);
    ex.putEllipsoid(35,21,42,3,5,3);
    // cor bege (pessoa sentada)
    ex.setColor(0.890,0.760,0.596,1.0);
    ex.putBox(54,43,4,55,44,6);
    ex.putBox(54,41,4,55,42,6);
    ex.putBox(54,43,6,56,44,7);
    ex.putBox(54,41,6,56,42,7);
    ex.putVoxel(55,42,10);
    ex.putBox(55,39,9,56,41,10);
    ex.putBox(55,44,9,56,46,10);
    // cor verde (pessoa sentada)
    ex.setColor(0.0,0.768,0.0,1.0);
    ex.putBox(55,41,7,56,44,10);
    // cor laranja (prancha)
    ex.setColor(1.0,0.647,0.0,1.0);
    ex.putBox(14,22,4,17,23,5);
    // cor bege (pessoa surfando)
    ex.setColor(0.780,0.478,0.345,1.0);
    ex.putBox(14,22,5,15,23,7);
    ex.putBox(16,22,5,17,23,7);
    ex.putVoxel(15,22,10);
    ex.putBox(12,22,9,14,23,10);
    ex.putBox(17,22,9,19,23,10);
    // cor ciano (roupa pessoa surfando)
    ex.setColor(0.878,1.0,1.0,1.0);
    ex.putBox(14,22,7,17,23,10);
    // cor marrom (pessoa correndo)
    ex.setColor(0.396,0.262,0.129,1.0);
    ex.putBox(30,4,1,31,5,4);
    ex.putBox(32,1,3,33,5,4);
    ex.putVoxel(31,4,7);
    ex.putBox(29,4,5,30,5,7);
    ex.putBox(33,4,5,34,5,7);
    // cor rosa (pessoa correndo)
    ex.setColor(1.0,0.752,0.796,1.0);
    ex.putBox(30,4,4,33,5,7);
    // cor branca (passaro)
    ex.setColor(1.0,1.0,1.0,1.0);
    ex.putEllipsoid(50,5,40,1,2,1);
    ex.cutVoxel(50,5,39);
    ex.putVoxel(51,5,40);




ex.writeOFF("/home/dimitri/OFF/ex.off");
    return 0;
}

