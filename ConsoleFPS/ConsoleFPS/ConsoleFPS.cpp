
#include <iostream>
#include "ConsoleGameEngine.h"

class ConsoleFPS : public ConsoleGameEngine
{
public:
	ConsoleFPS()
	{

	}
protected:
	virtual bool Start()
	{
		playerX = 20.0f;
		playerY = 20.f;
		return true;
	}
	virtual bool Update(float elapsedTime)
	{
		if (keys[VK_LEFT].onHeld)
			playerX -= 10.0f * elapsedTime;
		if (keys[VK_RIGHT].onHeld)
			playerX += 10.0f * elapsedTime;
		if (keys[VK_UP].onHeld)
			playerY -= 10.0f * elapsedTime;
		if (keys[VK_DOWN].onHeld)
			playerY += 10.0f * elapsedTime;
		
		Fill(0, 0, windowWidth, windowHeight, L' ', 0);
		Fill((int)playerX, (int)playerY, (int)playerX + 5, (int)playerY + 5);
		return true;
	}

private:
	float playerX;
	float playerY;
};

int main()
{
	ConsoleFPS game;
	game.ConstructConsole(160, 100, 8, 8);
	game.StartThread();

}