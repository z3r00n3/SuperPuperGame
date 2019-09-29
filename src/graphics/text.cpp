#include "agk.h"
#include "src/graphics/text.h"
#include "src/utils/common.h"

using namespace Common;

Text::~Text()
{
	delete _position;
}

// SETTERS

void Text::SetPosition(float x, float y)
{
	agk::SetTextPosition(_id, x, y);

	_position->x = x;
	_position->y = y;
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

void Text::SetAlignment(TextAlignment alignment)
{
	agk::SetTextAlignment(_id, alignment);
}

// GETTERS

int Text::GetID()
{
	return _id;
}

// MANAGEMENT

void Text::Initialize(std::string text, float x, float y, float size)
{
	_text = text;
	_id = agk::CreateText(_text.c_str());

	_size = size;
	SetSize(size);

	_position = new Coords();
	_position->x = x;
	_position->y = y;
	SetPosition(x, y);

	SetColor(255, 255, 255); // Здесь не должно быть значение конкретного цвета, оно должно быть параметрическим
}