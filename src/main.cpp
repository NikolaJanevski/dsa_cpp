#include <iostream>
#include "Interface.hpp"
#include "FIFO.hpp"
#include "LIFO.hpp"

using namespace std;

int main() {
    std::cout << "Hello World" << std::endl;
    FIFO<int> queue;
    LIFO<int> stack;
    return 0;
}