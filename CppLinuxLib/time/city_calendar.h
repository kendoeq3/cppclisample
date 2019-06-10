#ifndef XPL_TIME_CITY_CALENDAR_H_
#define XPL_TIME_CITY_CALENDAR_H_

#include "calendar.h"

#include <memory>
#include <unordered_set>

namespace xpl {
namespace time {

class CityCalendar : public Calendar {
public:
    CityCalendar(
            bool is_sun_weekend,
            bool is_mon_weekend,
            bool is_tue_weekend,
            bool is_wed_weekend,
            bool is_thu_weekend,
            bool is_fri_weekend,
            bool is_sat_weekend,
            std::unordered_set<Date> &&holidays);

    bool is_business_day(Date date) const override;

    static std::unique_ptr<Calendar> united_status();
    static std::unique_ptr<Calendar> italy();

    class Builder {
    public:
        Builder();

        Builder& is_sun_weekend(bool value);
        Builder& is_mon_weekend(bool value);
        Builder& is_tue_weekend(bool value);
        Builder& is_wed_weekend(bool value);
        Builder& is_thu_weekend(bool value);
        Builder& is_fri_weekend(bool value);
        Builder& is_sat_weekend(bool value);
        Builder& holidays(std::unordered_set<Date> &&holidays);
        std::unique_ptr<CityCalendar> build();

    private:
        bool is_sun_weekend_;
        bool is_mon_weekend_;
        bool is_tue_weekend_;
        bool is_wed_weekend_;
        bool is_thu_weekend_;
        bool is_fri_weekend_;
        bool is_sat_weekend_;
        std::unordered_set<Date> holidays_;
    };

    static Builder builder();

private:
    bool is_sun_weekend_;
    bool is_mon_weekend_;
    bool is_tue_weekend_;
    bool is_wed_weekend_;
    bool is_thu_weekend_;
    bool is_fri_weekend_;
    bool is_sat_weekend_;
    std::unordered_set<Date> holidays_;
};

}
}

#endif
