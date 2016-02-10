bin/main: Makefile src/mgame.cpp src/game.cpp src/drawable.cpp src/kapalterbang.cpp src/kapallaut.cpp src/bullet.cpp src/line-pattern.c src/bresenham.c src/printchar.cpp src/char.c src/game.h src/drawable.h src/kapalterbang.h src/kapallaut.h src/bullet.h src/line-pattern.h src/bresenham.h src/printchar.h src/char.h bin
	g++ src/mgame.cpp src/game.cpp src/drawable.cpp src/kapalterbang.cpp src/kapallaut.cpp src/bullet.cpp src/line-pattern.c src/bresenham.c src/printchar.cpp src/char.c -o bin/main -fpermissive -std=c++11 -w
	cp src/cat_pixel.txt bin/cat_pixel.txt
	cp src/ship.txt bin/ship.txt
	cp src/plane2.txt bin/plane2.txt
	cp src/color.txt bin/color.txt
	cp src/planecolor1.txt bin/planecolor1.txt
	cp src/planecolor2.txt bin/planecolor2.txt
	cp src/planecolor3.txt bin/planecolor3.txt
	cp src/explosion.txt bin/explosion.txt
	cp src/explosioncolor.txt bin/explosioncolor.txt
	cp src/alphabet-2.txt bin/alphabet-2.txt

bin:
	mkdir -p bin
