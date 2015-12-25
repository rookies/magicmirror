#ifndef _WIDGETMANAGER_HPP_
#define _WIDGETMANAGER_HPP_
#include <SFML/Graphics.hpp>
#include "ClockWidget.hpp"

class WidgetManager {
	public:
		WidgetManager();
		virtual ~WidgetManager();
		void draw(RenderWindow* window);
	private:
		ClockWidget *m_clock;
};
#endif
