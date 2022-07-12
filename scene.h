#ifndef SCENE_H_INCLUDED
#define SCENE_H_INCLUDED

#include "skybox.h"

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>


class Scene
{

    private:

        bool continuer;
        unsigned long dt;
        Carte* carte;
        Personnage* personnage;
        Skybox* skybox;

        void gererEvenements(void);
        void animer(void);
        void dessiner(void);
        void afficher(void);

    public:
        float direction;
        Scene();
        void executer();
};

#endif // SCENE_H_INCLUDED

