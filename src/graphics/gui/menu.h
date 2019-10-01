#pragma once

struct MenuTextData;
class Sprite;
class Text;
class Button;

class Menu
{
public:
	~Menu();

	void Initialize(MenuData menu);
	void Update();
	void ButtonActivate();
	void ButtonNext();
	void ButtonLast();

private:
	int _size;
	int _active_item;
	Sprite *_background;
	Button *_menu;
	Text *_title, *_note;
};
