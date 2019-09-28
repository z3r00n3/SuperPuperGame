#pragma once

#include <string>

namespace TextAlignment { enum TextAlignment; };
struct Coords;

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
	float _size;
	std::string _text;
	Coords *_position;
};