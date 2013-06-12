#ifndef GRID_H
#define GRID_H

#include <vector>

#include <SDL/SDL.h>

#include "Pixel.h"

using namespace std;

class Grid {
	vector< vector< Pixel * > * > pixels;

	public:
		Grid();

		void update();
		void draw( SDL_Surface *screen );

		int get_neighbors( int x, int y );
};

#endif
