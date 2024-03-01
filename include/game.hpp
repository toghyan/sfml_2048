#ifndef GAME_HPP
#define GAME_HPP

#include <map>
#include <string>
#include <SFML/Graphics.hpp>
#include "board.hpp"


class Game{
public:
    Game(unsigned int window_length, int board_size = 4);
    void Run();

private:

    void DrawBoard();
    void DrawSquare(int number, sf::Vector2f position);


    // This can be used to customize the appearnace of each number.
    struct VisualSetting{
        const std::string number;
        const sf::Color text_color;
        const sf::Color background_color;

        VisualSetting(const std::string number, const sf::Color text_color,
                      const sf::Color background_color) : 
                      number(number), text_color(text_color),
                      background_color(background_color) {}

    };

    static const std::map<sf::Keyboard::Scan::Scancode, MoveCommand> key_to_move_command_;
    const unsigned int window_length_;
    const int board_size_;
    const float element_size_;
    sf::RenderWindow window_;
    sf::Font font_;
    const sf::Color square_color_{192, 192, 192, 255};
    const sf::Color border_color_{128,128,128,128};
    const float border_thickness_ = -5.f;
    const sf::Color text_color_{80, 80, 80, 255};
    Board board_;

};

#endif  // GAME_HPP
