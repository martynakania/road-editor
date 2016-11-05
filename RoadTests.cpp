#include "Road.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(RoadTests)

BOOST_AUTO_TEST_CASE(create_a_road_and_get_instruction)
{
    Curve *c1= new Curve(Direction::left);
    Roundabaut *r1=new Roundabaut(2);
    Straight *s1 =new Straight(500);
    Road road( {c1, s1, r1} ) ;
    BOOST_CHECK_EQUAL( road.get_instruction(0) ,c1);
    BOOST_CHECK_EQUAL( road.get_instruction(1) ,s1);
    BOOST_CHECK_EQUAL( road.get_instruction(2) ,r1);
}

BOOST_AUTO_TEST_CASE(add_an_instruction3)
{
    Curve *c1= new Curve(Direction::left);
    Curve *c2= new Curve(Direction::right);
    Roundabaut *r1=new Roundabaut(2);
    Straight *s1 =new Straight(500);
    Road road( {c1, s1, c2} );
    road.add_instruction(s1);
    road.add_instruction(r1);
    BOOST_CHECK_EQUAL( road.get_instruction(1) ,s1);
    BOOST_CHECK_EQUAL( road.get_instruction(3) ,s1);
    BOOST_CHECK_EQUAL( road.get_instruction(4) ,r1);
}

BOOST_AUTO_TEST_CASE(delete_an_instruction)
{
    Curve *c1= new Curve(Direction::left);
    Curve *c2= new Curve(Direction::right);
    Roundabaut *r1=new Roundabaut(2);
    Straight *s1 =new Straight(500);
    Road road( {c1, s1, c2, s1} );
    road.delete_instruction(1);
    BOOST_CHECK_EQUAL( road.get_instruction(0) ,c1);
    BOOST_CHECK_EQUAL( road.get_instruction(1) ,c2);
    BOOST_CHECK_EQUAL( road.get_instruction(2) ,s1);
}

BOOST_AUTO_TEST_CASE(delete_last_instruction)
{
    Curve *c1= new Curve(Direction::left);
    Curve *c2= new Curve(Direction::right);
    Roundabaut *r1=new Roundabaut(2);
    Straight *s1 =new Straight(500);
    Road road( {c1, s1, c2, s1} );
    road.delete_last_instruction();
    BOOST_CHECK_EQUAL( road.get_instruction(0) ,c1);
    BOOST_CHECK_EQUAL( road.get_instruction(1) ,s1);
    BOOST_CHECK_EQUAL( road.get_instruction(2) ,c2);
}

BOOST_AUTO_TEST_CASE(edit_instruction)
{
    Curve *c1= new Curve(Direction::left);
    Roundabaut *r1=new Roundabaut(2);
    Straight *s1 =new Straight(500);
    Road road( {c1, s1} );
    road.edit_instruction(1, r1);
    BOOST_CHECK_EQUAL( road.get_instruction(0) ,c1);
    BOOST_CHECK_EQUAL( road.get_instruction(1) ,r1);
}

BOOST_AUTO_TEST_CASE(edit_first_instruction)
{
    Curve *c1= new Curve(Direction::left);
    Roundabaut *r1=new Roundabaut(2);
    Straight *s1 =new Straight(500);
    Road road( {c1, s1} );
    road.edit_instruction(0, r1);
    BOOST_CHECK_EQUAL( road.get_instruction(1) ,s1);
    BOOST_CHECK_EQUAL( road.get_instruction(0) ,r1);
}

BOOST_AUTO_TEST_CASE(edit_instruction_in_the_middle)
{
    Curve *c1= new Curve(Direction::left);
    Roundabaut *r1=new Roundabaut(2);
    Straight *s1 =new Straight(500);
    Road road( {c1, s1, c1} );
    road.edit_instruction(1, r1);
    BOOST_CHECK_EQUAL( road.get_instruction(2) ,c1);
    BOOST_CHECK_EQUAL( road.get_instruction(1) ,r1);
    BOOST_CHECK_EQUAL( road.get_instruction(0) ,c1);
}

BOOST_AUTO_TEST_CASE(edit_instruction_Give_the_same)
{
    Curve *c1= new Curve(Direction::left);
    Roundabaut *r1=new Roundabaut(2);
    Straight *s1 =new Straight(500);
    Road road( {c1, s1} );
    road.edit_instruction(1, s1);
    BOOST_CHECK_EQUAL( road.get_instruction(0) ,c1);
    BOOST_CHECK_EQUAL( road.get_instruction(1) ,s1);
}
BOOST_AUTO_TEST_CASE(check_if_there_is_a_roundabaut_Should_return_true)
{
    Curve *c1= new Curve(Direction::left);
    Roundabaut *r1=new Roundabaut(2);
    Straight *s1 =new Straight(500);
    Road road1( {c1, s1, s1, r1} );
    BOOST_CHECK( road1.is_there_a_roundabaut() );
    Road road2( {c1, s1, r1, s1} );
    BOOST_CHECK( road2.is_there_a_roundabaut() );
    Road road3( {r1, c1, s1, s1} );
    BOOST_CHECK( road3.is_there_a_roundabaut() );
}

BOOST_AUTO_TEST_CASE(check_if_there_is_a_roundabaut_Should_return_falsee)
{
    Curve *c1= new Curve(Direction::left);
    Straight *s1 =new Straight(500);
    Road road( {c1, s1} );
    BOOST_CHECK(! road.is_there_a_roundabaut() );
}

BOOST_AUTO_TEST_CASE(get_amount_of_instructions)
{
    Curve *c1= new Curve(Direction::left);
    Straight *s1 =new Straight(500);
    Road road( {c1, s1} );
    BOOST_CHECK_EQUAL( road.get_amount_of_instructions(),2);
}

BOOST_AUTO_TEST_CASE(get_amount_of_instruction_in_empty_collection)
{
    Road road;
    BOOST_CHECK_EQUAL( road.get_amount_of_instructions(),0);
}
BOOST_AUTO_TEST_CASE(check_if_is_empty_Should_return_false)
{
    Curve *c1= new Curve(Direction::left);
    Straight *s1 =new Straight(500);
    Road road( {c1, s1} );
    BOOST_CHECK(! road.is_empty());
}

BOOST_AUTO_TEST_CASE(check_if_is_empty_Should_return_true)
{
    Road road;
    BOOST_CHECK( road.is_empty());
}

BOOST_AUTO_TEST_CASE(safe_and_load_from_the_file)
{
    Curve *c1= new Curve(Direction::left);
    Roundabaut *r1=new Roundabaut;
    *r1= Roundabaut(2);
    Straight *s1 =new Straight(500);

    Road oldRoad( {r1, c1,  s1} ), newRoad;
    oldRoad.save_to_the_file("test");
    newRoad.load_from_the_file("test");
    BOOST_CHECK( oldRoad==newRoad);
}
BOOST_AUTO_TEST_SUITE_END()
