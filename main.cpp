#define DEBUG

#include <iostream>

int main()
{
#ifdef DEBUG
    std::cout << "Debug mode" << std::endl;
#endif
    std::cout << "Hello World!" << std::endl;
    return 0;
}
