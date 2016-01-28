#ifndef game_h
#define game_h

#include <vector>

#include "drawable.h"
#include "bullet.h"
#include "kapalterbang.h"
#include "kapallaut.h"

class game{
	public:
	game();

	void updateControls();
	void updateLogic();
	void drawScreen();
	bool gameOver();

	void init();
	void run();

	void addScreenObject(drawable * newScreenObject);

	void onMoveRightKeyPressed();
	void onMoveLeftKeyPressed();
	void onRightKeyPressed();
	void onLeftKeyPressed();
	void onShootKeyPressed();

	protected:
	std::vector<drawable*> screenObjects;

	std::vector<bullet*> bullets;

	kapalterbang kapalterbang1;

	kapallaut kapallaut1;

};

#endif
