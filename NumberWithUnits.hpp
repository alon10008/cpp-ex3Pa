#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;


namespace ariel{

    #define LENGTH 1
    #define WEIGHT 2
    #define TIME 3
    #define MONEY 4

    class NumberWithUnits{
    
        public:
            static void read_units(ifstream& file);
            NumberWithUnits(double size, string unit)
            {
                this->size = size; 
                this->unit = unit;
                if(unit=="m" || unit=="cm" || unit=="km"){this->type = LENGTH;}
                else if(unit=="kg" || unit=="ton" || unit=="g"){this->type = WEIGHT;}
                else if(unit=="hour" || unit=="min" || unit=="sec"){this->type = TIME;}
                else if(unit=="USD" || unit=="ILS"){this->type = MONEY;}
                else{throw invalid_argument("wrong input!\n");}
            }
            NumberWithUnits(const NumberWithUnits& n){this->size = n.get_size(); this->unit = n.get_unit();}
            double get_size()const {return this->size;}
            string get_unit()const {return this->unit;}
            NumberWithUnits operator+(const NumberWithUnits& nwu);
            NumberWithUnits& operator++();
            NumberWithUnits& operator++(int);
            NumberWithUnits operator+(const double& d);
            NumberWithUnits& operator+=(const NumberWithUnits& nwu);
            NumberWithUnits& operator+=(const double& d);
            NumberWithUnits operator-(const NumberWithUnits& nwu);
            NumberWithUnits& operator--();
            NumberWithUnits& operator--(int);
            NumberWithUnits operator-(const double& d);
            NumberWithUnits& operator-=(const NumberWithUnits& nwu);
            NumberWithUnits& operator-=(const double& d);
            NumberWithUnits operator-();
            NumberWithUnits operator*(const double& d);
            friend NumberWithUnits operator*(const double& d, const NumberWithUnits& nwu);
            bool operator<(const NumberWithUnits& nwu)const;
            bool operator<=(const NumberWithUnits& nwu)const;
            bool operator>(const NumberWithUnits& nwu)const;
            bool operator>=(const NumberWithUnits& nwu)const;
            bool operator==(const NumberWithUnits& nwu)const;
            bool operator!=(const NumberWithUnits& nwu)const;
            friend ostream& operator<<(ostream& os, const NumberWithUnits& nwu);
            friend istream& operator>>(istream& is, NumberWithUnits& nwu);
        private:
            string unit;
            double size;
            int type;
    };

}
