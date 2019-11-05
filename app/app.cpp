#include <cpp-playground/lib.hpp>

#include <fmt/format.h>
#include <nlohmann/json.hpp>

#include <iostream>
#include <vector>
#include <tuple>

using json = nlohmann::json;

int main() {
  std::vector<double> input = {1.2, 2.3, 3.4, 4.5};

  auto [mean, moment] = accumulate_vector(input);
  json json_example = {
      {"pi", 3.141},
      {"happy", true},
      {"name", "Niels"},
      {"nothing", nullptr},
      {"answer", {
                 {"everything", 42}
             }},
      {"list", {1, 0, 2}},
      {"object", {
                 {"currency", "USD"},
                   {"value", 42.99}
             }}
  };

  fmt::print("Mean: {}, Moment: {}\n",  mean, moment);
  std::cout << "\n";
  fmt::print("Some Json: {}\n", json_example.dump(2));

  return 0;
}
