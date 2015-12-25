#include "main.hpp"
#include <stdio.h>
using namespace std;
using namespace sf;

int main(/*int argc, char **argv*/) {
	/*
	 * Create window:
	*/
	RenderWindow window(VideoMode(800,600), "Magic Mirror");
	/*
	 * Create widget manager:
	*/
	WidgetManager wManager;
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
		wManager.draw(&window);
		window.display();
	}
	return EXIT_SUCCESS;
}
