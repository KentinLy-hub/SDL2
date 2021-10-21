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

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("Mouton et Loup", 100, 100, 1000, 600, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderClear(renderer);
//    SDL_Delay(500);
    SDL_RenderPresent(renderer);
//    SDL_Delay(500);
//    SDL_DestroyRenderer(renderer);
//    SDL_DestroyWindow(window);
//    SDL_UpdateWindowSurface(window_ptr);

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
