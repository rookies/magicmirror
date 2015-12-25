#include "main.hpp"
using namespace std;
using namespace sf;

int main(int argc, char **argv) {
	/*
	 * Supress warnings: (FIXME)
	*/
	argc = 0;
	argv = NULL;
	/*
	 * Create window:
	*/
	RenderWindow window(VideoMode(800,600), "Magic Mirror");
	//RenderWindow window(VideoMode::getDesktopMode(), "Magic Mirror", Style::Fullscreen);
	/*
	 * Load font & set text properties:
	*/
	FontManager::instance()->getFont("data/Ubuntu-B.ttf");
	FontManager::instance()->getFont("data/Ubuntu-B.ttf");
	Text text("xx:xx", *FontManager::instance()->getFont("data/Ubuntu-B.ttf"), 30);
	/*
	 * Event loop:
	*/
	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
				case Event::Closed:
					window.close();
					break;
				default:
					break;
			}
		}
		window.clear();
		window.draw(text);
		window.display();
	}
	return EXIT_SUCCESS;
}
