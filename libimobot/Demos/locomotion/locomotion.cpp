#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <imobot.h>

void moveJoint(CiMobot &robot, int id, double angle)
{
  double cur_angle;
  robot.getMotorPosition(id, cur_angle);
  robot.setMotorPosition(id, cur_angle + angle);
}

void move_forward(CiMobot &robot)
{
  moveJoint(robot, IMOBOT_MOTOR3, -90);
  moveJoint(robot, IMOBOT_MOTOR4, 90);
}

void move_backward(CiMobot &robot)
{
  moveJoint(robot, IMOBOT_MOTOR3, 90);
  moveJoint(robot, IMOBOT_MOTOR4, -90);
}

void arch(CiMobot &robot)
{
  robot.setMotorPosition(IMOBOT_MOTOR1, -30);
  robot.setMotorPosition(IMOBOT_MOTOR2, 30);
}

void inch_right(CiMobot &robot)
{
  robot.setMotorPosition(IMOBOT_MOTOR1, -50);
  robot.waitMotor(IMOBOT_MOTOR1);
  robot.setMotorPosition(IMOBOT_MOTOR2, 50);
  robot.waitMotor(IMOBOT_MOTOR2);
  robot.setMotorPosition(IMOBOT_MOTOR1, 0);
  robot.waitMotor(IMOBOT_MOTOR1);
  robot.setMotorPosition(IMOBOT_MOTOR2, 0);
  robot.waitMotor(IMOBOT_MOTOR2);
}

void inch_left(CiMobot &robot)
{
  robot.setMotorPosition(IMOBOT_MOTOR2, 50);
  robot.waitMotor(IMOBOT_MOTOR2);
  robot.setMotorPosition(IMOBOT_MOTOR1, -50);
  robot.waitMotor(IMOBOT_MOTOR1);
  robot.setMotorPosition(IMOBOT_MOTOR2, 0);
  robot.waitMotor(IMOBOT_MOTOR2);
  robot.setMotorPosition(IMOBOT_MOTOR1, 0);
  robot.waitMotor(IMOBOT_MOTOR1);
}

void rotate_right(CiMobot &robot)
{
  moveJoint(robot, IMOBOT_MOTOR3, 90);
  moveJoint(robot, IMOBOT_MOTOR4, 90);
}

void rotate_left(CiMobot &robot)
{
  moveJoint(robot, IMOBOT_MOTOR3, -90);
  moveJoint(robot, IMOBOT_MOTOR4, -90);
}

void stand(CiMobot &robot)
{
  int i;
  int speed;
  /* Go to home position first */
  for(i = IMOBOT_MOTOR1; i < IMOBOT_NUM_MOTORS; i++) {
    robot.setMotorPosition(i, 0);
  }
  robot.moveWait();
  sleep(IMOBOT_MOTOR3);

  /* Arch the robot */
  robot.setMotorPosition(IMOBOT_MOTOR1, -85);
  robot.setMotorPosition(IMOBOT_MOTOR2, 80);
  robot.moveWait();

  /* Twist the bottom face */
  robot.setMotorPosition(IMOBOT_MOTOR3, 45);
  robot.waitMotor(IMOBOT_MOTOR3);

  /* Stand the robot up slowly */
  /* First, save the speed */
  robot.getMotorSpeed(IMOBOT_MOTOR1, speed);
  robot.setMotorSpeed(IMOBOT_MOTOR1, 30);
  robot.setMotorPosition(IMOBOT_MOTOR1, 20);
  robot.waitMotor(IMOBOT_MOTOR1);
  /* Reset the old speed */
  robot.setMotorSpeed(IMOBOT_MOTOR1, speed);
}

int main()
{
  int i;
  CiMobot robot;

  /* Set the robot to "home" position, where all joint angles are 0 degrees. */
  robot.poseZero();
  robot.moveWait();

  /* Roll the robot forward */
  move_forward(robot);
  robot.moveWait();

  /* Rotate left */
  rotate_left(robot);
  robot.moveWait();

  /* Roll the robot backward */
  move_backward(robot);
  robot.moveWait();

  /* Rotate right */
  rotate_right(robot);
  robot.moveWait();

  /* Stand the robot up */
  stand(robot);
  robot.moveWait();

  return 0;
}


