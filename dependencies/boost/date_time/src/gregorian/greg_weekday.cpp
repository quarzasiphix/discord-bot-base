#ifndef BOOST_DATE_TIME_SOURCE
#define BOOST_DATE_TIME_SOURCE
#endif
#include <boost/date_time/gregorian/greg_weekday.hpp>

#include "greg_names.hpp"

namespace boost {
    namespace gregorian {

        const char* greg_weekday::as_short_string() const
        {
            return short_weekday_names[value_];
        }

        const char* greg_weekday::as_long_string() const
        {
            return long_weekday_names[value_];
        }

#ifndef BOOST_NO_STD_WSTRING

        const wchar_t* greg_weekday::as_short_wstring() const
        {
            return w_short_weekday_names[value_];
        }

        const wchar_t* greg_weekday::as_long_wstring() const
        {
            return w_long_weekday_names[value_];
        }

#endif // BOOST_NO_STD_WSTRING

    }
} //namespace gregorian
