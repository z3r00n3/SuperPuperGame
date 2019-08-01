#pragma once

#include "agk.h"
#include "util.h"

////-------------!!!-------------BEST PRACTICES------------!!!-------------////
//                                                                           //
// In private class members the first symbol of names is underscore '_'      //
//                                                                           //
// Constructor's parameter's names must have same names like private members //
// that they initialising                                                    //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

struct Coords
{
	float x, y;
};

class Sprite
{
public:
	Sprite(float _x, float _y, float _width, float _height)
	{
		_id = agk::CreateSprite(NULL); // image id is NULL for have a blank sprite
		
		agk::SetSpritePosition(_id, _x, _y);
		_position.x = _x;
		_position.y = _y;
		
		agk::SetSpriteSize(_id, _width, _height);
		this->_width = _width;
		this->_height = _height;
	}
	~Sprite()
	{
		agk::DeleteSprite(_id);
	}

	// Setters
	// void SetPosition(float x, float y);
	void SetOffset(float x, float y);
	void SetPositionByOffset(float x, float y);
	// void SetWidth(...);
	// void SetHeight(...);
	// void SetImage(...);
	
	// Getters
	// float GetWidth();
	// float GetHeight();
	// Coords GetPosition();
	// Coords GetPositionByOffset();
	// int GetImageID();
	// int GetID();

	// Other
	void DrawBounds(bool fill);

private:
	int _id;
	// int _img_id;
	float _width, _height;
	Coords _position;
	// Coords _offset;
};

class Button
{
public:

	Button(float x, float y, float width, float height, bool focus)
	{
		_sprite = Sprite();
	}

	// Setters
	// void SetPosition(float x, float y);
	// void SetWidth(float width);
	// void SetHeight(float height);
	void SetFocus(bool focus);
	
	// Getters
	
	// Other
	void Update();

private:
	Sprite _sprite;
	bool _focus;

};

class Menu
{
public:
	Menu(size_t _size, int _active_item) :
		_size(_size), _active_item(_active_item)
	{
		_menu = new Button *[_size];
		for (int i = 0; i < _size; i++)
			_menu[i] = new Button(330, 95 * (i + 1) + i * 30, 630, 95 * (i + 1) + 100 + i * 30, (i == _active_item) ? true : false);
	}
	~Menu()
	{
		for (int i = 0; i < _size; i++)
			delete _menu[i];
		delete _menu;
	}

	void Update();
	void ChangeFocusButton(Keys key);

private:
	Button **_menu;
	size_t _size;
	int _active_item;

};