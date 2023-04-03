#include <iostream>

const int FEBRUARY = 2;

class Date {
private:
    int totalDays = 0;

    int DaysInMonth(int month, int year) const {
        switch (month) {
                case 1:
                case 3:
                case 5:
                case 7:
                case 8:
                case 10:
                case 12:
                    return 31;
                case 2:
                    if ((year % 400 == 0 || year % 100 != 0) && year % 4 == 0) {
                        return 29;
                    } else {
                        return 28;
                    }
                default:
                    return 30;
        }
    }

    int DaysInYear(int year) const {
        if (DaysInMonth(FEBRUARY, year) == 28) {
            return 365;
        } else {
            return 366;
        }
    }

public:
    Date(int day, int month, int year) {
        if ((year > 1969 && year < 2100) && (month > 0 && month < 13) && (day >= 1 && day <= DaysInMonth(month, year))) {
            if (day > 1) {
                totalDays += day;
            }
            

            while (month > 1) {
                totalDays += DaysInMonth(month, year);
                --month;
            }

            while (year > 1970) {
                totalDays += DaysInYear(year);
                --year;
            }
        }
    }

    int GetDay() const {
        int year = 1970;
        int daysLeft = totalDays;
        while (daysLeft > DaysInYear(year)) {
            daysLeft -= DaysInYear(year);
            ++year; 
        }

        int month = 1;
        while (daysLeft > DaysInMonth(month, year)) {
            daysLeft -= DaysInMonth(month, year);
            ++month;
        }

        int day = daysLeft;

        if (day < 1) {
            return 1;
        } else {
            return day;
        }
        
    }
    
    int GetMonth() const {
        int year = 1970;
        int daysLeft = totalDays;
        while (daysLeft > DaysInYear(year)) {
            daysLeft -= DaysInYear(year);
            ++year; 
        }

        int month = 1;
        while (daysLeft > DaysInMonth(month, year)) {
            daysLeft -= DaysInMonth(month, year);
            ++month;
        }

        if (month < 1) {
            month = 1;
        }

        return month;
    }

    int GetYear() const {
        int year = 1970;
        int daysLeft = totalDays;
        while (daysLeft > DaysInYear(year)) {
            daysLeft -= DaysInYear(year);
            ++year; 
        }

        return year;
    }

    Date operator+ (int daysN) {
        Date result(*this);
        result.totalDays += daysN;
        return result;
    }

    Date operator- (int daysN) {
        Date result(*this);
        result.totalDays -= daysN;
        return result;
    }

    int operator- (Date date2) {
        return (totalDays - date2.totalDays);
    }
};

void PrintDate (const Date& date) {
    std::cout << date.GetDay() << "." << date.GetMonth() << "." << date.GetYear() << std::endl;
}

int main() {
    Date d1(19, 5, 2023);
    PrintDate(d1);

    Date d2(1, 1, 2024);
    PrintDate(d2);

    auto d3 = d2 - 839;
    PrintDate(d3);

    auto d4 = d1 + 473;
    PrintDate(d4);

    int d5 = d2 - d1;
    std::cout << d5 << std::endl;

    d5 = d4 - d3;
    std::cout << d5 << std::endl;

    Date d6(1, 1, 1970);
    PrintDate(d6);

    auto d7 = d6 - 42;
    PrintDate(d7);

    Date d8(31, 12, 2099);
    PrintDate(d8);

    auto d9 = d8 + 42;
    PrintDate(d9);
}