#include "Chrono.h"

class TicksToRPMConverter {
    public:
    int counter = 0;
    int new_pulse_flag;
    Chrono timer;
    int startTime = timer.elapsed();
    int motorDiameter;
    int wheelDiameter;

    TicksToRPMConverter(int _motorDiameter, int _wheelDiameter) {
        motorDiameter = _motorDiameter;
        wheelDiameter = _wheelDiameter;
    }

    float READ_RPM(){
        int stopTime = timer.elapsed();

        new_pulse_flag = 1; //tells the RPM ISR that we just read the RPM

        int Ts = CreateTs(stopTime);

        float MOTOR_RPM = GetMotorRPM(Ts);

        //convert motor RPM to wheel RPM
        float WHEEL_RPM = (motorDiameter/wheelDiameter) * MOTOR_RPM;

        counter = 0;
        timer.restart();
        int startTime = timer.elapsed();

        return WHEEL_RPM;
    }

    int CreateTs(int stopTime) {
        if(stopTime > startTime) { //ensures that Ts is a positive number
            return 0xFFFFFFFF - stopTime + startTime;
        }

        return startTime - stopTime;
    }

    float GetMotorRPM(int Ts) {
        if(Ts == 0) { //ensures that if no encoder pulses hit, we set RPM to 0
            return 0;
        }

        return counter * (6000000000.0/( (float)Ts * 7 * 20));
    }

    void increment_counter() {
        counter++;
    }

    int get_time_since_start() {
        return timer.elapsed();
    }
};
