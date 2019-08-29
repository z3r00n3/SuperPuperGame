#include "menu.h"

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
// SPRITE
///////////////////////////////////////////////////////////////////////////////

// SETTERS

void Sprite::SetOffset(float x, float y)
{
	agk::SetSpriteOffset(_id, x, y);
}

void Sprite::SetPositionByOffset(float x, float y)
{
	agk::SetSpritePositionByOffset(_id, x, y);

	_position.x = agk::GetSpriteX(_id);
	_position.y = agk::GetSpriteY(_id);
}

void Sprite::SetImage(int img_id)
{
	agk::SetSpriteImage(_id, img_id);
}

void Sprite::SetVisible(bool visible)
{
	agk::SetSpriteVisible(_id, visible);
}

// GETTERS

float Sprite::GetX()
{
	return _position.x;
}

float Sprite::GetY()
{
	return _position.y;
}

float Sprite::GetWidth()
{
	return _width;
}

float Sprite::GetHeight()
{
	return _height;
}

// MANAGEMENT

void Sprite::Initialize(int img_id, float x, float y, float width, float height)
{
	_id = agk::CreateSprite(img_id);

	_position.x = x;
	_position.y = y;
	agk::SetSpritePosition(_id, x, y);

	_width = width;
	_height = height;
	agk::SetSpriteSize(_id, width, height);
}

void Sprite::DrawBounds(bool fill)
{
	int red    = agk::MakeColor(255, 0, 0);
	int green  = agk::MakeColor(0, 255, 0);
	int blue   = agk::MakeColor(0, 0, 255);
	int middle = agk::MakeColor(127, 127, 127);

	agk::DrawBox(_position.x,
				 _position.y,
				 _position.x + _width,
				 _position.y + _height,
				 red,
				 green,
				 blue,
				 middle,
				 fill);
}

///////////////////////////////////////////////////////////////////////////////
// TEXT
///////////////////////////////////////////////////////////////////////////////

// SETTERS

void Text::SetPosition(float x, float y)
{
	agk::SetTextPosition(_id, x, y);

	_position.x = x;
	_position.y = y;
}

void Text::SetSize(float size)
{
	agk::SetTextSize(_id, size);

	_size = size;
}

void Text::SetColor(unsigned int red, unsigned int green, unsigned int blue)
{
	agk::SetTextColor(_id, red, green, blue);
}

void Text::SetAlignment(TextAlignment::TextAlignment alignment)
{
	agk::SetTextAlignment(_id, alignment);
}

// GETTERS

int Text::GetID()
{
	return _id;
}

// MANAGEMENT

void Text::Initialize(std::string text, float x, float y, float size)
{
	_text = text;
	_id = agk::CreateText(_text.c_str());
	
	_size = size;
	SetSize(size);
	
	_position.x = x;
	_position.y = y;
	SetPosition(x, y);

	SetColor(255, 255, 255);
}

///////////////////////////////////////////////////////////////////////////////
// BUTTON
///////////////////////////////////////////////////////////////////////////////

// SETTERS

void Button::SetPosition(float x, float y)
{
	_sprite.SetOffset(_sprite.GetWidth() / 2, _sprite.GetHeight() / 2);
	_sprite.SetPositionByOffset(x, y);

	_text.SetPosition(x, y - agk::GetTextTotalHeight(_text.GetID()) / 2);
}

void Button::SetState(ButtonState::ButtonState state)
{
	switch (state)
	{
	case ButtonState::IDLE:
		_state = state;
		_sprite.SetImage(_img_id_idle);
		break;
	case ButtonState::FOCUS:
		_state = state;
		_sprite.SetImage(_img_id_focus);
		break;
	case ButtonState::SELECT:
		_state = state;
		_sprite.SetImage(_img_id_select);
		break;
	default:
		break;
	}
}

// GETTERS

// MANAGEMENT

void Button::Initialize(float x,
						float y,
						float width,
						float height,
						std::string name,
						float text_size,
						void(*action)())
{
	_img_id_idle   = agk::LoadImage(BUTTON_IDLE_IMAGE, false);
	_img_id_focus  = agk::LoadImage(BUTTON_FOCUS_IMAGE, false);
	_img_id_select = agk::LoadImage(BUTTON_SELECT_IMAGE, false);
	_sprite.Initialize(_img_id_idle, x, y, width, height);

	_text.Initialize(name, x, y, text_size);
	_text.SetAlignment(TextAlignment::CENTER);
	
	_action = action;

	SetPosition(_sprite.GetX(), _sprite.GetY());
}

void Button::Update()
{	
	//_sprite.DrawBounds(false);
}

void Button::Action()
{
	_action();
}

///////////////////////////////////////////////////////////////////////////////
// MENU
///////////////////////////////////////////////////////////////////////////////

void Menu::Initialize(int menu_size, int active_item, MenuTextData title, MenuTextData note)
{
	_img_id_background = agk::LoadImage(MAIN_MENU_BG_IMAGE);
	_background.Initialize(_img_id_background, 0.0, 0.0, VIRTUAL_WIDTH, VIRTUAL_HEIGHT);

	_title.Initialize(title.text, title.x, title.y, title.size);
	_title.SetAlignment(title.alignment);
	_note.Initialize(note.text, note.x, note.y, note.size);
	_note.SetAlignment(note.alignment);

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

