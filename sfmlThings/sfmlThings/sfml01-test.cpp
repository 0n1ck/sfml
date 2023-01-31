//#include <iostream>
//#include "SFML\System.hpp"
//#include "SFML\Graphics.hpp"
//#include "SFML\Window.hpp"
//
//using namespace sf;
//
//int main()
//{
//    RenderWindow window(VideoMode(640, 400), "firstGame", Style::Default);
//    window.setFramerateLimit(60);
//    
//    /*float a, b;
//    a = 50, b = 100;
//
//    Vector2f(a, b);*/
//
//    CircleShape circle(50.f);
//    circle.setPosition(Vector2f(0.f, 0.f));
//    circle.setFillColor(Color(255, 0, 0, 100));
//    
//    
//    RectangleShape rect(Vector2f(50.f,100.f));
//    rect.setPosition(Vector2f(400.f, 200.f));
//    rect.setFillColor(Color(0, 0, 255, 100));
//
//    while (window.isOpen())
//    {
//        Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == Event::Closed)
//                window.close();
//            if (event.type == Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
//                window.close();
//
//        }
//
//        //Updatování
//        circle.move(0.5f, 0.f);
//        rect.move(-0.5f, -0.3f);
//
//        //Vykreslování
//        window.clear();
//        
//        //Vykreslování všeho
//        window.draw(circle);
//        window.draw(rect);
//
//
//        window.display();
//    }
//
//    return 0;
//}