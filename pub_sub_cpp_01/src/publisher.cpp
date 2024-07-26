#include "pub_sub_cpp_01/publisher.hpp"

#include <chrono>
#include <cstdio>
#include <memory>
#include <utility>

using namespace std::chrono_literals;

namespace kccs_pub_sub_cpp_01 {

Publisher::Publisher(const rclcpp::NodeOptions& options)
    : Node("publisher", options) {
  rclcpp::QoS qos(rclcpp::KeepLast{10});
  pub_ = this->create_publisher<std_msgs::msg::String>("chatter", qos);

  timer_ =
      this->create_wall_timer(500ms, [this]() -> void { timer_callback(); });
};

void Publisher::timer_callback() {
  std::unique_ptr<std_msgs::msg::String> msg_ = std::make_unique<std_msgs::msg::String>();
  msg_->data = "Hello World: " + std::to_string(count_++);
  RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", msg_->data.c_str());
  pub_->publish(std::move(msg_));
}

}  // namespace kccs_pub_sub_cpp_01

RCLCPP_COMPONENTS_REGISTER_NODE(kccs_pub_sub_cpp_01::Publisher)