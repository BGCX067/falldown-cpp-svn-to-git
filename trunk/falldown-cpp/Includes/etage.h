#ifndef		__ETAGE_H__
# define	__ETAGE_H__

#include <vector>
#include <utilitaires.h>
#include <render.h>
#include <mur.h>

#define vector_mur std::vector<mur>

class etage
{
    public:

    explicit etage(unsigned int init_y, char taille_ligne);
    ~etage();

    bool monte();
    void affiche_ligne();
    char collision(cube test);
    int gety();

    private:
    void genere_ligne();

    int pos_y;
    int angle;
    char taille;
    vector_mur mur_v;
};
#endif
