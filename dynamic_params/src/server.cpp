

#include <ros/ros.h>

#include <dynamic_reconfigure/server.h>
#include "dynamic_params/MpcParamsConfig.h"
#include "ros/ros.h"


void callback(dynamic_params::MpcParamsConfig &config, uint32_t level)
{
    ROS_INFO("Reconfigure request : %lf ",
             (double)config.acc2thrust);

    // do nothing for now
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "dynamic_reconfigure_node");
    dynamic_reconfigure::Server<dynamic_params::MpcParamsConfig > srv;
    dynamic_reconfigure::Server<dynamic_params::MpcParamsConfig >::CallbackType f;
    f = boost::bind(&callback, _1, _2);
    srv.setCallback(f);
    ROS_INFO("Starting to spin...");
    ros::spin();
    return 0;
}