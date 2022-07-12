#ifndef CONTENEURTEXTURES_H_INCLUDED
#define CONTENEURTEXTURES_H_INCLUDED

#include "init.h"
#include <map>
#include <string>

class ConteneurTextures
{
    private:
        struct Texture
        {
            GLuint texture;
            unsigned long compteur;
            signed long largeur;
            signed long hauteur;
        };

        typedef std::map<std::string, Texture> Textures;

        static Textures textures;
        void chargerTexture(const char* nomFichier, GLuint* texture, signed long* largeur, signed long* hauteur);

    public:
        Texture ajouter(std::string nomFichier);
        void supprimer(std::string nomFichier);
        Texture texture(std::string nomFichier);
};

#endif // CONTENEURTEXTURES_H_INCLUDED
