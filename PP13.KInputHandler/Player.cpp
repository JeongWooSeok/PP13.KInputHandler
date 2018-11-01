#include "Player.h"
#include "InputHandler.h"

Player::Player(const LoaderParams* pParams) :
	SDLGameObject(pParams)
{
}

void Player::handleInput()
{
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		m_velocity.setX(2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{
		m_velocity.setX(-2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
	{
		m_velocity.setY(-2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
	{
		m_velocity.setY(2);
	}

}

void Player::draw()
{
	SDLGameObject::draw();
}

void Player::update()
{
	//°¡¼Óµµ Áõ°¡·Î ¹«Ã´ »¡¶óÁü
	/*m_acceleration.setX(1);
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
	SDLGameObject::update();*/
	m_velocity.setX(0);
	m_velocity.setY(0);
	handleInput(); // add our function
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
	SDLGameObject::update();

}

void Player::clean()
{
}