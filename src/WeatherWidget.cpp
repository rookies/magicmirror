#include "WeatherWidget.hpp"

WeatherWidget::WeatherWidget(const Vector2f &pos, unsigned int size) {
	for (size_t i=0; i < WEATHERWIDGET_ICONS; ++i) {
		m_icons[i].setFont(*FontManager::instance()->getFont("data/Climacons.ttf"));
		m_icons[i].setPosition(pos);
		m_icons[i].setCharacterSize(size*1.5);
	}
	m_icons[0].move(Vector2f(0,40));
	m_icons[0].setCharacterSize(size*3);
	m_icons[1].move(Vector2f(0,0));
	m_icons[2].move(Vector2f(120,0));
	m_icons[1].setString(WEATHERWIDGET_ICON_SUNRISE);
	m_icons[2].setString(WEATHERWIDGET_ICON_SUNSET);
	for (size_t i=0; i < 2; ++i) {
		m_sunTimes[i].setFont(*FontManager::instance()->getFont("data/Ubuntu-R.ttf"));
		m_sunTimes[i].setPosition(pos);
		m_sunTimes[i].setCharacterSize(size);
	}
	m_sunTimes[0].move(Vector2f(35,5));
	m_sunTimes[1].move(Vector2f(155,5));
	m_sunTimes[0].setString("05:23");
	m_sunTimes[1].setString("20:17");
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
	for (size_t i=0; i < 2; ++i) {
		window->draw(m_sunTimes[i]);
	}
}
