#include <iostream>
using std::cout;
using std::endl;

template <class T>
void sort(T a[], int numberUsed);
// 선행조건: numberUsed <= 배열 a의 크기.
// a[0]부터 a[numverUser - 1]까지의 배열 원소는 값을 가지고 있다.
// T형 값에 대해 할당 연산자와 < 연산자가 작동한다.
// 사후조건: a[0]부터 a[numberUsed - 1]까지의 값들은
// a[0] <= a[1] <= ... <= a[numberUsed - 1]이 되도록 재배치되어 있다.

template <class T>
void swapValues(T &variable1, T &variable2);
// variable1과 variable2의 값을 교환한다.
// 할당 연산자가 T형에 대해 반드시 작동해야 한다.

template <class T>
int indexOfSmallest(const T a[], int startIndex, int numberUsed);
// 선행조건: 0 <= startIndex < numberUsed. 배열 원소에는 값이 들어있다.
// T형 값에 대해 할당 연산자와 < 연산자가 작동한다.
// a[startIndex, a[startIndex + ], ... , a[numberUsed - 1] 값 중
// 최소치가 a[i]일때 첨자 i를 리턴한다.

#include "sort.cpp"

int main()
{
    int i;
    int a[10] = {9, 8, 7, 6, 5, 1, 2, 3, 0, 4};
    cout << "Unsorted integers:\n";
    for (i = 0; i < 10; i++)
        cout << a[i] << " ";
    cout << endl;
    sort(a, 10);
    cout << "In sorted order the integers are:\n";
    for (i = 0; i < 10; i++)
        cout << a[i] << " ";
    cout << endl;
    double b[5] = {5.5, 4.4, 1.1, 3.3, 2.2};
    cout << "Unsorted doubles:\n";
    for (i = 0; i < 5; i++)
        cout << b[i] << " ";
    cout << endl;
    sort(b, 5);
    cout << "In sorted order the doubles are:\n";
    for (i = 0; i < 5; i++)
        cout << b[i] << " ";
    cout << endl;
    char c[7] = {'G', 'E', 'N', 'E', 'R', 'I', 'C'};
    cout << "Unsorted characters:\n";
    for (i = 0; i < 7; i++)
        cout << c[i] << " ";
    cout << endl;
    sort(c, 7);
    cout << "In sorted order the characters are:\n";
    for (i = 0; i < 7; i++)
        cout << c[i] << " ";
    cout << endl;

    return 0;
}
