#include <cstdio>
#include <render.h>
#include <etages.h>
#include <balle.h>

etages *mur0;
balle  *ball0;

bool keyb[sizeof(TOUCHE)];
int score;


void affichage()
{
        ball0->affiche();
        mur0->affiche();
        af_score(score);
        update_screen();
}

char logique()
{
    int test;

    mur0->defilement();
    test = ball0->graviter();

    score++;

    get_key(keyb);

     if(keyb[TDROITE])
        ball0->gauche();
     if(keyb[TGAUCHE])
        ball0->droite();
     if(keyb[TSPACE])
        ball0->AutoDir();

    return 0;

}

void jeu()
{

   int i=0;
   while(!keyb[TESCAP])
    {
        logique();
        if(++i > 2)
        {
            affichage();
            hard_wait();
            i=0;
        }
    }

}

/*
void jeu2()
{
    int temps_de_jeu=0, dessiner=1;
    char game_over=0;
    float vitesse=10;

    while(!keyb[TESCAP] && game_over==0)
        {
            //if((7 - score/2000.0f) > 4)
            //    vitesse= 7 - score/2000.0f;

            while(temps_de_jeu < (clock ()/vitesse))
            {
                game_over = logique();
                temps_de_jeu++;
                dessiner=1;
            }
            //Ensuite nous pouvons afficher
            if(dessiner)
            {
                affichage();
                dessiner=0;
            }
            else
                hard_wait();
        }

    //Game over ...
    if(game_over==1)
    {
        while(!keyb[TESCAP])
        {
            get_key(keyb);
            hard_wait();
        }
    }


}
*/

int main(int argc, char** argv)
{
    initRender();
    srand(time(NULL));

    mur0 = new etages(NB_BLOC_H);
    ball0 = new  balle(FSCREEN_W/2,FSCREEN_H/2);
    score=0;

    ball0->init_collision(mur0);

    jeu();

    //clean
    close_render();
    delete mur0;
    delete ball0;

	return 0;
}
//END_OF_MAIN()

