#include <iostream>
#include "NumberWithUnits.hpp"
#include "doctest.h"
#include <fstream>

using namespace std;
using namespace ariel;

TEST_CASE("LENGTH") {

    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);
    NumberWithUnits a{1, "cm"};
    NumberWithUnits b{1, "m"};
    NumberWithUnits c{1, "km"};
    /////NEGATIVE/////
    CHECK(-a.get_size() == -1*a.get_size());
    /////ADDITION/////
    CHECK((a+b).get_size()==101);
    CHECK((a+b).get_unit()=="cm");
    CHECK((b+a).get_size()==1.01);
    CHECK((b+a).get_unit()=="m");
    CHECK((a+c).get_size()==100001);
    CHECK((a+c).get_unit()=="cm");
    CHECK((c+a).get_size()==1.00001);
    CHECK((c+a).get_unit()=="km");
    a++;
    CHECK(a.get_size()==2);
    ++a;
    CHECK(a.get_size() == 3);
    CHECK((a+5).get_size() == 8);
    a += 10;
    CHECK(a.get_size() == 13);
    /////SUBTRACTION/////
    a = NumberWithUnits(1, "cm");
    b = NumberWithUnits(1, "m");
    c = NumberWithUnits(1, "km");
    CHECK((a-b).get_size()==-99);
    CHECK((a-b).get_unit()=="cm");
    CHECK((b-a).get_size()==0.99);
    CHECK((b-a).get_unit()=="m");
    CHECK((a-c).get_size()==-999999);
    CHECK((a-c).get_unit()=="cm");
    CHECK((c-a).get_size()==0.99999);
    CHECK((c-a).get_unit()=="km");
    a--;
    CHECK(a.get_size()==0);
    --a;
    CHECK(a.get_size() == -1);
    CHECK((a-5).get_size() == -6);
    a -= 10;
    CHECK(a.get_size() == -11);
    /////MULTIPLICATION/////
    a = NumberWithUnits(1, "cm");
    b = NumberWithUnits(1, "m");
    c = NumberWithUnits(1, "km");
    CHECK((a*4).get_size()==4);
    CHECK((5*a).get_size()==5);
    /////BOOLEAN//////
    //CHECK(a<b);
    //CHECK(b<c);
    //CHECK(a==NumberWithUnits(0.01, "m"));
    //CHECK(a==NumberWithUnits(0.000001, "km"));


}
TEST_CASE("WEIGHT") {

    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);
    NumberWithUnits a{1, "g"};
    NumberWithUnits b{1, "kg"};
    NumberWithUnits c{1, "ton"};
    /////NEGATIVE/////
    CHECK(-a.get_size() == -1*a.get_size());
    /////ADDITION/////
    CHECK((a+b).get_size()==1001);
    CHECK((a+b).get_unit()=="g");
    CHECK((b+a).get_size()==1.001);
    CHECK((b+a).get_unit()=="kg");
    CHECK((a+c).get_size()==1000001);
    CHECK((a+c).get_unit()=="g");
    CHECK((c+a).get_size()==1.000001);
    CHECK((c+a).get_unit()=="ton");
    a++;
    CHECK(a.get_size()==2);
    ++a;
    CHECK(a.get_size() == 3);
    CHECK((a+5).get_size() == 8);
    a += 10;
    CHECK(a.get_size() == 13);
    /////SUBTRACTION/////
    a = NumberWithUnits(1, "g");
    b = NumberWithUnits(1, "kg");
    c = NumberWithUnits(1, "ton");
    CHECK((a-b).get_size()==-999);
    CHECK((a-b).get_unit()=="g");
    CHECK((b-a).get_size()==0.999);
    CHECK((b-a).get_unit()=="kg");
    CHECK((a-c).get_size()==-9999999);
    CHECK((a-c).get_unit()=="g");
    CHECK((c-a).get_size()==0.999999);
    CHECK((c-a).get_unit()=="ton");
    a--;
    CHECK(a.get_size()==0);
    --a;
    CHECK(a.get_size() == -1);
    CHECK((a-5).get_size() == -6);
    a -= 10;
    CHECK(a.get_size() == -11);
    /////MULTIPLICATION/////
    a = NumberWithUnits(1, "g");
    b = NumberWithUnits(1, "kg");
    c = NumberWithUnits(1, "ton");
    CHECK((a*4).get_size()==4);
    CHECK((5*a).get_size()==5);

}
TEST_CASE("TIME"){

    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);
    NumberWithUnits a{1, "sec"};
    NumberWithUnits b{1, "min"};
    NumberWithUnits c{1, "hour"};
    /////NEGATIVE/////
    CHECK(-a.get_size() == -1*a.get_size());
    /////ADDITION/////
    CHECK((a+b).get_size()==61);
    CHECK((a+b).get_unit()=="sec");
    CHECK((b+a).get_size()==(double)((double)61/60));
    CHECK((b+a).get_unit()=="min");
    CHECK((a+c).get_size()==3601);
    CHECK((a+c).get_unit()=="sec");
    CHECK((c+a).get_size()==(double)((double)3601/60));
    CHECK((c+a).get_unit()=="hour");
    a++;
    CHECK(a.get_size()==2);
    ++a;
    CHECK(a.get_size() == 3);
    CHECK((a+5).get_size() == 8);
    a += 10;
    CHECK(a.get_size() == 13);
    /////SUBTRACTION/////
    a = NumberWithUnits(1, "sec");
    b = NumberWithUnits(1, "min");
    c = NumberWithUnits(1, "hour");
    CHECK((a-b).get_size()==-59);
    CHECK((a-b).get_unit()=="sec");
    CHECK((b-a).get_size()==(double)((double)59/60));
    CHECK((b-a).get_unit()=="min");
    CHECK((a-c).get_size()==-3599);
    CHECK((a-c).get_unit()=="sec");
    CHECK((c-a).get_size()==(double)((double)3599/3600));
    CHECK((c-a).get_unit()=="hour");
    a--;
    CHECK(a.get_size()==0);
    --a;
    CHECK(a.get_size() == -1);
    CHECK((a-5).get_size() == -6);
    a -= 10;
    CHECK(a.get_size() == -11);
    /////MULTIPLICATION/////
    a = NumberWithUnits(1, "sec");
    b = NumberWithUnits(1, "min");
    c = NumberWithUnits(1, "hour");
    CHECK((a*4).get_size()==4);
    CHECK((5*a).get_size()==5);

}
TEST_CASE("MONEY") {

    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);
    NumberWithUnits a{1, "USD"};
    NumberWithUnits b{1, "ILS"};
    /////NEGATIVE/////
    CHECK(-a.get_size() == -1*a.get_size());
    /////ADDITION/////
    CHECK((a+b).get_size()==(double)(1 + (1 / 3.33)));
    CHECK((a+b).get_unit()=="USD");
    CHECK((b+a).get_size()==(1 + 3.33));
    CHECK((b+a).get_unit()=="ILS");
    a++;
    CHECK(a.get_size()==2);
    ++a;
    CHECK(a.get_size() == 3);
    CHECK((a+5).get_size() == 8);
    a += 10;
    CHECK(a.get_size() == 13);
    /////SUBTRACTION/////
    a = NumberWithUnits(1, "USD");
    b = NumberWithUnits(1, "ILS");
    CHECK((a-b).get_size()==(double)(1-3.33));
    CHECK((a-b).get_unit()=="USD");
    CHECK((b-a).get_size()==(double)(1-(1/3.33)));
    CHECK((b-a).get_unit()=="ILS");
    a--;
    CHECK(a.get_size()==0);
    --a;
    CHECK(a.get_size() == -1);
    CHECK((a-5).get_size() == -6);
    a -= 10;
    CHECK(a.get_size() == -11);
    /////MULTIPLICATION/////
    a = NumberWithUnits(1, "USD");
    b = NumberWithUnits(1, "ILS");
    CHECK((a*4).get_size()==4);
    CHECK((5*a).get_size()==5);


}

TEST_CASE("THROW") {

    CHECK_THROWS(NumberWithUnits(1, "lb"));
    CHECK_THROWS(NumberWithUnits(1, "ft"));
    CHECK_THROWS(NumberWithUnits(1, "day"));
    CHECK_THROWS(NumberWithUnits(1, "EU"));

}