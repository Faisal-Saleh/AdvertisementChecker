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

// TODO: make a split between the logging functions (like the case of GetDimensions) where needed

class MetricLogger {
public:
    virtual string log(AdvertisementBase*) = 0;
};

class GetSize : public MetricLogger {
    string log(AdvertisementBase*) override;
};

class GetDimensions : public MetricLogger {
    string log(AdvertisementBase*) override;
    string log(ImageAdvertisement*);
    string log(VideoAdvertisement*);
};

class GetFrames : public MetricLogger {
    string log(AdvertisementBase*) override;
};

class GetDuration : public MetricLogger {
    string log(AdvertisementBase*) override;
};

class GetFPS : public MetricLogger {
    string log(AdvertisementBase*) override;
};

#endif // _METRIC_LOGGER_H_