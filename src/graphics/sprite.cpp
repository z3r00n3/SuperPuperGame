#include "agk.h"
#include "src/graphics/sprite.h"
#include "src/utils/common.h"

Sprite::~Sprite()
{
	delete _position;
	delete _dimensions;
}

// SETTERS

void Sprite::SetOffset(Coords coords)
{
	agk::SetSpriteOffset(_id, coords.x, coords.y);
}

void Sprite::SetPositionByOffset(Coords coords)
{
	_position->x = agk::GetSpriteX(_id);
	_position->y = agk::GetSpriteY(_id);
	
	agk::SetSpritePositionByOffset(_id, coords.x, coords.y);
}

//void Sprite::SetImage(unsigned int img_id)
//{
//	agk::SetSpriteImage(_id, img_id);
//}

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
	return _dimensions->width;
}

float Sprite::GetHeight()
{
	return _dimensions->height;
}

// MANAGEMENT

void Sprite::Initialize(SpriteData data)
{
	_id = agk::CreateSprite(data.img_id);

	_position = new Coords();
	_position->x = data.position.x;
	_position->y = data.position.y;
	agk::SetSpritePosition(_id, data.position.x, data.position.y);

	_dimensions = new Dimensions();
	_dimensions->width  = data.dimensions.width;
	_dimensions->height = data.dimensions.height;
	agk::SetSpriteSize(_id, data.dimensions.width, data.dimensions.height);
}

/*
 * Отрисовывает рамку вокруг спрайта
 * Пока использовалось только для дебага
 * false - рамка не залитая
 * true  - рамка залитая
 */
void Sprite::DrawBounds(bool fill)
{
	agk::DrawBox(_position->x,
				 _position->y,
				 _position->x + _dimensions->width,
				 _position->y + _dimensions->height,
				 // здесь использую литеральные константы
				 agk::MakeColor(255, 0, 0),     // красный
				 agk::MakeColor(0, 255, 0),     // зеленый
				 agk::MakeColor(0, 0, 255),     // синий
				 agk::MakeColor(127, 127, 127), // средний между тремя компонентами цвета
				 fill);
}