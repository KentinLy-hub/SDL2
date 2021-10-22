// SDL_Test.cpp: Definiert den Einstiegspunkt für die Anwendung.
//

#include "Project_SDL1.h"

#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <numeric>
#include <random>
#include <string>

void init() {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO) < 0)
    throw std::runtime_error("init():" + std::string(SDL_GetError()));

  // Initialize PNG loading
  int imgFlags = IMG_INIT_PNG;
  if (!(IMG_Init(imgFlags) & imgFlags))
    throw std::runtime_error("init(): SDL_image could not initialize! "
                             "SDL_image Error: " +
                             std::string(IMG_GetError()));
}


//


void application::window()
{
    auto window_ptr = SDL_CreateWindow("MOUTON ET LOUP",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        frame_width, frame_height,
        0);
    if (!window_ptr)
        throw std::runtime_error(std::string(SDL_GetError()));
    std::cout << "Window create!" << std::endl;
    
    //
    auto window_surface_ptr = SDL_GetWindowSurface(window_ptr);
    if (!window_surface_ptr)
        throw std::runtime_error(std::string(SDL_GetError()));
    std::cout << "Surface create!" << std::endl;

    SDL_FillRect(window_surface_ptr, NULL, SDL_MapRGB(window_surface_ptr->format, 0, 255, 0));
}



void application::handleEvents()
{
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
}

void application::clean()
{
    SDL_FreeSurface(window_surface_ptr_);
    SDL_DestroyWindow(window_ptr_);
    IMG_Quit();
    SDL_Quit();
    std::cout << "Game Cleaned " << std::endl;
}















//
namespace {
// Defining a namespace without a name -> Anonymous workspace
// Its purpose is to indicate to the compiler that everything
// inside of it is UNIQUELY used within this source file.

SDL_Surface* load_surface_for(const std::string& path,
                              SDL_Surface* window_surface_ptr) {
return 0 ;
  // Helper function to load a png for a specific surface
  // See SDL_ConvertSurface
    }
} // namespace
