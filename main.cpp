#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include "myDate.h"
//#include "myDate.cpp"
using namespace std;


struct Student
{

  char name[20];
  int studentID;
  char grade;
  myDate birthday;
  string hometown;

};

void menu();
void populate (Student **studentPtr);
void display(Student **studentPtr);
void sortByName(Student **studentPtr);
void sortByStudentID(Student **studentPtr);
void sortByGrade(Student **studentPtr);
void sortByBirthday(Student **studentPtr);
void sortByHometown(Student **studentPtr);
myDate randomBirthday();
int randomStudentID(int stdIDList[]);

int main()
{
  
  int studentID[10];
  Student *sptrArray[10];           //AN array of student pointers
  Student ** sptr = sptrArray;      //Student pointer pointer
  populate(sptr);   
  myDate bd;                //Pass the pointer to populate funtion
  *sptrArray[0] = {"Tom Thumb", randomStudentID(studentID), 'C', bd, "Small Ville"};
  strcpy( (*sptrArray[0]).name, "Tom Thumb");
  
  *sptrArray[1] = {"Fred Flintstone", randomStudentID(studentID), 'D', bd, "Bedrock"};
  strcpy( (*sptrArray[1]).name, "Fred Flintstone");
  //*sptrArray[2] = {"Sponge Bob", randomStudentID(studentID), 'B', randomBirthday(), "Bikini Bottom"};
  display(sptr);
  menu();
  int input;
  cin >> input;

  while (input != 6)
  {

    //Display list sorted by Name
    if(input == 1)
    {

     // sortByName(sptr);
      display(sptr);

    }

    //Display list sorted by Student ID
    else if(input == 2)
    {

      sortByStudentID(sptr);
      display(sptr);

    }

    //Display list sorted by Grade
    else if(input == 3)
    {

      sortByGrade(sptr);
      display(sptr);

    }

    //Display list sorted by Birthday
    else if(input == 4)
    {

      sortByBirthday(sptr);
      display(sptr);

    }

    //Display list sorted by Home Town
    else if(input == 5)
    {

      sortByHometown(sptr);
      display(sptr);


    }

    else
    {

      cout << "Invalid Input";

    }

    cout << endl;
    menu();
    cin >> input;

  }

  return 0;
  
}

void populate (Student **studentPtr)
{

  //10 elements
  for (int i = 0; i < 10; i++)
  {

    *studentPtr = new Student;
    studentPtr++;

  }

}

void menu()
{

  cout << "1) Display list sorted by Name" << endl;
  cout << "2) Display list sorted by Student ID" << endl;
  cout << "3) Display list sorted by Grade" << endl;
  cout << "4) Display list sorted by Birthday" << endl; 
  cout << "5) Display list sorted by Home Town" << endl;
  cout << "6) Exit" << endl;

}

void display(Student **studentPtr)
{

  cout << left << setw(20) <<"Name" << 
    left << setw(12) << "Student ID" <<
    left << setw(8) << "Grade" <<
    left << setw(18) << "Birthday" <<
    left << setw(10) << "Hometown" <<endl;

  Student **temp = studentPtr;
  for(int i = 0; i < 10; i++)
  {

    cout << left<< setw(20) <<(**temp).name <<
      left << setw(12) << (**temp).studentID <<
      left << setw(8) << (**temp).grade << 
      left << setw(18) << (**temp).birthday.toString() << 
      left << setw(10) << (**temp).hometown << endl;

    temp++;

  }
  
}

void sortByName(Student **studentPtr)
{

  Student **std1;
  Student **std2;

  for(int i = 0; i < 10; i++)
  {
    for(int j = 1; j < 10; j++)
    {

      std1 = studentPtr + i;
      std2 = studentPtr + j;

      if(strcmp( (*std1) -> name, (*std2) -> name) > 0)
      {

        Student **temp = std1;
        strcpy( (*std1) -> name, (*std2) -> name );
        strcpy( (*std2) -> name, (*temp) -> name );

      }

    }



  }

}

void sortByStudentID(Student **studentPtr)
{

  Student **std1;
  Student **std2;

  for(int i = 0; i < 10; i++)
  {
    for(int j = 1; j < 10; j++)
    {

      std1 = studentPtr + i;
      std2 = studentPtr + j;

      if( (*std2) -> studentID > (*std1) -> studentID)
      {

        Student **temp = std1;
        (*std1) -> studentID = (*std2) -> studentID;
        (*std2) -> studentID = (*temp) -> studentID;
       

      }

    }



  }

}

void sortByGrade(Student **studentPtr)
{



}

void sortByBirthday(Student **studentPtr)
{



}

void sortByHometown(Student **studentPtr)
{



}

myDate randomBirthday()
{

  myDate randomBD;
  randomBD.randBirthday();
  
}

int randomStudentID(int stdIDList[])
{

  int minID = 9000;
  int maxID = 9999;
  int diff = 9999 - 9000 + 1;

  int ID;
  bool repeat = true;
  bool doub = false;
  //srand(time(NULL));
  ID = rand() % diff + minID;
  cout <<ID << endl;

  
return ID;
}