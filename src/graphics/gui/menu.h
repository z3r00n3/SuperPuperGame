#pragma once

struct MenuData;
class Sprite;
class Text;
class Button;

class Menu
{
public:
	~Menu();

	void Initialize(MenuData menu);
	void Update();//?
	void ButtonActivate();
	void ButtonNext();
	void ButtonLast();

private:
	int _num_of_items;
	int _active_item;
	Sprite *_background;
	Button *_menu;
	Text *_title, *_note;
};
