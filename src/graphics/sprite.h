#pragma once

struct Coords;
struct Dimensions;
struct SpriteData;

class Sprite
{
public:
	~Sprite();

	// Setters
	void SetOffset(Coords coords);//???������������ ����������������
	void SetPositionByOffset(Coords coords);//???
	//???void SetImage(unsigned int img_id);

	// Getters
	float GetX();
	float GetY();
	float GetWidth();
	float GetHeight();

	// Management
	void Initialize(SpriteData data);
	void DrawBounds(bool fill); // ������������ ����� ������ �������

private:
	unsigned int _id;
	Dimensions *_dimensions;
	Coords *_position;
};