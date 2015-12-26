#include "WidgetManager.hpp"
using namespace sf;

WidgetManager::WidgetManager() {
	m_clock = new ClockWidget(Vector2f(10,10), 50);
	m_weather = new WeatherWidget(Vector2f(10,120), 25);
}
WidgetManager::~WidgetManager() {
	delete m_clock;
	delete m_weather;
}
void WidgetManager::draw(RenderWindow* window) {
	m_clock->draw(window);
	m_weather->draw(window);
	RectangleShape line(Vector2f(780, 5));
	line.setPosition(Vector2f(10,100));
	window->draw(line);
}
