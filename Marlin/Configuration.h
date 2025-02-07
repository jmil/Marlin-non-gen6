#ifndef CONFIGURATION_H
#define CONFIGURATION_H

// BASIC SETTINGS: select your board type, thermistor type, axis scaling, and endstop configuration

//// The following define selects which electronics board you have. Please choose the one that matches your setup
// MEGA/RAMPS up to 1.2  = 3,
// RAMPS 1.3 = 33
// Gen6 = 5, 
// Sanguinololu up to 1.1 = 6
// Sanguinololu 1.2 and above = 62
// Gen 3 Plus = 21
// gen 3  Monolithic Electronics = 22
#define MOTHERBOARD 33 

//// Thermistor settings:
// 1 is 100k thermistor
// 2 is 200k thermistor
// 3 is mendel-parts thermistor
// 4 is 10k thermistor
// 5 is ParCan supplied 104GT-2 100K
#define THERMISTORHEATER 3
#define THERMISTORBED 1

//// Calibration variables
// X, Y, Z, E steps per unit - Metric Prusa Mendel with Hinged Greg's Wade extruder:
// SloateBot:
// X and Y axes are 19.25 mm pitch diameter, SDP-SI.com #A6M35M012DF1005, which gives us
//    C=19.25pi mm per rev. At 1/2 stepping that is 400 steps per rev. so then we have 400/(19.25pi) = 6.614231401221625 stepspermm
//    At 1/4 stepping that is 800 steps per rev. so then we have 800/(19.25pi) = 13.22846280244325 stepspermm
//    At 1/16th stepping that is 3200/(19.25pi) = 52.913851209772999 stepspermm.
// Z-axis: 1.8 degree is 200 steps per revolution, 1 revolution is 1.25 mm (z-rod pitch), at 1/16th stepping
//    we have 3200 steps/1.25 mm to give 2560 stepspermm
// E-axis: 7.25 mm is diameter of hobbed bolt, so C = 7.25pi per rev. At 1/16th stepping this is: 800/(7.25pi), but we have
//    hinged wade extruder, so this is converted 43/10 ratio. I think these are all wrong anyway... just do 4x the quarter stepping
//    we had before
float axis_steps_per_unit[] = {52.913851209772999, 52.913851209772999, 2560, 498.120047595448};
// Metric Prusa Mendel with Makergear geared stepper extruder:
//float axis_steps_per_unit[] = {80,80,3200/1.25,1380}; 
// MakerGear Hybrid Prusa Mendel:
// Z axis value is for .9 stepper(if you have 1.8 steppers for Z, you need to use 2272.7272)
//float axis_steps_per_unit[] = {104.987, 104.987, 4545.4544, 1487};

//// Endstop Settings
#define ENDSTOPPULLUPS 1 // Comment this out (using // at the start of the line) to disable the endstop pullup resistors
// The pullups are needed if you directly connect a mechanical endswitch between the signal and ground pins.
const bool ENDSTOPS_INVERTING = false; //set to true to invert the logic of the endstops
//If your axes are only moving in one direction, make sure the endstops are connected properly.
//If your axes move in one direction ONLY when the endstops are triggered, set ENDSTOPS_INVERTING to true here

// This determines the communication speed of the printer
#define BAUDRATE 250000

// Comment out (using // at the start of the line) to disable SD support:
//#define SDSUPPORT 1


//// ADVANCED SETTINGS - to tweak parameters

#include "thermistortables.h"

// For Inverting Stepper Enable Pins (Active Low) use 0, Non Inverting (Active High) use 1
#define X_ENABLE_ON 0
#define Y_ENABLE_ON 0
#define Z_ENABLE_ON 0
#define E_ENABLE_ON 0

// Disables axis when it's not being used.
const bool DISABLE_X = false;
const bool DISABLE_Y = false;
const bool DISABLE_Z = true;
const bool DISABLE_E = false;

// Inverting axis direction
const bool INVERT_X_DIR = false;
const bool INVERT_Y_DIR = true;
const bool INVERT_Z_DIR = false;
const bool INVERT_E_DIR = true;

//// ENDSTOP SETTINGS:
// Sets direction of endstops when homing; 1=MAX, -1=MIN
#define X_HOME_DIR -1
#define Y_HOME_DIR -1
#define Z_HOME_DIR -1

const bool min_software_endstops = false; //If true, axis won't move to coordinates less than zero.
const bool max_software_endstops = true;  //If true, axis won't move to coordinates greater than the defined lengths below.
// With 40 mm fan we can only go max of 170 mm on x-axis
const int X_MAX_LENGTH = 170;
const int Y_MAX_LENGTH = 190;
const int Z_MAX_LENGTH = 130;

