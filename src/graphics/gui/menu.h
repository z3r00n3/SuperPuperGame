#pragma once

struct MenuTextData;
class Sprite;
class Text;
class Button;

////-------------!!!-------------BEST PRACTICES------------!!!-------------////
// In private class members the first symbol of names is underscore '_'      //
// This grants us fast understanding about private members when we're        //
// reading/writing                                                           //
//                                                                           //
// Dont use AGK functions in classe's contructors otherwise will be access   //
// error. Use Initialize() method instead constructor                        //
///////////////////////////////////////////////////////////////////////////////

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
