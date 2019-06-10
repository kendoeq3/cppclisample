#ifndef XPL_TIME_CALENDAR_H_
#define XPL_TIME_CALENDAR_H_

#include "date.h"

namespace xpl {
namespace time {

enum class BusinessDayConvention {
    Following,
    ModifiedFollowing,
    Preceding,
};

class Calendar {
public:
    virtual bool is_business_day(Date date) const = 0;

    bool is_holiday(Date date) const;

    Date next(Date date) const;
    Date prev(Date date) const;
    Date adjust(Date date, BusinessDayConvention bdc) const;
    Date advance(Date date, Period period, BusinessDayConvention bdc) const;
    int business_days_between(Date from, Date to) const;
};

}
}

#endif
