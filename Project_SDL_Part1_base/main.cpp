#include "Project_SDL1.h"
#include <stdio.h>
#include <string>

int main(int argc, char* argv[]) {
/*
  std::cout << "Starting up the application" << std::endl;

  if (argc != 4)
    throw std::runtime_error("Need three arguments - "
                             "number of sheep, number of wolves, "
                             "simulation time\n");

  init();

  std::cout << "Done with initilization" << std::endl;

  application my_app(std::stoul(argv[1]), std::stoul(argv[2]));

  std::cout << "Created window" << std::endl;

  int retval = my_app.loop(std::stoul(argv[3]));

  std::cout << "Exiting application with code " << retval << std::endl;
*/
    auto window_ptr = SDL_CreateWindow("SDL2 Window",
                                     SDL_WINDOWPOS_CENTERED,
                                     SDL_WINDOWPOS_CENTERED,
                                     1000, 500,
                                     0);
//    SDL_FillRect(window_ptr, NULL, SDL_MapRGB(window_ptr->format, 0 , 255 , 0));
    //SDL_MapRGB(window_ptr->format, 0, 255, 0);
/*
    SDL_Init(SDL_INIT_VIDEO);
    ecran = SDL_SetVideoMode(800, 520, 32, SDL_HWSURFACE);
     SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 17, 206, 112));
*/
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
    SDL_Quit();
    return EXIT_SUCCESS;
//  return retval;
}
