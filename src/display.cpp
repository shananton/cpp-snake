#include "display.h"
#include "game.h"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

namespace snake::display {

GameDisplay::GameDisplay(const game::Game &game, 
                         size_t cell_size_in_px,
                         size_t snake_thickness_in_px,
                         sf::Color background_color,
                         sf::Color snake_color,
                         sf::Color cell_wall_color,
                         sf::Color fruit_color)
    : game_{game}, cell_size_{cell_size_in_px},
      snake_thickness_{snake_thickness_in_px},
      snake_cell_margin_{(cell_size_in_px - snake_thickness_in_px) / 2},
      background_color_{background_color},
      snake_color_{snake_color},
      cell_wall_color_{cell_wall_color},
      fruit_color_{fruit_color},
      window_{sf::VideoMode(game.width() * cell_size_in_px,
                            game.height() * cell_size_in_px),
              "Snake", sf::Style::Titlebar | sf::Style::Close} {}

void GameDisplay::display_game() {
  window_.clear(background_color_);

  const auto &snake = game_.snake();
  for (size_t i = 0; i < std::size(snake) - 1; ++i) {
    const auto &cur = snake[i];
    const auto &prev = snake[i+1];
    auto x
  }

  window_.display();
}

void GameDisplay::draw_snake_rectangle_part(int x1, int y1, int x2, int y2) {
  auto w = snake_thickness_ + (x2 - x1) * cell_size_;
  auto h = snake_thickness_ + (y2 - y1) * cell_size_;
  auto rect = sf::RectangleShape({w, h});
}

} // namespace snake::display
