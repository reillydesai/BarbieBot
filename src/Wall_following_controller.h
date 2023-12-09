#ifndef WALL_FOLLOWING_CONTROLLER
#define WALL_FOLLOWING_CONTROLLER

#include <Romi32U4.h>

class WallFollowingController{
    private:
        const float Kp = 9; //Adapt parameters Kp and Kd until your robot consistently drives along a wall
        const float Kd = 3;
        float E_left = 0;
        float E_right = 0;
        float E_distance = 0;
        float prev_e_distance = 0;
        
        const float spike_threshold = 100;

    public:
        void Init(void);
        void Reset(void);
        float Process(float);
        bool SpikeDetected(void);
};

#endif