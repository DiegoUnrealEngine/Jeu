#include "light.h"

Light::Light(){

}

void Light::allumer(){
    //active la lumière
    glEnable(GL_LIGHTING);
    // notre lampe s'appelle GL_LIGHT0
    glEnable(GL_LIGHT0);
    //coefficient ambiant diffus spéculaire en fct de RVB
    GLfloat qaAmbientLight[] ={0.2,0.2,0.2,1.0};
    GLfloat qaDiffuseLight[] ={0.8,0.8,0.8,1.0};
    GLfloat qaSpecularLight[] ={1.0,1.0,1.0,1.0};
    glLightfv(GL_LIGHT0,GL_AMBIENT,qaAmbientLight);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,qaDiffuseLight);
    glLightfv(GL_LIGHT0,GL_SPECULAR,qaSpecularLight);
    //position de la lampe
    GLfloat qaLightPosition[] = {0.2f,1.f,1.f,0.0f};
    glLightfv(GL_LIGHT0,GL_POSITION,qaLightPosition);
    //active l'option que l'oeil est dans la scène et que les angles comptent
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);

    //Couleur : de base la couleur est blanche
    GLfloat qaWhite[] = {1.0,1.0,1.0,0.0};
    glMaterialfv(GL_FRONT,GL_AMBIENT,qaWhite);
    glMaterialfv(GL_FRONT,GL_DIFFUSE,qaWhite);
    glMaterialfv(GL_FRONT,GL_SPECULAR,qaWhite);
    glMaterialf(GL_FRONT,GL_SHININESS,128.f); // Shininess : largeur tache spéculaire
}

