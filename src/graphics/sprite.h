#pragma once

struct Coords;

class Sprite
{
public:
	~Sprite();

	// Setters
	void SetOffset(float x, float y);
	void SetPositionByOffset(float x, float y);
	void SetImage(int img_id);

	// Getters
	float GetX();
	float GetY();
	float GetWidth();
	float GetHeight();

	// Management
	void Initialize(int img_id, float x, float y, float width, float height);
	void DrawBounds(bool fill); // Для дебага

private:
	unsigned int _id;
	float _width, _height;
	Coords *_position;
};