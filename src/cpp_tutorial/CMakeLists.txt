cmake_minimum_required(VERSION 3.8)
project(cpp_tutorial)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(example_interfaces REQUIRED)

add_executable(simple_publisher src/simple_publisher.cpp)
ament_target_dependencies(simple_publisher rclcpp std_msgs)

add_executable(simple_suscriber src/simple_suscriber.cpp)
ament_target_dependencies(simple_suscriber rclcpp std_msgs)

add_executable(simple_service src/simple_service.cpp)
ament_target_dependencies(simple_service rclcpp example_interfaces)

add_executable(simple_client src/simple_client.cpp)
ament_target_dependencies(simple_client rclcpp example_interfaces)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

install(TARGETS
  simple_publisher
  DESTINATION lib/${PROJECT_NAME}
)

install(TARGETS
  simple_suscriber
  DESTINATION lib/${PROJECT_NAME}
)

install(TARGETS
  simple_service
  DESTINATION lib/${PROJECT_NAME}
)

install(TARGETS
  simple_client
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
