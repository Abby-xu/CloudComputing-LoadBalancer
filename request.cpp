/**
 * @file request.cpp
 * @brief Request 
 * @details declear a struct called request including the info of two IPs (in and out) and a random integer represent as the process time.
 */

#include <string>
using namespace std;
#define REQUEST_CPP

/**
 * @brief request struct
 * @details contaits IPin as source, IPout as destination, and process_time as an integer for random number.
 */
struct request{
    // variables: IP in & IP out & time need to take (int)
    string source; // IP in
    string destination; // IP out
    int process_time;
};