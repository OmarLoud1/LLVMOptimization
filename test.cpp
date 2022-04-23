#include <iostream>
#include <ctime>

extern "C" {
    double printstar(double);
}

int main(int argc, char* argv[]) {

    int start_s = clock(); 

    std::cout << printstar(1) << "\n";

    int stop_s=clock(); 
    std::cout << (stop_s - start_s)/double(CLOCKS_PER_SEC)*1000 << "\n";

    return 0;
}
