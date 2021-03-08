#ifndef MYDATE_H
#define MYDATE_H

#include <iostream>
#include <string>
using namespace std;

class myDate 
{

  private:
    int month;
    int day;
    int year;

  public:
    myDate();
    myDate(int, int, int);
    void display();
    void increaseDate(int);
    void decreaseDate(int);
    int daysBetween(myDate);
    int getMonth();
    int getDay();
    int getYear();
    int dayOfYear();
    string dayName();
    string toString();
    void randBirthday();
    int JDdate();


};
#endif