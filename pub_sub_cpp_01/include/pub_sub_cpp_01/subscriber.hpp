#ifndef SUBSCRIBER_H_
#define SUBSCRIBER_H_

#include "rclcpp/rclcpp.hpp"
#include "rclcpp_components/register_node_macro.hpp"
#include "std_msgs/msg/string.hpp"

namespace kccs_pub_sub_cpp_01 {

class Subscriber : public rclcpp::Node {
 public:
  Subscriber(const rclcpp::NodeOptions& options);

 private:
  void topic_callback(const std_msgs::msg::String::SharedPtr msg);
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub_;
};

}  // namespace kccs_pub_sub_cpp_01

#endif