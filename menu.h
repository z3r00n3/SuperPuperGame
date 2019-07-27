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
	float x1, y1, x2, y2; // only for drawing

	Button() {};
	Button(float x1, float y1, float x2, float y2) :
		x1(x1), y1(y1), x2(x2), y2(y2)
	{};

	void Update();

private:

};

class Menu
{
public:
	Menu(size_t size) :
		size(size)
	{
		btn = new Button *[size];
		for (int i = 0; i < size; i++)
			btn[i] = new Button(330, 95 * (i + 1), 630, 95 * (i + 1) + 100);
	}
	~Menu()
	{
		for (int i = 0; i < size; i++)
			delete btn[i];
		delete btn;
	}

	void Update();

private:
	Button **btn;
	size_t size;

};