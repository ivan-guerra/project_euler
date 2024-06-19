#include "solns/soln_19.h"

#include <iostream>
#include <sstream>

#include "common/types.h"

namespace euler {

enum Month {
  kJanuary = 0,
  kFebruary,
  kMarch,
  kApril,
  kJune,
  kJuly,
  kAugust,
  kSeptember,
  kOctober,
  kNovember,
  kDecember,
};

enum WeekDay {
  kSunday = 0,
  kMonday,
  kTuesday,
  kWednesday,
  kThursday,
  kFriday,
  kSaturday,
};

class Date {
 public:
  Date() = delete;
  Date(int year, Month month, int day, WeekDay weekday = WeekDay::kSunday)
      : year_(year), month_(month), day_(day - 1), weekday_(weekday) {}

  int GetYear() const { return year_; }
  Month GetMonth() const { return static_cast<Month>(month_); }
  int GetDay() const { return day_; }
  WeekDay GetWeekday() const { return static_cast<WeekDay>(weekday_); }

  Date& operator++() {
    weekday_ = (weekday_ + 1) % kDaysInAWeek;

    int prev_day = day_;
    if ((month_ == 1) && IsLeapYear()) {
      day_ = (day_ + 1) % (kDaysInMonth[month_] + 1);
    } else {
      day_ = (day_ + 1) % kDaysInMonth[month_];
    }

    if (day_ < prev_day) {
      int prev_month = month_;
      month_ = (month_ + 1) % kMonthsInAYear;
      if (month_ < prev_month) {
        year_++;
      }
    }

    return *this;
  }

  Date operator++(int) {
    Date old = *this;
    operator++();
    return old;
  }

  bool IsLeapYear() const {
    return (((year_ % 4 == 0) && (year_ % 100 != 0)) || (year_ % 400 == 0));
  }

  friend bool operator==(const Date& a, const Date& b) {
    return (a.year_ == b.year_) && (a.month_ == b.month_) && (a.day_ == b.day_);
  }

  friend bool operator!=(const Date& a, const Date& b) { return !(a == b); }

 private:
  static constexpr int kDaysInAWeek = 7;
  static constexpr int kMonthsInAYear = 12;
  static constexpr std::array<int, kMonthsInAYear> kDaysInMonth = {
      31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
  };

  int year_;
  int month_;
  int day_;
  int weekday_;
};

types::SolnFuncRet Soln19(const types::SolnFuncArgs& args) {
  if (args.size() != 2) {
    return std::unexpected(types::SolnErrorCode::kInvalidArgCount);
  }

  char seperator = '-';
  int start_year, start_month, start_day;
  std::istringstream start_date_ss(args[0].data());
  start_date_ss >> start_year >> seperator >> start_month >> seperator >>
      start_day;

  int end_year, end_month, end_day;
  std::istringstream end_date_ss(args[1].data());
  end_date_ss >> end_year >> seperator >> end_month >> seperator >> end_day;

  Date curr_date(1900, Month::kJanuary, 1,
                 WeekDay::kMonday); /* Monday January 1, 1900 */
  Date start_date(start_year, static_cast<Month>(start_month - 1), start_day);
  Date end_date(end_year, static_cast<Month>(end_month - 1), end_day);

  while (curr_date != start_date) {
    curr_date++;
  }
  int64_t first_sundays = 0;
  while (curr_date != end_date) {
    if ((curr_date.GetDay() == 1) &&
        (WeekDay::kSunday == curr_date.GetWeekday())) {
      first_sundays++;
    }
    curr_date++;
  }

  return first_sundays;
}

}  // namespace euler
