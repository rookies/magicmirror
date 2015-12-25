#include "ClockWidget.hpp"

ClockWidget::ClockWidget(const Vector2f &pos, unsigned int size) {
	m_text.setFont(*FontManager::instance()->getFont("data/Ubuntu-B.ttf"));
	m_text.setPosition(pos);
	m_text.setCharacterSize(size);
}
void ClockWidget::draw(RenderWindow* window) {
	time_t t = time(0);
	struct tm* now = localtime(&t);
	char buf[9];
	snprintf(buf, sizeof(buf), "%0.2d:%0.2d:%0.2d", now->tm_hour, now->tm_min, now->tm_sec);
	m_text.setString(buf);
	window->draw(m_text);
}
