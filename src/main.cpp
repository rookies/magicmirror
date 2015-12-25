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
	 * Create widgets:
	*/
	ClockWidget clock(Vector2f(10,10), 50);
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
		window.draw(clock.getDrawable());
		window.display();
	}
	return EXIT_SUCCESS;
}
