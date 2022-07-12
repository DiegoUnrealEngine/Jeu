#include "decor.h"

class Decor::Decor(){

}

void Decor::dessiner_maison(){
    this->conteneurTextures.ajouter("toit.bmp");

    glBindTexture(GL_TEXTURE_2D, this->conteneurTextures.texture("mur.bmp").texture);
    glBegin(GL_QUADS);
    glNormal3f(0.0,-1.0,0.0);
    glTexCoord2i(0, 1); glVertex3i(6, 5, 0);
    glTexCoord2i(1, 1); glVertex3i(7, 5, 0);
    glTexCoord2i(1, 0); glVertex3i(7, 5, 1);
    glTexCoord2i(0, 0); glVertex3i(6, 5, 1);
    glEnd();
    this->murs.push_back({6,5,7,5});
    glBegin(GL_QUADS);
    glNormal3f(1.0,0.0,0.0);
    glTexCoord2i(0, 1); glVertex3i(7, 5, 0);
    glTexCoord2i(1, 1); glVertex3i(7, 6, 0);
    glTexCoord2i(1, 0); glVertex3i(7, 6, 1);
    glTexCoord2i(0, 0); glVertex3i(7, 5, 1);
    glEnd();
    this->murs.push_back({7,5,7,6});
    glBegin(GL_QUADS);
    glNormal3f(0.0,1.0,0.0);
    glTexCoord2i(0, 1); glVertex3i(7, 6, 0);
    glTexCoord2i(1, 1); glVertex3i(6, 6, 0);
    glTexCoord2i(1, 0); glVertex3i(6, 6, 1);
    glTexCoord2i(0, 0); glVertex3i(7, 6, 1);
    glEnd();
    this->murs.push_back({7,6,6,6});
    glBegin(GL_QUADS);
    glNormal3f(-1.0,0.0,0.0);
    glTexCoord2i(0, 1); glVertex3i(6, 6, 0);
    glTexCoord2i(1, 1); glVertex3i(6, 5, 0);
    glTexCoord2i(1, 0); glVertex3i(6, 5, 1);
    glTexCoord2i(0, 0); glVertex3i(6, 6, 1);
    glEnd();
    this->murs.push_back({6,6,6,5});

    glBindTexture(GL_TEXTURE_2D, this->conteneurTextures.texture("toit.bmp").texture);
    glBegin(GL_QUADS);
    glNormal3f(-1.0,0.0,1.0);
    glTexCoord2i(0, 1);glVertex3f(6, 5, 1);
    glTexCoord2i(0, 0);glVertex3f(6.5f, 5, 1.5f);
    glTexCoord2i(1, 0);glVertex3f(6.5f, 6, 1.5f);
    glTexCoord2i(1, 1);glVertex3f(6, 6, 1);
    glEnd();

    glBegin(GL_QUADS);
    glNormal3f(1.0,0.0,1.0);
    glTexCoord2i(0, 1);glVertex3f(7, 5, 1);
    glTexCoord2i(1, 1);glVertex3f(7, 6, 1);
    glTexCoord2i(1, 0);glVertex3f(6.5f, 6, 1.5f);
    glTexCoord2i(0, 0);glVertex3f(6.5f, 5, 1.5f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glNormal3f(0.0,-1.0,0.0);
    glTexCoord2i(0, 1);glVertex3f(6, 5, 1);
    glTexCoord2i(1, 1);glVertex3f(7, 5, 1);
    glTexCoord2i(0, 0);glVertex3f(6.5f, 5, 1.5f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glNormal3f(0.0,1.0,0.0);
    glTexCoord2i(0, 1);glVertex3f(6, 6, 1);
    glTexCoord2i(0, 0);glVertex3f(6.5f, 6, 1.5f);
    glTexCoord2i(1,1);glVertex3f(7, 6, 1);
    glEnd();

}
