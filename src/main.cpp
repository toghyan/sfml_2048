#include <SFML/Graphics.hpp>
#include <iostream>


int main()
{
    auto window = sf::RenderWindow{ { 1920u, 1080u }, "2048 Game" };
    window.setFramerateLimit(144);

    float circle_x = 0.f;
    float circle_y = 0.f;

    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed)
            {
                switch (event.key.scancode){
                    case sf::Keyboard::Scan::Left:
                        std::cout << "Left arrow key was pressed" << std::endl;
                        circle_x -= 20.f;
                        break;
                    case sf::Keyboard::Scan::Right:
                        std::cout << "Right arrow key was pressed" << std::endl;
                        circle_x += 20.f;
                        break;
                    case sf::Keyboard::Scan::Up:
                        std::cout << "Up arrow key was pressed" << std::endl;
                        circle_y -= 20.f;
                        break;
                    case sf::Keyboard::Scan::Down:
                        std::cout << "Down arrow key was pressed" << std::endl;
                        circle_y += 20.f;
                        break;
                    default:
                        std::cout << "Press Up, Down, Right, Left arrow keys." <<  std::endl;
                }
            }
        }

        // Draw a Circle.
        sf::CircleShape circle(100);
        circle.setPosition(sf::Vector2f(circle_x, circle_y));
        circle.setFillColor(sf::Color(150, 50, 250));

        window.clear();
        window.draw(circle);
        window.display();
    }
}