#ifndef COUNTER_H
#define COUNTER_H

class Counter {
    public:
    int count = 0;

    void increment() {
        count++;
    }

    void reset() {
        count = 0;
    };
};

#endif