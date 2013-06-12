run: build
	./main
build:
	g++ -o main src/*.cpp -I include/ -lSDL -lSDL_image -lSDL_gfx -lSDL_ttf -lstdc++
