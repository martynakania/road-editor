#include "Curve.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(PointTests)

BOOST_AUTO_TEST_CASE(create_a_left_curve)
{
    Curve curve(Direction::left);
    BOOST_CHECK_EQUAL( curve.get_direction(), Direction::left);
}

BOOST_AUTO_TEST_CASE(create_a_right_curve)
{
    Curve curve(Direction::right);
    BOOST_CHECK_EQUAL( curve.get_direction(), Direction::right);
}
/*
BOOST_AUTO_TEST_CASE(say_to_turn_right)
{
    Curve curve(Direction::right);
    BOOST_CHECK_EQUAL( curve.what(), "skrec w prawo");
}

BOOST_AUTO_TEST_CASE(say_to_turn_left)
{
    Curve curve(Direction::left);
    BOOST_CHECK_EQUAL( curve.what(), "skrec w lewo");
}
*/


BOOST_AUTO_TEST_SUITE_END()
