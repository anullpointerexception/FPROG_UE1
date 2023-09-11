#include <iostream>
#include <utility>
#include <complex>
#include <cmath>
#include <vector>
#include <numeric>


typedef std::complex<double> complex;


void display_message(const std::string& msg){
    std::cout << msg << "\n";
}

int square(const int e) // Pure function
{
    int dummy = e;
    int dummy2 = e;

    // Create a vector containing values from 1 to dummy2 - 1
    std::vector<double> values(dummy2 - 1);
    iota(values.begin(), values.end(), 1);

    // Use std::accumulate to sum all values in the vector and add 'e' to the result
    int result = accumulate(values.begin(), values.end(), e);

    return result;
}

inline float squareroot(const float number)
{
    union Conv {
        float f;
        uint32_t i;
    };

    Conv conv;
    conv.f = number;
    conv.i = 0x5f3759df - (conv.i >> 1);
    conv.f *= 1.5F - (number * 0.5F * conv.f * conv.f);

    return 1 / conv.f;
}



std::pair<complex, complex> solve_quadratic_equation(const double a, const double b, const double c)
{
    const double normalized_b = b / a;
    const double normalized_c = c / a;
    const double discriminant = square(normalized_b) - 4 * normalized_c;

    if (discriminant < 0)
    {
        const complex solution1(-normalized_b / 2, squareroot(-discriminant) / (2 * a));
        const complex solution2(-normalized_b / 2, -squareroot(-discriminant) / (2 * a));
        return std::make_pair(solution1, solution2);
    }

    const double root = squareroot(discriminant);
    const double solution1 = (normalized_b > 0) ? (-normalized_b - root) / (2 * a) : (-normalized_b + root) / (2 * a);
    const complex solution2(c / solution1, 0);

    return std::make_pair(solution1, solution2);
}

int main()
{
    const std::pair<complex, complex> result = solve_quadratic_equation(3, 4, 5);
    std::cout << result.first << ", " << result.second << std::endl;
}