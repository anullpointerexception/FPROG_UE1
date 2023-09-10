/* Created by anullpointerexception on 10.09.2023


Example 1

- Removed global mutable variables (int x, int y, int z) and passed them as parameters to the pythagoras function.

- Modified the square and squareroot functions to compute and return values without modifying any external state or variables.

- Modified the pythagoras function to take x and y as parameters and return the result instead of modifying global variables.

- Removed the global variable z and returned it from the pythagoras function to be used in the main function.

- Removed unnecessary includes (<cmath> instead of <math.h>).
*/


#include <iostream>

using namespace std;

int square (int e)
{
	return e*e;
}

double squareroot (double x)
{				/* computes the square root of x */

  if (x == 0)
    return 0;

/* the sqrt must be between xhi and xlo */
  double xhi = x;
  double xlo = 0;
  double guess = x / 2;

/* We stop when guess*guess-x is very small */

  while (abs (guess * guess - x) > 0.00001)
    {
      if (guess * guess > x)
	      {
	        xhi = guess;
	      }

      else
	      {
	        xlo = guess;
	      }
      guess = (xhi + xlo) / 2;
    }

  cout << "guess:" << guess << endl;;
  return guess;
}


double pythagoras (double x, double y) // Calculates the pythagoras. 
{
  double xSqrt = square(x);
  double ySqrt = square(y);

  double z = squareroot(xSqrt + ySqrt);


  cout << "x: " << x << " y: " << y << endl;

  cout << "square (x) = " << xSqrt << " square (y) = " << ySqrt << endl;

  cout << "z: " <<  z << endl;
  cout << "euklid:" << z << endl;
  return z;
}


int main (int argc, char *argv[])
{
  double x = 3.0;
  double y = 4.0;
  double z = pythagoras(x,y);
  cout << z << endl;
  return 0;
}
