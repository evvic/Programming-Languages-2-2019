// CustomerData class
#ifndef CUSTOMERDATA_H
#define CUSTOMERDATA_H
#include <string>
#include "PersonData.h"
using namespace std;

class CustomerData : public PersonData
{
private:
   int customerNumber;     // Customer number
   bool mailingList;       // Include in mailing list?
   
public:

   //**********************************************
   // Constructor                                 *
   //**********************************************
   
   CustomerData(string ln, string fn, string addr,
                string c, string s, string z, string ph,
				int cn, bool ml) :
                PersonData(ln, fn, addr, c, s, z, ph)
      { customerNumber = cn;
        mailingList = ml; }

   //**********************************************
   // Default Constructor                         *
   //**********************************************
   
   CustomerData() : PersonData()
   { customerNumber = 0;
     mailingList = false; }

   //**********************************************
   // Mutator functions                           *
   //**********************************************
   
   void setCustomerNumber(int cn)
      { customerNumber = cn; }
   
   void setMailingList(bool ml)
      { mailingList = ml; }
      
   //**********************************************
   // Accessor functions                          *
   //**********************************************

   int getCustomerNumber()
      { return customerNumber; }
   
   bool getMailingList()
      { return mailingList; }
};

#endif