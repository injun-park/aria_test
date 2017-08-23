//
// Created by ijpark on 8/23/17.
//

#include <Aria.h>
#include <ros/ros.h>

//
// test
//

class PrintTask {
private:
    ArRobot* myRobot;
    ArFunctorC<PrintTask> myTaskCB;
public:
    PrintTask(ArRobot* robot) :
    myTaskCB(this, &PrintTask::doTask)
    {
        this->myRobot = robot;
        myRobot->addSensorInterpTask("PrintingTask", 50, &myTaskCB);
    }

    void doTask() {

        ROS_INFO("x %6.1f  y %6.1f  th  %6.1f vel %7.1f mpacs %3d \n", myRobot->getX(),
               myRobot->getY(), myRobot->getTh(), myRobot->getVel(),
               myRobot->getMotorPacCount());
    }
};


int main(int argc, char** argv) {

    ros::init(argc, argv, "mytest_node1");
    ros::NodeHandle nh;
    // the connection
    ArSimpleConnector con(&argc, argv);
    if(!con.parseArgs())
    {
        con.logOptions();
        return 1;
    }

    ArRobot robot;
    ArSonarDevice sonar;

    PrintTask pt(&robot);


    Aria::init();
    robot.addRangeDevice(&sonar);

    if(!con.connectRobot(&robot))
    {
        printf("Could not connect to the robot.\n");
        return 2;
    }

    printf("Connected to the robot. (Press Ctrl-C to exit)\n");
    robot.run();

}
