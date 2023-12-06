#include <Romi32U4.h>
#include  "Speed_controller.h"
#include  "Position_estimation.h"
#include "Inverse_kinematics.h"
#include "math.h"

SpeedController drive;
Position forwardKinematics;

void InverseKinematics::Init(void){

}

void InverseKinematics::DriveToTarget(float x, float y, float theta) {
    UpdatePose();
    float targetTheta = atan2(y - currenty, x - currentx);
    if (targetTheta > currentTheta) {
        while (targetTheta > currentTheta) {
            drive.Run(-50, 50)
            UpdatePose();
        }
    } else {
        while (targetTheta < currentTheta) {
            drive.Run(50, -50)
            UpdatePose();
        }
    }
    drive.Stop();
    if (x > currentx) {
        while (x > currentx) {
            drive.Run(50, 50)
            UpdatePose();
        }
    } else {
        while (x < currentx) {
            drive.Run(50, 50)
            UpdatePose();
        }
    }
    drive.Stop();
    if (theta > currentTheta) {
        while (theta > currentTheta) {
            drive.Run(-50, 50)
            UpdatePose();
        }
    } else {
        while (theta < currentTheta) {
            drive.Run(50, -50)
            UpdatePose();
        }
    }
}

void InverseKinematics::UpdatePose(void){
    currentx = forwardKinematics.GetX();
    currenty = forwardKinematics.GetY();
    currentTheta = forwardKinematics.GetTheta();
}

void InverseKinematics::Stop(void){
    drive.Stop();
}