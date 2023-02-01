#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Ruler
{
public:
	void generate(const sf::RenderWindow& window);

	void display(sf::RenderWindow& window);

	void backgroundColor(const sf::Color color);
	void lineColor(const sf::Color color);

private:
	sf::Color m_background_color;
	sf::Color m_lines_color;

	sf::RectangleShape m_background;
	std::vector<sf::RectangleShape> m_lines;

	bool recurvise_lines(const double left, const double right, const float line_length, const int iterations);
};

