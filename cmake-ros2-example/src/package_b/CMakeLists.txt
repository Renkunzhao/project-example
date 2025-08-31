cmake_minimum_required(VERSION 3.10)
project(package_b VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 创建可执行文件
add_executable(package_b src/package_b.cpp)

find_package(packageA REQUIRED)
target_link_libraries(package_b packageA::packageA)

find_package(package_a REQUIRED)
target_link_libraries(package_b package_a::package_a)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
ament_target_dependencies(package_b rclcpp)

install(TARGETS
  package_b
  DESTINATION lib/${PROJECT_NAME})

ament_package()
