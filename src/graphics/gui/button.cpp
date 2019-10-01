#include "agk.h"
#include "src/graphics/gui/button.h"
#include "src/utils/common.h"
#include "src/graphics/sprite.h"
#include "src/graphics/text.h"

Button::~Button()
{
	delete _sprite;
	delete _text;
}

// SETTERS

void Button::SetPosition(Coords coords)
{
	_sprite->SetOffset({ _sprite->GetWidth() / 2, _sprite->GetHeight() / 2 });
	_sprite->SetPositionByOffset(coords);

	_text->SetPosition({ coords.x, coords.y - agk::GetTextTotalHeight(_text->GetID()) / 2 });
}

//void Button::SetState(ButtonState::ButtonState state)
//{
//	_state = state;
//	
//	switch (state)
//	{
//	case ButtonState::IDLE:
//		_sprite->SetImage(_img_id_idle);
//		break;
//	case ButtonState::FOCUS:
//		_sprite->SetImage(_img_id_focus);
//		break;
//	case ButtonState::SELECT:
//		_sprite->SetImage(_img_id_select);
//		break;
//	default:
//		break;
//	}
//}

// GETTERS

// MANAGEMENT

void Button::Initialize(ButtonData data)
{
	_img_id_idle   = agk::LoadImage(data.img_idle, false);
	_img_id_focus  = agk::LoadImage(data.img_focus, false);
	_img_id_select = agk::LoadImage(data.img_select, false);

	_sprite = new Sprite();
	_sprite->Initialize({ _img_id_idle, data.position, data.dimensions });

	_text = new Text();
	_text->Initialize({ data.label });

	_action = data.action;

	/*
	 * важно, чтобы вызов SetPosition() был после создания и инициализации
	 * спрайта и текста, так как, в свою очередь, этод метод задает новую
	 * позицию для спрайта и текста
	 */
	SetPosition({ _sprite->GetX(), _sprite->GetY() });
}

void Button::Update()
{
	//_sprite.DrawBounds(false);
}

void Button::Action()
{
	_action();
}