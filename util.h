#pragma once

///////////////////////////////////////////////////////////////////////////////
// INCLUDES
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// DEFINES
///////////////////////////////////////////////////////////////////////////////

#define WINDOW_WIDTH  960
#define WINDOW_HEIGHT 540

#define VIRTUAL_WIDTH  960
#define VIRTUAL_HEIGHT 540

#define APP_VERSION "v 0.14d"

#define DBG_FILE "../DbgLog.txt"

#define MAIN_MENU_SIZE 3
#define MAIN_MENU_BG_IMAGE  "media/images/backgrounds/main_menu_background.png"
#define BUTTON_IDLE_IMAGE   "media/images/buttons/idle.png"
#define BUTTON_FOCUS_IMAGE  "media/images/buttons/focus.png"
#define BUTTON_SELECT_IMAGE "media/images/buttons/select.png"

#define WS_IMAGE    "media/images/WS.png"
#define TOWER_IMAGE "media/images/Tower.png"

///////////////////////////////////////////////////////////////////////////////
// ENUMS
///////////////////////////////////////////////////////////////////////////////

////-------------!!!-------------BEST-PRACTICES------------!!!-------------////
// Every global enumeration need his own namespace otherwise will be         //
// redefinition of constants                                                 //
///////////////////////////////////////////////////////////////////////////////

namespace TextAlignment
{
	enum TextAlignment
	{
		LEFT   = 0,
		CENTER = 1,
		RIGHT  = 2
	};
}

namespace ButtonState
{
	enum ButtonState
	{
		IDLE   = 0,
		FOCUS  = 1,
		SELECT = 2,
	};
}

///////////////////////////////////////////////////////////////////////////////
// STRUCTS
///////////////////////////////////////////////////////////////////////////////

struct Coords
{
	float x, y;
};

struct MenuTextData
{
	std::string text;
	float x, y;
	float size;
	TextAlignment::TextAlignment alignment;
};

struct ButtonData
{
	float x, y;
	float width, height;
	std::string name;
	float text_size;
};

///////////////////////////////////////////////////////////////////////////////
// FUNCTION'S PROTOTYPES
///////////////////////////////////////////////////////////////////////////////

void DbgLog(const char *str);

///////////////////////////////////////////////////////////////////////////////
// CLASSES
///////////////////////////////////////////////////////////////////////////////
