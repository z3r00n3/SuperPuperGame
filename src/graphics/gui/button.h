#pragma once

//namespace ButtonState { enum ButtonState; };
struct Coords;
struct ButtonData;
class Sprite;
class Text;

class Button
{
public:
	~Button();

	// Setters
	void SetPosition(Coords coords);//???пересмотреть позиционирование
	//void SetState(ButtonState::ButtonState state);

	// Getters

	// Management
	void Initialize(ButtonData data);
	void Update();//???
	void Action();//???

private:
	unsigned int _img_id_idle;//?
	unsigned int _img_id_focus;//?
	unsigned int _img_id_select;//?
	Sprite *_sprite;
	Text *_text;
	//ButtonState::ButtonState _state;
	void(*_action)();
};