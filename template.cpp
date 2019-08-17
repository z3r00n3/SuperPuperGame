// Includes
#include "template.h"

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

	_main_menu.Initialize(MAIN_MENU_SIZE, 0, Title, Note);
	_WS.Initialize(agk::LoadImage(WS_IMAGE), 70.0, 174.0, 130.0, -1.0);
	_Tower.Initialize(agk::LoadImage(TOWER_IMAGE), 750.0, 0.0, 170.0, -1.0);
}

int app::Loop(void)
{
	_main_menu.Update();
	
	if (agk::GetRawKeyPressed(KEY_ENTER))
		_main_menu.InputHandler(KEY_ENTER);
	if (agk::GetRawKeyPressed(KEY_ESCAPE))
		return 1;
	if (agk::GetRawKeyPressed(KEY_UP))
		_main_menu.InputHandler(KEY_UP);
	if (agk::GetRawKeyPressed(KEY_DOWN))
		_main_menu.InputHandler(KEY_DOWN);

	agk::Sync();

	return 0; // return 1 to close app
}


void app::End(void)
{
	agk::DeleteAllImages();
	agk::DeleteAllSprites();
	agk::DeleteAllText();
}
