
#include <etages.h>
#include <balle.h>
#include <utilitaires.h>

class collision
{
    public:

    collision();

    void init(etages *obj)
    {obj1=obj;
    }
    void init(balle *obj)
    {obj2=obj;
    }

    char collison_test()
    {
        return collision_cube(obj2->get_cube(),obj1->get_cube());
    }

    private:
    etages *obj1;
    balle *obj2;

};

