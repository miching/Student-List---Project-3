#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include "myDate.h"
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
int randomStudentID();

int main()
{
  
  Student *sptrArray[10];           //AN array of student pointers
  Student ** sptr = sptrArray;      //Student pointer pointer
  populate(sptr);                   //Pass the pointer to populate funtion

  display(sptr);
  menu();
  int input;
  cin >> input;

  while (input != 6)
  {

    //Display list sorted by Name
    if(input == 1)
    {

      sortByName(sptr);
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

  Student **stdPtr = studentPtr;
  Student **creatorPtr = studentPtr;

  //10 elements
  for (int i = 0; i < 10; i++)
  {

    *studentPtr = new Student;
    studentPtr++;

  }
  
  myDate randoBDList [10];
  for(int i = 0; i < 10; i++)
  {

    myDate randoBD;
    randoBD.randBirthday();
    randoBDList[i] = randoBD;

  }

  **creatorPtr = {"Tom Thumb", randomStudentID(), 'C', randoBDList[0], "Small Ville"};
  creatorPtr++;

  **creatorPtr = {"Fred Flintstone", randomStudentID(), 'D', randoBDList[1], "Bedrock"};
  creatorPtr++;

  **creatorPtr = {"Sponge Bob", randomStudentID(), 'B', randoBDList[2], "Bikini Bottom"};
  creatorPtr++;

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
    left << setw(25) << "Birthday" <<
    left << setw(10) << "Hometown" <<endl;

  Student **temp = studentPtr;
  for(int i = 0; i < 10; i++)
  {

    cout << left<< setw(20) <<(**temp).name <<
      left << setw(12) << (**temp).studentID <<
      left << setw(8) << (**temp).grade << 
      left << setw(25) << (**temp).birthday.toString() << 
      left << setw(10) << (**temp).hometown << endl;

    temp++;

  }
  
}

void sortByName(Student **studentPtr)
{

  Student **std1 = studentPtr;
  Student **std2 = studentPtr;

  for(int i = 0; i < 9; i++)
  {
    for(int j = 1; j < 10; j++)
    {

      std1 = studentPtr + i;
      std2 = studentPtr + j;

      if(strcmp( (*std1) -> name, (*std2) -> name) > 0)
      {

        Student *temp = *std1;
        *std1 = *std2;
        *std2 = temp;

      }

    }



  }

}

void sortByStudentID(Student **studentPtr)
{

 

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

int randomStudentID()
{

  int minID = 9000;
  int maxID = 9999;
  int range = 9999 - 9000 + 1;
  
  //srand(time(NULL));
  int ID = rand() % range + minID;

  return ID;
 
}