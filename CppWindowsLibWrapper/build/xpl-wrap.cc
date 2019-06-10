#include <sstream>
#include "../time/date.h"


extern "C" __declspec(dllexport)
void xpl_xxx_cstr_del_(const char* cstr) {
    delete [] cstr;
}

extern "C" __declspec(dllexport)
int xpl_time_Weekday_Sun_() {
    return static_cast<int>(xpl::time::Weekday::Sun);
}

extern "C" __declspec(dllexport)
int xpl_time_Weekday_Mon_() {
    return static_cast<int>(xpl::time::Weekday::Mon);
}

extern "C" __declspec(dllexport)
int xpl_time_Weekday_Tue_() {
    return static_cast<int>(xpl::time::Weekday::Tue);
}

extern "C" __declspec(dllexport)
int xpl_time_Weekday_Wed_() {
    return static_cast<int>(xpl::time::Weekday::Wed);
}

extern "C" __declspec(dllexport)
int xpl_time_Weekday_Thu_() {
    return static_cast<int>(xpl::time::Weekday::Thu);
}

extern "C" __declspec(dllexport)
int xpl_time_Weekday_Fri_() {
    return static_cast<int>(xpl::time::Weekday::Fri);
}

extern "C" __declspec(dllexport)
int xpl_time_Weekday_Sat_() {
    return static_cast<int>(xpl::time::Weekday::Sat);
}

extern "C" __declspec(dllexport)
int xpl_time_Date_new_(int y, int m, int d) {
    return xpl::time::Date(y, m, d);
}

extern "C" __declspec(dllexport)
const char* xpl_time_Date_cstr_new_(int obj) {
    std::stringstream ss;
    ss << xpl::time::Date(obj);
    auto str = ss.str();
    auto cstr = new char[str.size() + 1];
    std::char_traits<char>::copy(cstr, str.c_str(), str.size() + 1);
    return cstr;
}

extern "C" __declspec(dllexport)
int xpl_time_Date_year_(int obj) {
    return xpl::time::Date(obj).year();
}