#ifndef PFARRY_H
#define PFARRY_H

namespace PFArraySavitch
{
    template <class T>
    class PFArray
    {
    public:
        PFArray(); // 용량을 50으로 초기화한다.
        PFArray(int capacityValue);
        PFArray(const PFArray<T> &pfaObject);

        void addElement(const T &element);
        // 선행조건: 배열은 가득 차 있지 않다.
        // 사후조건: 원소가 추가되었다.
        bool full() const; // 배열이 가득 차 있다면 true를, 아니라면 false를 리턴한다.

        int getCapacity() const;
        int getNumberUsed() const;

        void emptyArray();
        // 사용된 원소의 수를 0으로 설정하여 배열을 효과적으로 비게 한다.

        T &operator[](int index);
        // 0부터 numberUsed - 1까지의 원소를 참조하여 변경한다.

        PFArray<T> &operator=(const PFArray<T> &rightSide);

        virtual ~PFArray();

    private:
        T *a;         // T형 배열을 위한 것
        int capacity; // 배열의 크기를 위한 것
        int used;     // 현재 사용 중인 배열의 위치에 대한 번호를 위한 것
    };

} // PFArraySavitch

#endif // PFARRY_H
