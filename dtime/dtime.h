#ifndef DTIME_H
#define DTIME_H

#include <iostream>
using std::istream;
using std::ostream;

namespace DTimeSavitch
{
    class DigitalTime
    {
    public:
        DigitalTime(int theHour, int theMinute);
        DigitalTime();
        // 시간 값을 0:00(자정을 나타냄)으로 초기화시킨다.

        int getHour() const;
        int getMinute() const;
        void advance(int minutesAdded);
        // 현재 시간을 minutesAdded 값만큼의 분 이후로 변경한다.

        void advance(int hoursAdded, int minutesAdded);
        // 현재시간을 hoursAdded 값만큼의 시간을 더하고 minutesAdded 값만큼의 분 이후로 변경한다.

        friend bool operator==(const DigitalTime &time1, const DigitalTime &time2);
        friend istream &operator>>(istream &ins, DigitalTime &theObject);
        friend ostream &operator<<(ostream &outs, const DigitalTime &theObject);

    private:
        int hour;
        int minute;
    };

} // namespace DTimeSavitch

#endif // DTIME_H
