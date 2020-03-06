#include "agk.h"
#include "src/graphics/gui/menu.h"
#include "src/utils/common.h"
#include "src/graphics/sprite.h"
#include "src/graphics/text.h"
#include "src/graphics/gui/button.h"

Menu::~Menu()
{
	delete _background;
	delete _title;
	delete _note;
	delete[] _menu;
}

void Menu::Initialize(MenuData menu)
{
	_background = new Sprite();
	_background->Initialize({ agk::LoadImage(menu.bg_image), menu.position, menu.dimensions });

	_title = new Text();
	_title->Initialize(menu.title);

	_note = new Text();
	_note->Initialize(menu.note);

	_num_of_items = menu.buttons.size;

	_menu = new Button[menu.buttons.size];
	for (int i = 0; i < menu.buttons.size; i++)
		_menu[i].Initialize(menu.buttons[i]);

	_active_item = 0;
	//_menu[_active_item].SetState(ButtonState::FOCUS);
}

void Menu::Update()
{
	for (int i = 0; i < _num_of_items; i++)
		_menu[i].Update();
}

void Menu::ButtonActivate()
{
	//_menu[_active_item].SetState(ButtonState::SELECT);
	_menu[_active_item].Action();
}

void Menu::ButtonNext()
{
	//_menu[_active_item].SetState(ButtonState::IDLE);
	_active_item > 0 ? _active_item-- : _active_item = _num_of_items - 1;
	//_menu[_active_item].SetState(ButtonState::FOCUS);
}

void Menu::ButtonLast()
{
	//_menu[_active_item].SetState(ButtonState::IDLE);
	_active_item < _num_of_items - 1 ? _active_item++ : _active_item = 0;
	//_menu[_active_item].SetState(ButtonState::FOCUS);
}

