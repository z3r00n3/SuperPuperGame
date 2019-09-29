#pragma once

/*
 * «десь подключаетс€ хедер, так как предварительное объ€вление не поможет,
 * ибо необходим полный тип, чтобы далее можно было сделать вызов методов
 * объекта, хран€щегос€ по указателю menu, а создавать ради этого целый
 * файл реализации... пока не возникло необходимости
*/
#include "src/graphics/gui/menu.h"

class Command
{
public:
	virtual ~Command() {};
	virtual void Execute(Menu *menu) = 0;
};

class ButtonActivate : public Command
{
public:
	virtual void Execute(Menu *menu) { menu->ButtonActivate(); }
};

class ButtonNext : public Command
{
public:
	virtual void Execute(Menu *menu) { menu->ButtonNext(); }
};

class ButtonLast : public Command
{
public:
	virtual void Execute(Menu *menu) { menu->ButtonLast(); }
};