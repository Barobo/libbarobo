/* Discriptioin:
 * In this scene, two-module mobot do as fourWheelDrive.
 *      |---------|--------|             
 *1st 1 |    2    |   3    | 4    
 *      |---------|--------|             
 *                X
 *      |---------|--------|       
 *2nd 1 |    2    |   3    | 4    
 *      |---------|--------|      
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

mobot1.setJointSpeedRatios(0.8, 0.5, 0.5, 0.8);
mobot2.setJointSpeedRatios(0.8, 0.5, 0.5, 0.8);
/* rolling forward*/
mobot1.motionRollForwardNB(360);
mobot2.motionRollForwardNB(360);

mobot1.moveWait();
mobot2.moveWait();
/* rolling backward*/
mobot1.motionRollForwardNB(-2*360);
mobot2.motionRollForwardNB(-2*360);
mobot1.moveWait();
mobot2.moveWait();
