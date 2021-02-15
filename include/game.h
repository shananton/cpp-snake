#ifndef GAME_H

#include <cstddef>
#include <deque>
#include <random>

namespace snake::game {

enum class Direction { Right, Up, Left, Down };

struct Position {
  size_t x;
  size_t y;

  auto operator<=>(const Position &) const = default;
  Position moved_in_direction(const Direction &dir) const;
};

enum class GameState { Continue, Lose };

template <typename T>
class RandomGenerator {
public:
  T uniform_in_range(T lo, T hi) {
    return std::uniform_int_distribution<T>{lo, hi}(random_engine);
  }

private:
  std::default_random_engine random_engine;
};

class Game {
public:
  Position head() const;
  GameState make_move(const Direction &dir);

private:
  bool is_collision(const Position &pos) const;
  void place_fruit();

  size_t width_;
  size_t height_;
  std::deque<Position> snake_;
  Position fruit_;
  RandomGenerator<size_t> rng_;
};

} // namespace snake::model

#define GAME_H value
#endif /* ifndef GAME_H */
