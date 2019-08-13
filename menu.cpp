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

void Sprite::SetImage(int img_id)
{
	agk::SetSpriteImage(_id, img_id);
}

void Sprite::SetVisible(bool visible)
{
	agk::SetSpriteVisible(_id, visible);
}

// GETTERS

int Sprite::GetID()
{
	return _id;
}

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

void Text::SetAlignment(TextAlignment::TextAlignment alignment)
{
	agk::SetTextAlignment(_id, alignment);
}

//void Text::SetDepth(int depth)
//{
//	agk::SetTextDepth(_id, depth);
//}

// GETTERS

int Text::GetID()
{
	return _id;
}

float Text::GetX()
{
	return _position.x;
}

float Text::GetY()
{
	return _position.y;
}

float Text::GetSize()
{
	return _size;
}

std::string Text::GetText()
{
	return _text;
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

	_text.SetPosition(x, y - agk::GetTextTotalHeight(_text.GetID()) / 2);
}

void Button::SetFocus(bool focus)
{
	_focus = focus;
}

// GETTERS

bool Button::GetFocus()
{
	return _focus;
}

// MANAGEMENT

void Button::Initialize(float x, float y, float width, float height, /*std::string image, */std::string name, float text_size, bool focus)
{
	_focus = focus;

	_img_id_idle   = agk::LoadImage("..\\media\\images\\buttons\\idle.png");
	_img_id_focus  = agk::LoadImage("..\\media\\images\\buttons\\focus.png");
	_img_id_select = agk::LoadImage("..\\media\\images\\buttons\\select.png");
	DbgLog(std::to_string(_img_id_idle).c_str());
	DbgLog(std::to_string(_img_id_focus).c_str());
	DbgLog(std::to_string(_img_id_select).c_str());
	_sprite.Initialize(focus ? _img_id_focus : _img_id_idle, x, y, width, height);

	_text.Initialize(x, y, name, text_size);
	_text.SetAlignment(TextAlignment::CENTER);
	
	SetPosition(_sprite.GetX(), _sprite.GetY());
}

void Button::Update()
{	
	//_sprite.SetImage(_focus ? _img_id_focus : _img_id_idle); // need rework, it's bad idea
	// to call load image function every frame even if the button's state didn't chang

	_sprite.DrawBounds(false);
}

///////////////////////////////////////////////////////////////////////////////
// MENU
///////////////////////////////////////////////////////////////////////////////

void Menu::Initialize(int size, int active_item)
{
	_menu = new Button[3];
	for (int i = 0; i < size; i++)
		_menu[i].Initialize(480, 110 + 160 * i, 300, 100, std::string("button #") + std::to_string(i), 30, i == _active_item ? true : false);

	_size = size;
	_active_item = active_item;
}

void Menu::Update()
{
	for (int i = 0; i < _size; i++)
		_menu[i].Update();
}

void Menu::ChangeFocusButton(Key::Key key)
{
	switch (key)
	{
	case Key::UP:
		if (_active_item > 0)
		{
			_menu[_active_item].SetFocus(false);
			_active_item--;
			_menu[_active_item].SetFocus(true);
		}
		else
		{
			_menu[_active_item].SetFocus(false);
			_active_item = _size - 1;
			_menu[_active_item].SetFocus(true);
		}
		break;
	case Key::DOWN:
		if (_active_item < _size - 1)
		{
			_menu[_active_item].SetFocus(false);
			_active_item++;
			_menu[_active_item].SetFocus(true);
		}
		else
		{
			_menu[_active_item].SetFocus(false);
			_active_item = 0;
			_menu[_active_item].SetFocus(true);
		}
		break;
	default:
		break;
	}
}

