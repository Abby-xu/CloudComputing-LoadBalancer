/**
 * @file loadbalancer.cpp
 * @brief Load Balancer
 * @details declear a class called loadbalancer to include a queue of requests and keep tracking the time.
 */

#ifndef LOADBALANCER_H
#include "loadbalancer.h"
#endif

/**
 * @details get the system time
 * @return system_time 
 */
int loadbalancer::getTime() { return system_time; }

/**
 * @details increase the time clock
 * @return inc system_time 
 */
void loadbalancer::incTime() { system_time++; }

/**
 * @details add request into the load balancer
 * @param r as a request
 * @return None
 */
void loadbalancer::addRequest(request r) {
    requestQueue.enqueue(r);
    incTime();
}

/**
 * @details check if the load balancer is empty or not
 * @return True for empty and False for non-empty
 */
bool loadbalancer::isRequestQueueEmpty() { return requestQueue.isEmpty(); }

/**
 * @details get the request
 * @return a request
 */
request loadbalancer::getRequest() {
    incTime();
    if (!isRequestQueueEmpty()) {
        request r = requestQueue.front();
        requestQueue.dequeue();
        return r;
    }
}