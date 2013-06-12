run: build
	./main
build:
	g++ -o main src/*.cpp -I include/ -lSDL -lstdc++
