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

	Button()
	{
		x1 = 100.0f;
		y1 = 100.0f;
		x2 = 860.0f;
		y2 = 440.0f;
		log("Button()");
	};

	Button(float x1, float y1, float x2, float y2) :
		x1(x1), y1(y1), x2(x2), y2(y2)
	{
		log("Button(float x1, float y1, float x2, float y2)");
	};

	void UpdateButton();

private:

};