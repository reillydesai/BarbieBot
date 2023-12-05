#include <Romi32U4.h>
#include "Behaviors.h"
#include "Speed_controller.h"
#include "Position_estimation.h"
#include "Montage_tasks.h"

// sensors
Romi32U4ButtonA buttonA;

// motor-speed controller
SpeedController robot;

// function imports
Position positionTracking;
Montage tasks;

void Behaviors::Init(void)
{
    robot.Init();
}

void Behaviors::Stop(void)
{
    robot.Stop();
}

void Behaviors::Run(void)
{
    switch (robot_state)
    {
    case IDLE:
        // if next step recieved from barbie
            // change state to next step
            
    case DRIVE:
        
        break;
    
    case HULA_HOOP:
        if (tasks.HulaHoop()) robot_state = IDLE;
        break;

    case BUZZER:
        if (tasks.Buzzer()) 
        break;
    }
}