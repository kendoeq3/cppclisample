#include "calendar.h"

namespace xpl {
namespace time {

bool Calendar::is_holiday(Date date) const {
    return !is_business_day(date);
}

Date Calendar::next(Date date) const {
    date = date + 1;
    return is_business_day(date) ? date : next(date);
}

Date Calendar::prev(Date date) const {
    date = date - 1;
    return is_business_day(date) ? date : prev(date);
}

Date Calendar::adjust(Date date, BusinessDayConvention bdc) const {
    if (is_business_day(date)) {
        return date;
    } else if (bdc == BusinessDayConvention::Following) {
        return next(date);
    } else if (bdc == BusinessDayConvention::ModifiedFollowing) {
        auto next_date = next(date);
        return (date.month() == next_date.month()) ? next_date : prev(date);
    } else if (bdc == BusinessDayConvention::Preceding) {
        return prev(date);
    } else {
        throw;
    }
}

Date Calendar::advance(Date date, Period period, BusinessDayConvention bdc) const {
    if (period.type() == Period::Type::Day) {
        return (period.n() == 0) ? date : advance(next(date), Period::Day(period.n() - 1), bdc);
    } else {
        return adjust(date + period, bdc);
    }
}

int Calendar::business_days_between(Date from, Date to) const {
    if (from >= to) {
        return 0;
    } else {
        return business_days_between(from + 1, to) + (is_business_day(from) ? 1 : 0);
    }
}

}
}
