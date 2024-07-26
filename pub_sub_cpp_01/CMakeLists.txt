cmake_minimum_required(VERSION 3.8)
project(pub_sub_cpp_01)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(std_msgs REQUIRED)

# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)


include_directories(include)

function(add_dependencies_func library)
  target_compile_definitions(${library}
    PRIVATE "KCCS_PUB_SUB_TEST_NODES_CPP_BUILDING_LIBRARY")
  ament_target_dependencies(${library}
    "rclcpp"
    "rclcpp_components"
    "std_msgs")
endfunction()

add_library(pub_sub_cpp_01_lib SHARED
  src/publisher.cpp
  src/subscriber.cpp
)

add_dependencies_func(pub_sub_cpp_01_lib)

rclcpp_components_register_node(pub_sub_cpp_01_lib
  PLUGIN "kccs_pub_sub_cpp_01::Publisher"
  EXECUTABLE publisher)
rclcpp_components_register_node(pub_sub_cpp_01_lib
  PLUGIN "kccs_pub_sub_cpp_01::Subscriber"
  EXECUTABLE subscriber)

install(TARGETS
  pub_sub_cpp_01_lib
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin)

install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}
)

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

ament_package()
