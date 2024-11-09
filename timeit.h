#include <time.h>
#include <stdio.h>

#define TIMER_MICROSECONDS 1000000
#define TIMER_MILLISECONDS 1000

#define TIMER_START 2
#define TIMER_END 1
#define TIMER_RESULT 0

struct Timer {
    double precision;
    clock_t start;
    clock_t end;
    double time;
};

void timeit(struct Timer *timer, int timer_status) {
    if (timer_status == TIMER_START)
        timer->start = clock();
    else if (timer_status == TIMER_END)
        timer->end = clock();
    else if (timer_status == TIMER_RESULT) {
        timer->time = ((double)timer->end - (double)timer->start) / CLOCKS_PER_SEC * timer->precision;
    }
}