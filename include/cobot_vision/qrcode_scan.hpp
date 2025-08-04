#ifndef COBOT_VISION__QRCODE_SCAN_HPP_
#define COBOT_VISION__QRCODE_SCAN_HPP_

#include <string>

#include "opencv2/opencv.hpp"

#include "rclcpp/rclcpp.hpp"

#include "std_msgs/msg/string.hpp"

class QRCodeScan : public rclcpp::Node
{
public:
  QRCodeScan();
private:
  void callback();

  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr pub_;
  rclcpp::TimerBase::SharedPtr timer_;

  cv::VideoCapture cap;
  cv::QRCodeDetector qr;
};

#endif  // COBOT_VISION__QRCODE_SCAN_HPP_