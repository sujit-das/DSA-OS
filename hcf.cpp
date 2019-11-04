// File usage: g++ hcf.cpp
#include<iostream>

using namespace std;

namespace LibAlgo
{
	int hcf(const int, const int);
	int hcf_array(const int, const int*);

	int hcf(const int arg1, const int arg2)
	{
		cout << "TRACE: hcf( " << "arg1: " <<arg1<<", arg2: "<<arg2<< " )"<<endl;
		int mod = arg1 % arg2;
		if( 0 == mod )
			return arg2;
		else
			hcf(arg2, mod );
	}

	int hcf_array(const int size, const int* ai)
	{
		if(ai == NULL)
		{
			cout << "Input ERROR" << endl;
			return (-1);
		}
		else if(size == 1)
		{
			cout << "Only one value passed" << endl;
			return (*ai);
		}
		else
		{
			int loop, arg1, arg2;
			for(loop = 0, arg1 = *(ai+loop), arg2 = *(ai+loop+1) ; loop < (size-1); loop++, arg2 = *(ai+loop+1))
			{
				arg1 = hcf(arg1,arg2);
			}
			return arg1;
		}
	}	
}

int main()
{
   signed int nN = 0;
   cout << "How many nubers?" << endl;
   cin >> nN;
   if (nN > 0)
   {
      cout << "Enter integer(s)" << endl;
      int *ai = new int[nN];
      for(int loop = 0; loop < nN; loop++)
      {
	     cin >> *(ai+loop);
      }
	  
	  int _hcf = LibAlgo::hcf_array(nN, ai);
      cout << "HCF: " << _hcf;
      delete[] ai;
   }
}
