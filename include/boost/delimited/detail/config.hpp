
//          Copyright Oliver Kowalke 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_DELIMITED_DETAIL_CONFIG_H
#define BOOST_DELIMITED_DETAIL_CONFIG_H

#include <boost/config.hpp>
#include <boost/detail/workaround.hpp>

#ifdef BOOST_DELIMITED_DECL
# undef BOOST_DELIMITED_DECL
#endif

#if (defined(BOOST_ALL_DYN_LINK) || defined(BOOST_DELIMITED_DYN_LINK) ) && ! defined(BOOST_DELIMITED_STATIC_LINK)
# if defined(BOOST_DELIMITED_SOURCE)
#  define BOOST_DELIMITED_DECL BOOST_SYMBOL_EXPORT
# else
#  define BOOST_DELIMITED_DECL BOOST_SYMBOL_IMPORT
# endif
#endif

#if ! defined(BOOST_DELIMITED_DECL)
# define BOOST_DELIMITED_DECL
#endif

#if ! defined(BOOST_DELIMITED_SOURCE) && ! defined(BOOST_ALL_NO_LIB) && ! defined(BOOST_DELIMITED_NO_LIB)
# define BOOST_LIB_NAME boost_delimited
# if defined(BOOST_ALL_DYN_LINK) || defined(BOOST_DELIMITED_DYN_LINK)
#  define BOOST_DYN_LINK
# endif
# include <boost/config/auto_link.hpp>
#endif

#endif // BOOST_DELIMITED_DETAIL_CONFIG_H
