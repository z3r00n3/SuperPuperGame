#pragma once

#include <string>

#include "agk.h"
#include "util.h"

////-------------!!!-------------BEST PRACTICES------------!!!-------------////
// In private class members the first symbol of names is underscore '_'      //
// This grants us fast understanding about private members when we're        //
// reading/writing                                                           //
//                                                                           //
// Dont use AGK functions in classe's contructors otherwise will be access   //
// error. Use Initialize() method instead constructor                        //
///////////////////////////////////////////////////////////////////////////////

class Sprite
{
public:
	// Setters
	void SetOffset(float x, float y);
	void SetPositionByOffset(float x, float y);
	void SetImage(int img_id);
	void SetVisible(bool visible);
	
	// Getters
	float GetX();
	float GetY();
	float GetWidth();
	float GetHeight();

	// Management
	void Initialize(int img_id, float x, float y, float width, float height);
	void DrawBounds(bool fill);

private:
	unsigned int _id;
	float _width, _height;
	Coords _position;
};

class Text
{
public:
	// Setters
	void SetPosition(float x, float y);
	void SetSize(float size);
	void SetColor(unsigned int red, unsigned int green, unsigned int blue);
	void SetAlignment(TextAlignment::TextAlignment alignment);

	// Getters
	int GetID();

	// Management
	void Initialize(std::string text, float x, float y, float size);

private:
	unsigned int _id;
	std::string _text;
	float _size;
	Coords _position;
};

class Button
{
public:
	// Setters
	void SetPosition(float x, float y);
	void SetState(ButtonState::ButtonState state);
	
	// Getters
	
	// Management
	void Initialize(float x, float y, float width, float height, std::string name, float text_size);
	void Update();

private:
	int _img_id_idle;
	int _img_id_focus;
	int _img_id_select;
	Sprite _sprite;
	Text _text;
	ButtonState::ButtonState _state;
};

class Menu
{
public:
	~Menu()
	{
		delete [] _menu;
	}

	void Initialize(int menu_size, int active_item, MenuTextData title, MenuTextData note);
	void Update();
	void InputHandler(Key::Key key);

private:
	int _img_id_background;
	Sprite _background;
	int _size;
	Button *_menu;
	int _active_item;
	Text _title, _note;
};