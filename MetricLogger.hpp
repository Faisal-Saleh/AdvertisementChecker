/**
 * @file metric_logging.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef _METRIC_LOGGER_H_
#define _METRIC_LOGGER_H_

using namespace std;

#include <string>
// #include "Advertisement.hpp"

class Advertisement;


class MetricLogger {
public:
    virtual string log(Advertisement*) = 0;
};

class GetSize : public MetricLogger {
public:
    string log(Advertisement* ad);
};

class GetFrames : public MetricLogger {
    string log(Advertisement* ad);
};

class GetSeconds : public MetricLogger {
    string log(Advertisement*);
};

class GetFPS : public MetricLogger {
    string log(Advertisement*);
};



#endif // _METRIC_LOGGER_H_