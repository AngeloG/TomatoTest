#ifndef MYGAME_H_INCLUDED
#define MYGAME_H_INCLUDED

#include <Game/Game.h>
#include <Game/Window.h>

class MyGame : public TomatoLib::Game
{
public:
	TomatoLib::Window* Window;
	TomatoLib::Vector2 BoxPosition;
	TomatoLib::Vector2 BoxVelocity;

	TomatoLib::Font Font;

public:
	MyGame();
	~MyGame();

	virtual void Init();
	virtual void Update();
	virtual void Draw(TomatoLib::Render& r);
};

#endif
