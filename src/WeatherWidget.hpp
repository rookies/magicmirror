#ifndef _WEATHERWIDGET_HPP_
#define _WEATHERWIDGET_HPP_
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "FontManager.hpp"
#define WEATHERWIDGET_ICONS 3
#define WEATHERWIDGET_ICON_SUNNY "I"
#define WEATHERWIDGET_ICON_CLOUDY "\""
#define WEATHERWIDGET_ICON_RAINY "$"
#define WEATHERWIDGET_ICON_SNOW "9"
#define WEATHERWIDGET_ICON_THUNDERSTORM "F"
#define WEATHERWIDGET_ICON_SUNRISE "K"
#define WEATHERWIDGET_ICON_SUNSET "J"

class WeatherWidget {
	public:
		WeatherWidget(const Vector2f &pos, unsigned int size);
		void draw(RenderWindow* window);
	private:
		Text m_icons[WEATHERWIDGET_ICONS];
		Text m_sunTimes[2];
		Clock m_clock;
};
#endif
