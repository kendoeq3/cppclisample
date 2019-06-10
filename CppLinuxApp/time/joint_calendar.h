#ifndef XPL_TIME_JOINT_CALENDAR_H_
#define XPL_TIME_JOINT_CALENDAR_H_

#include <initializer_list>
#include <vector>
#include <memory>

#include "calendar.h"

namespace xpl {
namespace time {

class JointCalendar : public Calendar {
public:
    JointCalendar(std::vector<std::shared_ptr<const Calendar>> &&calendars);

    bool is_business_day(Date date) const override;

private:
    std::vector<std::shared_ptr<const Calendar>> calendars_;
};

}
}

#endif
