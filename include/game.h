#ifndef GAME_H

#include <cstddef>
#include <deque>
#include <random>

namespace snake::game {

enum class Direction { Right, Up, Left, Down };

inline bool are_opposite(const Direction &lhs, const Direction &rhs) {
  return (static_cast<int>(lhs) ^ static_cast<int>(rhs)) == 2;
}

struct Position {
  int x;
  int y;

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
  size_t width() const { return width_; }
  size_t height() const { return height_; }
  const std::deque<Position> &snake() const { return snake_; }
  Position fruit() const { return fruit_; }
  Position head() const { return snake_.front(); }
  bool try_change_direction(const Direction &dir);
  GameState make_move(const Direction &dir);

private:
  bool is_collision(const Position &pos) const;
  void place_fruit();

  int width_;
  int height_;
  std::deque<Position> snake_;
  Position fruit_;
  RandomGenerator<int> rng_;
};

} // namespace snake::model

#define GAME_H value
#endif /* ifndef GAME_H */
