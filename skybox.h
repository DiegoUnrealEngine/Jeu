#ifndef SKYBOX_H_INCLUDED
#define SKYBOX_H_INCLUDED

#include "personnage.h"


class Skybox {
    private:
        ConteneurTextures conteneurTextures;
    public :
        void dessiner(Personnage* personnage);
};

#endif // SKYBOX_H_INCLUDED
