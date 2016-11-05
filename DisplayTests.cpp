#include <boost/test/unit_test.hpp>
#include <boost/test/output_test_stream.hpp>
#include <iostream>
#include "Display.h"

BOOST_AUTO_TEST_SUITE( TestSuite1 )

struct cout_redirect {
    cout_redirect( std::streambuf * new_buffer )
        : old( std::cout.rdbuf( new_buffer ) )
    { }

    ~cout_redirect( ) {
        std::cout.rdbuf( old );
    }

private:
    std::streambuf * old;
};
Display visitor;
BOOST_AUTO_TEST_CASE( say_to_go_straight )
{
    Straight s(15);
    boost::test_tools::output_test_stream output;
    {
        cout_redirect guard( output.rdbuf( ) );
        s.accept(visitor);
    }

    BOOST_CHECK( output.is_equal( "jedz prosto 15 metrow\n" ) );
}

BOOST_AUTO_TEST_CASE( say_to_turn_left)
{
    Curve c(Direction::left);
    boost::test_tools::output_test_stream output;
    {
        cout_redirect guard( output.rdbuf( ) );
        c.accept(visitor);
    }

    BOOST_CHECK( output.is_equal( "skrec w lewo\n" ) );
}

BOOST_AUTO_TEST_CASE( say_to_turn_right)
{
    Curve c(Direction::right);
    boost::test_tools::output_test_stream output;
    {
        cout_redirect guard( output.rdbuf( ) );
        c.accept(visitor);
    }

    BOOST_CHECK( output.is_equal( "skrec w prawo\n" ) );
}

BOOST_AUTO_TEST_CASE( say_abaut_a_roundabaut)
{
    Roundabaut r(3);
    boost::test_tools::output_test_stream output;
    {
        cout_redirect guard( output.rdbuf( ) );
        r.accept(visitor);
    }

    BOOST_CHECK( output.is_equal( "zjedz z ronda 3 zjazdem\n" ) );
}
BOOST_AUTO_TEST_SUITE_END()
