#include <Romi32U4.h>
#include "Encoders.h"
#include  "Speed_controller.h"
#include "Montage_tasks.h"

SpeedController controller;

void Montage::Init(void)
{
    time_prev = millis();
    // initiaize buzzer pin
}

bool Montage::HulaHoop()
{
    // if less than 3 turns return false
    // if more than 3 turns controller.stop stop & return true
}

bool Montage::Buzzer()
{
    if (i < 0 /*num rows/notes in song*/) {
        if (millis() - time_prev < song[i][1])
        {
            /*play note at song[i][0]*/ 
        } else {
            BuzzerStop();
            i++;
            time_prev = millis();
        }
        return false;
    } else {
        return true;
    }
}

void Montage::BuzzerStop()
{
    // set buzzer to off
}

bool Montage::Turn()
{
    // if less than 90 degrees (turning left) return false
    // if less than 90 degrees controller.stop & return true
}