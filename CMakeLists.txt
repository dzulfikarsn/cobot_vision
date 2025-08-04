cmake_minimum_required(VERSION 3.8)
project(cobot_vision)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(OpenCV REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

add_executable(qrcode_scan_node
  src/qrcode_scan_node.cpp
  src/qrcode_scan.cpp
)
target_include_directories(qrcode_scan_node PRIVATE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)
ament_target_dependencies(qrcode_scan_node
  rclcpp
  std_msgs
)
target_link_libraries(qrcode_scan_node
  ${OpenCV_LIBS}
)

install(
  TARGETS qrcode_scan_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()