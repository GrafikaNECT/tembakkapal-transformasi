bin/main: Makefile src/mgame.cpp src/game.cpp src/drawable.cpp src/line-pattern.c src/bresenham.c src/printchar.c src/char.c bin
	g++ src/mgame.cpp src/game.cpp src/drawable.cpp src/line-pattern.c src/bresenham.c src/printchar.c src/char.c -o bin/main -fpermissive
	cp src/cat_pixel.txt bin/cat_pixel.txt

bin:
	mkdir -p bin
