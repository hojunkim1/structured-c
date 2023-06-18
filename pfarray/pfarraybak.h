#ifndef PFARRAYBAK_H
#define PFARRAYBAK_H

#include "pfarray.h"

namespace PFArraySavitch
{
    template <class T>
    class PFArrayBak : public PFArray<T>
    {
    public:
        PFArrayBak();
        // 배열의 크기를 50으로 초기화.

        PFArrayBak(int capacityValue);

        PFArrayBak(const PFArrayBak<T> &oldObject);

        void backup();
        // 부분적으로 채워진 배열의 백업 사본을 만든다.

        void restore();
        // 가장 최근에 저장된 버전의 부분적으로 채워진 배열로 복원한다.
        // 만약 백업이 한 번도 이루어진 적이 없다면 부분적으로 채워진 배열이 빈 채로 유지된다.
        PFArrayBak<T> &operator=(const PFArrayBak<T> &rightSide);

        virtual ~PFArrayBak();

    private:
        T *b;      // 메인 배열의 백업.
        int usedB; // 상속된 멤버 변수 used의 백업.
    };

} // PFArraySavitch

#endif // PFARRAYDBAK_H
