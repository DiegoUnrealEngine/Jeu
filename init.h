#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

#ifndef INIT_H_INCLUDED
#define INIT_H_INCLUDED


#define LARGEUR_FENETRE (320*2.5)
#define HAUTEUR_FENETRE (240*2.5)

#define TITRE_APPLICATION "JEU"

#define PRET 0.1
#define LOIN 1000.0
#define ANGLE_VISION 70.0

void initSDL(void);
void initOpenGL(void);

#endif // INIT_H_INCLUDED
