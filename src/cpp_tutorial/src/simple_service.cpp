#include "example_interfaces/srv/add_two_ints.hpp"
#include "rclcpp/rclcpp.hpp"

using std::placeholders::_1;
using std::placeholders::_2;

class ServiceServer01 : public rclcpp::Node {
public:
    ServiceServer01(std::string name) : Node(name) {
        RCLCPP_INFO(this->get_logger(), "节点已启动：%s.", name.c_str());
        // 创建服务
        add_ints_server_ = this->create_service<example_interfaces::srv::AddTwoInts>(
            "add_two_ints_srv", std::bind(&ServiceServer01::handle_add_two_ints, this, _1, _2)
        );
    }

private:
    // 声明一个服务
    rclcpp::Service<example_interfaces::srv::AddTwoInts>::SharedPtr add_ints_server_;

    using Request = std::shared_ptr<example_interfaces::srv::AddTwoInts::Request>;
    using Response = std::shared_ptr<example_interfaces::srv::AddTwoInts::Response>;

    // 收到请求的处理函数
    void handle_add_two_ints(const Request request, Response response) {
        RCLCPP_INFO(this->get_logger(), "收到a: %ld b: %ld", request->a, request->b);
        response->sum = request->a + request->b;
    };
};

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<ServiceServer01>("service_server_01");
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
