#include <cstdlib>
#include <iostream>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "Grid.h"

using namespace std;

int main() {

	Grid derp;

	if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
		printf( "Unable to init SDL: %s", SDL_GetError() );
		return 1;
	}

	atexit( SDL_Quit );

	SDL_Surface* screen = SDL_SetVideoMode( 500, 500, 16, SDL_HWSURFACE|SDL_DOUBLEBUF );

	bool done = false;

	while( !done ) {

		SDL_Event event;
		if( SDL_PollEvent( &event ) ) {
			if( event.type == SDL_QUIT ) {
				done = true;
			}
		}

	}

	return 0;
}
