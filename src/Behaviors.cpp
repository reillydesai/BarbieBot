#include <Romi32U4.h>
#include "Behaviors.h"
#include "Speed_controller.h"
#include "Position_estimation.h"
#include "Montage_tasks.h"
#include "Wall_following_controller.h"

// sensors
Romi32U4ButtonA buttonA;

//
SpeedController robot;
Position positionTracking;
Montage tasks;
WallFollowingController wallFollower;


void Behaviors::Init(void)
{
    robot.Init();
    wallFollower.Init();
    tasks.Init();
}

void Behaviors::Stop(void)
{
    robot.Stop();
}

void Behaviors::Run(void)
{
    switch (drive_state)
    {
        case IDLE:
            break;
                
        case WALL_FOLLOW:
            if (wallFollower.SpikeDetected()) {
                drive_state = TURN;
            }
            else if (/*seeing april tag*/ false) {
                // if num change state and add to array in communications class unless turn
                // if buzzer num change buzzer state, add to array, and start sending communications
            }
            if (positionTracking.EndReached()) drive_state = IDLE;
            break;
        
        case TURN:
            if (tasks.Turn()) {
                drive_state = WALL_FOLLOW;
                wallFollower.Reset();
            }
            break;

        case HULA_HOOP:
            if (tasks.HulaHoop()) {
                drive_state = WALL_FOLLOW;
                wallFollower.Reset();
            }
            break;
    }

    switch (buzzer_state)
    {
        case OFF:
            break;

        case ON:
            if (tasks.Buzzer()) {
                buzzer_state = OFF;
            }
            break;
    }

    // may reevaluate placement once communications class is developed
    if (positionTracking.TurnDetected() && drive_state != HULA_HOOP) {
        // add to array of strings to send in communications class
    }

    

}