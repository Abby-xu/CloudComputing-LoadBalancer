// webserver.cpp
// Rong Xu 928009312

#include <string>
#include "request.cpp"
using namespace std;
#define WEBSERVER_CPP

/*
- take request from the LB
- process request
- ask for another
*/
class webserver {
    public:
        request getRequest() { return r; }
        string getName() { return server_name; }

        // default constructor
        webserver() {
            request_start_time = 0;
            server_name = ' ';
        }
        // constructor w/ server name
        webserver (char c) {
            request_start_time = 0;
            server_name = c;
        }

        void addRequest(request req, int curr_time) {
            r = req;
            request_start_time = curr_time;
        }
        
        bool isRequestDone(int curr_time) { return (curr_time > (request_start_time + r.process_time)); }

    private:
        request r;
        int request_start_time;
        string server_name;

};