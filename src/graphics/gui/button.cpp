#include "agk.h"
#include "src/graphics/gui/button.h"
#include "src/utils/common.h"
#include "src/graphics/sprite.h"
#include "src/graphics/text.h"

using namespace Common;

// SETTERS

void Button::SetPosition(float x, float y)
{
	_sprite->SetOffset(_sprite->GetWidth() / 2, _sprite->GetHeight() / 2);
	_sprite->SetPositionByOffset(x, y);

	_text->SetPosition(x, y - agk::GetTextTotalHeight(_text->GetID()) / 2);
}

void Button::SetState(ButtonState state)
{
	switch (state)
	{
	case ButtonState::IDLE:
		_state = state;
		_sprite->SetImage(_img_id_idle);
		break;
	case ButtonState::FOCUS:
		_state = state;
		_sprite->SetImage(_img_id_focus);
		break;
	case ButtonState::SELECT:
		_state = state;
		_sprite->SetImage(_img_id_select);
		break;
	default:
		break;
	}
}

// GETTERS

// MANAGEMENT

void Button::Initialize(float x,
	float y,
	float width,
	float height,
	std::string name,
	float text_size,
	void(*action)())
{
	_img_id_idle = agk::LoadImage(BUTTON_IDLE_IMAGE, false);
	_img_id_focus = agk::LoadImage(BUTTON_FOCUS_IMAGE, false);
	_img_id_select = agk::LoadImage(BUTTON_SELECT_IMAGE, false);

	_sprite = new Sprite();
	_sprite->Initialize(_img_id_idle, x, y, width, height);

	_text = new Text();
	_text->Initialize(name, x, y, text_size);
	_text->SetAlignment(TextAlignment::CENTER);

	_action = action;

	SetPosition(_sprite->GetX(), _sprite->GetY());
}

void Button::Update()
{
	//_sprite.DrawBounds(false);
}

void Button::Action()
{
	_action();
}