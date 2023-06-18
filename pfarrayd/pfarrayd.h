#ifndef PFARRAYD_H
#define PFARRAYD_H

class PFArrayD
{
public:
    PFArrayD();
    // 배열의 크기를 50으로 초기화

    PFArrayD(int capacityValue);

    PFArrayD(const PFArrayD &pfaObject);

    void addElement(double element);
    // 선행조건: 배열이 가득 차지 않았다.
    // 사후조건: element가 추가되었다.

    bool full() const { return (capacity == used); }
    // 배열이 가득 차 있다면 true를 반환하고 그렇지 않으면 false를 반환한다.

    int getCapacity() const { return capacity; };

    int getNumberUsed() const { return used; };

    void emptyArray() { used = 0; };
    // 숫자 used를 0으로 설정하면 실질적으로 배열을 비우게 된다.

    double &operator[](int index);
    // 0부터 numberUsed - 1까지의 요소들을 읽고 바꾼다.

    PFArrayD &operator=(const PFArrayD &rightSide);

    ~PFArrayD();

protected:
    double *a;    // double형의 배열
    int capacity; // 배열의 크기
    int used;     // 현재 사용되고 있는 배열 위치 번호
};

#endif // PFARRAYD_H
