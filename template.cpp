// Includes
#include "template.h"
#include "util.h"

// Namespace
using namespace AGK;

app App;

void app::Begin(void)
{
	// Alternative approach for the coordinate system in AGK, that set fixed resolution
	// Default approach it's a percentage based system where 0,0 represents the
	// top left corner and 100,100 the bottom right
	agk::SetVirtualResolution(960, 540);
	
	// This statements specifies the width to height ratio of the window or screen
	// If this statement is omitted from a program using the percentage system, 
	// other commands may not operate correctly
	//
	// ratio - is a floating point number giving the width to height ratio
	// agk::SetDisplayAspect(16.0 / 9.0);

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

	menu.Initialize(3, 0);
}

int app::Loop(void)
{
	menu.Update();
	
	if (agk::GetRawKeyPressed(UP))
		menu.ChangeFocusButton(UP);
	if (agk::GetRawKeyPressed(DOWN))
		menu.ChangeFocusButton(DOWN);

	agk::Sync();

	return 0; // return 1 to close app
}


void app::End(void)
{
	agk::DeleteAllImages();
	agk::DeleteAllSprites();
	agk::DeleteAllText();
}
