// loadbalancer.cpp
// Rong Xu 928009312

#ifndef LOADBALANCER_H
#include "loadbalancer.h"
#endif

int loadbalancer::getTime() { return system_time; }

void loadbalancer::incTime() { system_time++; }

void loadbalancer::addRequest(request r) {
    requestQueue.enqueue(r);
    incTime();
}

bool loadbalancer::isRequestQueueEmpty() { return requestQueue.isEmpty(); }

request loadbalancer::getRequest() {
    incTime();
    if (!isRequestQueueEmpty()) {
        request r = requestQueue.front();
        requestQueue.dequeue();
        return r;
    }
}