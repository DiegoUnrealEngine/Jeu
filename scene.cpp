#include "scene.h"

Scene::Scene()
{
    // Maintien de la souris dans la fenetre
    SDL_WM_GrabInput(SDL_GRAB_ON);

    // La souris est au centre de l'ecran
    SDL_WarpMouse( (LARGEUR_FENETRE/2), (HAUTEUR_FENETRE/2) );

    // La souris est invisible
    SDL_ShowCursor(false);

    //this->skybox = new Objet3DStatique("skybox.m3s");
    this->personnage = new Personnage(1, 2, 0.0, -130);
    this->carte = new Carte();
    this->skybox = new Skybox();
}

void Scene::executer()
{
    // Initialisation des variables de gestion du temps
    this->dt = 0; // pas de temps
    unsigned long t = SDL_GetTicks(); // temps actuel

    this->continuer = true;

    while(this->continuer)
    {
        gererEvenements();
        animer();
        dessiner();
        afficher();

        this->dt = SDL_GetTicks() - t; // calcul du temps d'une frame
        t += this->dt;
    }
}

void Scene::gererEvenements(void)
{
    SDL_Event evenement;
    while (SDL_PollEvent(&evenement))
    {
        switch(evenement.type)
        {
            case SDL_QUIT:
                this->continuer = false;
                break;

            case SDL_MOUSEMOTION:
                // Si la souris n'est plus au centre de l'écran
                if ((LARGEUR_FENETRE/2) != evenement.motion.x || (HAUTEUR_FENETRE/2) != evenement.motion.y)
                {
                    // Fait tourner le personnage
                    this->personnage->tournerHorizontalement(-evenement.motion.xrel * 0.06);
                    this->personnage->tournerVerticalement(-evenement.motion.yrel * 0.06);

                    // Replace la souris au milieu de l'ecran
                    SDL_WarpMouse( (LARGEUR_FENETRE/2), (HAUTEUR_FENETRE/2) );
                }
                break;

            case SDL_KEYDOWN:
                // Permet de quitter grace a la touche Echap
                if (evenement.key.keysym.sym == SDLK_ESCAPE)
                {
                    this->continuer = false;
                }
                break;
        }
    }
}

void Scene::animer(void)
{
    // Lecture de l'état des touches
    int nombreDeTouches;
    unsigned char* pTouches = SDL_GetKeyState(&nombreDeTouches);
    unsigned char* touches = new unsigned char[nombreDeTouches];
    memcpy(touches, pTouches, nombreDeTouches);

    // Evite les deplacements absurdes
    if (touches[SDLK_w] == touches[SDLK_s]) // Avancer et reculer
    {
        touches[SDLK_w] = 0u;
        touches[SDLK_s] = 0u;
    }
    if (touches[SDLK_a] == touches[SDLK_d]) // Gauche et droite
    {
        touches[SDLK_a] = 0u;
        touches[SDLK_d] = 0u;
    }

    /*gestion des déplacements*/
    bool deplacement = false;

    if (touches[SDLK_w]) // Touche Z
    {
        // Avancer
        deplacement = true;

        // En diagonale
        if (touches[SDLK_a]) direction = 45.0;
        else if (touches[SDLK_d]) direction = -45.0;

        // Droit
        else direction = 0.0;
    }
    else if (touches[SDLK_s]) // Touche S
    {
        // Reculer
        deplacement = true;

        // En diagonale
        if (touches[SDLK_a]) direction = 135.0;
        else if (touches[SDLK_d]) direction = -135.0;

        // Droit
        else direction = 180.0;
    }

    if(deplacement == false)
    {
        if (touches[SDLK_a]) // Touche Q
        {
            // Gauche
            direction = 90.0;
            deplacement = true;
        }
        else if (touches[SDLK_d]) // Touche D
        {
            // Droite
            direction = -90.0;
            deplacement = true;
        }
    }

    // supprime l'allocation mémoire de touches
    delete[] touches;

    if (touches[SDLK_SPACE]) //touche espace
        this->personnage->saut=true;

    // Si un deplacement est demande
    if (deplacement && !this->personnage->saut){

        #define VITESSE_DEPLACEMENT (3.0f)

        // Calcule de la distance à parcourir
        float distance = (float)dt * VITESSE_DEPLACEMENT / 1000.0f;

        // Deplacement du personnage dans la direction demandée
        this->personnage->deplacer(distance, direction, this->carte->murs);
    }

    if (this->personnage->saut){

        #define VITESSE_DEPLACEMENT (3.0f)

        // Calcule de la distance à parcourir
        float distance = (float)dt * VITESSE_DEPLACEMENT / 1000.0f;

        // Deplacement du personnage dans la direction demandée
        this->personnage->sauter(distance, direction, this->carte->murs,this->dt);
    }

}

void Scene::dessiner(void)
{
    // Vidage de l'écran
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Place la camera
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    // point de vue du personnage
    this->personnage->regarder(this->carte);

    //dessiner skybox
    this->skybox->dessiner(this->personnage);

    // Dessin de la carte
    this->carte->dessiner();

}

void Scene::afficher(void)
{
    glFlush();
    SDL_GL_SwapBuffers();
}


