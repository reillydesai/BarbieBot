#include <Romi32U4.h>
#include "Encoders.h"
#include  "Speed_controller.h"
#include "Montage_tasks.h"

SpeedController controller;

void Montage::Init(void){

}

bool Montage::HulaHoop(){
    // if less than 3 turns return false
    // if more than 3 turns call stop & return true
}

void Montage::HulaHoopStop(){
    controller.Stop();
}

bool Montage::Buzzer(){

}

void Montage::BuzzerStop(){

}