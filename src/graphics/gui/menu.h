#pragma once

struct MenuTextData;
class Sprite;
class Text;
class Button;

class Menu
{
public:
	~Menu()
	{
		//delete [] _menu;
	}

	void Initialize(int menu_size, int active_item, MenuTextData title, MenuTextData note);
	void Update();
	void ButtonActivate();
	void ButtonNext();
	void ButtonLast();

private:
	int _img_id_background;
	int _size;
	int _active_item;
	Sprite *_background;
	Button *_menu;
	Text *_title, *_note;
};
