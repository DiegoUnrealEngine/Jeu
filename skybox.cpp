#include "skybox.h"

void Skybox::dessiner(Personnage* personnage){

    glTranslated(personnage->positionX,personnage->positionY,personnage->positionZ);

    glDisable(GL_LIGHTING);
    glDepthMask(GL_FALSE);

    float L=100;

    glBindTexture(GL_TEXTURE_2D, this->conteneurTextures.texture("haut.bmp").texture);

    glBegin(GL_QUADS);
    glNormal3f(0.0,0.0,-1.0);
    glTexCoord2i(1, 1); glVertex3i(-L, -L, L);
    glTexCoord2i(1, 0); glVertex3i(-L, L, L);
    glTexCoord2i(0, 0); glVertex3i(L, L, L);
    glTexCoord2i(0, 1); glVertex3i(L, -L, L);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, this->conteneurTextures.texture("nord.bmp").texture);

    glBegin(GL_QUADS);
    glNormal3f(0.0,1.0,0.0);
    glTexCoord2i(1, 1); glVertex3i(L, L, -L);
    glTexCoord2i(1, 0); glVertex3i(L, L, L);
    glTexCoord2i(0, 0); glVertex3i(-L, L, L);
    glTexCoord2i(0, 1); glVertex3i(-L, L, -L);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, this->conteneurTextures.texture("est.bmp").texture);

    glBegin(GL_QUADS);
    glNormal3f(1.0,0.0,0.0);
    glTexCoord2i(0, 1); glVertex3i(L, L, -L);
    glTexCoord2i(1, 1); glVertex3i(L, -L, -L);
    glTexCoord2i(1, 0); glVertex3i(L, -L, L);
    glTexCoord2i(0, 0); glVertex3i(L, L, L);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, this->conteneurTextures.texture("sud.bmp").texture);

    glBegin(GL_QUADS);
    glNormal3f(0.0,-1.0,0.0);
    glTexCoord2i(0, 1); glVertex3i(L, -L, -L);
    glTexCoord2i(1, 1); glVertex3i(-L, -L, -L);
    glTexCoord2i(1, 0); glVertex3i(-L, -L, L);
    glTexCoord2i(0, 0); glVertex3i(L, -L, L);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, this->conteneurTextures.texture("ouest.bmp").texture);

    glBegin(GL_QUADS);
    glNormal3f(-1.0,0.0,0.0);
    glTexCoord2i(1, 1); glVertex3i(-L, L, -L);
    glTexCoord2i(1, 0); glVertex3i(-L, L, L);
    glTexCoord2i(0, 0); glVertex3i(-L, -L, L);
    glTexCoord2i(0, 1); glVertex3i(-L, -L, -L);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, this->conteneurTextures.texture("bas.bmp").texture);
    glBegin(GL_QUADS);
    glNormal3f(0.0,0.0,-1.0);
    glTexCoord2i(1, 1); glVertex3i(L, -L, -L);
    glTexCoord2i(0, 1); glVertex3i(L, L, -L);
    glTexCoord2i(0, 0); glVertex3i(-L, L, -L);
    glTexCoord2i(1, 0); glVertex3i(-L, -L, -L);
    glEnd();

    glDepthMask(GL_TRUE);
    glEnable(GL_LIGHTING);

    glTranslated(-personnage->positionX,-personnage->positionY,-personnage->positionZ);
}
