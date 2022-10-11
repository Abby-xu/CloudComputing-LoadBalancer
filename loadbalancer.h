// loadbalancer.h
// Rong Xu 928009312

#include "arrayqueue.h"
#ifndef REQUEST_CPP
#include "request.cpp"
#endif

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

