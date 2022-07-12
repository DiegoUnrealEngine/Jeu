#include "personnage.h"

Personnage::Personnage(float positionX, float positionY, float positionZ, float angleHorizontal)
{
    this->positionX = positionX;
    this->positionY = positionY;
    this->positionZ = positionZ;
    this->angleHorizontal = angleHorizontal;
    this->rayon = 0.3f;
    this->angleVertical = 0.0f;
}

void Personnage::deplacer(float distance, float direction,std::vector<std::vector<float>> murs)
{
    direction += this->angleHorizontal;

    // Calcule de la position cible du personnage
    float positionCibleY = this->positionY - distance * sin(direction * 3.1415 / 180.0);
    float positionCibleX = this->positionX - distance * cos(direction * 3.1415 / 180.0);

    gestion_collision(this->positionY,this->positionX,positionCibleY,positionCibleX,murs);

    this->positionY = positionCibleY;
    this->positionX = positionCibleX;
}

void Personnage::sauter(float distance, float direction,std::vector<std::vector<float>> murs,unsigned long dt)
{
    direction += this->angleHorizontal;

    // Calcule de la position cible du personnage
    float positionCibleY = this->positionY - 0.5f*distance * sin(direction * 3.1415 / 180.0);
    float positionCibleX = this->positionX - 0.5f*distance * cos(direction * 3.1415 / 180.0);

    gestion_collision(this->positionY,this->positionX,positionCibleY,positionCibleX,murs);

    this->positionY = positionCibleY;
    this->positionX = positionCibleX;
    this->positionZ += 0.8f*distance*(1-2*t_saut);
    t_saut+=(float)dt/1000.f;
    if (this->positionZ<0.0){
        saut=false;
        t_saut=0;
    }
}

void Personnage::tournerHorizontalement(float angle)
{
    this->angleHorizontal += angle;

    while (this->angleHorizontal >= 180.0f) // Lorsqu'on dépasse la limite (1/2 tour)
        this->angleHorizontal -= 360.0f;
    while (this->angleHorizontal < -180.0f) // Idem après 1/2 tours vers la droite
        this->angleHorizontal += 360.0f;
}

void Personnage::tournerVerticalement(float angle)
{
    this->angleVertical += angle;

    if (45.0f < this->angleVertical)
    {
        this->angleVertical = 45.0f;
    }
    else if (-45.0f > this->angleVertical)
    {
        this->angleVertical = -45.0f;
    }
}

void Personnage::regarder(Carte* carte)
{
    #define RADIANS_PAR_DEGRES 0.0174532925199

    float X = positionX*carte->nbmaille/carte->size_map;
    float Y = positionY*carte->nbmaille/carte->size_map;

    float dx=carte->size_map/((float)carte->nbmaille);

    int J = abs(X);
    int K = abs(Y);

    float j = J*dx;
    float k = K*dx;

    float delta;

    if (X-J+Y-K<=1){
        float a = carte->terrain[J+1][K]-carte->terrain[J][K];
        float b = carte->terrain[J][K+1]-carte->terrain[J][K];
        float c = -dx;
        float d = -a*j-b*k-c*carte->terrain[J][K];
        delta = (-a*positionX-b*positionY-d)/c;
    }
    else {
        float a = carte->terrain[J+1][K+1]-carte->terrain[J][K+1];
        float b = carte->terrain[J+1][K+1]-carte->terrain[J+1][K];
        float c = -dx;
        float d = -a*(j+dx)-b*(k+dx)-c*carte->terrain[J+1][K+1];
        delta = (-a*positionX-b*positionY-d)/c;
    }

    gluLookAt(
        // Position de l'oeil
        this->positionX, this->positionY, this->positionZ+0.8f+delta ,
        // Point vise
        this->positionX - cos(-this->angleHorizontal * RADIANS_PAR_DEGRES),
        this->positionY + sin(-this->angleHorizontal * RADIANS_PAR_DEGRES),
        delta+this->positionZ + tan(this->angleVertical * RADIANS_PAR_DEGRES),
        // La verticale est en Z
        0,0,1);
}


void Personnage::gestion_collision(float positionY,float positionX,float& positionCibleY,float& positionCibleX,std::vector<std::vector<float>> murs){
    for (int k =0;k<murs.size();k+=1){
        float a = murs[k][0];
        float b = murs[k][1];
        float c = murs[k][2];
        float d = murs[k][3];
        float x;
        float y;
        if (a!=c){
            x = (positionCibleX*pow(c-a,2)+(b-d)*(b-positionCibleY)*(c-a)+a*pow(d-b,2))/(pow(c-a,2)+pow(d-b,2));
            if (x<std::min(a,c))
                x=std::min(a,c);
            if (x>std::max(a,c))
                x=std::max(a,c);
            y = (d-b)*(x-a)/(c-a)+b;
        }
        if (a==c){
            x = a;
            y = positionCibleY;
            if (y<std::min(b,d))
                y=std::min(b,d);
            if (y>std::max(b,d))
                y=std::max(b,d);
         }
        if (pow(positionCibleX-x,2)+pow(positionCibleY-y,2)<pow(this->rayon,2)){
            float dx=0;
            float xnew=x+dx*(positionCibleX-x);
            float ynew=y+dx*(positionCibleY-y);
            while (pow(xnew-x,2)+pow(ynew-y,2)<pow(this->rayon,2)){
                dx+=0.01;
                xnew=x+dx*(positionCibleX-x);
                ynew=y+dx*(positionCibleY-y);
            }
            positionCibleX=xnew;
            positionCibleY=ynew;
        }
    }
}




