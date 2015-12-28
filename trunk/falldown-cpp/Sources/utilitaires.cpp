#include "utilitaires.h"

int aleatoire(int a,int b)
{
    if(a<b)
        return (rand()% (b-a+1)) + a;
    else
        return (rand()% (a-b+1)) + b;
}
/*
bool test_point(int x, int y , cube c2)
{
    if(x >= c2.x1 && x <= c2.x2 )
        if(y >= c2.y1 && y <= c2.y2 )
            return true;

    return false;
}
*/

char bounding_box_collision ( int b1_x, int b1_y, int b1_w, int b1_h, int b2_x, int b2_y, int b2_w, int b2_h )
{
        if ( ( b1_x > b2_x + b2_w - 1 )  ||  // is b1 on the right side of b2?
        ( b1_y > b2_y + b2_h - 1 )       ||  // is b1 under b2?
        ( b2_x > b1_x + b1_w - 1 )       ||  // is b2 on the right side of b1?
        ( b2_y > b1_y + b1_h - 1 ) )         // is b2 under b1?
        {
                // no collision
                return 0;
        }

        // collision
        return 1;
}

char collision_cube(cube c1, cube c2)
{
    return bounding_box_collision( c1.x, c1.y, c1.w, c1.h, c2.x, c2.y, c2.w, c2.h );
}
