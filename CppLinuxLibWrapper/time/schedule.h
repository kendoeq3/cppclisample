#ifndef XPL_TIME_SCHEDULE_H_
#define XPL_TIME_SCHEDULE_H_

#include <memory>

#include "date.h"
#include "calendar.h"

namespace xpl {
namespace time {

enum class DateGenerationRule {
    Forward,
};

class Schedule {
public:
    Schedule(
            Date effective_date,
            Date termination_date,
            Period tenor,
            const std::shared_ptr<const Calendar> &calendar,
            BusinessDayConvention convention,
            BusinessDayConvention termination_date_convention,
            DateGenerationRule rule,
            bool end_of_month);

    class Iterator {
    public:
        Iterator(const Schedule &schedule);

        bool operator!=(const Iterator &rhs) const;
        Iterator& operator++();
        Date operator*() const;

        friend class Schedule;

    private:
        const Schedule &schedule_;
        int n_;
        Date curr_date_;
        Date last_date_;
    };

    friend class Iterator;

    Iterator begin() const;
    Iterator end() const;

private:
    Date effective_date_;
    Date termination_date_;
    Period tenor_;
    std::shared_ptr<const Calendar> calendar_;
    BusinessDayConvention convention_;
    BusinessDayConvention termination_date_convention_;
    DateGenerationRule rule_;
    bool end_of_month_;

};

}
}

#endif
