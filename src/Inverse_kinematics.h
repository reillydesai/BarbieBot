#ifndef INVERSE_KINEMATICS
#define INVERSE_KINEMATICS

#include <Romi32U4.h>

class InverseKinematics{
    private:
        float currentx = 0;
        float currenty = 0;
        float currentTheta = 0;

        void UpdatePose(void); // updates currentx, currenty, currentTheta

    public:
        void Init(void);
        void DriveToTarget(float, float, float); // x, y, theta as parsed from Barbie; BLOCKING
        void Stop(void);
};

#endif