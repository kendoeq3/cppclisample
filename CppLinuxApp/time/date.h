#ifndef XPL_TIME_DATE_H_
#define XPL_TIME_DATE_H_

#include <iostream>
#include <tuple>

#include "period.h"

namespace xpl {
namespace time {

enum class Weekday {
    Sun,
    Mon,
    Tue,
    Wed,
    Thu,
    Fri,
    Sat,
};

class Date {
public:
    Date(int d);
    Date(int y, int m, int d);

    operator int() const;

    int sn() const;

    std::tuple<int, int, int> ymd() const;
    int year() const;
    int month() const;
    int day() const;

    Weekday weekday() const;

private:
    int n_;
};

bool operator==(Date lhs, Date rhs);
bool operator!=(Date lhs, Date rhs);
bool operator<(Date lhs, Date rhs);
bool operator<=(Date lhs, Date rhs);
bool operator>(Date lhs, Date rhs);
bool operator>=(Date lhs, Date rhs);
Date operator+(Date lhs, int rhs);
Date operator+(Date lhs, Period rhs);
Date operator-(Date lhs, int rhs);
std::ostream& operator<<(std::ostream& os, xpl::time::Date obj);

}
}

namespace std {
    template <>
    struct hash<xpl::time::Date> {
        std::size_t operator()(xpl::time::Date obj) const noexcept {
            return std::hash<int>()(obj.sn());
        }
    };
}

#endif
