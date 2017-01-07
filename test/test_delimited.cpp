
//          Copyright Oliver Kowalke 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <tuple>
#include <vector>

#include <boost/assert.hpp>
#include <boost/test/unit_test.hpp>

#include <boost/delimited/all.hpp>

namespace ctx = boost::context;
namespace del = boost::delimited;

void test_reset_proxy() {
    reset = []{};
    reset = []{ int i = 0; return i; };
}

void test_reset_lambda() {
    int i = 0;
    reset = [&i]{ i = 7; };
    BOOST_CHECK_EQUAL( i, 7);
}

void test_void() {
    int i = 0;
    reset = [&i]{
        i = 3;
        shift = [&i](){
            i += i;
        };
    };
    BOOST_CHECK_EQUAL( i, 6);
}

boost::unit_test::test_suite * init_unit_test_suite( int, char* [])
{
    boost::unit_test::test_suite * test =
        BOOST_TEST_SUITE("Boost.Delimited: delimited continuation test suite");

    test->add( BOOST_TEST_CASE( & test_reset_proxy) );
    test->add( BOOST_TEST_CASE( & test_reset_lambda) );
    test->add( BOOST_TEST_CASE( & test_void) );

    return test;
}
