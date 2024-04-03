using namespace std;

class RPMToMPHConverter {
    public:
    float distance;
    float pi;
    RPMToMPHConverter(float radius) {
        pi = 3.14;
        distance = 2 * pi * radius;
    }

    float Convert(float rpm) {
        const float FEET_PER_MINUTE = rpm * distance;
        const int HOUR = 60;
        const int FEET_IN_MILE = 5280;
        return FEET_PER_MINUTE * HOUR / FEET_IN_MILE;
    }
};
