#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Monster.h"
#include <vector>

using namespace std;

class Game
{
public:
	~Game() {}

	bool init(const char* title, int xpos, int ypos,
		int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool running() { return m_bRunning; }

	static Game* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}

	SDL_Renderer* getRenderer() const { return m_pRenderer; }

private:
	Game() {}

	static Game* s_pInstance;

	std::vector<GameObject*> m_gameObjects;


	SDL_Window * m_pWindow;
	SDL_Renderer* m_pRenderer;
	SDL_Renderer* m_bRenderer;
	
	bool m_bRunning;

};

typedef Game TheGame;