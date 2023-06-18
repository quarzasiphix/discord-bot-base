#include <boost/date_time/gregorian/custom_greg_weekday.hpp>

namespace boost {
    namespace gregorian {

        const char* custom_greg_weekday::as_short_string() const
        {
            static const char* const short_weekday_names[]
                = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

            return short_weekday_names[value_];
        }

        const char* custom_greg_weekday::as_long_string() const
        {
            static const char* const long_weekday_names[]
                = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

            return long_weekday_names[value_];
        }

    } // namespace gregorian
} // namespace boost
