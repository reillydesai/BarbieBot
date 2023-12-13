#ifndef POSITION_ESTIMATION
#define POSITION_ESTIMATION

#include <Romi32U4.h>

class Position{
    private:
        float x, y, theta;
        
        unsigned long time_prev, time_now; //time for forward kinematics
        unsigned long turn_t_prev, turn_t_now; //time for turn detection
        const unsigned long interval = 50; //interval for turn detection
        
        float theta_prev;
        
        float x_lower_target = 0;
        float x_upper_target = 0;
        float y_lower_target = 0;
        float y_upper_target = 0;

        const float l = 0.142875; //meters
    public:
        void Init(void);
        void UpdatePose(float,float);
        String PoseToString(void);
        void Stop(void);
        float GetX(void);
        float GetY(void);
        float GetTheta(void);
        bool TurnDetected(void);
        bool EndReached(void);
};

#endif