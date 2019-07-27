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

void Button::Update()
{
	int red = agk::MakeColor(255, 0, 0);
	int green = agk::MakeColor(0, 255, 0);
	int blue = agk::MakeColor(0, 0, 255);
	int middle = agk::MakeColor(127, 127, 127);

	agk::DrawBox(x1, y1, x2, y2, red, green, blue, middle, true);
}

void Menu::Update()
{
	for (int i = 0; i < size; i++)
		btn[i]->Update();
}
