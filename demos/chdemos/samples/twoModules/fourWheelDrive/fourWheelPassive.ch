/* Filename: fourWheelPassive.ch
   Control two modules with four wheels.
      |---------|--------|             
1st 1 |    2    |   3    | 4    
      |---------|--------|             
                X
      |---------|--------|       
2nd 1 |    2    |   3    | 4    
      |---------|--------|      
*/
#include <mobot.h>
CMobot mobot1;
CMobot mobot2;

/* Connect mobot variables to the mobot modules. */
mobot1.connect();
mobot2.connect();

/* Set the mobot to "home" position, where all joint angles are 0 degrees. */
mobot1.resetToZeroNB();
mobot2.resetToZeroNB();
mobot1.moveWait();
mobot2.moveWait();

/* rolling with second one passive */
mobot1.motionRollForwardNB(2*360);
mobot2.moveContinuousTime(ROBOT_NEUTRAL, ROBOT_HOLD, 
                        ROBOT_HOLD, ROBOT_NEUTRAL, 5);
mobot1.moveWait();
mobot2.moveWait();
