#include "game.h"

#include <array>
#include <cstddef>
#include <deque>
#include <algorithm>

namespace snake::game {

Position Position::moved_in_direction(const Direction &dir) const {
  constexpr std::array DX{1, 0, -1, 0};
  constexpr std::array DY{0, -1, 0, 1};
  auto dir_no = static_cast<size_t>(dir);
  return {x + DX[dir_no], y + DY[dir_no]};
}

GameState Game::make_move(const Direction &dir) {
  auto next_pos = head().moved_in_direction(dir);
  if (is_collision(next_pos)) {
    return GameState::Lose;
  }

  snake_.push_front(next_pos);
  if (head() != fruit_) {
    snake_.pop_back();
  } else {
    place_fruit();
  }
  return GameState::Continue;
}

bool Game::is_collision(const Position &pos) const {
  return pos.x < 0 || pos.x >= width_ ||
         pos.y < 0 || pos.y >= height_ ||
         std::ranges::find(snake_, pos) != std::end(snake_);
}

void Game::place_fruit() {
  do {
    fruit_ = { rng_.uniform_in_range(0, width_), rng_.uniform_in_range(0, height_) };
  } while (is_collision(fruit_));
}

} // namespace snake::model
