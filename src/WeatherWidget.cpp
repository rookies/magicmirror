#include "WeatherWidget.hpp"

WeatherWidget::WeatherWidget(const Vector2f &pos, unsigned int size) {
	for (size_t i=0; i < WEATHERWIDGET_ICONS; ++i) {
		m_icons[i].setFont(*FontManager::instance()->getFont("data/Climacons.ttf"));
		m_icons[i].setPosition(pos);
		m_icons[i].setCharacterSize(size);
	}
	m_icons[1].move(Vector2f(100,0));
	m_icons[2].move(Vector2f(200,0));
	m_icons[1].setString(WEATHERWIDGET_ICON_SUNRISE);
	m_icons[2].setString(WEATHERWIDGET_ICON_SUNSET);
}
void WeatherWidget::draw(RenderWindow* window) {
	float t = m_clock.getElapsedTime().asSeconds();
	if (t <= 1) {
		m_icons[0].setString(WEATHERWIDGET_ICON_SUNNY);
	} else if (t > 1 && t <= 2) {
		m_icons[0].setString(WEATHERWIDGET_ICON_CLOUDY);
	} else if (t > 2 && t <= 3) {
		m_icons[0].setString(WEATHERWIDGET_ICON_RAINY);
	} else if (t > 3 && t <= 4) {
		m_icons[0].setString(WEATHERWIDGET_ICON_SNOW);
	} else if (t > 4 && t <= 5) {
		m_icons[0].setString(WEATHERWIDGET_ICON_THUNDERSTORM);
	} else {
		m_clock.restart();
	};
	for (size_t i=0; i < WEATHERWIDGET_ICONS; ++i) {
		window->draw(m_icons[i]);
	}
}
