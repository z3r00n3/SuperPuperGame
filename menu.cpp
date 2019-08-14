#include "menu.h"

ButtonData MainMenu[MAIN_MENU_SIZE] =
{
	{480, 110, 300, 100, "Start",    30},
	{480, 270, 300, 100, "Settings", 30},
	{480, 430, 300, 100, "About",    30},
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

void Text::Initialize(float x, float y, std::string text, float size)
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

void Button::Initialize(float x, float y, float width, float height, std::string name, float text_size)
{
	_img_id_idle   = agk::LoadImage(BUTTON_IDLE_IMAGE, false);
	_img_id_focus  = agk::LoadImage(BUTTON_FOCUS_IMAGE, false);
	_img_id_select = agk::LoadImage(BUTTON_SELECT_IMAGE, false);
	_sprite.Initialize(_img_id_idle, x, y, width, height);

	_text.Initialize(x, y, name, text_size);
	_text.SetAlignment(TextAlignment::CENTER);
	
	SetPosition(_sprite.GetX(), _sprite.GetY());
}

void Button::Update()
{	
	_sprite.DrawBounds(false);
}

///////////////////////////////////////////////////////////////////////////////
// MENU
///////////////////////////////////////////////////////////////////////////////

void Menu::Initialize(int size, int active_item)
{
	_menu = new Button[3];
	for (int i = 0; i < size; i++)
		_menu[i].Initialize(MainMenu[i].x,
							MainMenu[i].y,
							MainMenu[i].width,
							MainMenu[i].height,
							MainMenu[i].name,
							MainMenu[i].text_size);

	_size = size;
	_active_item = active_item;
	_menu[active_item].SetState(ButtonState::FOCUS);
}

void Menu::Update()
{
	for (int i = 0; i < _size; i++)
		_menu[i].Update();
}

void Menu::InputHandler(Key::Key key)
{
	switch (key)
	{
	case Key::UP:
		_menu[_active_item].SetState(ButtonState::IDLE);
		_active_item > 0 ? _active_item-- : _active_item = _size - 1;
		_menu[_active_item].SetState(ButtonState::FOCUS);
		break;
	case Key::DOWN:
		_menu[_active_item].SetState(ButtonState::IDLE);
		_active_item < _size - 1 ? _active_item++ : _active_item = 0;
		_menu[_active_item].SetState(ButtonState::FOCUS);
		break;
	case Key::ENTER:
		_menu[_active_item].SetState(ButtonState::SELECT);
		//_menu[_active_item].SetState(ButtonState::FOCUS);
		break;
	default:
		break;
	}
}

