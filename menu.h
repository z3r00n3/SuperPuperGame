#pragma once

#include <string>

#include "agk.h"
#include "util.h"

////-------------!!!-------------BEST PRACTICES------------!!!-------------////
//                                                                           //
// In private class members the first symbol of names is underscore '_'      //
//                                                                           //
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
	float GetX();
	float GetY();
	float GetWidth();
	float GetHeight();
	//Coords GetPosition();
	//Coords GetPositionByOffset();
	//int GetImageID();
	//int GetID();

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
	//void SetDepth(int depth);
	//void SetAlignment();
	//void SetText();

	// Getters

	// Management
	void Initialize(std::string text, float size, float x, float y);

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
		delete _menu;
	}

	void Initialize(size_t size, int active_item);
	void Update();
	void ChangeFocusButton(Keys key);

private:
	size_t _size;
	Button *_menu;
	int _active_item;
};