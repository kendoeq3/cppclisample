#include "period.h"

namespace xpl {
namespace time {

Period Period::Day(int n) {
    return Period(n, Type::Day);
}

Period Period::Week(int n) {
    return Period(n, Type::Week);
}

Period Period::Month(int n) {
    return Period(n, Type::Month);
}

Period Period::Year(int n) {
    return Period(n, Type::Year);
}

int Period::n() const {
    return n_;
}

Period::Type Period::type() const {
    return type_;
}

Period::Period(int n, Type type)
        : n_(n)
        , type_(type) {

}

Period& Period::operator*=(int n) {
    n_ *= n;
    return *this;
}

Period operator*(int n, Period rhs) {
    rhs *= n;
    return rhs;
}

Period operator*(Period lhs, int n) {
    return n * lhs;
}

std::ostream& operator<<(std::ostream &os, Period obj) {
    switch (obj.type()) {
    case Period::Type::Day:
        os << 'T' << obj.n() << 'D';
        break;
    case Period::Type::Week:
        os << 'T' << 7 * obj.n() << 'D';
        break;
    case Period::Type::Month:
        os << 'T' << obj.n() << 'M';
        break;
    case Period::Type::Year:
        os << 'T' << obj.n() << 'Y';
        break;
    }
    return os;
}

}
}
