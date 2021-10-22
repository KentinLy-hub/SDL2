#include "Project_SDL1.h"
#include <stdio.h>
#include <string>


//application* app = nullptr;

int main(int argc, char* argv[]) 
{
   /* init();
    application* app = new application();
    
    app->window();
    app->handleEvents();
    app->clean();
    */
   

    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        throw std::runtime_error(std::string(SDL_GetError()));

    //Initialize PNG loading
    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags))
        throw std::runtime_error("SDL_image could not initialize! "
            "SDL_image Error: " + std::string(IMG_GetError()));

    auto window_ptr = SDL_CreateWindow("MOUTON ET LOUP",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        frame_width, frame_height,
        0);

    if (!window_ptr)
        throw std::runtime_error(std::string(SDL_GetError()));
    //
    auto window_surface_ptr = SDL_GetWindowSurface(window_ptr);

    if (!window_surface_ptr)
        throw std::runtime_error(std::string(SDL_GetError()));

    SDL_FillRect(window_surface_ptr, NULL, SDL_MapRGB(window_surface_ptr->format, 0, 255, 0));

    auto sheep = IMG_Load("media/sheep.png");
    auto wolf = IMG_Load("media/wolf.png");

   if (!sheep)
       throw std::runtime_error("Could not load image");

   if (!wolf)
       throw std::runtime_error("Could not load image");



   auto rect = SDL_Rect{ 0,0,194,259 };
   auto rect1 = SDL_Rect{ 100,100,100,259 };
   //auto rect2 = SDL_Rect{ 0,0,194,100 };

   if (SDL_BlitSurface(sheep, NULL, window_surface_ptr, &rect))
       throw std::runtime_error("Could not apply texture.");

   if (SDL_BlitSurface(wolf, NULL, window_surface_ptr, &rect1))
       throw std::runtime_error("Could not apply texture.");

   //if (SDL_BlitSurface(sheep, NULL, window_surface_ptr, &rect2))
     //  throw std::runtime_error("Could not apply texture.");

    SDL_UpdateWindowSurface(window_ptr);

    auto start = SDL_GetTicks();

    SDL_Event e;
    bool quit = false;
    while (!quit && (SDL_GetTicks() - start < 10000)) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = true;
                break;
            }
        }
    }

    SDL_FreeSurface(window_surface_ptr);
    SDL_DestroyWindow(window_ptr);
    IMG_Quit();
    SDL_Quit();
    std::cout << "Game Cleaned " << std::endl;


    return EXIT_SUCCESS;
}
