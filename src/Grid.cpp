#include <iostream>
#include <cstdlib>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_gfxPrimitives.h>

#include "Grid.h"

using namespace std;

Grid::Grid() {
	cout << "Grid" << endl;
	for( int i = 0; i < 10; i++ ) {
		vector< Pixel * > *temp = new vector< Pixel * >;
		for( int j = 0; j < 10; j++ ) {
			Pixel *p = new Pixel();
			temp->push_back( p );
		}
		pixels.push_back( temp );
		temp = new vector< Pixel * >;
	}
}

int Grid::get_neighbors( int x, int y ) {
	printf( "%s", pixels[0][0]->isBlank()?"Not":"Is" );
	int count = 0;

	// Whether or not it is in the bounds
	bool xlb = !( x < 0 );
	bool xub = !( x >= pixels.size() );
	bool ylb = !( y < 0 );
	bool yub = !( y >= pixels[0].size() );

	printf( "1\n" );
	printf( "%s", pixels[0][0]->isBlank()?"Not":"Is" );
	if( xlb && ylb && pixels[x-1][y-1]->isBlank() ) {
		count ++;
	}
	printf( "2\n" );
	if( xlb && pixels[x-1][y]->isBlank() ) {
		count ++;
	}
	printf( "3\n" );
	if( xlb && yub && pixels[x-1][y+1]->isBlank() ) {
		count ++;
	}
	printf( "4\n" );
	if( ylb && pixels[x][y-1]->isBlank() ) {
		count ++;
	}
	printf( "5\n" );
	if( yub && pixels[x][y+1]->isBlank() ) {
		count ++;
	}
	printf( "6\n" );
	if( xub && ylb && pixels[x+1][y-1]->isBlank() ) {
		count ++;
	}
	printf( "7\n" );
	if( xub && pixels[x+1][y]->isBlank() ) {
		count ++;
	}
	printf( "8\n" );
	if( xub && yub && pixels[x+1][y+1]->isBlank() ) {
		count ++;
	}
	return count;
}

void Grid::update() {
//	int neighbors[pixels.size()][pixels[0].size()];
	for( int i = 0; i < pixels.size(); i++ ) {
		for( int j = 0; j < pixels[0].size(); j++ ) {
//			neighbors[i][j] = get_neighbors( i, j );	
			get_neighbors( i, j ) ;
		}
	}
}

void Grid::draw( SDL_Surface *screen ) {
	for( int i = 0; i < pixels.size(); i++ ) {
		for( int j = 0; j < pixels[0].size(); j++ ) {
			boxRGBA( screen, i*15, j*15, i*15+10, j*15+10, pixels[i][j]->getR(), pixels[i][j]->getG(), pixels[i][j]->getB(), 255 );
		}
	}
}
