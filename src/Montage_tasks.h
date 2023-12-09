#ifndef MONTAGE_TASKS
#define MONTAGE_TASKS

#include <Romi32U4.h>

class Montage{
    private:
        // buzzer pin
        // PWM consts for notes
        long/*?*/ song[8][2] = {0}; // 2D array for notes in order with times
        int i = 0;
        unsigned long time_prev;

        void BuzzerStop(void);

    public:
        void Init(void);
        bool HulaHoop(void);
        bool Buzzer(void);
        bool Turn(void); // 90 degrees
};

#endif