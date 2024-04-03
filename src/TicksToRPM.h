class TicksToRPMConverter {
    public:
    float READ_RPM(){
        int Ts;

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

        return RPM;
    }
};
