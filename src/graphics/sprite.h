#pragma once

struct Coords;
struct Dimensions;
struct SpriteData;

class Sprite
{
public:
	~Sprite();

	// Setters
	void SetOffset(Coords coords);//???пересмотреть позиционирование
	void SetPositionByOffset(Coords coords);//???
	//???void SetImage(unsigned int img_id);

	// Getters
	float GetX();
	float GetY();
	float GetWidth();
	float GetHeight();

	// Management
	void Initialize(SpriteData data);
	void DrawBounds(bool fill); // Отрисовывает рамку вокруг спрайта

private:
	unsigned int _id;
	Dimensions *_dimensions;
	Coords *_position;
};