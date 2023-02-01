#include "Ruler.h"
#include <iostream>

void Ruler::generate(const sf::RenderWindow& window)
{
	m_background.setFillColor(m_background_color);
	m_background.setSize(sf::Vector2f(window.getSize().x, 200));
	m_background.setOrigin(0, m_background.getLocalBounds().height/2);
	m_background.setPosition(0, window.getSize().y/2);

	recurvise_lines(0, window.getSize().x, 100, 2);
}

void Ruler::display(sf::RenderWindow& window)
{
	window.draw(m_background);
	for (int i = 0; i < m_lines.size(); i++)
		window.draw(m_lines.at(i));
}

void Ruler::backgroundColor(const sf::Color color)
{
	m_background_color = color;
}

void Ruler::lineColor(const sf::Color color)
{
	m_lines_color = color;
}

bool Ruler::recurvise_lines(const double left, const double right, const float line_length, const int iterations)
{
	//Make line
	sf::RectangleShape line(sf::Vector2f(3, line_length));
	line.setFillColor(m_lines_color);
	line.setOrigin(line.getLocalBounds().width/2, 0);

	//find midpoint and set position
	line.setPosition((left + right) / 2, m_background.getPosition().y - (m_background.getLocalBounds().height/2));

	m_lines.push_back(line);

	std::cout << left + (right / 2) << std::endl;

	if (iterations > 0)
	{
		recurvise_lines(left, (left + right) / 2, line_length / 1.5, iterations - 1);
		recurvise_lines((left + right) / 2, right, line_length / 1.5, iterations - 1);
	}

	return true;
}
