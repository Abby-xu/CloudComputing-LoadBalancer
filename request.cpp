// request.cpp
// Rong Xu 928009312

#include <string>
using namespace std;
#define REQUEST_CPP

// request class
struct request{
    // variables: IP in & IP out & time need to take (int)
    string source; // IP in
    string destination; // IP out
    int process_time;
};