#include<mur.h>

 mur::mur(int xi, int yi)
{
    x=xi;
    y=yi;
}

char  mur::collision(cube test)
{
    cube tmur;
    tmur.x = x;
    tmur.y = y;
    tmur.w = TAILLE_MUR_W;
    tmur.h = TAILLE_MUR_H;

    //draw_cube(tmur);
    return collision_cube(test,tmur);
}

void  mur::affiche()
{
    affiche_mur(x,y,angle);
}

void  mur::move_up()
{y-=VIT_MONTE;}

int  mur::getx()
{return x;}

