#include "menu.h"

///////////////////////////////////////////////////////////////////////////////
// SPRITE
///////////////////////////////////////////////////////////////////////////////

// SETTERS

//void Sprite::SetPosition(float x, float y)
//{
//	agk::SetSpritePosition(_id, x, y);
//	
//	_position.x = x;
//	_position.y = y;
//}

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

//void Sprite::SetDepth(int depth)
//{
//	agk::SetSpriteDepth(_id, depth);
//}

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

void Sprite::Initialize(float x, float y, float width, float height)
{
	_img_id = NULL; // image id is NULL for have a blank sprite
	_id = agk::CreateSprite(_img_id);

	_position.x = x;
	_position.y = y;

	_width = width;
	_height = height;

	agk::SetSpritePosition(_id, x, y);
	agk::SetSpriteSize(_id, width, height);
}

void Sprite::DrawBounds(bool fill)
{
	int red    = agk::MakeColor(255, 0, 0);
	int green  = agk::MakeColor(0, 255, 0);
	int blue   = agk::MakeColor(0, 0, 255);
	int middle = agk::MakeColor(127, 127, 127);

	agk::DrawBox(_position.x, _position.y, _position.x + _width, _position.y + _height, red, green, blue, middle, fill);
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

//void Text::SetDepth(int depth)
//{
//	agk::SetTextDepth(_id, depth);
//}

// GETTERS

// MANAGEMENT

void Text::Initialize(std::string text, float size, float x, float y)
{
	_text = text;
	_id = agk::CreateText(_text.c_str());
	_size = size;
	_position.x = x;
	_position.y = y;

	SetPosition(x, y);
	SetSize(size);
	SetColor(0, 0, 0);
}

///////////////////////////////////////////////////////////////////////////////
// BUTTON
///////////////////////////////////////////////////////////////////////////////

// SETTERS

void Button::SetPosition(float x, float y)
{
	_sprite.SetOffset(_sprite.GetWidth() / 2, _sprite.GetHeight() / 2);
	_sprite.SetPositionByOffset(x, y);
}

void Button::SetFocus(bool focus)
{
	_focus = focus;
}

// MANAGEMENT

void Button::Initialize(float x, float y, float width, float height, std::string name, float text_size, bool focus)
{
	_sprite.Initialize(x, y, width, height);
	_text.Initialize(name, text_size, x, y);

	SetPosition(_sprite.GetX(), _sprite.GetY());
}

void Button::Update()
{
	_sprite.DrawBounds(_focus ? true : false);
}

///////////////////////////////////////////////////////////////////////////////
// MENU
///////////////////////////////////////////////////////////////////////////////

void Menu::Initialize(size_t size, int active_item)
{
	_menu = new Button[3];
//	for (int i = 0; i < _size; i++)
//		_menu[i]->Initialize(std::string("button #") + std::to_string(i), 30, 600, 110 + 160 * i);
}

void Menu::Update()
{
	for (int i = 0; i < _size; i++)
		_menu[i]->Update();
}

void Menu::ChangeFocusButton(Keys key)
{
	switch (key)
	{
	case UP:
		if (_active_item > 0)
		{
			_menu[_active_item]->SetFocus(false);
			_active_item--;
			_menu[_active_item]->SetFocus(true);
		}
		else
		{
			_menu[_active_item]->SetFocus(false);
			_active_item = static_cast<int>(_size) - 1;
			_menu[_active_item]->SetFocus(true);
		}
		break;
	case DOWN:
		if (_active_item < _size - 1)
		{
			_menu[_active_item]->SetFocus(false);
			_active_item++;
			_menu[_active_item]->SetFocus(true);
		}
		else
		{
			_menu[_active_item]->SetFocus(false);
			_active_item = 0;
			_menu[_active_item]->SetFocus(true);
		}
		break;
	default:
		break;
	}
}

