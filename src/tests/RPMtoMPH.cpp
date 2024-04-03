using namespace std;

class RPMtoMPH {
    public:
    float distance;
    float pi;
    RPMtoMPH(float radius) {
        pi = 3.14;
        distance = 2 * pi * radius;
    }

    float Convert(float rpm) {
        const float FEET_PER_MINUTE = rpm * this.distance;
        const int HOUR = 60;
        const int FEET_IN_MILE = 5280;
        return FEET_PER_MINUTE * HOUR / FEET_IN_MILE;
    }
}

void main() {
    RPMtoMPH rpmtoMPH(.2);
    cout << rpmtoMPH.Convert(1000);
}
