#ifndef _CLOCKWIDGET_HPP_
#define _CLOCKWIDGET_HPP_
#include <time.h>
#include <SFML/Graphics.hpp>
#include "FontManager.hpp"

class ClockWidget {
	public:
		ClockWidget(const Vector2f &pos, unsigned int size);
		void draw(RenderWindow* window);
	private:
		Text m_text;
};
#endif
