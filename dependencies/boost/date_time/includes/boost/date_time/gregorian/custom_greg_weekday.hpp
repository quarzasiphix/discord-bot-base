#ifndef CUSTOM_GREG_WEEKDAY_HPP
#define CUSTOM_GREG_WEEKDAY_HPP

#include <boost/date_time/gregorian/greg_weekday.hpp>

namespace boost {
    namespace gregorian {

        class custom_greg_weekday : public greg_weekday {
        public:
            using greg_weekday::greg_weekday;

            const char* as_short_string() const;
            const char* as_long_string() const;
        };

    } // namespace gregorian
} // namespace boost

#endif // CUSTOM_GREG_WEEKDAY_HPP
