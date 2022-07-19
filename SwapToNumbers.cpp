/*
 *
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
 
#include <iostream>

using namespace std;

void swapArithmatic (int &pa1, int &pa2);
void swapXor (int &pa1, int &pa2);

int main ()
{
  int a1 = -12, a2 = -34;
  cout << "Before swap" << endl;
  cout << "Numbers: " << a1 << " " << a2 << endl;
  swapArithmatic (a1, a2);
  cout << "After swap" << endl;
  cout << "Numbers: " << a1 << " " << a2 << endl;
  swapXor (a1, a2);
  cout << "After swap" << endl;
  cout << "Numbers: " << a1 << " " << a2 << endl;
  return 0;
}

void swapArithmatic (int &pa1, int &pa2)
{
  pa1 = pa1 - pa2;
  pa2 = pa1 + pa2;
  pa1 = pa2 - pa1;
}

void swapXor (int &pa1, int &pa2)
{
  pa1 = pa1 ^ pa2;
  pa2 = pa1 ^ pa2;
  pa1 = pa1 ^ pa2;
}





