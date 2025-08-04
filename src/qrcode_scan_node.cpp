#include "cobot_vision/qrcode_scan.hpp"

#include <memory>

#include "rclcpp/executor.hpp"
#include "rclcpp/utilities.hpp"

int main(int argc, char* argv[]) {
  rclcpp::init(argc, argv);
  auto node = std::make_shared<QRCodeScan>();
  rclcpp::spin(node);
  rclcpp::shutdown();

  return 0;
}