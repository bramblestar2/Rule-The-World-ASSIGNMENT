#include "Window.h"

Window::Window()
{
	initWindow();

	ruler.backgroundColor(sf::Color(255, 100, 25));
	ruler.lineColor(sf::Color(0, 0, 0));

	iterations = 5;

	ruler.generate(*window, iterations);
}

Window::~Window()
{
	delete window;
}

void Window::run()
{
	while (window->isOpen())
	{
		update();
		updateDt();
		updateSFMLEvents();
		render();
	}
}

void Window::render()
{
	window->clear();
	
	ruler.display(*window);

	window->display();
}

void Window::update()
{
}

void Window::updateDt()
{
	dt = dtClock.restart().asSeconds();
}

void Window::updateSFMLEvents()
{
	while (window->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
				window->close();
				break;
		case sf::Event::KeyPressed:
				switch (event.key.code)
				{
				case sf::Keyboard::Escape:
						window->close();
						break;
				case sf::Keyboard::Left:
					if (iterations > 0)
						iterations--;

					ruler.generate(*window, iterations);
					break;
				case sf::Keyboard::Right:
					iterations++;
					ruler.generate(*window, iterations);
					break;
				}
				break;
		}
	}
}

void Window::initWindow()
{
	window = new sf::RenderWindow(sf::VideoMode(500, 300), "TITLE", sf::Style::Default);
}
