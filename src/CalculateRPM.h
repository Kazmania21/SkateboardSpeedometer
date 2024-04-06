#ifndef CALCULATE_RPM_H
#define CALCULATE_RPM_H

#include "./Counter.h"

class RPMCalculator {
    public:
    float motorDiameter;
    float wheelDiameter;
    Counter* counter;

    RPMCalculator(float _motorDiameter, float _wheelDiameter, Counter* _counter) {
        motorDiameter = _motorDiameter;
        wheelDiameter = _wheelDiameter;
        counter = _counter;
    }

    float GetMotorRPM(int Ts) {
        const int GEAR_RATIO = 30;
        const int TICKS_PER_REVOLUTION = 3;

        if(Ts == 0) { //ensures that if no encoder pulses hit, we set RPM to 0
            return 0;
        }

        return 60000 * (counter->count/( (float)Ts * TICKS_PER_REVOLUTION * GEAR_RATIO));
    }

    float GetWheelRPM(float MOTOR_RPM) {
        return (motorDiameter/wheelDiameter) * MOTOR_RPM;
    }
};

#endif
