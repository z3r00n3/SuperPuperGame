#ifndef _H_AGK_TEMPLATE_
#define _H_AGK_TEMPLATE_

// Link to GDK libraries
#include "AGK.h"

#define DEVICE_WIDTH 960
#define DEVICE_HEIGHT 540
#define DEVICE_POS_X 32
#define DEVICE_POS_Y 32
#define FULLSCREEN false

// used to make a more unique folder for the write path
#define COMPANY_NAME "My Company"

namespace Common { enum GameState; };
class Sprite;
class Menu;
class Input;
class Command;

// Global values for the app
class app
{
public:
	// constructor
	//app() { memset(this, 0, sizeof(app)); }
	app() { ; }
	~app() { ; }

	// main app functions - mike to experiment with a derived class for this..
	void Begin(void);
	int Loop(void);
	void End(void);

private:
	//Sprite *_WS;
	//Sprite *_Tower;
	Menu *_main_menu;
	Input *_input;
	Command *_command;
	Common::GameState _gameState;
};

extern app App;

#endif

// Allow us to use the LoadImage function name
#ifdef LoadImage
 #undef LoadImage
#endif