//
//acodemia.pl
//

#ifndef H_BULLET_ACODEMIA
#define H_BULLET_ACODEMIA

#include "SFML/Graphics.hpp"
///
///Klasa reprezentje pocisk
///
class Bullet
{
public:
	Bullet();
	~Bullet();
	virtual void draw(sf::RenderWindow & render);
	void Load(const sf::Texture & texture);

private:
	
	sf::Sprite m_sprite;
	float m_speed;
	sf::Vector2f m_position;
};

#endif//H_BULLET_ACODEMIA