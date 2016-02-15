bin/main: obj Makefile src/mgame.cpp obj/game.o obj/drawable.o obj/kapalterbang.o obj/kapallaut.o obj/bullet.o obj/line-pattern.o obj/bresenham.o obj/print.o obj/drawBitPicture-old.o obj/alphabet.o obj/pixelBoolMatrix.o obj/letter.o obj/polygon.o src/alphabet-2.txt bin obj/balingbaling.o obj/person.o obj/banterbakar.o  obj/point.o
	g++ src/mgame.cpp obj/game.o obj/drawable.o obj/kapalterbang.o obj/kapallaut.o obj/bullet.o obj/line-pattern.o obj/bresenham.o obj/drawBitPicture-old.o obj/alphabet.o obj/pixelBoolMatrix.o obj/letter.o obj/polygon.o obj/balingbaling.o obj/person.o obj/banterbakar.o obj/print.o obj/point.o -fpermissive -std=c++11 -w -g
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
	cp src/ban.txt bin/ban.txt
	cp src/orang.txt bin/orang.txt
	cp src/parasut.txt bin/parasut.txt
	cp src/ban-terbakar.txt bin/ban-terbakar.txt
	cp src/ban-color.txt bin/ban-color.txt

bin:
	mkdir -p bin

obj:
	mkdir -p obj

obj/game.o: src/drawable.h src/movingObject.h src/bullet.h src/kapalterbang.h src/kapallaut.h src/alphabet.h src/person.h src/banterbakar.h src/game.cpp src/game.h src/print.h
	g++ src/game.cpp -c -o obj/game.o -fpermissive -std=c++11 -w -g

obj/drawable.o: src/drawable.h src/drawable.cpp
	g++ src/drawable.cpp -c -o obj/drawable.o -fpermissive -std=c++11 -w -g

obj/kapalterbang.o: src/kapalterbang.h src/kapalterbang.cpp src/bullet.h src/drawable.h src/movingObject.h src/balingbaling.h src/polygon.h src/line-pattern.h src/bresenham.h src/print.h src/drawBitPicture-old.h src/polygon.h
	g++ -c src/kapalterbang.cpp -o obj/kapalterbang.o -fpermissive -std=c++11 -w -g

obj/kapallaut.o: src/kapallaut.h src/kapallaut.cpp src/bullet.h src/print.h src/drawable.h src/line-pattern.h src/kapallaut.cpp src/print.h src/bresenham.h src/line-pattern.h src/drawBitPicture-old.h 
	g++ -c src/kapallaut.cpp -o obj/kapallaut.o -fpermissive -std=c++11 -w -g

obj/bullet.o: src/bullet.cpp src/bullet.h src/drawable.h src/line-pattern.h src/bresenham.h 
	g++ -c src/bullet.cpp -o obj/bullet.o -fpermissive -std=c++11 -w -g

obj/line-pattern.o: src/line-pattern.c src/line-pattern.h src/print.h
	g++ -c src/line-pattern.c -o obj/line-pattern.o -fpermissive -std=c++11 -w -g

obj/bresenham.o:  src/bresenham.h src/bresenham.c src/line-pattern.h
	g++ -c src/bresenham.c -o obj/bresenham.o -fpermissive -std=c++11 -w -g

obj/print.o:  src/print.c src/print.h
	g++ -c src/print.c -o obj/print.o -fpermissive -std=c++11 -w -g

obj/drawBitPicture-old.o:  src/drawBitPicture-old.cpp src/drawBitPicture-old.h src/print.h
	g++ -c src/drawBitPicture-old.cpp -o obj/drawBitPicture-old.o -fpermissive -std=c++11 -w -g

obj/alphabet.o:  src/alphabet.cpp src/alphabet.h src/letter.h
	g++ -c src/alphabet.cpp -o obj/alphabet.o -fpermissive -std=c++11 -w -g

obj/pixelBoolMatrix.o:  src/pixelBoolMatrix.h src/pixelBoolMatrix.cpp src/print.h src/point.h src/polygon.h
	g++ -c src/pixelBoolMatrix.cpp -o obj/pixelBoolMatrix.o -fpermissive -std=c++11 -w -g

obj/letter.o:  src/letter.h src/polygon.h src/pixelBoolMatrix.h src/letter.cpp
	g++ -c src/letter.cpp -o obj/letter.o -fpermissive -std=c++11 -w -g

obj/polygon.o:  src/polygon.h src/pixelBoolMatrix.h src/polygon.cpp src/point.h
	g++ -c src/polygon.cpp -o obj/polygon.o -fpermissive -std=c++11 -w -g

obj/point.o:  src/point.cpp src/point.h
	g++ -c src/point.cpp -o obj/point.o -fpermissive -std=c++11 -w -g

obj/balingbaling.o:  src/balingbaling.h src/balingbaling.cpp src/polygon.h src/movingObject.h src/drawable.h
	g++ -c src/balingbaling.cpp -o obj/balingbaling.o -fpermissive -std=c++11 -w -g

obj/banterbakar.o:  src/banterbakar.cpp src/banterbakar.h src/polygon.h src/print.h src/drawBitPicture-old.h src/movingObject.h src/drawable.h
	g++ -c src/banterbakar.cpp -o obj/banterbakar.o -fpermissive -std=c++11 -w -g

obj/person.o:  src/drawable.h src/movingObject.h src/polygon.h src/circle.h src/person.h src/print.h
	g++ -c src/person.cpp -o obj/person.o -fpermissive -std=c++11 -w -g
