#include "carte.h"

Carte::Carte(){
    this->creerListeAffichage();
}

Carte::~Carte()
{
    this->conteneurTextures.supprimer("mur.bmp");
    this->conteneurTextures.supprimer("herbe.bmp");
    this->conteneurTextures.supprimer("toit.bmp");
    this->conteneurTextures.supprimer("haut.bmp");
    this->conteneurTextures.supprimer("bas.bmp");
    this->conteneurTextures.supprimer("nord.bmp");
    this->conteneurTextures.supprimer("est.bmp");
    this->conteneurTextures.supprimer("ouest.bmp");
    this->conteneurTextures.supprimer("sud.bmp");
}

void Carte::dessiner()
{
    glCallList(this->listeAffichage);
}

void Carte::creerListeAffichage()
{
    // Chargement de la texture du mur
    this->conteneurTextures.ajouter("herbe.bmp");
    this->conteneurTextures.ajouter("haut.bmp");
    this->conteneurTextures.ajouter("bas.bmp");
    this->conteneurTextures.ajouter("nord.bmp");
    this->conteneurTextures.ajouter("est.bmp");
    this->conteneurTextures.ajouter("ouest.bmp");
    this->conteneurTextures.ajouter("sud.bmp");

    // Creation de la liste d'affichage
    this->listeAffichage = glGenLists(1);
    glNewList(this->listeAffichage, GL_COMPILE);

    // Activation des textures
    glEnable(GL_TEXTURE_2D);

    //allume la lumière
    Light* light = new Light();
    light->allumer();

    //dessiner la maison
    maison.dessiner();
    //hitbox maison
    this->murs.push_back({6,5,7,5});
    this->murs.push_back({7,5,7,6});
    this->murs.push_back({7,6,6,6});
    this->murs.push_back({6,6,6,5});

    //dessiner l'herbe
    dessiner_herbe();

    // Fin de la liste d'affichage
    glEndList();
}

void Carte::dessiner_herbe(){

    float dx=this->size_map/((float)nbmaille);
    for (int k=0;k<nbmaille;k++){
        for (int n=0;n<nbmaille;n++){
            this->terrain[k][n]=10*Get2DPerlinNoiseValue((float)k, (float)n, 30.f)+Get2DPerlinNoiseValue((float)k, (float)n, 7.f)
            +0.1*Get2DPerlinNoiseValue((float)k, (float)n, 2.f);
        }
    }

    float normale[nbmaille][nbmaille][2];//normales des points
    for (int k=0;k<nbmaille;k++){
        for (int n=0;n<nbmaille;n++){
            normale[k][n][0]=-dx*(this->terrain[k+1][n]-this->terrain[k][n]);
            normale[k][n][1]=-dx*(this->terrain[k+1][n+1]-this->terrain[k+1][n]);
        }
    }

    //chargement de la texture
    glBindTexture(GL_TEXTURE_2D, this->conteneurTextures.texture("herbe.bmp").texture);

    //enlève le spéculaire
    GLfloat qaDark[] = {0,0,0,0};
    glMaterialfv(GL_FRONT,GL_SPECULAR,qaDark);

    float j=0.f;
    float k=0.f;
    for (int J=0;J<nbmaille-1;J++){
        for (int K=0;K<nbmaille-1;K++){
            int n = rand()%2;
            int m = rand()%2;
            glBegin(GL_TRIANGLES);
            //couleur//
            GLfloat delta = 0.5*Get2DPerlinNoiseValue(j,k, 1.0000005f);
            if (delta<0) delta = - delta;
            GLfloat qacolor[] = {1.0-delta/2,1.0-delta,1.0-delta,0};
            glMaterialfv(GL_FRONT,GL_AMBIENT,qacolor);
            //*******//
            glNormal3f(normale[J][K][0],normale[J][K][1],pow(dx,2));
            glTexCoord2i(n, m); glVertex3f(j, k, this->terrain[J][K]);
            //couleur//
            delta = 0.5*Get2DPerlinNoiseValue(j+dx,k, 1.0000005f);
            if (delta<0) delta = - delta;
            qacolor[0] = 1.0-delta/2;qacolor[1] = 1.0-delta;qacolor[2] = 1.0-delta;
            glMaterialfv(GL_FRONT,GL_AMBIENT,qacolor);
            //*******//
            glNormal3f(normale[J+1][K][0],normale[J+1][K][1],pow(dx,2));
            glTexCoord2i((n+1)%2, m); glVertex3f(j+dx, k, this->terrain[J+1][K]);
            //couleur//
            delta = 0.5*Get2DPerlinNoiseValue(j,k+dx, 1.0000005f);
            if (delta<0) delta = - delta;
            qacolor[0] = 1.0-delta/2;qacolor[1] = 1.0-delta;qacolor[2] = 1.0-delta;
            glMaterialfv(GL_FRONT,GL_AMBIENT,qacolor);
            //*******//
            glNormal3f(normale[J][K+1][0],normale[J][K+1][1],pow(dx,2));
            glTexCoord2i(n, (m+1)%2); glVertex3f(j,k+dx ,this->terrain[J][K+1]);
            glEnd();
            glBegin(GL_TRIANGLES);
            //couleur//
            delta = 0.5*Get2DPerlinNoiseValue(j+dx,k, 1.0000005f);
            if (delta<0) delta = - delta;
            qacolor[0] = 1.0-delta/2;qacolor[1] = 1.0-delta;qacolor[2] = 1.0-delta;
            glMaterialfv(GL_FRONT,GL_AMBIENT,qacolor);
            //*******//
            glNormal3f(normale[J+1][K][0],normale[J+1][K][1],pow(dx,2));
            glTexCoord2i((n+1)%2, m); glVertex3f(j+dx, k, this->terrain[J+1][K]);
            //couleur//
            delta = 0.5*Get2DPerlinNoiseValue(j+dx,k+dx, 1.0000005f);
            if (delta<0) delta = - delta;
            qacolor[0] = 1.0-delta/2;qacolor[1] = 1.0-delta;qacolor[2] = 1.0-delta;
            glMaterialfv(GL_FRONT,GL_AMBIENT,qacolor);
            //*******//
            glNormal3f(normale[J+1][K+1][0],normale[J+1][K+1][1],pow(dx,2));
            glTexCoord2i((n+1)%2,(m+1)%2); glVertex3f(j+dx, k+dx, this->terrain[J+1][K+1]);
            //couleur//
            delta = 0.5*Get2DPerlinNoiseValue(j,k+dx, 1.0000005f);
            if (delta<0) delta = - delta;
            qacolor[0] = 1.0-delta/2;qacolor[1] = 1.0-delta;qacolor[2] = 1.0-delta;
            glMaterialfv(GL_FRONT,GL_AMBIENT,qacolor);
            //*******//
            glNormal3f(normale[J][K+1][0],normale[J][K+1][1],pow(dx,2));
            glTexCoord2i(n,(m+1)%2); glVertex3f(j,k+dx ,this->terrain[J][K+1]);
            glEnd();
            k+=dx;
        }
        k=0;
        j+=dx;
    }

    //remet le spéculaire
    GLfloat qaWhite[] = {1.0,1.0,1.0,0};
    glMaterialfv(GL_FRONT,GL_SPECULAR,qaWhite);


}



