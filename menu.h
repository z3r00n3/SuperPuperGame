#pragma once

#include "agk.h"
#include "util.h"

// IN PRIVATE CLASS MEMBERS THE FIRST SYMBOL OF NAMES IS UNDERSCORE '_'

struct Coords
{
	float x, y;
};

class Sprite
{
public:
	Sprite() :
		_id(_id), _img_id(_img_id), _width(_width), _height(_height)
	{}

	// Setters
	void SetSpritePosition(float x, float y);
	void SetSpriteOffset(float x, float y);
	void SetSpritePositionByOffset(float x, float y);
	// void SetSpriteWidth(...);
	// void SetSpriteHeight(...);
	// void SetSpriteImage(...);
	
	// Getters
	// Coords GetSpritePosition();
	// Coords GetSpritePositionByOffset();
	// float GetSpriteWidth();
	// float GetSpriteHeight();
	// int GetImageID();
	// int GetID();

private:
	int _id;
	int _img_id;
	float _width, _height;
	Coords _position;
	//???Coords _offset;
};

class Button
{
public:

	Button() {};
	Button(float x1, float y1, float x2, float y2, bool _focused = false) :
		x1(x1), y1(y1), x2(x2), y2(y2), _focused(_focused)
	{};

	void Update();

private:
	float x1, y1, x2, y2; // only for drawing

	bool _focused;

};

class Menu
{
public:
	Menu(size_t _size, int _active_item) :
		_size(_size), _active_item(_active_item)
	{
		_btn = new Button *[_size];
		for (int i = 0; i < _size; i++)
			_btn[i] = new Button(330, 95 * (i + 1) + i * 30, 630, 95 * (i + 1) + 100 + i * 30, (i == _active_item) ? true : false);
	}
	~Menu()
	{
		for (int i = 0; i < _size; i++)
			delete _btn[i];
		delete _btn;
	}

	void Update();
	void ChangeFocusButton(Keys key);

private:
	Button **_btn;
	size_t _size;
	int _active_item;

};