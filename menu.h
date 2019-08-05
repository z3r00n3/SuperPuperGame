#pragma once

#include <string>

#include "agk.h"
#include "util.h"

////-------------!!!-------------BEST PRACTICE-------------!!!-------------////
// In private class members the first symbol of names is underscore '_'      //
// This grants us fast understanding about private members when we're        //
// reading/writing                                                           //
///////////////////////////////////////////////////////////////////////////////

struct Coords
{
	float x, y;
};

class Sprite
{
public:
	/* // Copy constructor
	Sprite(Sprite const &obj)
	{
		_position.x = obj._position.x;
		_position.y = obj._position.y;
		_width = obj._width;
		_height = obj._height;
	}*/

	// Setters
	//void SetPosition(float x, float y);
	void SetOffset(float x, float y);
	void SetPositionByOffset(float x, float y);
	//void SetDepth(int depth);
	//void SetWidth(...);
	//void SetHeight(...);
	//void SetImage(...);
	
	// Getters
	//int GetImageID();
	int GetID();
	float GetX();
	float GetY();
	float GetWidth();
	float GetHeight();
	//Coords GetPosition();
	//Coords GetPositionByOffset();

	// Management
	void Initialize(float x, float y, float width, float height);
	void DrawBounds(bool fill);

private:
	unsigned int _id;
	unsigned int _img_id;
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
	//void SetText();
	//void SetDepth(int depth);

	// Getters
	int GetID();
	float GetX();
	float GetY();
	float GetSize();
	std::string GetText();

	// Management
	void Initialize(float x, float y, std::string text, float size);

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
	//void SetWidth(float width);
	//void SetHeight(float height);
	void SetFocus(bool focus);
	
	// Getters
	bool GetFocus();
	
	// Management
	void Initialize(float x, float y, float width, float height, std::string name, float text_size, bool focus);
	void Update();

private:
	Sprite _sprite;
	Text _text;
	bool _focus;
};

class Menu
{
public:
	~Menu()
	{
		delete [] _menu;
	}

	void Initialize(int size, int active_item);
	void Update();
	void ChangeFocusButton(Key::Key key);

private:
	int _size;
	Button *_menu;
	int _active_item;
};