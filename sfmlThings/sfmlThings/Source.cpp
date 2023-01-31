#include <iostream>
#include "SFML\System.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include <vector>

const int blockSize = 10;
const int width = 30;
const int height = 20;

class SnakeBlock
{
public:
    SnakeBlock(int x, int y)
    {
        shape.setPosition(x * blockSize, y * blockSize);
        shape.setSize({ blockSize, blockSize });
        shape.setFillColor(sf::Color::Green);
    }

    sf::RectangleShape shape;
};

int main()
{
    char keyHor = ' ';
    char keyVer = 'R';

    sf::RenderWindow window(sf::VideoMode(width * blockSize, height * blockSize), "SFML Snake");
    window.setFramerateLimit(10);

    std::vector<SnakeBlock> snake = { {5,5}, {5,6}, {5,7} };
    int dx = 1, dy = 0;

    sf::RectangleShape food;
    food.setFillColor(sf::Color::Red);
    food.setSize({ blockSize, blockSize });
    food.setPosition(10 * blockSize, 10 * blockSize);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (keyVer != 'D' && sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            dx = 0;
            dy = -1;
            keyVer = 'U';
            keyHor = ' ';
        }
        if (keyVer != 'U' && sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            dx = 0;
            dy = 1;
            keyVer = 'D';
            keyHor = ' ';
        }
        if (keyHor  != 'R' && sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            dx = -1;
            dy = 0;
            keyHor = 'L';
            keyVer = ' ';
        }
        if (keyHor != 'L' && sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            dx = 1;
            dy = 0;
            keyHor = 'R';
            keyVer = ' ';
        }
      
        auto& head = snake.front();
        int newX = head.shape.getPosition().x + dx * blockSize;
        int newY = head.shape.getPosition().y + dy * blockSize;

        if (newX >= 0 && newX < width * blockSize && newY >= 0 && newY < height * blockSize)
        {
            snake.insert(snake.begin(), SnakeBlock(newX / blockSize, newY / blockSize));

            if (food.getGlobalBounds().intersects(snake.front().shape.getGlobalBounds()))
            {
                food.setPosition(rand() % width * blockSize, rand() % height * blockSize);
            }
            else
            {
                snake.pop_back();
            }
        }
        else
        {
            std::cout << "Game Over" << std::endl;
            break;
        }

        window.clear();
        for (auto& block : snake)
        {
            window.draw(block.shape);
        }

        window.draw(food);
        window.display();
    }

    return 0;
}
