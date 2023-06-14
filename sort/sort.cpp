template <class T>
void sort(T a[], int numberUsed)
{
    int indexOfNextSmallest;
    for (int index = 0; index < numberUsed - 1; index++)
    {
        // a[index]에 올바른 값이 있게 한다
        indexOfNextSmallest = indexOfSmallest(a, index, numberUsed);
        swapValues(a[index], a[indexOfNextSmallest]);
        // a[0] <= a[1] <= ... <= a[index]가 되며
        // 원래의 배열 원소 중에서 가장 작은 값들이 된다.
        // 나머지 원소들은 남아 있는 다른 위치에 있다.
    }
}

template <class T>
void swapValues(T &variable1, T &variable2)
{
    T temp;
    temp = variable1;
    variable1 = variable2;
    variable2 = temp;
}

template <class T>
int indexOfSmallest(const T a[], int startIndex, int numberUsed)
{
    T min = a[startIndex], indexOfMin = startIndex;
    for (int index = startIndex + 1; index < numberUsed; index++)
        if (a[index] < min)
        {
            min = a[index];
            indexOfMin = index;
            // min은 a[startIndex]부터 a[index]까지의 값 중에서 최소차이다.
        }

    return indexOfMin;
}
