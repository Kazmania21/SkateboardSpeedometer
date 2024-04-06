#include "./Counter.h"
#include "./Timer.h"
#include "./CalculateRPM.h"
#include "Timer.h"

class TicksToRPMConverter {
    public:
    Counter* counter = 0;
    int new_pulse_flag;
    Timer* timer;
    int startTime = 0;
    int motorDiameter;
    int wheelDiameter;
    RPMCalculator* rpmCalculator;
    //int _motorDiameter, int _wheelDiameter,

    TicksToRPMConverter(Counter* _counter, Timer* _timer, RPMCalculator* _rpmCalculator) {
        /*motorDiameter = _motorDiameter;
        wheelDiameter = _wheelDiameter;*/
        counter = _counter;
        timer = _timer;
        rpmCalculator = _rpmCalculator;
    }

    float READ_RPM(){
        int stopTime = timer->elapsed();

        new_pulse_flag = 1; //tells the RPM ISR that we just read the RPM

        //int Ts = CreateTs(stopTime);

        float MOTOR_RPM = rpmCalculator->GetMotorRPM(stopTime);

        //convert motor RPM to wheel RPM
        float WHEEL_RPM = rpmCalculator->GetWheelRPM(MOTOR_RPM);

        counter->reset();
        timer->restart();

        return WHEEL_RPM;
    }

    int CreateTs(int stopTime) {
        if(stopTime > startTime) { //ensures that Ts is a positive number
            return 0xFFFFFFFF - stopTime + startTime;
        }

        return startTime - stopTime;
    }

    /*float GetMotorRPM(int Ts) {
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
    }*/
};
