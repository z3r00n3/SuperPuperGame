#pragma once

#include "agk.h"
#include "util.h"

////-------------!!!-------------BEST PRACTICES------------!!!-------------////
//                                                                           //
// In private class members the first symbol of names is underscore '_'      //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

struct Coords
{
	float x, y;
};

class Sprite
{
public:
	Sprite(float x, float y, float width, float height)
	{
		_img_id = NULL; // image id is NULL for have a blank sprite

		_position.x = x;
		_position.y = y; 
		
		_width = width;
		_height = height;
	}

	/*Sprite(Sprite const &obj)
	{
		_position.x = obj._position.x;
		_position.y = obj._position.y;
		_width = obj._width;
		_height = obj._height;
	}*/

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
	void Initialize();
	void Delete();
	void DrawBounds(bool fill);

private:
	unsigned int _id;
	unsigned int _img_id;
	float _width, _height;
	Coords _position;
	// Coords _offset;
};

class Button
{
public:
	Button(float x, float y, float width, float height, bool focus)
		: _sprite(new Sprite(x, y, width, height)), _focus(focus)
	{};

	~Button()
	{
		delete _sprite;
	}

	// Setters
	// void SetPosition(float x, float y);
	// void SetWidth(float width);
	// void SetHeight(float height);
	void SetFocus(bool focus);
	
	// Getters
	
	// Other
	void Initialize();
	void Delete();
	void Update();

private:
	Sprite *_sprite;
	bool _focus;

};

class Menu
{
public:
	Menu(size_t size, int active_item)
		: _size(size), _menu(new Button *[_size]), _active_item(active_item)
	{
		for (int i = 0; i < _size; i++)
			_menu[i] = new Button(480.0, 110.0 + 160 * i, 300.0, 100.0, (i == _active_item) ? true : false);
	}

	~Menu()
	{
		for (int i = 0; i < _size; i++)
			delete _menu[i];
		delete _menu;
	}

	void Initialize();
	void Delete();
	void Update();
	void ChangeFocusButton(Keys key);

private:
	size_t _size;
	Button **_menu;
	int _active_item;
};