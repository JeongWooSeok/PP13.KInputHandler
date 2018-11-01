#include "Monster.h"

Monster::Monster(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}

void Monster::draw()
{
	SDLGameObject::draw();
}

void Monster::update()
{
	/*if (this->m_textureID == "mob1")
		control(1.0f, 0.0f, int(((SDL_GetTicks() / 100) % 1)));
	else if (this->m_textureID == "mob2")
		control(2.0f, 0.0f, int(((SDL_GetTicks() / 20) % 1)));*/ //지우

}

void Monster::clean()
{
}

void Monster::control(float m_x, float m_y, int currentFrame)
{
	//몬스터 왕복코드
	if (this->m_position.getX() >= 0 && this->m_position.getX() < 100 && goR == true)
	{
		this->m_position.setX(m_position.getX() + m_x);

		if (this->m_position.getX() == 100)
		{
			goR = false;
		}
	}
	else if (goR == false)
	{
		this->m_position.setX(m_position.getX() - m_x);

		if (this->m_position.getX() == 0)
		{
			goR = true;
		}
	}

	//프레임 수 제어
	m_currentFrame = currentFrame;
}