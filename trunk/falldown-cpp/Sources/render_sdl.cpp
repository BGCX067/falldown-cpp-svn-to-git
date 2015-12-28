#include <render.h>
#include <SDL.h>
#include <math.h>

SDL_Surface *mur;
SDL_Surface *balle;
SDL_Surface *buffer;

//*****************************************************************************
void update_screen()
{
      SDL_Flip(buffer);
      SDL_FillRect(buffer, 0, SDL_MapRGB(buffer->format, 0, 0, 0));
}

void initRender()
{
    // initialize SDL video
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "Unable to init SDL: %s\n", SDL_GetError() );
    }

    // make sure SDL cleans up before exit
    atexit(SDL_Quit);

    // create a new window
    buffer = SDL_SetVideoMode(FSCREEN_W, FSCREEN_H, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
    if ( !buffer )
    {
        printf("Unable to set video: %s\n", SDL_GetError());
    }

    SDL_WM_SetCaption("Falldown", NULL);

    //init objet
    mur = SDL_LoadBMP("wall.bmp");
    balle = SDL_LoadBMP("ball.bmp");
    if(mur == NULL || balle == NULL)
    {
        printf("Unable to get images: %s\n", SDL_GetError());
        exit(-1);
    }

/*
    mur = SDL_CreateRGBSurface(SDL_HWSURFACE, TAILLE_MUR_W, TAILLE_MUR_H, 30, 0, 0, 0, 0);
    SDL_FillRect(mur, NULL, SDL_MapRGB(buffer->format, 230, 200, 30));


    balle = SDL_CreateRGBSurface(SDL_HWSURFACE, TAILLE_BALLE_W, TAILLE_BALLE_H, 32, 0, 0, 0, 0);
    SDL_FillRect(balle, NULL, SDL_MapRGB(buffer->format, 230, 100, 30));
*/
}

void affiche_balle(int x,int y)
{
    SDL_Rect position;
    position.x=x;
    position.y=y;
    SDL_BlitSurface(balle, NULL, buffer, &position);
}

void affiche_mur(int x,int y, int angle)
{

    SDL_Rect position;
    position.x=x;
    position.y=y;
    SDL_BlitSurface(mur, NULL, buffer, &position);

}

void draw_cube(cube c)
{
    SDL_Surface *cc = SDL_CreateRGBSurface(SDL_HWSURFACE, c.w, c.w, 30, 0, 0, 0, 0);
    SDL_FillRect(cc, NULL, SDL_MapRGB(buffer->format, 230, 200, 30));
    SDL_Rect position;
    position.x=c.x;
    position.y=c.y;
    SDL_BlitSurface(cc, NULL, buffer, &position);
    SDL_FreeSurface(cc);

}

void af_score(int score)
{

}

TOUCHE recup_touche()
{
    Uint8 *keystate = SDL_GetKeyState(NULL);
    SDL_PumpEvents();
    {
        if (keystate[SDLK_ESCAPE])
            return TESCAP;
        else if (keystate[SDLK_RIGHT])
            return TDROITE;
        else if (keystate[SDLK_LEFT])
            return TGAUCHE;
    }

    return TRIEN;
}

void get_key(bool keyboard[])
{
    Uint8 *keystate = SDL_GetKeyState(NULL);
    SDL_PumpEvents();

    if(keystate[SDLK_LEFT])
      keyboard[TDROITE] = true;
    else
      keyboard[TDROITE] = false;

    if(keystate[SDLK_RIGHT])
      keyboard[TGAUCHE] = true;
    else
      keyboard[TGAUCHE] = false;

    if(keystate[SDLK_ESCAPE])
      keyboard[TESCAP] = true;
    else
      keyboard[TESCAP] = false;

    if(keystate[SDLK_SPACE])
      keyboard[TSPACE] = true;
    else
      keyboard[TSPACE] = false;
}

void hard_wait()
{
    SDL_Delay(8);
}

void close_render()
{
    SDL_Quit();
    SDL_FreeSurface(mur);
    SDL_FreeSurface(balle);
}
