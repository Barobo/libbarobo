#ifndef _GTKIMOBOTCONTROLLER_H_
#define _GTKIMOBOTCONTROLLER_H_

#include <gtk/gtk.h>
#include <imobot.h>
#include "gait.h"
#define MOTION_POSE 0
#define MOTION_MOVE 1

/* These function prototypes need to be in "C" so that gmodule can find them */
extern "C" {

int initialize();
int init_gaits();

/* Main Dialog */
void on_menuitem_connect_activate(GtkWidget* widget, gpointer data);
void on_menuitem_localInit_activate(GtkWidget* widget, gpointer data);
void on_menuitem_quit_activate(GtkWidget* widget, gpointer data);
void on_button_connectRemote_clicked(GtkWidget* widget, gpointer data);
void on_button_connectLocal_clicked(GtkWidget* widget, gpointer data);
void on_checkmenuitem_motorPos_toggled(GtkWidget* widget, gpointer data);

/* Connect Dialog */
void on_button_connect_clicked(GtkWidget* widget, gpointer data);
void on_button_connect_cancel_clicked(GtkWidget* widget, gpointer data);

/* Movement Handlers */
void on_button_forward_clicked(GtkWidget* widget, gpointer data);
void buttonForward();
void on_button_backward_clicked(GtkWidget* widget, gpointer data);
void buttonBackward();
void on_button_rotateLeft_clicked(GtkWidget* widget, gpointer data);
void buttonRotateLeft();
void on_button_rotateRight_clicked(GtkWidget* widget, gpointer data);
void buttonRotateRight();
void on_button_lfaceForward_clicked(GtkWidget* widget, gpointer data);
void buttonLFaceForward();
void on_button_lfaceBackward_clicked(GtkWidget* widget, gpointer data);
void buttonLFaceBackward();
void on_button_rfaceForward_clicked(GtkWidget* widget, gpointer data);
void buttonRFaceForward();
void on_button_rfaceBackward_clicked(GtkWidget* widget, gpointer data);
void buttonRFaceBackward();
void on_button_inchLeft_clicked(GtkWidget* widget, gpointer data);
void on_button_inchRight_clicked(GtkWidget* widget, gpointer data);
void on_button_stop_clicked(GtkWidget* widget, gpointer data);
void buttonStop();
void on_button_home_clicked(GtkWidget* widget, gpointer data);
void buttonHome();
void on_button_playGait_clicked(GtkWidget* widget, gpointer data);
void on_button_moveJoints_clicked(GtkWidget* widget, gpointer data);
void buttonMoveJoints();
gboolean on_vscale_motorspeed0_change_value(
    GtkRange* range,
    GtkScrollType scroll,
    gdouble value,
    gpointer user_data);
void on_vscale_motorspeed0_value_changed(GtkRange* range, gpointer data);

void buttonMotorForward(int id);
void buttonMotorStop(int id);
void buttonMotorBack(int id);
void motor_forward(int id);
void motor_stop(int id);
void motor_back(int id);
void buttonSpeed1(double speed);
void buttonSpeed2(double speed);
void buttonSpeed3(double speed);
void buttonSpeed4(double speed);
void on_button_motor0forward_clicked(GtkWidget* widget, gpointer data);
void on_button_motor1forward_clicked(GtkWidget* widget, gpointer data);
void on_button_motor2forward_clicked(GtkWidget* widget, gpointer data);
void on_button_motor3forward_clicked(GtkWidget* widget, gpointer data);
void on_button_motor0stop_clicked(GtkWidget* widget, gpointer data);
void on_button_motor1stop_clicked(GtkWidget* widget, gpointer data);
void on_button_motor2stop_clicked(GtkWidget* widget, gpointer data);
void on_button_motor3stop_clicked(GtkWidget* widget, gpointer data);
void on_button_motor0back_clicked(GtkWidget* widget, gpointer data);
void on_button_motor1back_clicked(GtkWidget* widget, gpointer data);
void on_button_motor2back_clicked(GtkWidget* widget, gpointer data);
void on_button_motor3back_clicked(GtkWidget* widget, gpointer data);

gboolean on_vscale_motorspeed0_button_release_event(GtkRange* range, GdkEvent* event, gpointer data);
gboolean on_vscale_motorspeed1_button_release_event(GtkRange* range, GdkEvent* event, gpointer data);
gboolean on_vscale_motorspeed2_button_release_event(GtkRange* range, GdkEvent* event, gpointer data);
gboolean on_vscale_motorspeed3_button_release_event(GtkRange* range, GdkEvent* event, gpointer data);
gboolean on_vscale_motorPos_button_press_event(GtkRange* range, GdkEvent* event, gpointer data);
gboolean on_vscale_motorPos_button_release_event(GtkRange* range, GdkEvent* event, gpointer data);

/* Misc. */
void quick_message (GtkWidget* parent, gchar *message);
int getIterModelFromTreeSelection(GtkTreeView *treeView, GtkTreeModel **model, GtkTreeIter *iter);
int addGait(Gait* gait);
Gait* findGait(const char* name);
int executeGait(Gait* gait);
int executeGaitMotion(Gait* gait, int numMotion);
void* updateMotorAngles(gpointer data);

int setMotorDirection(int motor, int direction);
int setMotorSpeed(int motor, double speed);
int stop();
int setMotorPosition(int motor, double position);
int setMotorPositionPID(int motor, double position);
int getMotorPosition(int motor, double *position);
int waitMotor(int motor);
int isMoving();
}

typedef enum stateType_e {
  STATE_IDLE,
  STATE_BEGINGAIT,
  STATE_GAIT,
  STATE_SENDCMD
}stateType_t;

typedef enum buttons_e {
  B_FORWARD,
  B_BACKWARD,
  B_ROTATELEFT,
  B_ROTATERIGHT,
  B_LFACEFORWARD,
  B_LFACEBACKWARD,
  B_RFACEFORWARD,
  B_RFACEBACKWARD,
  B_STOP,
  B_HOME,
  B_MOVEJOINTS,
  B_SPEED1,
  B_SPEED2,
  B_SPEED3,
  B_SPEED4,
  B_M1F, //Motor 1 forward
  B_M2F, 
  B_M3F,
  B_M4F, 
  B_M1B, // Motor Backward
  B_M2B,
  B_M3B,
  B_M4B,
  B_M1S, // Motor Stop
  B_M2S,
  B_M3S,
  B_M4S,
  B_NUMBUTTONS
}button_t;

typedef struct buttonState_s
{
  int clicked;
  int iargs[4];
  double dargs[4];
} buttonState_t;

typedef struct programState_s {
  stateType_t state;
  int arg;
  int index;
  Gait* gait;
  pthread_mutex_t* lock;
  char command[512];
}programState_t;

extern buttonState_t* g_buttonState;
extern programState_t* g_programState;
extern GtkBuilder *builder;
extern br_comms_t *imobotComms;
extern iMobot_t *iMobot;
extern GtkWidget  *window;
extern GtkWidget  *dialog_connect;
extern GtkWidget  *dialog_intro;
extern Gait* g_gaits[100];
extern int g_numGaits;
extern GtkVScale* scale_motorSpeeds[4];
extern int g_isConnected;
extern int g_localInit;
extern GtkVScale* scale_motorPositions[4];
extern int motor_position_scale_pressed[4];

#endif
