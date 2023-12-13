/**
 * @file ContentHandler.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef _CONTENT_HANDLER_H_
#define _CONTENT_HANDLER_H_

#include <vector>

#include "Advertisement.hpp"
#include "MetricLogger.hpp"
#include "ApplyTransfromation.hpp"

class ContentHandler {
private:
    vector<Transformation*> transformations;
    vector<MetricLogger*> loggers;
    AdvertisementBase* advertisement;
public:
    ContentHandler(AdvertisementBase*);
    ~ContentHandler() = default;

    void add_metric_analyzer(MetricLogger*);
    void add_transformation(Transformation*);

    void set_metrics(vector<MetricLogger*>&);
    void set_transformers(vector<Transformation*>&);

    void analyze(void);
    void transform(void);
};

#endif // _CONTENT_HANDLER_H_