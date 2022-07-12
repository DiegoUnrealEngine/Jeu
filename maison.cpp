#include "maison.h"

void Maison::dessiner(){

    this->conteneurTextures.ajouter("toit.bmp");
    this->conteneurTextures.ajouter("mur.bmp");

    // sélection de la texture
    glBindTexture(GL_TEXTURE_2D, this->conteneurTextures.texture("mur.bmp").texture);

    #ifndef GL_REPEAT
        #define GL_REPEAT (0x812F)
    #endif
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glNormal3f(0.0,-1.0,0.0);
    float di=0.1f;
    float i=6;
    float j=0;
    float dj = 0.15f;
    float x=0;
    float dy=2*1.f/10.f;
    float y=1-dy;
    float dx=2*1.f/10.f;
    while (i<7-di){
        while (j<1.5f-dj){
            glBegin(GL_QUADS);
            glTexCoord2f(x, y+dy);glVertex3f(i, 5, j);
            glTexCoord2f(x+dx,y+dy);glVertex3f(i+di, 5, j);
            glTexCoord2f(x+dx, y);glVertex3f(i+di, 5, j+dj);
            glTexCoord2f(x, y);glVertex3f(i, 5, j+dj);
            glEnd();
            y-=dy;
            j+=dj;
        }
        i+=di;
        j=0;
        y=1-dy;
        x+=dx;
    }


    glNormal3f(1.0,0.0,0.0);
    di=0.1f;
    i=5;
    j=0;
    dj = 0.15f;
    x=0;
    dy=2*1.f/10.f;
    y=1-dy;
    dx=2*1.f/10.f;
    while (i<6-di){
        while (j<1.5f-dj){
            glBegin(GL_QUADS);
            glTexCoord2f(x, y+dy);glVertex3f(7, i, j);
            glTexCoord2f(x+dx,y+dy);glVertex3f(7, i+di, j);
            glTexCoord2f(x+dx, y);glVertex3f(7, i+di, j+dj);
            glTexCoord2f(x, y);glVertex3f(7, i, j+dj);
            glEnd();
            y-=dy;
            j+=dj;
        }
        i+=di;
        j=0;
        y=1-dy;
        x+=dx;
    }

    glNormal3f(0.0,1.0,0.0);
    di=0.1f;
    i=6;
    j=0;
    dj = 0.15f;
    x=1-dx;
    dy=2*1.f/10.f;
    y=1-dy;
    dx=2*1.f/10.f;
    while (i<7-di){
        while (j<1.5f-dj){
            glBegin(GL_QUADS);
            glTexCoord2f(x+dx, y+dy);glVertex3f(i, 6, j);
            glTexCoord2f(x+dx,y);glVertex3f(i, 6, j+dj);
            glTexCoord2f(x, y);glVertex3f(i+di, 6, j+dj);
            glTexCoord2f(x, y+dy);glVertex3f(i+di, 6, j);
            glEnd();
            y-=dy;
            j+=dj;
        }
        i+=di;
        j=0;
        y=1-dy;
        x-=dx;
    }

    glNormal3f(-1.0,0.0,0.0);
    di=0.1f;
    i=5;
    j=0;
    dj = 0.15f;
    x=1-dx;
    dy=2*1.f/10.f;
    y=1-dy;
    dx=2*1.f/10.f;
    while (i<6-di){
        while (j<1.5f-dj){
            glBegin(GL_QUADS);
            glTexCoord2f(x+dx, y+dy);glVertex3f(6, i, j);
            glTexCoord2f(x+dx,y);glVertex3f(6, i, j+dj);
            glTexCoord2f(x, y);glVertex3f(6, i+di, j+dj);
            glTexCoord2f(x, y+dy);glVertex3f(6, i+di, j);
            glEnd();
            y-=dy;
            j+=dj;
        }
        i+=di;
        j=0;
        y=1-dy;
        x-=dx;
    }


    glBindTexture(GL_TEXTURE_2D, this->conteneurTextures.texture("toit.bmp").texture);

    #ifndef GL_REPEAT
        #define GL_REPEAT (0x812F)
    #endif
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glNormal3f(-1.0,0.0,1.0);
    di=0.05f;
    i=6;
    j=5;
    dj = 0.1f;
    x=0;
    dy=2*1.f/10.f;
    y=1-dy;
    dx=2*1.f/10.f;
    while (i<6.5f){
        while (j<6.f-dj){
            glBegin(GL_QUADS);
            glTexCoord2f(x, y+dy);glVertex3f(i, j, i-4.5f);
            glTexCoord2f(x, y);glVertex3f(i+di, j, i-4.5f+di);
            glTexCoord2f(x+dx, y);glVertex3f(i+di, j+dj, i-4.5f+di);
            glTexCoord2f(x+dx, y+dy);glVertex3f(i, j+dj, i-4.5f);
            glEnd();
            x+=dx;
            j+=dj;
        }
        i+=di;
        j=5;
        x=0;
        y-=dy;
    }

    glNormal3f(1.0,0.0,1.0);
    di=0.05f;
    i=6.5f;
    j=5;
    dj = 0.1f;
    dx=2*1.f/10.f;
    x=1-dx;
    dy=2*1.f/10.f;
    y=0;
    while (i<7.f){
        while (j<6.f-dj){
            glBegin(GL_QUADS);
            glTexCoord2f(x+dx, y);glVertex3f(i, j, -i+8.5f);
            glTexCoord2f(x+dx, y+dy);glVertex3f(i+di, j, -i+8.5f-di);
            glTexCoord2f(x, y+dy);glVertex3f(i+di, j+dj, -i+8.5f-di);
            glTexCoord2f(x, y);glVertex3f(i, j+dj, -i+8.5f);
            glEnd();
            x-=dx;
            j+=dj;
        }
        i+=di;
        j=5;
        x=-dx;
        y+=dy;
    }

    glBegin(GL_TRIANGLES);
    glNormal3f(0.0,-1.0,0.0);
    glTexCoord2i(0, 1);glVertex3f(6, 5, 1.5f);
    glTexCoord2i(1, 1);glVertex3f(7, 5, 1.5f);
    glTexCoord2i(0, 0);glVertex3f(6.5f, 5, 2);
    glEnd();

    glBegin(GL_TRIANGLES);
    glNormal3f(0.0,1.0,0.0);
    glTexCoord2i(0, 1);glVertex3f(6, 6, 1.5f);
    glTexCoord2i(0, 0);glVertex3f(6.5f, 6, 2);
    glTexCoord2i(1,1);glVertex3f(7, 6, 1.5f);
    glEnd();
}
