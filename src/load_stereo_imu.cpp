#include <ros/ros.h>  
#include <sensor_msgs/image_encodings.h> //ROS图象类型的编码函数
#include <image_transport/image_transport.h> //用来在ROS系统中的话题上发布和订阅图象消息
#include <sensor_msgs/Imu.h>
 
//OpenCV2标准头文件
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <cv_bridge/cv_bridge.h>     //cv_bridge中包含CvBridge库
 
#include <iostream> //C++标准输入输出库
#include <string>

using namespace std;
 
//消息订阅回调函数
void LeftImage_cb(const sensor_msgs::ImageConstPtr& msg)
{
    try
    {
        // cout << " image_L receive success " << endl;
        cv::imshow("image_l",cv_bridge::toCvShare(msg,"bgr8")->image);
        cv::waitKey(1);//因为highgui处理来自cv::imshow()的绘制请求需要时间 10代表10ms
    }
    catch (cv_bridge::Exception& e)
    {
        cout << "Could not convert from " << msg->encoding.c_str() << "to 'brg8'." << endl;
    }   
}

void RightImage_cb(const sensor_msgs::ImageConstPtr& msg)
{
    try
    {
        // cout << " image_R receive success " << endl;
        cv::imshow("image_r",cv_bridge::toCvShare(msg,"bgr8")->image);
        cv::waitKey(1);//因为highgui处理来自cv::imshow()的绘制请求需要时间 10代表10ms
    }
    catch (cv_bridge::Exception& e)
    {
        cout << "Could not convert from " << msg->encoding.c_str() << "to 'brg8'." << endl;
    }   
}

void IMU_cb(const sensor_msgs::Imu::ConstPtr& msg)
{
    sensor_msgs::Imu imu_msg; //建立一个该消息体类型的变量，用于存储订阅的信息
    try 
    { 
        imu_msg = *msg;
        cout<<"angular_velocity:"<<"  \t"
            <<imu_msg.angular_velocity.x<<"  "
            <<imu_msg.angular_velocity.y<<"  "
            <<imu_msg.angular_velocity.z<<endl;
        cout<<"linear_acceleration:"<<"  \t"
            <<imu_msg.linear_acceleration.x<<"  "
            <<imu_msg.linear_acceleration.y<<"  "
            <<imu_msg.linear_acceleration.z<<endl;
    }
    catch(...)
    {
        cout<<"Something Wrong!"<<endl;
    }
}

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "stereo_imu_subscriber");
 
    ros::NodeHandle nh;//创建句柄
    image_transport::ImageTransport it(nh);
    string camera_left_topic,camera_right_topic,imu_topic;
 
    image_transport::Subscriber camera_left;
    image_transport::Subscriber camera_right;
    ros::Subscriber imu_data;
 
    //设置订阅主题 camera/image
    camera_left = it.subscribe("stereo_camera/left/image_raw",1,LeftImage_cb);
    camera_right = it.subscribe("stereo_camera/right/image_raw",1,RightImage_cb);
    imu_data = nh.subscribe<sensor_msgs::Imu>("imu",10,IMU_cb);
 
    ros::spin();
 
    return 0;
}