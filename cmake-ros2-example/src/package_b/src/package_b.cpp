#include <iostream>
#include <rclcpp/rclcpp.hpp>
#include <packageA/packageA.h>

int main() {
    std::cout << helloA() << std::endl;
    return 0;
}
