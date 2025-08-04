#include "cobot_vision/qrcode_scan.hpp"

using namespace std::chrono_literals;

QRCodeScan::QRCodeScan()
: Node("qrcode_scan_node")
{
  cap.open(0);
  if (!cap.isOpened()) {
    RCLCPP_ERROR(this->get_logger(), "Failed to open the camera.");
    rclcpp::shutdown();
    return;
  }

  pub_ = this->create_publisher<std_msgs::msg::String>("destination", 1);
  timer_ = this->create_wall_timer(
    500ms, std::bind(&QRCodeScan::callback, this));
}

void QRCodeScan::callback() {
  cv::Mat frame;
  cap >> frame;

  if (frame.empty()) {
    return;
  }

  std::string result = qr.detectAndDecode(frame);
  if (!result.empty()) {
    std_msgs::msg::String msg;
    msg.data = result;
    pub_->publish(msg);
    RCLCPP_INFO(this->get_logger(), "QR Code: %s", result.c_str());
  }
}