// #define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>

unsigned int Factorial(unsigned int number) {
  return number <= 1 ? 1 : Factorial(number - 1) * number;
}

TEST_CASE("Fac 0 and 1", "[factorial]") {
  REQUIRE(Factorial(0) == 1);
  REQUIRE(Factorial(1) == 1);
}

TEST_CASE("Fac 2 and 3", "[factorial]") {
  REQUIRE(Factorial(2) == 2);
  REQUIRE(Factorial(3) == 6);
}

TEST_CASE("Fac more", "[factorial]") {
  REQUIRE(Factorial(10) == 3628800);
}

TEST_CASE("vectors can be sized and resized", "[vector]") {

  std::vector<int> v(5);

  REQUIRE(v.size() == 5);
  REQUIRE(v.capacity() >= 5);

  SECTION("resizing bigger changes size and capacity") {
    v.resize(10);

    REQUIRE(v.size() == 10);
    REQUIRE(v.capacity() >= 10);
  }
  SECTION("resizing smaller changes size but not capacity") {
    v.resize(0);

    REQUIRE(v.size() == 0);
    REQUIRE(v.capacity() >= 5);
  }
  SECTION("reserving bigger changes capacity but not size") {
    v.reserve(10);

    REQUIRE(v.size() == 5);
    REQUIRE(v.capacity() >= 10);
  }
  SECTION("reserving smaller does not change size or capacity") {
    v.reserve(0);

    REQUIRE(v.size() == 5);
    REQUIRE(v.capacity() >= 5);
  }
}

TEST_CASE("nested sections", "[vector]") {
  SECTION("reserving bigger changes capacity but not size") {
    std::vector<int> v(5);
    v.reserve(10);

    REQUIRE(v.size() == 5);
    REQUIRE(v.capacity() >= 10);
    SECTION("reserving down unused capacity does not change capacity") {
      v.reserve(7);
      REQUIRE(v.size() == 5);
      REQUIRE(v.capacity() >= 10);
    }
  }
}
