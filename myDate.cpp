#include "myDate.h"

using namespace std;

int Greg2Julian(int y, int m, int d)
{

  int I = y;
  int J = m;
  int K = d;
  
  int JD = K - 32075 + 1461 * (I + 4800 + (J-14)/12)/4 + 367 * (J - 2 - (J - 14)/12 * 12)/12 - 3 * ((I + 4900 + (J-14)/12)/100)/4;

  return JD;

}

void Julian2Greg(int JD, int & year, int & month, int & day)
{

  int I,J,K;
  int L = JD + 68569;
  int N = 4 * L/146097;
  L = L - (146097 * N + 3)/4;
  I = 4000 * (L + 1) / 1461001;
  L = L - 1461 * I/4 + 31;
  J = 80 * L /2447;
  K = L - 2447 * J/80;
  L = J/11;
  J = J + 2 - 12 * L;
  I = 100 * (N - 49) + I + L;

  year = I;
  month = J; 
  day = K;

}

myDate::myDate()
{

  month = 5;
  day = 11;
  year = 1959;

}

myDate::myDate(int m, int d, int y)
{

  int orginalM = m;
  int orginalD = d;
  int orginalY = y;

  int JD = Greg2Julian(y, m, d);
  Julian2Greg(JD, y, m, d);

  if( (m == orginalM) && (d == orginalD) && (y == orginalY) )
  {

    month = m;
    day = d;
    year = y;

  }
  else
  {
  
    month = 5;
    day = 11;
    year = 1959;

  }


  /*
  if ( (m >= 13 || m <= 0) || (d >= 32 || d <= 0) || (y <= -4769) )
  {

    month = 5;
    day = 11;
    year = 1959;

  }
  else
  {

    month = m;
    day = d;
    year = y;

  }
  */

}

void myDate::display()
{

  string monthName;

  if(month == 1)
  {

    monthName = "January";

  }
  else if(month == 2)
  {

    monthName = "February";

  }
  else if(month == 3)
  {

    monthName = "March";

  }
  else if(month == 4)
  {

    monthName = "April";

  }
  else if(month == 5)
  {

    monthName = "May";

  }
  else if(month == 6)
  {

    monthName = "June";

  }
  else if(month == 7)
  {

    monthName = "July";

  }
  else if(month == 8)
  {

    monthName = "August";

  }
  else if(month == 9)
  {

    monthName = "September";

  }
  else if(month == 10)
  {

    monthName = "October";

  }
  else if(month == 11)
  {

    monthName = "November";

  }
  else if(month == 12)
  {

    monthName = "December";

  }

  cout << monthName << " " << day <<", " << year;

}

void myDate::increaseDate(int days)
{

  int JD = Greg2Julian(year, month, day);
  JD += days;
  Julian2Greg(JD, year, month, day);

}

void myDate::decreaseDate(int days)
{

  int JD = Greg2Julian(year, month, day);
  JD -= days;
  Julian2Greg(JD, year, month, day);

}

int myDate::daysBetween(myDate d)
{

  int thisDate = Greg2Julian(year, month, day);
  int otherDate = Greg2Julian(d.getYear(), d.getMonth(), d.getDay());
  otherDate -= thisDate;
  return otherDate;

}

int myDate::getMonth()
{

  return month;

}

int myDate::getDay()
{

  return day;

}

int myDate::getYear()
{

  return year;

}

int myDate::dayOfYear()
{

 int JD = Greg2Julian(year, month, day);
 int startOfYear = Greg2Julian(year, 1, 1);
 JD = JD - startOfYear + 1;
 return JD;

}

string myDate::dayName()
{

  int JD = Greg2Julian(year, month, day);
  string dayName;

  if(JD % 7 == 0)
  {

    dayName = "Monday";

  }
  else if(JD % 7 == 1)
  {

    dayName = "Tuesday";

  }
  else if(JD % 7 == 2)
  {

    dayName = "Wednesday";

  }
  else if(JD % 7 == 3)
  {

    dayName = "Thursday";

  }
  else if(JD % 7 == 4)
  {

    dayName = "Friday";

  }
  else if(JD % 7 == 5)
  {

    dayName = "Saturday";

  }
  else if (JD % 7 == 6)
  {

    dayName = "Sunday";
    
  }
  
   return dayName;

}

string myDate::toString()
{

  string date;

  if(month == 1)
  {

    date = "January";

  }
  else if(month == 2)
  {

    date = "February";

  }
  else if(month == 3)
  {

    date = "March";

  }
  else if(month == 4)
  {

    date = "April";

  }
  else if(month == 5)
  {

    date = "May";

  }
  else if(month == 6)
  {

    date = "June";

  }
  else if(month == 7)
  {

    date = "July";

  }
  else if(month == 8)
  {

    date = "August";

  }
  else if(month == 9)
  {

    date = "September";

  }
  else if(month == 10)
  {

    date = "October";

  }
  else if(month == 11)
  {

    date = "November";

  }
  else if(month == 12)
  {

    date = "December";

  }
  
  date = date + " " + to_string(day) + ", " + to_string(year);

  return date;
}

 void myDate::randBirthday()
 {

   int oldestDate = Greg2Julian(1995, 1, 1);
   int youngestDate = Greg2Julian(2005, 12, 31);
   int range = oldestDate - youngestDate + 1;
  
   //srand(time(NULL));
   int birthday = rand() % range + oldestDate;
   Julian2Greg(birthday, year, month, day);


 }