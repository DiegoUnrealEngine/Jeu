#include "scene.h"

int main(int argc, char* argv[])
{
    // Initialisation de la SDL et d'OpenGL
    initSDL();
    initOpenGL();

    // Execution de la scene
    Scene scene;
    scene.executer();

    // Arrêt de la SDL
    SDL_Quit();

    return 0;
}

