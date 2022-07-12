#ifndef OBJET3DSTATIQUE_H_INCLUDED
#define OBJET3DSTATIQUE_H_INCLUDED

#include <string>
#include <set>
#include "types.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include "conteneurTextures.h"

class Objet3DStatique
{
    private:
        typedef std::set<std::string> Textures;

        Textures textures; // Les textures de l'objet
        ConteneurTextures conteneurTextures;
        GLuint listeAffichage;
        GLuint listeRST;

    protected:
        // Position de l'objet
        float16 positionX;
        float16 positionY;

        // Angle horizontal avec la verticale en z
        float16 angleHorizontal;

        std::string nom;

    public:
        Objet3DStatique(std::string nomFichier);
        ~Objet3DStatique();
        void dessiner();
        float16 positionZ;


};

#endif // OBJET3DSTATIQUE_H_INCLUDED
