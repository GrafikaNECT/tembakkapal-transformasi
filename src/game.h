#include <vector>

#include "drawable.h"
#include "bullet.h"
#include "kapalterbang.h"

class game{
	public:
	game();

	void updateLogic();
	void drawScreen();

	void init();
	void run();

	void addScreenObject(drawable * newScreenObject);

	protected:
	std::vector<drawable*> screenObjects;

	std::vector<bullet> bullets;

	kapalterbang kapalterbang1;
};
