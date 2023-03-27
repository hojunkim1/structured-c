#include <iostream>
#define NDEBUG
#include <cassert>
using namespace std;

void show_number(int *ptr)
{
    assert(ptr != NULL);
    cout << "The number is: " << *ptr << endl;
}

int main()
{
    int x;

    int *first_ptr = NULL;
    int *second_ptr = NULL;

    x = 10;
    first_ptr = &x;

    show_number(first_ptr);
    show_number(second_ptr);

    return 0;
}
