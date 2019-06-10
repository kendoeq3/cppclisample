#include "date.h"

#include <iomanip>

namespace xpl {
namespace time {

const int EOM_DAY[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int ORD_DAYS_FROM_MAR[12] = {0, 31, 61, 92, 122, 153, 184, 214, 245, 275, 306, 337};

bool is_leap(int y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int eom_day(int y, int m) {
    return (m == 2 && is_leap(y)) ? 29 : EOM_DAY[m - 1];
}

Date::Date(int d) : n_(d) {

}

Date::Date(int y, int m, int d) {
    if (m < 3) {
        --y;
        m += 12;
    }

    n_ = 365 * y + (y / 4) - (y / 100) + (y / 400) + (306 * (m + 1) / 10) + d - 428;
}

Date::operator int() const {
    return n_;
}

int Date::sn() const {
    return n_;
}

std::tuple<int, int, int> Date::ymd() const {
    int mod_d = n_ + 305;
    int y = mod_d / 146097 * 400;
    mod_d %= 146097;
    y += mod_d / 36524 * 100;
    mod_d %= 36524;
    y += mod_d / 1461 * 4;
    mod_d %= 1461;
    y += mod_d / 365;
    int d = n_ + 1 - (365 * y + (y / 4) - (y / 100) + (y / 400) + 122 + 1 - 428);
    if (d == 0) {
        return std::tuple<int, int, int>(y, 2, 29);
    } else {
        int m = 2;
        for (int i = 0; i < 12; ++i) {
            if (d <= ORD_DAYS_FROM_MAR[i]) {
                break;
            }
            ++m;
        }
        d -= ORD_DAYS_FROM_MAR[m - 3];
        return (m > 12)
            ? std::tuple<int, int, int>(y + 1, m - 12, d)
            : std::tuple<int, int, int>(y, m, d);
    }
}

int Date::year() const {
    return std::get<0>(ymd());
}

int Date::month() const {
    return std::get<1>(ymd());
}

int Date::day() const {
    return std::get<2>(ymd());
}

Weekday Date::weekday() const {
    return static_cast<Weekday>(n_ % 7);
}

bool operator==(Date lhs, Date rhs) {
    return lhs.sn() == rhs.sn();
}

bool operator!=(Date lhs, Date rhs) {
    return !(lhs == rhs);
}

bool operator<(Date lhs, Date rhs) {
    return lhs.sn() < rhs.sn();
}

bool operator<=(Date lhs, Date rhs) {
    return (lhs < rhs) || (lhs == rhs);
}

bool operator>(Date lhs, Date rhs) {
    return !(lhs == rhs) && !(lhs < rhs);
}

bool operator>=(Date lhs, Date rhs) {
    return (lhs > rhs) || (lhs == rhs);
}

Date operator+(Date lhs, int rhs) {
    return Date(lhs.sn() + rhs);
}

Date operator+(Date lhs, Period rhs) {
    if (rhs.type() == Period::Type::Day) {
        return Date(lhs.sn() + rhs.n());
    } else if (rhs.type() == Period::Type::Week) {
        return Date(lhs.sn() + rhs.n() * 7);
    } else if (rhs.type() == Period::Type::Month) {
        auto ymd = lhs.ymd();
        int m = std::get<1>(ymd) + rhs.n();
        int y = std::get<0>(ymd) + (m - 1) /12;
        m = (m - 1) % 12 + 1;
        int eom = eom_day(y, m);
        int d = std::get<2>(ymd);
        if (eom < d) {
            d = eom;
        }
        return Date(y, m, d);
    } else if (rhs.type() == Period::Type::Year) {
        auto ymd = lhs.ymd();
        int y = std::get<0>(ymd);
        int m = std::get<1>(ymd);
        int d = std::get<2>(ymd);
        int eom = eom_day(y, m);
        if (eom < d) {
            d = eom;
        }
        return Date(y, m, d);
    } else {
        throw;
    }
}

Date operator-(Date lhs, int rhs) {
    return Date(lhs.sn() - rhs);
}

std::ostream& operator<<(std::ostream& os, Date obj) {
    auto ymd = obj.ymd();
    os << std::setfill('0') << std::setw(4) << std::get<0>(ymd);
    os << '-';
    os << std::setfill('0') << std::setw(2) << std::get<1>(ymd);
    os << '-';
    os << std::setfill('0') << std::setw(2) << std::get<2>(ymd);
    return os;
}

}
}
