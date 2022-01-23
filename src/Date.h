#ifndef AED_PROJ1_DATE_H
#define AED_PROJ1_DATE_H

#include <exception>
#include <iostream>
#include <iomanip>

using namespace std;
/**
 * Created to handle date type inputs.
 *
 * very simple implementation of date (format entered must be yyyy-mm-dd or yyyy/mm/dd.
 */
class Date {
    /**
     * responsible to assure the input of date into sstream works .
     * @param out the ostream that is fed the data.
     * @param d1 the data that is going to be transformed.
     * @return the out parameter after receiving the transformed date.
     */
    friend ostream& operator<<(ostream& out, const Date& d1);
    /**
     * esponsible to assure the output of date into sstream works
     * @param is the istream that is going to provide the data.
     * @param d the data that is ultimately used.
     * @return the is parameter after being processed.
     */
    friend istream& operator>>(istream& is, Date& d);
private:
    static unsigned monthArray[13];
    unsigned day;
    unsigned month;
    unsigned year;
public:
    /**
     * returns the number of days each specific month has.
     * @param year non-trivial because in odd years the number of days of certain months is different.
     * @param month trivial - every month has a specific number of days.
     * @return an int with the number of days.
     */
    inline unsigned GetMonthDay(int year, int month) const;
    /**
     * main constructor, assigns data to day,month and year atributes.
     * @param day trivial.
     * @param month trivial.
     * @param year trivial.
     */
    Date(unsigned day, unsigned month, unsigned year);
    /**
     * default constructor.
     */
    Date();
    /**
     * getter
     * @return day of "this" date object
     */
    unsigned getDay() const;
    /**
     * getter
     * @return month of "this" date object
     */
    unsigned getMonth() const;
    /**
     * getter
     * @return day of "this" date object
     */
    unsigned getYear() const;
    /**
     * comparable operator essential to the success of search and sort algorithms
     * @param d1
     * @return
     */
    bool operator<(const Date& d1) const;
    /**
     * equality operator essential to the success of if statements throughout the menu
     * @param d1
     * @return
     */
    bool operator==(const Date& d1) const;


};

class ErrorInvalidDate: public exception{
public:
    ErrorInvalidDate(){};
};


#endif
