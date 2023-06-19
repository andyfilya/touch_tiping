#include <iostream>

#include "solve.h"

int main() {
    try {
        solve::Solve solution{};
        solution.run();
    } catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }
}