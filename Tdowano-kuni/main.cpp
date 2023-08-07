#include <iostream>

#include <SFML/Graphics.hpp>

//const unsigned int WINDOW_WIDTH = 1920;
//const unsigned int WINDOW_HEIGHT = 1080;
const unsigned int WINDOW_WIDTH = 512;
const unsigned int WINDOW_HEIGHT = 512;
const sf::Color BACKGROUND_COLOR = sf::Color(100, 100, 100);

int main() {
	// init window
	sf::VideoMode vm(WINDOW_WIDTH, WINDOW_HEIGHT);
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
		"Samurai",
		//sf::Style::Fullscreen);
		sf::Style::Close | sf::Style::Resize);
	sf::View view(sf::FloatRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT));
	window.setView(view);

	sf::Texture testTexture;
	testTexture.loadFromFile("graphics/Samurai/Idle.png");

	unsigned int currentFrame = 0;
	unsigned int realFrame = 0;

	sf::Sprite testSprite;
	testSprite.setTexture(testTexture);

	// game loop
	while (window.isOpen())
	{
		testSprite.setTextureRect(sf::IntRect(sf::Vector2i(testTexture.getSize().x / 6 * realFrame,
			testTexture.getSize().y * 0),
			sf::Vector2i(testTexture.getSize().x / 6,
				testTexture.getSize().y)));

		// keyboard events
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			testSprite.move(-1.0f, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			testSprite.move(1.0f, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			realFrame = ++currentFrame % 6;
			std::cout << "Current Frame = " << realFrame << std::endl;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}
		window.clear(BACKGROUND_COLOR);
		window.draw(testSprite);
		window.display();
	}
}