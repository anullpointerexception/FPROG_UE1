#include <iostream>
#include <sstream>


// Silly square function that is not immutable and not pure
double silly_square(double x) {
    return x * x;
}

void display_message(const std::string& msg){
    std::cout << msg << "\n";
}


// Helper function to calculate square root without using std::sqrt()
double square_root(double x, double epsilon = 1e-10, int max_iterations = 1000) {
    display_message("Calculating the square root of " + std::to_string(x) + "\n");
    if (x < 0) {
        return -1; // Invalid input
    }
    if (x == 0) {
        return 0;
    }

    double low = 0, high = x;
    double mid;
    for (int i = 0; i < max_iterations; ++i) {
        mid = (low + high) / 2.0;
        double mid_square = mid * mid;


        display_message("Iteration " + std::to_string(i+1) + ": Midpoint = " + std::to_string(mid) + ", Midpoint squared = " + std::to_string(mid_square) + "\n");

        if (mid_square > x) {
            high = mid;
        } else if (mid_square < x) {
            low = mid;
        }

        if (high - low < epsilon) {
            break;
        }
    }

    return mid;
}

double calculate_median() {
    display_message("Calculating the median of a triangle with sides a = " + std::to_string(a) + ", b = " + std::to_string(b) + ", c = " + std::to_string(c) + "\n");
    double result = 0.5 * square_root(2 * silly_square(b) + 2 * silly_square(c) - silly_square(a));
    return result;
}


int main() {
    double a = 3;
    double b = 4;
    double c = 5;
    display_message("Triangle sides: a = " + std::to_string(a) + ", b = " + std::to_string(b) +", c = " + std::to_string(c) + "\n");
    double median_a = calculate_median();
    a = 4, b = 3, c = 5;
    double median_b = calculate_median();
    a = 5, b = 3, c = 4;
    double median_c = calculate_median();

    display_message("Medians:\n");
    display_message("Median from vertex A: " + std::to_string(median_a) + "\n");
    display_message("Median from vertex B: " + std::to_string(median_b) + "\n");
    display_message("Median from vertex C: " + std::to_string(median_c) + "\n");

    return 0;
}
