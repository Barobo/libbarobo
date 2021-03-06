/* Filename: dogWithTumbles.ch
   Control five modules to make three of them tumble 3 times in one direction
   and the other two tumble three times.
               1
            -------
             |   |
            2|   |
             |   |
            ------- 3rd
             |   |
            3|   |
             |   |
            --------
            \  4   /
            /\    /\3
          \/ 4\  /4 \/
          |\  /\/\  /|
       2nd| \/3   \/ |  1st
          |  \    /  |2
          |  |2   |  |
         ------  ------
           1        1

      |---------|--------|
4th 1 |    2    |   3    | 4
      |---------|--------|
                X
      |---------|--------|
5th 1 |    2    |   3    | 4
      |---------|--------|

All switches are located at the positions with "3" marked.
Before assembling, please make sure every modules are in the home position.
*/
#include <mobot.h>
CMobot mobot1;
CMobot mobot2;
CMobot mobot3;
CMobot mobot4;
CMobot mobot5;
int i;

/* Connect mobot variables to the mobot modules. */
mobot1.connect();
mobot2.connect();
mobot3.connect();
mobot4.connect();
mobot5.connect();

/* set mobots' joints speed */
mobot1.setJointSpeedRatios(0.45, 0.45, 0.45, 0.45);
mobot2.setJointSpeedRatios(0.45, 0.45, 0.45, 0.45);
mobot3.setJointSpeedRatios(0.45, 0.45, 0.45, 0.45);
mobot4.setJointSpeedRatios(0.9, 0.9, 0.9, 0.9);
mobot5.setJointSpeedRatios(0.8, 0.8, 0.8, 0.8);

// direction: left
mobot4.motionTumbleRightNB(3);
mobot5.motionTumbleRightNB(3);

for (i = 0; i < 1; i++)
{
    /* mobot 3 on the top */
    mobot3.moveTo(0, -5, 96, 90);
    mobot1.moveTo(0, -55, 63.5, 90);
    mobot2.moveTo(0, -5, 92.5, 90);

    mobot1.moveToNB(0, 0, -63.5, 90);
    mobot3.moveToNB(0, 0, 63.5, 90);
    mobot1.moveWait();
    mobot3.moveWait();

    /* mobot 2 on the top */
    mobot2.moveTo(0, -5, 96, 90);
    mobot3.moveTo(0, -55, 63.5, 90);
    mobot1.moveTo(0, -5, 92.5, 90);

    mobot3.moveToNB(0, 0, -63.5, 90);
    mobot2.moveToNB(0, 0, 63.5, 90);
    mobot3.moveWait();
    mobot2.moveWait();

    /* mobot 1 on the top */
    mobot1.moveTo(0, -5, 96, 90);
    mobot2.moveTo(0, -55, 63.5, 90);
    mobot3.moveTo(0, -5, 92.5, 90);

    mobot2.moveToNB(0, 0, -63.5, 90);
    mobot1.moveToNB(0, 0, 63.5, 90);
    mobot2.moveWait();
    mobot1.moveWait();
}
mobot4.motionWait();
mobot5.motionWait();

// direction: right
mobot4.motionTumbleLeftNB(3);
mobot5.motionTumbleLeftNB(3);

for (i = 0; i < 1; i++) {
    /* mobot 3 on the top */
    mobot3.moveTo(0, 5, -96, 90);
    mobot2.moveTo(0, 55, -63.5, 90);
    mobot1.moveTo(0, 5, -92.5, 90);

    mobot2.moveToNB(0, 0, 63.5, 90);
    mobot3.moveToNB(0, 0, -63.5, 90);
    mobot2.moveWait();
    mobot3.moveWait();

    /* mobot 1 on the top */
    mobot1.moveTo(0, 5, -96, 90);
    mobot3.moveTo(0, 55, -63.5, 90);
    mobot2.moveTo(0, 5, -92.5, 90);

    mobot3.moveToNB(0, 0, 63.5, 90);
    mobot1.moveToNB(0, 0, -63.5, 90);
    mobot3.moveWait();
    mobot1.moveWait();

    /* mobot 2 on the top*/
    mobot2.moveTo(0, 5, -96, 90);
    mobot1.moveTo(0, 55, -63.5, 90);
    mobot3.moveTo(0, 5, -92.5, 90);

    mobot1.moveToNB(0, 0, 63.5, 90);
    mobot2.moveToNB(0, 0, -63.5, 90);
    mobot1.moveWait();
    mobot2.moveWait();
}

mobot4.motionWait();
mobot5.motionWait();
