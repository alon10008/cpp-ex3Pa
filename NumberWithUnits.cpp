#include <iostream>
#include "NumberWithUnits.hpp"
#include <string>
#include <fstream>

using namespace ariel;
using namespace std;


void ariel::NumberWithUnits::read_units(ifstream& file) {

    /*string line;
    while(getline(file, line))
    {
        cout << line << endl;
    }
    file.close();*/

}
NumberWithUnits ariel::NumberWithUnits::operator+(const NumberWithUnits& nwu){

    NumberWithUnits n(*this);
    n.size += nwu.size;
    return n;

}
NumberWithUnits& ariel::NumberWithUnits::operator++(){

    ++this->size;
    return *this;

}
NumberWithUnits& ariel::NumberWithUnits::operator++(int){

    this->size++;
    return *this;

}
NumberWithUnits ariel::NumberWithUnits::operator+(const double& d){

    NumberWithUnits nwu(*this);
    nwu.size += d;
    return nwu;

}
NumberWithUnits& ariel::NumberWithUnits::operator+=(const NumberWithUnits& nwu){

    this->size += nwu.size;
    return *this;

}
NumberWithUnits& ariel::NumberWithUnits::operator+=(const double& d){

    this->size += d;
    return *this;

}
NumberWithUnits ariel::NumberWithUnits::operator-(const NumberWithUnits& nwu){

    NumberWithUnits n(*this);
    n.size -= nwu.size;
    return n;

}
NumberWithUnits& ariel::NumberWithUnits::operator--(){

    --this->size;
    return *this;

}
NumberWithUnits& ariel::NumberWithUnits::operator--(int){

    this->size--;
    return *this;

}
NumberWithUnits ariel::NumberWithUnits::operator-(const double& d){

    NumberWithUnits n(*this);
    n.size -= d;
    return n;

}
NumberWithUnits& ariel::NumberWithUnits::operator-=(const NumberWithUnits& nwu){

    this->size -= nwu.size;
    return *this;

}
NumberWithUnits& ariel::NumberWithUnits::operator-=(const double& d){

    this->size -= d;
    return *this;

}
NumberWithUnits ariel::NumberWithUnits::operator-(){

    NumberWithUnits n(*this);
    n.size *= -1;
    return n;

}
NumberWithUnits ariel::NumberWithUnits::operator*(const double& d){

    NumberWithUnits nwu(*this);
    nwu.size *= d;
    return nwu;

}
NumberWithUnits ariel::operator*(const double& d, const NumberWithUnits& nwu){
 
    NumberWithUnits n(nwu);
    n.size *= d;
    return n;

}
bool ariel::NumberWithUnits::operator<(const NumberWithUnits& nwu)const{

    return this->get_size()<nwu.get_size();

}
bool ariel::NumberWithUnits::operator<=(const NumberWithUnits& nwu)const{

    return this->size<=nwu.size;

}
bool ariel::NumberWithUnits::operator>(const NumberWithUnits& nwu)const{

    return this->size>nwu.size;

}
bool ariel::NumberWithUnits::operator>=(const NumberWithUnits& nwu)const{

    return this->size>=nwu.size;

}
bool ariel::NumberWithUnits::operator==(const NumberWithUnits& nwu)const{

    return this->size==nwu.size;

}
bool ariel::NumberWithUnits::operator!=(const NumberWithUnits& nwu)const{

    return this->size!=nwu.size;

}
ostream& ariel::operator<<(ostream& os, const NumberWithUnits& nwu){

    os << nwu.size << " [" << nwu.unit << "]"; 
    return os;

}
istream& ariel::operator>>(istream& is, NumberWithUnits& nwu){

    string unit;
    is >> nwu.size;
    is >> nwu.unit >> nwu.unit;
    return is;

}


