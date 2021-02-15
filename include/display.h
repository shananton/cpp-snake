#ifndef DISPLAY_H

#include "game.h"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

namespace snake::display {

class GameDisplay {
public:
  GameDisplay(const game::Game &game, 
              size_t cell_size_in_px,
              size_t snake_thickness_in_px,
              sf::Color background_color,
              sf::Color snake_color,
              sf::Color cell_wall_color,
              sf::Color fruit_color);
  void display_game();

private:
  void draw_snake_rectangle_part(int x1, int y1, int x2, int y2);

  const game::Game &game_;
  const size_t cell_size_;
  const size_t snake_thickness_;
  const size_t snake_cell_margin_;
  const sf::Color background_color_;
  const sf::Color snake_color_;
  const sf::Color cell_wall_color_;
  const sf::Color fruit_color_;
  sf::RenderWindow window_;
};

} // namespace snake::display

#define DISPLAY_H value
#endif /* ifndef DISPLAY_H */
