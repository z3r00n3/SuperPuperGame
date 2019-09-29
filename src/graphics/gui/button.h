#pragma once

namespace ButtonState { enum ButtonState; };
class Sprite;
class Text;

class Button
{
public:
	// Setters
	void SetPosition(float x, float y);
	void SetState(ButtonState::ButtonState state);

	// Getters

	// Management
	void Initialize(float x,
					float y,
					float width,
					float height,
					std::string name,
					float text_size,
					void(*action)());
	void Update();
	void Action();

private:
	int _img_id_idle;
	int _img_id_focus;
	int _img_id_select;
	Sprite *_sprite;
	Text *_text;
	ButtonState::ButtonState _state;
	void(*_action)();
};