#ifndef BEHAVIORS
#define BEHAVIORS

#include <Romi32U4.h>

class Behaviors{
    private:
        enum DRIVE_STATE {IDLE, WALL_FOLLOW, TURN, HULA_HOOP};
        enum BUZZER_STATE {ON, OFF};
        DRIVE_STATE drive_state = IDLE; //initial state: IDLE
        BUZZER_STATE buzzer_state = OFF; //initial state: OFF

        
    public:
        void Init(void); 
        void Stop(void);
        void Run(void);
};

#endif