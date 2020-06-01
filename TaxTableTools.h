#include <iostream>
#include <vector>
using namespace std;

class TaxTableTools {
   public:
      TaxTableTools();
      double GetValue(int searchArgument);
      void setTables(int salary, double taxRate = 0);

   private:
      vector<int> search;
      vector<double> value;
      int nEntries;
};