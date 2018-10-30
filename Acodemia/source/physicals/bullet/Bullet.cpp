//acodemia.pl


#include "Bullet.h"

Bullet::Bullet():
	m_sprite()
{
	m_sprite.setPosition(50, 50);
}

Bullet::~Bullet()
{
}

//Wirtualna metoda renderująca obiekt
void Bullet::draw(sf::RenderWindow & render)
{
	render.draw(m_sprite);
}

void Bullet::Load(const sf::Texture & texture)
{
	m_sprite.setTexture(texture);
}
