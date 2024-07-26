#ifndef PUBLISHER_H_
#define PUBLISHER_H_

#include "rclcpp/rclcpp.hpp"
#include "rclcpp_components/register_node_macro.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

namespace kccs_pub_sub_cpp_01 {

class Publisher : public rclcpp::Node {
 public:
  Publisher(const rclcpp::NodeOptions& options);

 private:
  void timer_callback();
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr pub_;
  size_t count_;
};

}  // namespace kccs_pub_sub_cpp_01

#endif