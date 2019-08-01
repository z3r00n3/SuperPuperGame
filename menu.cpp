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

void Sprite::Initialize()
{
	_id = agk::CreateSprite(_img_id);
	agk::SetSpritePosition(_id, _position.x, _position.y);
	agk::SetSpriteSize(_id, _width, _height);
}

void Sprite::Delete()
{
	agk::DeleteSprite(_id);
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
// BUTTON
///////////////////////////////////////////////////////////////////////////////

// SETTERS

void Button::SetPosition(float x, float y)
{
	_sprite->SetOffset(_sprite->GetWidth() / 2, _sprite->GetHeight() / 2);
	_sprite->SetPositionByOffset(x, y);
}

void Button::SetFocus(bool focus)
{
	_focus = focus;
}

// MANAGEMENT

void Button::Initialize()
{
	_sprite->Initialize();

	SetPosition(_sprite->GetX(), _sprite->GetY());
}

void Button::Delete()
{
	_sprite->Delete();
}

void Button::Update()
{
	_sprite->DrawBounds(_focus ? true : false);
}

///////////////////////////////////////////////////////////////////////////////
// MENU
///////////////////////////////////////////////////////////////////////////////

void Menu::Initialize()
{
	for (int i = 0; i < _size; i++)
		_menu[i]->Initialize();
}

void Menu::Delete()
{
	for (int i = 0; i < _size; i++)
		_menu[i]->Delete();
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
