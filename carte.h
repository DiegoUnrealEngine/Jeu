#ifndef CARTE_H_INCLUDED
#define CARTE_H_INCLUDED

#include <vector>
#include <random>


#include "light.h"
#include "perlin.h"
#include "maison.h"

#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL/SDL.h>


class Carte
{
    private:
        ConteneurTextures conteneurTextures;
        Light light;
        GLuint listeAffichage;
        void creerListeAffichage();
        void dessiner_herbe();
        Maison maison;

    public:
        Carte();
        ~Carte();
        std::vector<std::vector<float>> murs;
        void dessiner();
        static const int nbmaille=100;
        float size_map=50.f;
        float terrain[nbmaille][nbmaille];

};

#endif // CARTE_H_INCLUDED
