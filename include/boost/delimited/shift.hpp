
//          Copyright Oliver Kowalke 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_DELIMITED_SHIFT_H
#define BOOST_DELIMITED_SHIFT_H

#include <exception>
#include <type_traits>
#include <utility>

#include <boost/assert.hpp>
#include <boost/config.hpp>
#include <boost/context/continuation.hpp>

#include <boost/delimited/detail/config.hpp>

#ifdef BOOST_HAS_ABI_HEADERS
#  include BOOST_ABI_PREFIX
#endif

namespace boost {
namespace delimited {

template< typename R >
class shift_op {
private:
    context::continuation   c_;

public:
    template< typename Fn >
    shift_op( Fn && fn) :
        c_{} {
        c_ = context::callcc(
                [fn=std::move( fn)]( context::continuation && c) mutable {
                    R r = fn();
                    return std::move( c);
                });
    }

    void operator()() {
        context::resume( std::move( c_) );
    }
};

template<>
class shift_op< void > {
private:
    context::continuation   c_;

public:
    template< typename Fn >
    shift_op( Fn && fn) :
        c_{} {
        c_ = context::callcc(
                [fn=std::move( fn)]( context::continuation && c) mutable {
                    fn();
                    return std::move( c);
                });
    }

    void operator()() {
        context::resume( std::move( c_) );
    }
};

struct shift_proxy {
    template< typename Fn >
    void operator=( Fn && fn) {
        typedef typename std::result_of< typename std::decay< Fn >::type() >::type  result_t;
        shift_op< result_t > op{ std::forward< Fn >( fn) };
        op();
    }

    static shift_proxy instance;
};

#define shift boost::delimited::shift_proxy::instance

}}

#ifdef BOOST_HAS_ABI_HEADERS
#  include BOOST_ABI_SUFFIX
#endif

#endif // BOOST_DELIMITED_SHIFT_H