//// MOVEMENT SETTINGS
const int NUM_AXIS = 4; // The axis order in all axis related arrays is X, Y, Z, E
float max_feedrate[] = {200000, 200000, 300, 500000};
float homing_feedrate[] = {1500,1500,300};
bool axis_relative_modes[] = {false, false, false, false};


// Comment this to disable ramp acceleration
#define RAMP_ACCELERATION 1

//// Acceleration settings
#ifdef RAMP_ACCELERATION
// X, Y, Z, E maximum start speed for accelerated moves. E default values are good for skeinforge 40+, for older versions raise them a lot.
float acceleration = 2000;         // Normal acceleration mm/s^2
float retract_acceleration = 7000; // Normal acceleration mm/s^2
float max_xy_jerk = 20.0*60;
float max_z_jerk = 0.4*60;
float max_start_speed_units_per_second[] = {10.0,10.0,0.2,10.0};
long max_acceleration_units_per_sq_second[] = {500,500,50,500}; // X, Y, Z and E max acceleration in mm/s^2 for printing moves or retracts
#endif

// Machine UUID
// This may be useful if you have multiple machines and wish to identify them by using the M115 command. 
// By default we set it to zeros.
char uuid[] = "00000000-0000-0000-0000-000000000000";


//// AD595 THERMOCOUPLE SUPPORT UNTESTED... USE WITH CAUTION!!!!

//// PID settings:
// Uncomment the following line to enable PID support. This is untested and could be disastrous. Be careful.
//#define PIDTEMP 1
#ifdef PIDTEMP
#define PID_MAX 255 // limits current to nozzle
#define PID_INTEGRAL_DRIVE_MAX 220
#define PID_PGAIN 180 //100 is 1.0
#define PID_IGAIN 2 //100 is 1.0
#define PID_DGAIN 100 //100 is 1.0
#endif

// How often should the heater check for new temp readings, in milliseconds
#define HEATER_CHECK_INTERVAL 500
#define BED_CHECK_INTERVAL 5000
// Comment the following line to enable heat management during acceleration
#define DISABLE_CHECK_DURING_ACC
#ifndef DISABLE_CHECK_DURING_ACC
  // Uncomment the following line to disable heat management during moves
  //#define DISABLE_CHECK_DURING_MOVE
#endif
// Uncomment the following line to disable heat management during travel moves (and extruder-only moves, eg: retracts), strongly recommended if you are missing steps mid print.
// Probably this should remain commented if are using PID.
// It also defines the max milliseconds interval after which a travel move is not considered so for the sake of this feature.
#define DISABLE_CHECK_DURING_TRAVEL 1000

//// Temperature smoothing - only uncomment this if your temp readings are noisy (Gen6 without EvdZ's 5V hack)
//#define SMOOTHING 1
//#define SMOOTHFACTOR 16 //best to use a power of two here - determines how many values are averaged together by the smoothing algorithm

//// Experimental watchdog and minimal temp
// The watchdog waits for the watchperiod in milliseconds whenever an M104 or M109 increases the target temperature
// If the temperature has not increased at the end of that period, the target temperature is set to zero. It can be reset with another M104/M109
//#define WATCHPERIOD 5000 //5 seconds

//// The minimal temperature defines the temperature below which the heater will not be enabled
#define MINTEMP 5

//// Experimental max temp
// When temperature exceeds max temp, your heater will be switched off.
// This feature exists to protect your hotend from overheating accidentally, but *NOT* from thermistor short/failure!
// You should use MINTEMP for thermistor short/failure protection.
#define MAXTEMP 275

// Select one of these only to define how the nozzle temp is read.
#define HEATER_USES_THERMISTOR
//#define HEATER_USES_AD595
//#define HEATER_USES_MAX6675

// Select one of these only to define how the bed temp is read.
#define BED_USES_THERMISTOR
//#define BED_USES_AD595

// Uncomment the following line to enable debugging. You can better control debugging below the following line
//#define DEBUG
#ifdef DEBUG
  //#define DEBUG_PREPARE_MOVE //Enable this to debug prepare_move() function
  //#define DEBUG_BRESENHAM //Enable this to debug the Bresenham algorithm
  //#define DEBUG_RAMP_ACCELERATION //Enable this to debug all constant acceleration info
  //#define DEBUG_MOVE_TIME //Enable this to time each move and print the result
  //#define DEBUG_HEAT_MGMT //Enable this to debug heat management. WARNING, this will cause axes to jitter!
  //#define DEBUG_DISABLE_CHECK_DURING_TRAVEL //Debug the namesake feature, see above in this file
#endif

#endif
