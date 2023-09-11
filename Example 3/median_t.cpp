#include <iostream>
#include <sstream>

void display_message(const std::string& msg){
    std::cout << msg << "\n";
}


double silly_square_loop_recursive(const double x, const int current_iteration, const double current_result){
    if (current_iteration < x) {
        const double new_result = current_result + x;
        display_message("Iteration " + (std::to_string(current_iteration+1)) + ": Current result = " + std::to_string(new_result) + "\n");
        return silly_square_loop_recursive(x, current_iteration + 1, new_result);
    } else {
        return current_result;
    }
}

// Silly square function that is not immutable and not pure
double silly_square(const double x) {
    display_message("Calculating the silly square of " + std::to_string(x) + "\n");

    return silly_square_loop_recursive(x, 0, 0.0);
}

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

double calculate_median(const double a, const double b, const double c) {
    display_message("Calculating the median of a triangle with sides a = " + std::to_string(a) + ", b = " + std::to_string(b) + ", c = " + std::to_string(c) + "\n");
    double result = 0.5 * square_root(2 * silly_square(b) + 2 * silly_square(c) - silly_square(a));
    return result;
}

int main() {
    double a = 3;
    double b = 4;
    double c = 5;
    display_message("Triangle sides: a = " + std::to_string(a) + ", b = " + std::to_string(b) + ", c = " + std::to_string(c) + "\n");

    double median_a = calculate_median(a, b, c);
    a = 4, b = 3, c = 5;
    double median_b = calculate_median(a, b, c);
    a = 5, b = 3, c = 4;
    double median_c = calculate_median(a, b, c);

    display_message("Medians:\n");
    display_message("Median from vertex A: " + std::to_string(median_a) + "\n");
    display_message("Median from vertex B: " + std::to_string(median_b) + "\n");
    display_message("Median from vertex C: " + std::to_string(median_c) + "\n");

    return 0;
}
