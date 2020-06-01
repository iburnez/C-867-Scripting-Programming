#include <iostream>
#include <vector>
#include <limits>
#include "TaxTableTools.h"
using namespace std;

// Default constructor
TaxTableTools::TaxTableTools() {
   search.push_back(0);
   search.push_back(20000);
   search.push_back(50000);
   search.push_back(100000);
   search.push_back(numeric_limits<int>::max());
   value.push_back(0.0);
   value.push_back(0.10);
   value.push_back(0.20);
   value.push_back(0.30);
   value.push_back(0.40);
   nEntries = search.size();  // Set the length of the search table

   return;
}

// ***********************************************************************

// FIXME: Write a void setter function that sets new values for the private
//        search and value tables. Name the function: setTables
//        The function receives as parameters tables from which to load the 
//        search and value tables.

void TaxTableTools::setTables(int salary, double taxRate) {
   bool keepLooking = true;
   int i = 0;
   
   while ((i < nEntries) && keepLooking) {
      if (salary > search.at(i)) {
         search.insert(search.begin() + i, salary);
         value.insert(value.begin() + i, taxRate);
         keepLooking = false;
      }
      else i++;
   }
}
   
// ************************************************************************ 

// Function to get a value from one table based on a range in the other table
double TaxTableTools::GetValue(int searchArgument) {
   double result = 0.0;
   bool keepLooking = true;
   int i = 0;

   while ((i < nEntries) && keepLooking) {
      if (searchArgument <= search.at(i)) {
         result = value[i];
         keepLooking = false;
      }
      else {
         ++i;
      }
   }

   return result;
}