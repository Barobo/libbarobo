#include <stdlib.h>
#include "mobot.h"
#include "mobot_internal.h"
#include "linkbot.h"

#define DEPRECATED(from, to) \
  fprintf(stderr, "Warning: The function \"%s()\" is deprecated. Please use \"%s()\"\n" , from, to)

CLinkbotIGroup::CLinkbotIGroup()
{
  _numRobots = 0;
  _motionInProgress = 0;
  _thread = (THREAD_T*)malloc(sizeof(THREAD_T));
  _robots = (CLinkbotI**)CMobotGroup::_robots;
}

CLinkbotIGroup::~CLinkbotIGroup()
{
}

int CLinkbotIGroup::addRobot(CLinkbotI& mobot)
{
  int rc;
  rc = CMobotGroup::addRobot((CMobot&)mobot);
  _robots = (CLinkbotI**)CMobotGroup::_robots;
  return rc;
}

int CLinkbotIGroup::addRobots(CLinkbotI mobots[], int numMobots)
{
  int rc = CMobotGroup::addRobots(mobots, numMobots);
  _robots = (CLinkbotI**)CMobotGroup::_robots;
  return rc;
}

int CLinkbotIGroup::connect()
{
  for(int i = 0; i < _numRobots; i++) {
    ((CLinkbotI*)_robots[i])->connect();
  }
  return 0;
}

int CLinkbotIGroup::driveToDirect(double angle1, double angle2, double angle3)
{
  driveToDirectNB(angle1, angle2, angle3);
  return moveWait();
}

int CLinkbotIGroup::driveTo(double angle1, double angle2, double angle3)
{
  driveToDirectNB(angle1, angle2, angle3);
  return moveWait();
}

int CLinkbotIGroup::driveToDirectNB(double angle1, double angle2, double angle3)
{
  for(int i = 0; i < _numRobots; i++) {
    _robots[i]->driveToDirectNB(angle1, angle2, angle3);
  }
  return 0;
}

int CLinkbotIGroup::driveToNB(double angle1, double angle2, double angle3)
{
  for(int i = 0; i < _numRobots; i++) {
    _robots[i]->driveToDirectNB(angle1, angle2, angle3);
  }
  return 0;
}

int CLinkbotIGroup::move(double angle1, double angle2, double angle3)
{
  moveNB(angle1, angle2, angle3);
  return moveWait();
}

int CLinkbotIGroup::moveNB(double angle1, double angle2, double angle3)
{
  for(int i = 0; i < _numRobots; i++) {
    _robots[i]->moveNB(angle1, angle2, angle3);
  }
  return 0;
} 

int CLinkbotIGroup::moveContinuousNB(mobotJointState_t dir1, 
                       mobotJointState_t dir2, 
                       mobotJointState_t dir3)
{
  DEPRECATED("moveContinuousNB", "setMovementStateNB");
  return setMovementStateNB(dir1, dir2, dir3);
}

int CLinkbotIGroup::moveContinuousTime(mobotJointState_t dir1, 
                           mobotJointState_t dir2, 
                           mobotJointState_t dir3, 
                           double seconds)
{
  DEPRECATED("moveContinuousTime", "setMovementStateTime");
  return setMovementStateTime(dir1, dir2, dir3, seconds);
}

int CLinkbotIGroup::moveTo(double angle1, double angle2, double angle3)
{
  moveToNB(angle1, angle2, angle3);
  return moveWait();
}

int CLinkbotIGroup::moveToDirect(double angle1, double angle2, double angle3)
{
  moveToDirectNB(angle1, angle2, angle3);
  return moveWait();
}

int CLinkbotIGroup::moveToNB(double angle1, double angle2, double angle3)
{
  for(int i = 0; i < _numRobots; i++) {
    _robots[i]->moveToNB(angle1, angle2, angle3);
  }
  return 0;
}

int CLinkbotIGroup::moveToDirectNB(double angle1, double angle2, double angle3)
{
  for(int i = 0; i < _numRobots; i++) {
    _robots[i]->moveToDirectNB(angle1, angle2, angle3);
  }
  return 0;
}

int CLinkbotIGroup::setJointSpeeds(double speed1, double speed2, double speed3)
{
  for(int i = 0; i < _numRobots; i++) {
    _robots[i]->setJointSpeeds(speed1, speed2, speed3);
  }
  return 0;
}

int CLinkbotIGroup::setJointSpeedRatios(double ratio1, double ratio2, double ratio3)
{
  for(int i = 0; i < _numRobots; i++) {
    _robots[i]->setJointSpeedRatios(ratio1, ratio2, ratio3);
  }
  return 0;
}

int CLinkbotIGroup::setMovementStateNB(mobotJointState_t dir1, 
                       mobotJointState_t dir2, 
                       mobotJointState_t dir3)
{
  for(int i = 0; i < _numRobots; i++) {
    _robots[i]->setMovementStateNB(dir1, dir2, dir3);
  }
  return 0;
}

int CLinkbotIGroup::setMovementStateTime(mobotJointState_t dir1, 
                           mobotJointState_t dir2, 
                           mobotJointState_t dir3, 
                           double seconds)
{
  int msecs = seconds * 1000.0;
  for(int i = 0; i < _numRobots; i++) {
    _robots[i]->setMovementStateNB(dir1, dir2, dir3);
  }
#ifdef _WIN32
  Sleep(msecs);
#else
  usleep(msecs*1000);
#endif
  for(int i = 0; i < _numRobots; i++) {
    //_robots[i]->stop();
    _robots[i]->setMovementStateNB(MOBOT_HOLD, MOBOT_HOLD, MOBOT_HOLD);
  }
  return 0;
}

int CLinkbotIGroup::setMovementStateTimeNB(mobotJointState_t dir1, 
                           mobotJointState_t dir2, 
                           mobotJointState_t dir3, 
                           double seconds)
{
  int msecs = seconds * 1000.0;
  for(int i = 0; i < _numRobots; i++) {
    _robots[i]->setMovementStateNB(dir1, dir2, dir3);
  }
  return 0;
}

