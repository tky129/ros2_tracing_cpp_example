#include "pub_sub_cpp_01/subscriber.hpp"

namespace kccs_pub_sub_cpp_01 {

Subscriber::Subscriber(const rclcpp::NodeOptions& options)
    : Node("subscriber", options) {
  rclcpp::QoS qos(rclcpp::KeepLast{10});
  sub_ = this->create_subscription<std_msgs::msg::String>(
      "chatter", qos,
      [this](const std_msgs::msg::String::SharedPtr msg) -> void {
        topic_callback(std::move(msg));
      });
}

void Subscriber::topic_callback(const std_msgs::msg::String::SharedPtr msg) {
  RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg->data.c_str());
}

}  // namespace kccs_pub_sub_cpp_01

RCLCPP_COMPONENTS_REGISTER_NODE(kccs_pub_sub_cpp_01::Subscriber)