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

	agk::DrawBox(x1, y1, x2, y2, red, green, blue, middle, _focus ? false : true);
}

void Button::SetFocus(bool focus)
{
	_focus = focus;
}

void Menu::Update()
{
	for (int i = 0; i < _size; i++)
		_menu[i]->Update();
}

void Menu::ChangeFocusButton(Keys key)
{
	switch (key)
	{
	case UP:
		if (_active_item > 0)
		{
			_menu[_active_item]->SetFocus(false);
			_active_item--;
			_menu[_active_item]->SetFocus(true);
		}
		else
		{
			_menu[_active_item]->SetFocus(false);
			_active_item = _size - 1;
			_menu[_active_item]->SetFocus(true);
		}
		break;
	case DOWN:
		if (_active_item < _size - 1)
		{
			_menu[_active_item]->SetFocus(false);
			_active_item++;
			_menu[_active_item]->SetFocus(true);
		}
		else
		{
			_menu[_active_item]->SetFocus(false);
			_active_item = 0;
			_menu[_active_item]->SetFocus(true);
		}
		break;
	}
}
