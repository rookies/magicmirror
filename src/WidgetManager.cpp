#include "WidgetManager.hpp"
using namespace sf;

WidgetManager::WidgetManager() {
	m_clock = new ClockWidget(Vector2f(10,10), 50);
}
WidgetManager::~WidgetManager() {
	delete m_clock;
}
void WidgetManager::draw(RenderWindow* window) {
	m_clock->draw(window);
}
