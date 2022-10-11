/**
 * @file loadbalancer.h
 * @brief Load Balancer
 * @details declear a class called loadbalancer to include a queue of requests and keep tracking the time.
 */

#include "arrayqueue.h"
#ifndef REQUEST_CPP
#include "request.cpp"
#endif

/**
 * @brief load balancer
 * @details include mutiple functions and private variables
 */
class loadbalancer {
    public:
        loadbalancer() {
            system_time = 0;
        }
        int getTime();
        void incTime();
        void addRequest (request r);
        request getRequest();
        bool isRequestQueueEmpty();
    private:
        int system_time;
        ArrayQueue <request> requestQueue;
};

