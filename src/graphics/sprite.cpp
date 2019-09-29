#include "agk.h"
#include "src/graphics/sprite.h"
#include "src/utils/common.h"

Sprite::~Sprite()
{
	delete _position;
}

// SETTERS

void Sprite::SetOffset(float x, float y)
{
	agk::SetSpriteOffset(_id, x, y);
}

void Sprite::SetPositionByOffset(float x, float y)
{
	agk::SetSpritePositionByOffset(_id, x, y);

	_position->x = agk::GetSpriteX(_id);
	_position->y = agk::GetSpriteY(_id);
}

void Sprite::SetImage(int img_id)
{
	agk::SetSpriteImage(_id, img_id);
}

// GETTERS

float Sprite::GetX()
{
	return _position->x;
}

float Sprite::GetY()
{
	return _position->y;
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

	_position = new Coords();
	_position->x = x;
	_position->y = y;
	agk::SetSpritePosition(_id, x, y);

	_width = width;
	_height = height;
	agk::SetSpriteSize(_id, width, height);
}

void Sprite::DrawBounds(bool fill)
{
	int red = agk::MakeColor(255, 0, 0);
	int green = agk::MakeColor(0, 255, 0);
	int blue = agk::MakeColor(0, 0, 255);
	int middle = agk::MakeColor(127, 127, 127);

	agk::DrawBox(_position->x,
				 _position->y,
				 _position->x + _width,
				 _position->y + _height,
				 red,
				 green,
				 blue,
				 middle,
				 fill);
}