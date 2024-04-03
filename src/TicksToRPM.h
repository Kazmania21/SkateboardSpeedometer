#include "Chrono.h"

class TicksToRPMConverter {
    public:
    int counter = 0;
    int new_pulse_flag;
    Chrono timer;
    int startTime = timer.elapsed();

    float READ_RPM(){
        float RPM;

        int Ts;

        int stopTime = timer.elapsed();

        new_pulse_flag = 1; //tells the RPM ISR that we just read the RPM

        if(stopTime > startTime) { //ensures that Ts is a positive number
            Ts = 0xFFFFFFFF - stopTime + startTime;
        }

        else {
            Ts = startTime - stopTime;
        }


        if(Ts == 0) { //ensures that if no encoder pulses hit, we set RPM to 0
            RPM = 0;
        }

        else {
            RPM = counter * (6000000000.0/( (float)Ts * 7 * 20));
        }

        timer.restart();
        int startTime = timer.elapsed();

        return RPM;
    }

    void increment_counter() {
        counter++;
    }

    void get_time_since_start() {
        return timer.elapsed();
    }
};
