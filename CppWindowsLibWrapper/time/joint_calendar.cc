#include "joint_calendar.h"

#include <numeric>

namespace xpl {
namespace time {

JointCalendar::JointCalendar(std::vector<std::shared_ptr<const Calendar>> &&calendars)
        : calendars_(std::move(calendars)) {

}

bool JointCalendar::is_business_day(Date date) const {
	return true;
    //return std::accumulate(calendars_.begin(), calendars_.end(), true, [date](bool acc, std::shared_ptr<const Calendar>& i) {
    //    return acc && i->is_business_day(date);
    //});
}

}
}
