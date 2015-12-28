#ifndef ETAGES_H
#define ETAGES_H

#include <vector>
#include <etage.h>

#define vector_etage std::vector<etage>

class etages
{
    public:

    etages(int nb_ligne);

    ~etages();
    void defilement();
    char collision(cube test,int *y);
    void affiche();

    private:

    vector_etage etage_v;

};
#endif
