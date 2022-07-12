#ifndef PERSONNAGE_H_INCLUDED
#define PERSONNAGE_H_INCLUDED

#include "carte.h"

#include <vector>

class Personnage
{
    private:
        float rayon;
        float angleVertical;

        // Angle horizontal avec la verticale en z
        float angleHorizontal;

    public:
        Personnage(float positionX, float positionY, float positionZ, float angleHorizontal);

        float positionX;
        float positionY;
        float positionZ;

        // Déplacement
        void deplacer(float distance, float direction,std::vector<std::vector<float>> murs);
        void tournerHorizontalement(float angle);
        void tournerVerticalement(float angle);

        void sauter(float distance, float direction,std::vector<std::vector<float>> murs,unsigned long dt);
        bool saut=false;
        float t_saut=0;

        void gestion_collision(float positionY,float positionX,float& positionCibleY,float& positionCibleX,std::vector<std::vector<float>> murs);

        void regarder(Carte* carte);
};

#endif // PERSONNAGE_H_INCLUDED
