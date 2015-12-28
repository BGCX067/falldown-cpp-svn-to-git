#include<etages.h>

etages::etages(int nb_ligne)
{
    for(int i=0; i<nb_ligne ;i++)
        etage_v.push_back(etage(FSCREEN_H + ECART*i, NB_BLOC_W));
}

etages::~etages(){etage_v.clear();}

void etages::defilement()
{
    for(vector_etage::iterator it=etage_v.begin(); it != etage_v.end(); ++it)
        it->monte();
}

char etages::collision(cube test,int *y)
{
     for(vector_etage::iterator it=etage_v.begin(); it != etage_v.end(); ++it)
        if(it->gety() > (test.y - MARGE_COLLISION) && it->gety() < (test.y + MARGE_COLLISION) )
        {   char t = it->collision(test);
            if(t != 0)
            {
                *y = it->gety();
                return t;
            }
        }
    *y = 0;
    return 0;
}

void etages::affiche()
{
    for(vector_etage::iterator it=etage_v.begin(); it != etage_v.end(); ++it)
        it->affiche_ligne();
}
