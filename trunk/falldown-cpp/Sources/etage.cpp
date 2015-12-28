#include<etage.h>
#include<math.h>

etage::etage(unsigned int init_y, char taille_ligne)
{
    pos_y = init_y;
    taille = taille_ligne;
    genere_ligne();
}

etage::~etage()
{
    mur_v.clear();
}

bool etage::monte()
{
    if(pos_y>-TAILLE_MUR_H)
    {
        pos_y-=VIT_MONTE;
        for(vector_mur::iterator it=mur_v.begin(); it != mur_v.end(); ++it)
            it->move_up();
    }
    else
    {   //Reset ligne
        pos_y = FSCREEN_H;
        genere_ligne();
    }
    return true;
}

void etage::affiche_ligne()
{
    for(vector_mur::iterator it=mur_v.begin(); it != mur_v.end(); ++it)
        it->affiche();
}

char etage::collision(cube test)
{
    for(vector_mur::iterator it=mur_v.begin(); it != mur_v.end(); ++it)
      if(it->getx() > (test.x - MARGE_COLLISION) && it->getx() < (test.x + MARGE_COLLISION))
      {
        char t = it->collision(test);
        if(t != 0)
            return t;
      }
    return 0;
}

int etage::gety()
{return pos_y;}

void etage::genere_ligne()
{
    char ligne[taille];
    mur_v.clear();

    int test=0;
    /*
    for(int i=0;i<taille;i+=2)
    {
        if(aleatoire(0,3))
        {
            ligne[i] = 1;
            ligne[i+1] = 1;
            test+=2;
        }
        else
        {
            ligne[i] = 0;
            ligne[i+1] = 0;
        }
    }
    */

     for(int i=0;i<taille;i++)
    {
        if(aleatoire(0,3))
        {
            ligne[i] = 1; test++;
            if(aleatoire(0,1))
                {ligne[++i] = 1; test++;}
        }
        else
        {
            ligne[i] = 0;
        }
    }

    if(test >= taille)
        ligne[aleatoire(0,taille-1)] = 0;

    for(int i=0;i<taille;i++)
        if(ligne[i] == 1)
            mur_v.push_back(mur(i*TAILLE_MUR_W,pos_y));
}
