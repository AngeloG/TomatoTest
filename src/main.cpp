#include <cstdio>

#include "MyGame.h"

#include <GLFW/glfw3.h>

int main()
{
	// Initialize GLFW
	if(glfwInit() == GL_FALSE) {
		printf("Failed to initialize GLFW\n");
		return 1;
	}

	// Create a window to host our game in
	TomatoLib::Window* pWindow = new TomatoLib::Window();
	pWindow->Create(1600, 900);

	// Create a game (and catch eventual errors thrown by shader compilation)
	MyGame* pGame = 0;
	try {
		pGame = new MyGame();
		pGame->RenderObject.ScreenSize = pWindow->GetSize();
		pGame->Window = pWindow;
	} catch(const char* error) {
		printf("%s\n", error);
	}

	// Start running the game
	pGame->Run();

	// Clean up
	delete pWindow;
	delete pGame;

	return 0;
}
