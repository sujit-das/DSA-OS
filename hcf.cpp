/*
 * Copyright (C) 2022 Sujit Das
 *
 * This is a free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software; if not, see <http://www.gnu.org/licenses/>.
 */

// Description: To compute highest common factor
// Usage: g++ hcf.cpp -o hcf , ./hcf
#include<iostream>

using namespace std;

namespace LibAlgo
{
	typedef int (*FUNCP)(const int, const int);
	int hcf(const int, const int);
	int lcm(const int, const int);
	int func_array(const int, const int*);

	// Function to determine HCF(Highest Common Factor) of two integer numbers.
	int hcf(const int arg1, const int arg2)
	{
		cout << "TRACE: hcf( " << "arg1: " <<arg1<<", arg2: "<<arg2<< " )"<<endl;
		while(arg1 != arg2)
		{
			if(arg1 > arg2)
				return hcf(arg1 - arg2, arg2);
			else
				return hcf(arg2 - arg1, arg1);
		}
		return arg1;
	}

	// Function to determine LCM(Lowest Common Multiple) of two integer numbers.
	int lcm(const int arg1, const int arg2)
	{
		cout << "TRACE: lcm( " << "arg1: " <<arg1<<", arg2: "<<arg2<< " )"<<endl;
		int _hcf = hcf(arg1, arg2 );
		return ((arg1 * arg2)/_hcf);
	}

	// Function which execute operation on entire array, starting with first two elements 
	int func_array(const FUNCP fp, const int size, const int* ai)
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
				arg1 = (*fp)(arg1,arg2);
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

      int _hcf = LibAlgo::func_array(LibAlgo::hcf, nN, ai);
      int _lcm = LibAlgo::func_array(LibAlgo::lcm, nN, ai);
      cout << "HCF: " << _hcf << endl;
      cout << "LCM: " << _lcm << endl;
      delete[] ai;
   }
}
