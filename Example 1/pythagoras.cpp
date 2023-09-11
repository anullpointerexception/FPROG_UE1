/* Created by anullpointerexception on 10.09.2023


Example 1

- Removed global mutable variables (int x, int y, int z) and passed them as parameters to the pythagoras function.

- Modified the square and squareroot functions to compute and return values without modifying any external state or variables.

- Modified the pythagoras function to take x and y as parameters and return the result instead of modifying global variables.

- Removed the global variable z and returned it from the pythagoras function to be used in the main function.

- Removed unnecessary includes (<cmath> instead of <math.h>).
*/


#include <iostream>
#include <cmath>
#include <sstream>
#include <vector>
#include <numeric>

using namespace std;


/* unused recursive approach
int square_recursive(const int e, const int dummy, const int dummy2, int i = 1, int result = 0){

  if(i < dummy2)
  {
    result += e;
    return square_recursive(e, dummy, dummy2, i + 1, result);
  } else {
    return result;
  }
}

*/

int square(const int e) // Pure function
{
    int dummy = e;
    int dummy2 = e;

    // Create a vector containing values from 1 to dummy2 - 1
    vector<double> values(dummy2 - 1);
    iota(values.begin(), values.end(), 1);

    // Use std::accumulate to sum all values in the vector and add 'e' to the result
    int result = accumulate(values.begin(), values.end(), e);

    return result;
}

double squareroot(const double x) // Pure function
{
    if (x == 0)
        return 0;

    double xhi = x;
    double xlo = 0;
    double guess = x / 2;
    double epsilon = 0.00001;

    while (abs(guess * guess - x) > epsilon)
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

    return guess;
}

double pythagoras(const int x, const int y) // Pure function
{
    const int xSquared = square(x);
    const int ySquared = square(y);
    const double z = squareroot(xSquared + ySquared);

    return z;
}

void display_message(const std::string& msg){
    cout << msg << "\n";
}

int main(int argc, char *argv[])
{
    const int x = 3;
    const int y = 4;
    const double z = pythagoras(x, y);
    display_message("z: " + to_string(z) + "\n");
    return 0;
}
