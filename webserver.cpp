/**
 * @file webserver.cpp
 * @brief Webserver
 * @details declear a class called webserver to take the request from the load balancer, process request, and ask for another request.
 */

#include <string>
#include "request.cpp"
using namespace std;
#define WEBSERVER_CPP

/*
- take request from the LB
- process request
- ask for another
*/
/**
 * @brief web server class
 * @details include mutiple functions and private variables
 */
class webserver {
    public:
        request getRequest() { return r; }
        string getName() { return server_name; }

        /**
         * @details default constructor
         */
        webserver() {
            request_start_time = 0;
            server_name = ' ';
        }
        
        /**
         * @details constructor with the param c
         * @param c as a char for the server name
         */
        webserver (char c) {
            request_start_time = 0;
            server_name = c;
        }

        /**
         * @details add request to the webserver
         * @param r as a request, curr_time as an integer
         * @return None
         */
        void addRequest(request req, int curr_time) {
            r = req;
            request_start_time = curr_time;
        }

        /**
         * @details check if the request is done
         * @param curr_time as an integer
         * @return True for it's done and False as not
         */
        bool isRequestDone(int curr_time) { return (curr_time > (request_start_time + r.process_time)); }

    private:
        request r;
        int request_start_time;
        string server_name;

};