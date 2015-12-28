#ifndef		__BALLE_H__
#define	__BALLE_H__

#include <etages.h>
#include <render.h>


class balle
{
    public:

    balle(int init_x,int init_y);
    ~balle();
    void droite();
    void gauche();
    char graviter();
    void init_collision(etages *iobjet);
    void affiche();

    void AutoDir();

    private:

    int collision(int xd,int yd);
    char inertie_balle(DIR sens);

    int x,y;
    int inertie;
    etages *objet;

};
#endif
