#include <iostream>
#include <map>
#include <string>
#include <SFML/Graphics.hpp>
#include "board.hpp"
#include "game.hpp"


Game::Game(unsigned int window_length, int board_size)
    : window_length_(window_length), board_size_(board_size), element_size_(static_cast<float>(window_length)/board_size),
    window_({window_length, window_length}, "2048 Game"), board_(board_size)
{
    window_.setFramerateLimit(144);
    if (!font_.loadFromFile("../assets/fredoka_font.ttf")){
        std::cerr << "Failed to load font" << std::endl;
    }
}

void Game::Run()
{
    while (window_.isOpen())
    {
        for (auto event = sf::Event{}; window_.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed) {
                window_.close();
            } else if (event.type == sf::Event::KeyPressed) {
                auto it = key_to_move_command_.find(event.key.scancode);
                if (it != key_to_move_command_.end()) {
                    board_.Move(it->second);
                } else {
                    std::cout << "Press Up, Down, Right, Left arrow keys." << std::endl;
                }
            }
        }
        DrawBoard();
    }
}

void Game::DrawBoard()
{
    window_.clear(sf::Color::White);

    auto board_state = board_.GetBoard();

    for(int row=0; row < board_size_; row++) {
        for(int col=0; col < board_size_; col++) {
            DrawSquare(board_state[row][col],
                       sf::Vector2f(col * element_size_ + element_size_/2.0f,
                                    row * element_size_ + element_size_/2.0f));
        }
    }

    window_.display();

}

void Game::DrawSquare(int number, sf::Vector2f position)
{
    sf::RectangleShape square(sf::Vector2f(element_size_, element_size_));
    square.setOrigin(element_size_/2.0f, element_size_/2.0f);
    square.setPosition(position);
    square.setFillColor(square_color_);
    square.setOutlineThickness(border_thickness_);
    square.setOutlineColor(border_color_);
    window_.draw(square);

    if (number != 0){
        sf::Text text(std::to_string(number), font_, 60);
        sf::FloatRect textRect = text.getLocalBounds();
        text.setOrigin(textRect.left + textRect.width/2.0f, textRect.top  + textRect.height/2.0f);
        text.setPosition(square.getPosition());
        text.setFillColor(text_color_);
        text.setStyle(sf::Text::Bold);
        window_.draw(text);
    }
}

const std::map<sf::Keyboard::Scancode, MoveCommand> Game::key_to_move_command_ = {
    {sf::Keyboard::Scan::Scancode::Left, MoveCommand::kLeft},
    {sf::Keyboard::Scan::Scancode::Right, MoveCommand::kRight},
    {sf::Keyboard::Scan::Scancode::Up, MoveCommand::kUp},
    {sf::Keyboard::Scan::Scancode::Down, MoveCommand::kDown},
};
