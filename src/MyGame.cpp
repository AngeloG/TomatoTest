#include "MyGame.h"

MyGame::MyGame()
{
	Window = 0;
}

MyGame::~MyGame()
{
}

void MyGame::Init()
{
	Font.Load("../content/Roboto-Regular.ttf", 12);
}

void MyGame::Update()
{
	Window->PollEvents();

	if(Window->KeysIn[GLFW_KEY_ESCAPE] != 0) {
		Quit();
	}

	float fAcceleration = 0.25f;
	float fMaxSpeed = 6.0f;
	float fDeceleration = 0.95f;

	if(Window->KeysIn[GLFW_KEY_A] != 0) {
		BoxVelocity.X -= fAcceleration;
	} else if(Window->KeysIn[GLFW_KEY_D] != 0) {
		BoxVelocity.X += fAcceleration;
	}

	if(Window->KeysIn[GLFW_KEY_W] != 0) {
		BoxVelocity.Y -= fAcceleration;
	} else if(Window->KeysIn[GLFW_KEY_S] != 0) {
		BoxVelocity.Y += fAcceleration;
	}

	if(BoxVelocity.Length() > fMaxSpeed) {
		BoxVelocity = BoxVelocity.Normalized() * fMaxSpeed;
	}

	BoxVelocity *= fDeceleration;
	BoxPosition += BoxVelocity;
}

void MyGame::Draw(TomatoLib::Render &r)
{
	for(int i=255; i>=0; i--) {
		float fScale = i / 255.0f;
		TomatoLib::Vector2 vPos = BoxPosition * fScale;
		r.Box(vPos.X, vPos.Y, 100.0f * (1.0f + fScale * 2.0f), 100.0f * (1.0f + fScale * 2.0f), TomatoLib::Color(i, 255-i, i, 255));
	}
	r.Box(BoxPosition.X + 100.0f, BoxPosition.Y + 100.0f, 100.0f, 100.0f, TomatoLib::Color(255, 255, 255, 255));
	r.Text(&Font, "Use W,A,S,D", 10, 10, TomatoLib::Color(0, 0, 0, 255));
	r.DrawOnScreen();
	Window->SwapBuffer();
}
