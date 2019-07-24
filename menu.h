#pragma once

#include "agk.h"

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
	Button(float x1, float y1, float x2, float y2)
	{
		_top_left.x = x1;
		_top_left.y = y1;
		_bottom_right.x = x2;
		_bottom_right.y = y2;
	}

	void UpdateButton();

private:
	Coords _top_left, _bottom_right; // only for drawing
	Sprite _sprite;
};

class Menu
{
public:
	Button *button;
	Menu()
	{
		button = new Button(270, 480, 415, 720);
	};

	void UpdateScreen();
	
private:

};