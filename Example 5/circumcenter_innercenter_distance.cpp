#include <iostream>
#include <tuple>
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

std::tuple<double, double> calculate_area_and_radii(const double a, const double b, const double c) {
    const double s = (a + b + c) / 2;
    const double area = square_root(s * (s - a) * (s - b) * (s - c));
    const double inradius = area / s;
    const double circumradius = (a * b * c) / (4 * area);
    const std::tuple<double, double> info = std::make_tuple(inradius, circumradius);
    return info;
}

const double calculate_distance(const double circumradius, const double inradius) {
    return square_root(circumradius * circumradius - 2 * circumradius * inradius);
}

int main() {
    const double a = 3;
    const double b = 4;
    const double c = 5;
    display_message("Triangle sides: a = " + std::to_string(a) + ", b = " + std::to_string(b) + ", c = " + std::to_string(c) + "\n");

    const std::tuple<double, double> info = calculate_area_and_radii(a, b, c);
    display_message("Inradius: " + std::to_string(std::get<0>(info)) + "\n");
    display_message("Circumradius: " + std::to_string(std::get<1>(info)) + "\n");

    const double distance = calculate_distance(std::get<1>(info), std::get<0>(info));
    display_message("Distance between circumcenter and incenter: " + std::to_string(distance) + "\n");

    return 0;
}
