#include "agk.h"
#include "src/graphics/gui/menu.h"
#include "src/utils/util.h"
#include "src/graphics/sprite.h"
#include "src/graphics/text.h"
#include "src/graphics/gui/button.h"

#include <vector>

///////////////////////////////////////////////////////////////////////////////
// GLOBALS
///////////////////////////////////////////////////////////////////////////////

std::vector<ButtonData> MainMenuData =
{
	{480.0, 150.0, 300.0, 100.0, "Start",    30.0, &ButtonStartAction},
	{480.0, 270.0, 300.0, 100.0, "Settings", 30.0, &ButtonStartAction},
	{480.0, 390.0, 300.0, 100.0, "About",    30.0, &ButtonStartAction},
};

///////////////////////////////////////////////////////////////////////////////
// MENU
///////////////////////////////////////////////////////////////////////////////

void Menu::Initialize(int menu_size, int active_item, MenuTextData title, MenuTextData note)
{
	_img_id_background = agk::LoadImage(MAIN_MENU_BG_IMAGE);
	
	_background = new Sprite();
	_background->Initialize(_img_id_background, 0.0, 0.0, VIRTUAL_WIDTH, VIRTUAL_HEIGHT);

	_title = new Text();
	_title->Initialize(title.text, title.x, title.y, title.size);
	_title->SetAlignment(title.alignment);

	_note = new Text();
	_note->Initialize(note.text, note.x, note.y, note.size);
	_note->SetAlignment(note.alignment);

	_size = menu_size;

	_menu = new Button[3];
	for (int i = 0; i < menu_size; i++)
		_menu[i].Initialize(MainMenuData[i].x,
							MainMenuData[i].y,
							MainMenuData[i].width,
							MainMenuData[i].height,
							MainMenuData[i].name,
							MainMenuData[i].text_size,
							MainMenuData[i].action);

	_active_item = active_item;
	_menu[active_item].SetState(ButtonState::FOCUS);
}

void Menu::Update()
{
	for (int i = 0; i < _size; i++)
		_menu[i].Update();
}

void Menu::ButtonActivate()
{
	_menu[_active_item].SetState(ButtonState::SELECT);
	_menu[_active_item].Action();
}

void Menu::ButtonNext()
{
	_menu[_active_item].SetState(ButtonState::IDLE);
	_active_item > 0 ? _active_item-- : _active_item = _size - 1;
	_menu[_active_item].SetState(ButtonState::FOCUS);
}

void Menu::ButtonLast()
{
	_menu[_active_item].SetState(ButtonState::IDLE);
	_active_item < _size - 1 ? _active_item++ : _active_item = 0;
	_menu[_active_item].SetState(ButtonState::FOCUS);
}

