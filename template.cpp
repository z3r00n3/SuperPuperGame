// Includes
#include "template.h"
#include "src/utils/common.h"
#include "src/graphics/sprite.h"
#include "src/graphics/gui/menu.h"
#include "src/input/input.h"
#include "src/input/command.h"

#include <vector>

// Namespace
using namespace AGK;

app App;

///////////////////////////////////////////////////////////////////////////////
// Данные о свойствах объектов, составляющих игру
///////////////////////////////////////////////////////////////////////////////

std::vector<ButtonData> MainMenuButtons =
{
	{ BUTTON_IDLE_IMAGE, BUTTON_FOCUS_IMAGE, BUTTON_SELECT_IMAGE, { 480.0, 150.0 }, { 300.0, 100.0 }, { "Start", 30.0 },    &ButtonStartAction },
	{ BUTTON_IDLE_IMAGE, BUTTON_FOCUS_IMAGE, BUTTON_SELECT_IMAGE, { 480.0, 270.0 }, { 300.0, 100.0 }, { "Settings", 30.0 }, &ButtonStartAction },
	{ BUTTON_IDLE_IMAGE, BUTTON_FOCUS_IMAGE, BUTTON_SELECT_IMAGE, { 480.0, 390.0 }, { 300.0, 100.0 }, { "About", 30.0 },    &ButtonStartAction },
};
Color White = { 255, 255, 255 };
TextData MainMenuTitle = { APP_NAME,    480.0, 0.0,   70.0, TextAlignment::CENTER, White };
TextData MainMenuNote  = { APP_VERSION, 40.0,  510.0, 25.0, TextAlignment::CENTER, White };
MenuData MainMenu = { MAIN_MENU_BG_IMAGE,
					  { 0.0, 0.0 },
					  { VIRTUAL_WIDTH, VIRTUAL_HEIGHT },
					  MainMenuTitle,
					  MainMenuNote,
					  sizeof(MainMenuButtons) / sizeof(MainMenuButtons[0],
					  MainMenuButtons) };

///////////////////////////////////////////////////////////////////////////////

void app::Begin(void)
{
	// Alternative approach for the coordinate system in AGK, that set fixed
	// resolution. Default approach it's a percentage based system where 0,0
	// represents the top left corner and 100,100 the bottom right
	agk::SetVirtualResolution(VIRTUAL_WIDTH, VIRTUAL_HEIGHT);
	
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
	_main_menu->Initialize(MainMenu);

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
