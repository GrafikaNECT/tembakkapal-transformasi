bin/main: Makefile src/mgame.cpp src/game.cpp src/drawable.cpp src/kapalterbang.cpp src/kapallaut.cpp src/bullet.cpp src/line-pattern.c src/bresenham.c src/printchar.cpp src/char.c src/game.h src/drawable.h src/kapalterbang.h src/kapallaut.h src/bullet.h src/line-pattern.h src/bresenham.h src/printchar.h src/char.h bin
	g++ src/mgame.cpp src/game.cpp src/drawable.cpp src/kapalterbang.cpp src/kapallaut.cpp src/bullet.cpp src/line-pattern.c src/bresenham.c src/printchar.cpp src/char.c -o bin/main -fpermissive -std=c++11
	cp src/cat_pixel.txt bin/cat_pixel.txt

bin:
	mkdir -p bin
