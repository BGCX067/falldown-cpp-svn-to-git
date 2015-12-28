#include<balle.h>

#define MAX_INERTIE 15
balle::balle(int init_x,int init_y)
{
    x=init_x;
    y=init_y;
    objet=NULL;
    inertie=0;
}

balle::~balle()
{   objet=NULL;
}

void balle::droite()
{   if(!collision( x + VIT_BALL, y))
        if(x < (FSCREEN_W-TAILLE_BALLE_W))
            if(inertie_balle(DROITE))
                x+=VIT_BALL;
            else
                x+=VIT_BALL/2;


}

void balle::gauche()
{
    if(!collision( x - VIT_BALL, y))
        if( x > 0 )
            if(inertie_balle(GAUCHE))
                x-=VIT_BALL;
            else
                x-=VIT_BALL/2;

}

char balle::inertie_balle(DIR sens)
{
    return 1;

    if(sens == DROITE)
    {
        if(inertie < MAX_INERTIE)
            inertie++;

        if(inertie>=0)
            return 1;
        else
            return 0;
    }

     if(sens == GAUCHE)
    {
        if(inertie > -MAX_INERTIE)
            inertie--;

        if(inertie<=0)
            return 1;
        else
            return 0;
    }


    return 0;
}

char balle::graviter()
{
    int yy;
    char test=0;
    if(yy = collision( x, y + VIT_BALL))
    {
        if(yy > 20)
            y=yy - TAILLE_BALLE_H;
            //y-=VIT_MONTE;
        else
            test=1;
    }
    else
    {
        if(y < (FSCREEN_H - TAILLE_BALLE_H))
            y+=VIT_BALL;
    }

    return test;
}

void balle::init_collision(etages *iobjet)
{objet = iobjet;
}

void balle::affiche()
{affiche_balle(x,y);
}


int balle::collision(int xd,int yd)
{
    int ty;
    cube tballe;
    tballe.x = xd;
    tballe.y = yd;
    tballe.w = TAILLE_BALLE_W ;
    tballe.h = TAILLE_BALLE_H ;

   //draw_cube(tballe);

   objet->collision(tballe,&ty);

   return ty;
}

void balle::AutoDir()
{
    //Auto dirige la balle !
    int position = FSCREEN_W/2;

    //Cherche un "trou" si balle en contact avec un mur
    if(collision( x, y + VIT_BALL))
        for (int i=0; i<FSCREEN_W; i+=TAILLE_BALLE_W)
        {
            if(!collision( i, y + 5))
            {
                position = i;
                break;
            }
        }

    if(position < x)
        gauche();
    else
        droite();
}
