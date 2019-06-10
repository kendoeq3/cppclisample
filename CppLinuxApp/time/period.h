#ifndef XPL_TIME_PERIOD_H_
#define XPL_TIME_PERIOD_H_

#include <iostream>

namespace xpl {
namespace time {

class Period {
public:
    enum class Type {
        Day,
        Week,
        Month,
        Year,
    };

    static Period Day(int n);
    static Period Week(int n);
    static Period Month(int n);
    static Period Year(int n);

    Period& operator*=(int n);

    int n() const;
    Type type() const;

private:
    Period(int n, Type type);

    int n_;
    Type type_;
};

Period operator*(int n, Period rhs);
Period operator*(Period lhs, int n);

std::ostream& operator<<(std::ostream& os, Period obj);

}
}

#endif
