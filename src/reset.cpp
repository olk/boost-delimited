
//          Copyright Oliver Kowalke 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include "boost/delimited/reset.hpp"

#include <boost/config.hpp>

#ifdef BOOST_HAS_ABI_HEADERS
# include BOOST_ABI_PREFIX
#endif

namespace boost {
namespace delimited {

reset_proxy reset_proxy::instance{};

}}

# ifdef BOOST_HAS_ABI_HEADERS
#  include BOOST_ABI_SUFFIX
# endif
