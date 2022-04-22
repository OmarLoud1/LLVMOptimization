#include <iostream>

extern "C" {
    double printstar(double);
}

int main(int argc, char* argv[]) {

    std::cout << printstar(1) << "\n";

    return 0;
}
