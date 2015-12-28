#ifndef UTILITAIRES_H
#define UTILITAIRES_H

#include <cstdio>
#include <stdlib.h>

typedef struct cube {
    int x,y;
    int w,h;
    int angle;
}cube;

enum DIR{DROITE,GAUCHE};

int aleatoire(int a,int b);
char collision_cube(cube c1, cube c2);


#endif
