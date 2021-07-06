#include <iostream>

using namespace std;

class Time
{
    private:
        int hour;
        int minute;
        int second;
    
    public:

        int hours()
        {
            return hour;
        }

        int minutes()
        {
            return minute;
        }

        int seconds()
        {
            return second;
        }

        void reset(int h, int m, int s)
        {
            hour = h;
            minute = m;
            second = s;
        }

        void advance(int h, int m, int s)
        {
            second += s;
            
            
            if (second > 59)
            {
                minute++;
            }
            second %= 60;
            
            minute += m;
            if (minute > 59)
            {
                hour++;
                minute %= 60;
            }

            hour += h;
            if (hour >= 24) hour %= 24;
        }

        void print()
        {
            cout << hour << ":" << minute << ":" << second << "\n";
        }
};

int main()
{
    Time test;
    test.reset(5, 48, 55);

    test.print();

    test.advance(30, 14, 43);

    test.print();
}