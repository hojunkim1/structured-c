#include <iostream>

class DayOfYear
{
public:
    DayOfYear(int newMonth, int newDay)
    {
        month = newMonth;
        day = newDay;
    }
    void output();

private:
    int month;
    int day;
};

void DayOfYear::output()
{
    std::cout << "month = " << month << std::endl;
    std::cout << "day = " << day << std::endl;
}

int main()
{
    DayOfYear today(4, 25);
    today.output();
    return 0;
}
