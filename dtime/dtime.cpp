#include <iostream>
#include <cctype>
#include <cstdlib>
using std::cin;
using std::cout;
using std::istream;
using std::ostream;
#include "dtime.h"

namespace
{
    int digitToInt(char c)
    {
        return (static_cast<int>(c) - static_cast<int>('0'));
    }

    void readMinute(int &theMinute)
    {
        char c1, c2;
        cin >> c1 >> c2;

        if (!(isdigit(c1) && isdigit(c2)))
        {
            cout << "Error: illegal input to readMinute\n";
            exit(1);
        }

        theMinute = digitToInt(c1) * 10 + digitToInt(c2);

        if (theMinute < 0 || theMinute > 59)
        {
            cout << "Error: illegal input to readMinute\n";
            exit(1);
        }
    }

    void readHour(int &theHour)
    {
        char c1, c2;
        cin >> c1 >> c2;
        if (!(isdigit(c1) && isdigit(c2) || c2 == ':'))
        {
            cout << "Error: illegal input to readHour\n";
        }

        if (isdigit(c1) && c2 == ':')
        {
            theHour = digitToInt(c1);
        }
        else
        {
            theHour = digitToInt(c1) * 10 + digitToInt(c2);
            cin >> c2; // ':'를 버림
            if (c2 != ':')
            {
                cout << "Error: illegal input to readHour\n";
            }
        }

        if (theHour == 24)
            theHour = 0; // 자정을 0:00으로 표준화

        if (theHour < 0 || theHour > 23)
        {
            cout << "Error: illegal input to readHour\n";
            exit(1);
        }
    }
} // 명명되지 않은 네임스페이스

namespace DTimeSavitch
{
    DigitalTime::DigitalTime(int theHour, int theMinute)
    {
        if (theHour < 0 || theHour > 24 || theMinute < 0 || theMinute > 59)
        {
            cout << "Illegal argument to DigitalTime constructor.";
            exit(1);
        }
        else
        {
            hour = theHour;
            minute = theMinute;
        }

        if (hour == 24)
            hour = 0; // 자정을 0:00으로 표준화
    }

    DigitalTime::DigitalTime()
    {
        hour = 0;
        minute = 0;
    }

    int DigitalTime::getHour() const
    {
        return hour;
    }

    int DigitalTime::getMinute() const
    {
        return minute;
    }

    void DigitalTime::advance(int minutesAdded)
    {
        int grossMinutes = minute + minutesAdded;
        minute = grossMinutes % 60;
        int hourAdjustment = grossMinutes / 60;
        hour = (hour + hourAdjustment) % 24;
    }

    void DigitalTime::advance(int hoursAdded, int minutesAdded)
    {
        hour = (hour + hoursAdded) % 24;
        advance(minutesAdded);
    }

    bool operator==(const DigitalTime &time1, const DigitalTime &time2)
    {
        return (time1.hour == time2.hour && time1.minute == time2.minute);
    }

    istream &operator>>(istream &ins, DigitalTime &theObject)
    {
        readHour(theObject.hour);
        readMinute(theObject.minute);
        return ins;
    }

    ostream &operator<<(ostream &outs, const DigitalTime &theObject)
    {
        outs << theObject.hour << ":";
        if (theObject.minute < 10)
            outs << '0';
        outs << theObject.minute;
        return outs;
    }

} // namespace DTimeSavitch
