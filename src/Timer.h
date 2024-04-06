#ifndef TIMER_H
#define TIMER_H

#include "Chrono.h"

class Timer {
    public:
    Chrono timer;
    int startTime = timer.elapsed();

    int elapsed() {
        return timer.elapsed();
    }

    int restart() {
        timer.restart();
        startTime = timer.elapsed();
    }
};

#endif
