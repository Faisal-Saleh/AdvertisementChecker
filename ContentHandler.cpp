/**
 * @file ContentHandler.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "ContentHandler.hpp"

void ContentHandler::add_metric_analyzer(MetricLogger* m) {
    logger_functions.emplace_back(m);
}

void ContentHandler::add_transformation(Transformation* t) {
    transformations.emplace_back(t);
}

void ContentHandler::set_metrics(vector<MetricLogger*>& metrics) {
    logger_functions = metrics;
}

void ContentHandler::set_transformers(vector<Transformation*>& trans) {
    transformations = trans;
}


/*****************************************************************************/
/******************* Implementation of ImageContentHandler *******************/
/*****************************************************************************/

ImageContentHandler::ImageContentHandler(AdvertisementBase* ad, shared_ptr<spdlog::logger> l) {
    advertisement = ad;
    logger = l;
    logger_functions.emplace_back(new GetSize());
    logger_functions.emplace_back(new GetDimensions());
    logger_functions.emplace_back(new GetFrames());
}


/*****************************************************************************/
/******************* Implementation of VideoContentHandler *******************/
/*****************************************************************************/

VideoContentHandler::VideoContentHandler(AdvertisementBase* ad, shared_ptr<spdlog::logger> l) {
    advertisement = ad;
    logger = l;
    logger_functions.emplace_back(new GetSize());
    logger_functions.emplace_back(new GetDimensions());
    logger_functions.emplace_back(new GetFrames());
    logger_functions.emplace_back(new GetFPS());
    logger_functions.emplace_back(new GetDuration());
}
