#include "MyGame.h"

MyGame::MyGame()
{
	Window = 0;
}

MyGame::~MyGame()
{
}

void MyGame::Update()
{
}

void MyGame::Draw(TomatoLib::Render &r)
{
	r.Box(100, 100, 100, 100, TomatoLib::Color(255, 255, 255, 255));
	r.DrawOnScreen();
	Window->SwapBuffer();
}
