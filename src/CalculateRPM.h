#include "./Counter.h"

class RPMCalculator {
    public:
    int motorDiameter;
    int wheelDiameter;
    Counter* counter;

    RPMCalculator(int _motorDiameter, int _wheelDiameter, Counter* _counter) {
        motorDiameter = _motorDiameter;
        wheelDiameter = _wheelDiameter;
        counter = _counter;
    }

    float GetMotorRPM(int Ts) {
        if(Ts == 0) { //ensures that if no encoder pulses hit, we set RPM to 0
            return 0;
        }

        return counter->count * (6000000000.0/( (float)Ts * 7 * 20));
    }

    float GetWheelRPM(float MOTOR_RPM) {
        return (motorDiameter/wheelDiameter) * MOTOR_RPM;
    }
};
