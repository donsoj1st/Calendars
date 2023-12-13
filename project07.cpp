/***********************************************************************
* Program:
*    Project 07, Calendar
*    Brother Ridges, cs124
* Author:
*    Adesoji Adekunle
* Summary: 
*   This Program will display "Calendar" on the screen.
*    Estimated:  0.8 hrs   
*    Actual:     0.6 hrs
*     it is not easy to use but as time goes on I will be use to it.
************************************************************************/
#include <iomanip>
#include <iostream>
using namespace std;

/*********************************************************************
 * This function will get month number for the user.
 *********************************************************************/
int getMonthNumber()
{
   int monthNumber;
   cout << "Enter a month number: ";// prompt user for month number
   cin >> monthNumber;// allow user to enter month number
   while ( monthNumber < 0 || monthNumber > 12 )
   {
      cout << "Month must be between 1 and 12.\n";
      cout << "Enter a month number: ";
      cin >> monthNumber;
   }
   
   return monthNumber;
}

/*********************************************************************
 * This function will get the year from the user
 ********************************************************************/
int getYear()
{
   int year; //  variable year
   cout << "Enter year: ";  // prompt user for  year
   cin >> year; //Allow  the user to enter year
   while ( year < 1753 )
   {
      cout << "Year must be 1753 or later.\n";
      cout << "Enter year: ";
      cin >> year;
   }
   cout << "\n";


   
   return year; //return the value for year
}

/********************************************************************
 * The function isALeapyear determine is a leap year.
 ********************************************************************/
bool isALeapyear( int years )
{
   if ( years % 400 == 0 || ( years % 100 != 0 && years % 4 == 0 ) )
      return true;    // this condition determine leap year by 
   else                                  // returning true or false
      return false; 
         
         
}

/*******************************************************************
 * this function return the  number in a year and leap year
 ******************************************************************/
int yearNumber( int yearNumber )
{
   if ( isALeapyear( yearNumber ))
      return 366; // return yearnumber when it is leap year
   else
      return 365; // return year number when not leap year
         
}

/*********************************************************************
 * This function will return the number of days in a month
 *********************************************************************/
int getDaynumber(int year, int day )
{
   
   if ( day == 2 &&  isALeapyear( year ))//this will determine what number
      return 29;                    // of days in a month.
   else if ( day == 2 &&  !isALeapyear( year ) )
      return 28;
   else if ( day == 4 || day == 6 || day == 9 || day == 11 )
      return 30;
   else 
      return 31;
}



/**********************************************************************
 * The function of main is to display "Calendar"
 ***********************************************************************/
int main()
{
   int monthnumber = getMonthNumber();// this call the function get
                                     //     number of month
   int yearvalue = getYear();// this call the function to get year
   int sumYear = 0;
   int sumDay = 0;
   //this perform the loop year. and n variable name represent loop
   // and sum year days together
   
   for ( int n = 1753; n <= yearvalue - 1 ; n++ )
   {                                   
      int years = yearNumber(n);       
      sumYear += years;              
   }

   for ( int y = 1; y <= monthnumber - 1; y++ )//loop for year day in month
   {                    
      int days = getDaynumber( yearvalue,y); //variable

      sumDay += days;     // this sum up all the days in the month

   }
   int sumTotal = ( sumDay + sumYear ) % 7; // this help to calculate offset
   
   int numberOfDay =   getDaynumber( yearvalue , monthnumber );//this will
                                                          //determine
                                                        //number of day
   int offset =  sumTotal; //this will tell the offset

   if ( monthnumber == 1 )
      cout << "January, " << yearvalue << "\n";
   else if ( monthnumber == 2 )
      cout << "February, " << yearvalue << "\n";
   else if ( monthnumber == 3 )
      cout << "March, " << yearvalue << "\n";
   else if ( monthnumber == 4 )
      cout << "April, " << yearvalue << "\n";
   else if ( monthnumber == 5 )
      cout << "May, " << yearvalue << "\n";
   else if ( monthnumber == 6 )
      cout << "June, " << yearvalue << "\n";
   else if ( monthnumber == 7 )
      cout << "July, " << yearvalue << "\n";
   else if ( monthnumber == 8 )
      cout << "August, " << yearvalue << "\n";
   else if ( monthnumber == 9 )
      cout << "September, " << yearvalue << "\n";
   else if ( monthnumber == 10 )
      cout << "October, " << yearvalue << "\n";
   else if ( monthnumber == 11 )
      cout << "November, " << yearvalue << "\n";
   else if ( monthnumber == 12 )
      cout << "December, " << yearvalue << "\n";
   
   cout << setw(4) << "Su"
        << setw(4) << "Mo"
        << setw(4) << "Tu"
        << setw(4) << "We"
        << setw(4) << "Th"
        << setw(4) << "Fr"
        << setw(5) << "Sa\n";

// this help the compute offset to display  
   
   if ( offset == 6 )
      offset = -1;
   int dayWeek = 0;

   for ( int n = -offset ; n <= numberOfDay; n++)
   { 
      if ( n > 0)
         cout << setw(4) << n;
      else
         cout << "    ";

   if ( dayWeek % 7 == 6)
      cout << "\n";
   dayWeek++;


   }
   if ( dayWeek % 7 != 0 )
       cout << "\n";

     

   

   return 0;

}
 
