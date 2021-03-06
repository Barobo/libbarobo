/* Filename: stand2.ch 
 * Make a Mobot stand up on a faceplate */
#include <mobot.h>
CMobot robot;

/* Connect to the paired Mobot */
robot.connect();

/* Set robot motors to speed of 90 degrees per second */
robot.setJointSpeed(ROBOT_JOINT2, 90);
robot.setJointSpeed(ROBOT_JOINT3, 90);
/* Set the robot to "home" position, where all joint angles are 0 degrees. */
robot.resetToZero();

/* Move the robot into a fetal position */
robot.moveJointTo(ROBOT_JOINT2, -85);
robot.moveJointTo(ROBOT_JOINT3, 70);

/* Wait a second for the robot to settle down */
delay(1);

/* Rotate the bottom faceplate by 45 degrees */
robot.moveJointTo(ROBOT_JOINT1, 45);

/* Lift the body up */
robot.moveJointTo(ROBOT_JOINT2, 20);

/* Pan the robot around for 3 seconds at 45 degrees per second*/
robot.setJointSpeed(ROBOT_JOINT1, 45);
robot.setMovementStateTime(ROBOT_FORWARD, ROBOT_HOLD, ROBOT_HOLD, ROBOT_HOLD, 3);

