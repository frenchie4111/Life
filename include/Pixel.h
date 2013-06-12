#ifndef PIXEL_H
#define PIXEL_H

#include <iostream>

using namespace std;

class Pixel {
	private:
		int r, g, b;
	public:
		Pixel();
		int getR() { return r; };
		int getG() { return g; };
		int getB() { return b; };
		void setR( int newr ) { r = newr; };
		void setG( int newg ) { g = newg; };
		void setB( int newb ) { b = newb; };
};


#endif
