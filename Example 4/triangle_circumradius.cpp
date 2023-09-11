#include <iostream>
#include <sstream>
// Global variables


void display_message(const std::string& msg){
    std::cout << msg << "\n";
}
// Helper function to calculate square root without using std::sqrt()
double square_root_recursive(const double x, const double low, const double high, const double epsilon, const int max_iterations, const int current_iteration){
    display_message("Iteration " + std::to_string(current_iteration) + ": Midpoint = " + std::to_string((low + high) / 2.0) +
                   ", Midpoint squared = " + std::to_string(((low + high) / 2.0) * ((low + high) / 2.0)));

    if (current_iteration >= max_iterations || high - low < epsilon) {
        return (low + high) / 2.0;
    }

    const double mid = (low + high) / 2.0;
    const double mid_square = mid * mid;

    if (mid_square > x) {
        return square_root_recursive(x, low, mid, epsilon, max_iterations, current_iteration + 1);
    } else if (mid_square < x) {
        return square_root_recursive(x, mid, high, epsilon, max_iterations, current_iteration + 1);
    } else {
        return mid;
    }
}

// Helper function to calculate square root without using std::sqrt()
double square_root(const double x, const double epsilon = 1e-10, const int max_iterations = 1000) {
   display_message("Calculating the square root of " + std::to_string(x) + "\n");
    if (x < 0) {
        return -1; // Invalid input
    }
    if (x == 0) {
        return 0;
    }

    return square_root_recursive(x, 0, x, epsilon, max_iterations, 0);
}

const double calculate_circumradius(const double a, const double b, const double c) {
    const double s = (a + b + c) / 2;
    const double area = square_root(s * (s - a) * (s - b) * (s - c));
    return (a * b * c) / (4 * area);
}




int main() {
    const double a = 3;
    const double b = 4;
    const double c = 5;
    display_message("Triangle sides: a = " + std::to_string(a) + ", b = " + std::to_string(b) + ", c = " + std::to_string(c) + "\n");

    const double circumradius = calculate_circumradius(a, b, c);

    std::cout << "Circumradius: " << circumradius << "\n";

    return 0;
}
