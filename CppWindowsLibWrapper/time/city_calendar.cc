#include "city_calendar.h"

namespace xpl {
namespace time {

CityCalendar::CityCalendar(
        bool is_sun_weekend,
        bool is_mon_weekend,
        bool is_tue_weekend,
        bool is_wed_weekend,
        bool is_thu_weekend,
        bool is_fri_weekend,
        bool is_sat_weekend,
        std::unordered_set<Date> &&holidays)
        : is_sun_weekend_(is_sun_weekend),
          is_mon_weekend_(is_mon_weekend),
          is_tue_weekend_(is_tue_weekend),
          is_wed_weekend_(is_wed_weekend),
          is_thu_weekend_(is_thu_weekend),
          is_fri_weekend_(is_fri_weekend),
          is_sat_weekend_(is_sat_weekend),
          holidays_(std::move(holidays)) {

}

bool CityCalendar::is_business_day(Date date) const {
    switch (date.weekday()) {
    case Weekday::Sun:
        if (is_sun_weekend_) {
            return false;
        }
        break;
    case Weekday::Mon:
        if (is_mon_weekend_) {
            return false;
        }
        break;
    case Weekday::Tue:
        if (is_tue_weekend_) {
            return false;
        }
        break;
    case Weekday::Wed:
        if (is_wed_weekend_) {
            return false;
        }
        break;
    case Weekday::Thu:
        if (is_thu_weekend_) {
            return false;
        }
        break;
    case Weekday::Fri:
        if (is_fri_weekend_) {
            return false;
        }
        break;
    case Weekday::Sat:
        if (is_sat_weekend_) {
            return false;
        }
        break;
    }

    return holidays_.find(date) == holidays_.end();
}

std::unique_ptr<Calendar> CityCalendar::united_status() {
    return builder()
        .is_sun_weekend(true)
        .is_sat_weekend(true)
        .holidays(std::unordered_set<Date> {
                Date(2015, 1, 1),
                Date(2015, 1, 19),
                Date(2015, 5, 25),
                Date(2015, 7, 3),
                Date(2015, 9, 7),
                Date(2015, 10, 12),
                Date(2015, 11, 11),
                Date(2015, 11, 26),
                Date(2015, 12, 25),
                Date(2016, 1, 1),
        })
        .build();
}

std::unique_ptr<Calendar> CityCalendar::italy() {
    return builder()
        .is_sun_weekend(true) 
        .is_sat_weekend(true)
        .holidays(std::unordered_set<Date> {
                Date(2015, 4, 6),
                Date(2015, 5, 1),
                Date(2015, 6, 2),
        })
        .build();
}

CityCalendar::Builder::Builder()
        : is_sun_weekend_(false),
          is_mon_weekend_(false),
          is_tue_weekend_(false),
          is_wed_weekend_(false),
          is_thu_weekend_(false),
          is_fri_weekend_(false),
          is_sat_weekend_(false),
          holidays_() {

}

CityCalendar::Builder& CityCalendar::Builder::is_sun_weekend(bool value) {
    is_sun_weekend_ = value;
    return *this;
}

CityCalendar::Builder& CityCalendar::Builder::is_mon_weekend(bool value) {
    is_mon_weekend_ = value;
    return *this;
}

CityCalendar::Builder& CityCalendar::Builder::is_tue_weekend(bool value) {
    is_tue_weekend_ = value;
    return *this;
}

CityCalendar::Builder& CityCalendar::Builder::is_wed_weekend(bool value) {
    is_wed_weekend_ = value;
    return *this;
}

CityCalendar::Builder& CityCalendar::Builder::is_thu_weekend(bool value) {
    is_thu_weekend_ = value;
    return *this;
}

CityCalendar::Builder& CityCalendar::Builder::is_fri_weekend(bool value) {
    is_fri_weekend_ = value;
    return *this;
}

CityCalendar::Builder& CityCalendar::Builder::is_sat_weekend(bool value) {
    is_sat_weekend_ = value;
    return *this;
}

CityCalendar::Builder& CityCalendar::Builder::holidays(std::unordered_set<Date> &&value) {
    holidays_ = std::move(value);
    return *this;
}

std::unique_ptr<CityCalendar> CityCalendar::Builder::build() {
    return std::unique_ptr<CityCalendar>(
		new CityCalendar(
            is_sun_weekend_,
            is_mon_weekend_,
            is_tue_weekend_,
            is_wed_weekend_,
            is_thu_weekend_,
            is_fri_weekend_,
            is_sat_weekend_,
            std::move(holidays_)));
}

CityCalendar::Builder CityCalendar::builder() {
    return CityCalendar::Builder();
}

}
}
