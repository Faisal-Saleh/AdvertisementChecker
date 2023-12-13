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
#include "Advertisement.hpp"


class MetricLogger {
public:
    virtual string log(AdvertisementBase*) = 0;
};

class GetSize : public MetricLogger {
public:
    string log(AdvertisementBase* ad);
};

class GetFrames : public MetricLogger {
    string log(AdvertisementBase* ad);
};

class GetSeconds : public MetricLogger {
    string log(AdvertisementBase*);
};

class GetFPS : public MetricLogger {
    string log(AdvertisementBase*);
};



#endif // _METRIC_LOGGER_H_