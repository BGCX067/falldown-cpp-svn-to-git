
#include <render.h>
#include <utilitaires.h>

class mur
{
    public:

    mur(int xi, int yi);
    char collision(cube test);
    void affiche();
    void move_up();
    int getx();

    int angle;
    int x,y;

    private:



};
