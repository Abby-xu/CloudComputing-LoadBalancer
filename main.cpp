/**
 * @file main.cpp
 * @brief Main Script
 * @details create request -> random number generator -> an array of webservers -> loop -> check if the webserver is done -> give it a new request
 */

#include "webserver.cpp"
#include "loadbalancer.cpp"

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>
using namespace std;

request createRandomRequest() {
    stringstream ip_in, ip_out;
    request r; 

    //creating random ip address as Ipv4 with the format of 255.255.255.255
    ip_in << (rand() % 256) << '.' << (rand() % 256) << '.' << (rand() % 256) << '.' << (rand() % 256);
    ip_out << (rand() % 256) << '.' << (rand() % 256) << '.' << (rand() % 256) << '.' << (rand() % 256);

    // assign the IPs to the request and return it
    r.source = ip_in.str();
    r.destination = ip_out.str();
    r.process_time = rand() % 500;
    return r;
}

int main() {

    int num_webserver, run_time;

    cout << "Please input the number of servers: ";
    cin >> num_webserver;
    cout << "Please input the time you want to run the load balancer (integer like 100000): ";
    cin >> run_time;

    srand(time(0));
    loadbalancer lb;

    // full queue
    for (int i = 0; i < 10; i++) {
        request r = (createRandomRequest());
        lb.addRequest(r);
    }

    // an array of webservers
    webserver webarray[num_webserver];
    for (int i = 0; i < num_webserver; i++) {
        webserver w((char)(i+65));
        webarray[i] = w;
        webarray[i].addRequest(lb.getRequest(), lb.getTime());
    }
    
    // loop
    while (lb.getTime() < run_time) {
        int curr_time = lb.getTime();

        // check if each webserver is done
        if(webarray[curr_time % num_webserver].isRequestDone(curr_time)) {
            request r = webarray[curr_time % num_webserver].getRequest();
            cout << "At " << curr_time << " " << webarray[curr_time % num_webserver].getName() << " process request from " << r.source << " to " << r.destination << endl;
            webarray[curr_time % num_webserver].addRequest(lb.getRequest(), curr_time); // give a new request   
        }

        if (rand() % 10 == 0) {
            request r = (createRandomRequest());
            lb.addRequest(r);
        }
    }
}