#include "Roundabaut.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(RoundabautTests)

BOOST_AUTO_TEST_CASE(create_a_roundabaut)
{
    Roundabaut r(2);
    BOOST_CHECK_EQUAL( r.get_exit() ,2);
}

BOOST_AUTO_TEST_CASE(create_a_roundabaut_with_negative_distance_Should_throw_error)
{

    BOOST_CHECK_THROW( Roundabaut r(-15), std::invalid_argument );
}
/*
BOOST_AUTO_TEST_CASE(say_about_roundabaut)
{
    Roundabaut r(2);
    BOOST_CHECK_EQUAL( r.what(), "zjedz z ronda 2 zjazdem");
}*/


BOOST_AUTO_TEST_SUITE_END()
