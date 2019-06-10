#include "schedule.h"

namespace xpl {
namespace time {

Schedule::Schedule(
        Date effective_date,
        Date termination_date,
        Period tenor,
        const std::shared_ptr<const Calendar> &calendar,
        BusinessDayConvention convention,
        BusinessDayConvention termination_date_convention,
        DateGenerationRule rule,
        bool end_of_month)
        : effective_date_(effective_date),
          termination_date_(termination_date),
          tenor_(tenor),
          calendar_(calendar),
          convention_(convention),
          termination_date_convention_(termination_date_convention),
          rule_(rule),
          end_of_month_(end_of_month) {

}

Schedule::Iterator Schedule::begin() const {
    return Schedule::Iterator(*this);
}

Schedule::Iterator Schedule::end() const {
    auto iter = Schedule::Iterator(*this);
    iter.curr_date_ = Date(9999, 12, 31);
    return iter;
}

Schedule::Iterator::Iterator(const Schedule &schedule)
        : schedule_(schedule),
          n_(-1),
          curr_date_(0),
          last_date_(0) {
    last_date_ = schedule_.calendar_->adjust(
            schedule_.termination_date_, schedule_.termination_date_convention_);
    ++(*this);
}

bool Schedule::Iterator::operator!=(const xpl::time::Schedule::Iterator &rhs) const {
    return curr_date_ != rhs.curr_date_;
}

Schedule::Iterator& Schedule::Iterator::operator++() {
    if (curr_date_ < last_date_) {
        ++n_;
        auto role_date = schedule_.effective_date_ + n_ * schedule_.tenor_;
        auto next_date = schedule_.calendar_->adjust(role_date, schedule_.convention_);
        curr_date_ = (next_date <= last_date_) ? next_date : last_date_;
    } else if (curr_date_ == last_date_) {
        curr_date_ = Date(9999, 12, 31);
    }
    return *this;
}

Date Schedule::Iterator::operator*() const {
    return curr_date_;
}

}
}
