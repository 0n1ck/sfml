//#include <iostream>
//#include "SFML\System.hpp"
//#include "SFML\Graphics.hpp"
//#include "SFML\Window.hpp"
//
//using namespace sf;
//
//void UpdateF(RectangleShape &square);
//void DrawF(RenderTarget &window, RectangleShape& square);
//
//
//
//int main() {
//	RenderWindow window(VideoMode(640, 480), "Simple WASDnMouse");
//
//	RectangleShape square(Vector2f(100.f, 100.f));
//	square.setFillColor(Color::Red);
//	square.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f);
//
//	while (window.isOpen()) {
//		Event event;
//		while (window.pollEvent(event)) {
//			if (event.type == Event::Closed) {
//				window.close();
//
//				if (event.KeyPressed && event.key.code == Keyboard::Escape)
//					window.close();
//			}
//
//			//Update
//			UpdateF(square);
//			//Draw
//			DrawF(window, square);
//			window.display();
//		}
//
//	}
//	return 0;
//}
//
//void UpdateF(RectangleShape &square) {
//
//}
//
//void DrawF(RenderWindow &window, RectangleShape& square) {
//	window.clear(Color::Magenta);
//
//	//Draw stuff
//	window.draw(square);
//
//	window.display();
//}
