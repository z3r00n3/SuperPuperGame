// Includes
#include "template.h"
#include "src/utils/util.h"
#include "src/graphics/sprite.h"
#include "src/graphics/gui/menu.h"
#include "src/input/input.h"
#include "src/input/command.h"

// Namespace
using namespace AGK;

////-------------!!!-------------BEST-PRACTICES------------!!!-------------////
// Float/double numbers always must have the real part of the number even if //
// this part is equal to .0                                                  //
///////////////////////////////////////////////////////////////////////////////

app App;

MenuTextData Title = { "SuperPuperGame", 480.0, 0.0, 70.0, TextAlignment::CENTER };
MenuTextData Note = { APP_VERSION, 40.0, 510.0, 25.0, TextAlignment::CENTER };

void app::Begin(void)
{
	// Alternative approach for the coordinate system in AGK, that set fixed
	// resolution. Default approach it's a percentage based system where 0,0
	// represents the top left corner and 100,100 the bottom right
	agk::SetVirtualResolution(960, 540);
	
	// This statements specifies the width to height ratio of the window or
	// screen. If this statement is omitted from a program using the percentage
	// system, other commands may not operate correctly.
	//
	// ratio - is a floating point number giving the width to height ratio
	//agk::SetDisplayAspect(16.0 / 9.0);

	// set background color in RGB (0-255)
	agk::SetClearColor(63, 127, 255);
	
	// fps - The desired frame rate in frames per second, 0 for unlimited
	// mode - 1 to use a possibly more accurate but CPU intensive method, 
	//        0 (default) to save CPU and battery
	agk::SetSyncRate(60, 1);
	
	// 
	agk::SetScissor(0, 0, 0, 0);

	//
	agk::UseNewDefaultFonts(true);

	_gameState = GameState::MAIN_MENU;

	_main_menu = new Menu();
	_main_menu->Initialize(MAIN_MENU_SIZE, 0, Title, Note);

	_input = new Input();
}

int app::Loop(void)
{
	switch (_gameState)
	{
	case GameState::MAIN_MENU:
		_main_menu->Update();
		break;
	case GameState::GAME:
		break;
	default:
		break;
	}
	
	_command = _input->Handler();
	if (_command) _command->Execute(_main_menu);

	if (agk::GetRawKeyPressed(Key::ESCAPE))
		return 1;

	agk::Sync();

	return 0; // return 1 to close app
}


void app::End(void)
{
	agk::DeleteAllImages();
	agk::DeleteAllSprites();
	agk::DeleteAllText();
}
