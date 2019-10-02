#include "agk.h"
#include "src/graphics/text.h"
#include "src/utils/common.h"

// SETTERS

void Text::SetPosition(Coords coords)
{
	agk::SetTextPosition(_id, coords.x, coords.y);
}

// GETTERS

int Text::GetID()
{
	return _id;
}

// MANAGEMENT

void Text::Initialize(TextData data)
{
	_id = agk::CreateText(data.text.c_str());

	agk::SetTextPosition(_id, data.coords.x, data.coords.y);
	agk::SetTextSize(_id, data.size);
	agk::SetTextAlignment(_id, data.alignment);
	agk::SetTextColor(_id, data.color.red, data.color.green, data.color.blue);
}