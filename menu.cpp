#include "menu.h"

void Sprite::SetSpritePosition(float x, float y)
{
	agk::SetSpritePosition(_id, x, y);
	
	_position.x = x;
	_position.y = y;
}

void Sprite::SetSpriteOffset(float x, float y)
{
	agk::SetSpriteOffset(_id, x, y);
}

void Sprite::SetSpritePositionByOffset(float x, float y)
{
	agk::SetSpritePositionByOffset(_id, x, y);

	_position.x = x;
	_position.y = y;
}

void Button::UpdateButton()
{
	int red = agk::MakeColor(255, 0, 0);
	int green = agk::MakeColor(0, 255, 0);
	int blue = agk::MakeColor(0, 0, 255);
	int middle = agk::MakeColor(127, 127, 127);

	agk::DrawBox(_top_left.x, _top_left.y, _bottom_right.x, _bottom_right.y, red, green, blue, middle, true);
}

void Menu::UpdateScreen()
{
	button->UpdateButton();
}