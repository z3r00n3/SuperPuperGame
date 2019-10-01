#pragma once

struct Coords;
struct TextData;

class Text
{
public:
	// Setters
	void SetPosition(Coords coords);//???пересмотреть позиционирование

	// Getters
	int GetID();

	// Management
	void Initialize(TextData data);

private:
	unsigned int _id;
};