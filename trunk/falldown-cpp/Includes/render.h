#ifndef		__RENDER_H__
# define	__RENDER_H__

#include <utilitaires.h>

#define TAILLE_BALLE_W 20
#define TAILLE_BALLE_H 20

#define TAILLE_MUR_W 30
#define TAILLE_MUR_H 20

#define FSCREEN_W 260
#define FSCREEN_H 340

#define VIT_BALL 2
#define	VIT_MONTE 1

#define	MARGE_COLLISION TAILLE_MUR_W*2

#define NB_BLOC_H 4
#define ECART FSCREEN_H / NB_BLOC_H

#define NB_BLOC_W FSCREEN_W/TAILLE_MUR_W+1

//*************************AFFICHAGE***************************
void initRender();
void update_screen();
void affiche_balle(int x,int y);
void affiche_mur(int x,int y,int angle);
void draw_cube(cube c);
void scrolling();
void hard_wait();
void close_render();
void af_score(int score);
//*************************CLAVIER***************************
enum TOUCHE{TDROITE,TGAUCHE,TESCAP,TSPACE,TRIEN};
TOUCHE recup_touche();
void get_key(bool keyboard[]);

#endif
