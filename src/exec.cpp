#include <cartesian_impedance_controller/cartesian_impedance_controller_ros.h>
#include <ros/ros.h>
int main(int argc, char **argv){
    ros::init(argc, argv, "cartesian_impedance_controller");
    ros::NodeHandle nh;

    cartesian_impedance_controller::CartesianImpedanceControllerRos controller;
    controller.init(nh);

    ros::Time current_time = ros::Time::now(); // 현재 시간

    controller.starting(current_time);


    ros::Rate loop_rate(controller.update_frequency_);

    while (ros::ok()){
      current_time = ros::Time::now(); // 현재 시간
      ros::Duration period(1.0 / controller.update_frequency_); // 0.01초, 예를 들어
      controller.update(current_time, period);

      loop_rate.sleep();


    }
    return 0;
  }
