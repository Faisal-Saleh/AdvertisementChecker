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

#include "Common.h"
#include "ContentHandler.hpp"

ContentHandler::ContentHandler(AdvertisementBase* ad): advertisement(ad) {
    loggers.emplace_back(new GetSize());
    loggers.emplace_back(new GetFrames());
    // check if it is video
    if (dynamic_cast<VideoAdvertisement*>(advertisement)) {
        loggers.emplace_back(new GetFPS());
        loggers.emplace_back(new GetSeconds());
    } else if (!dynamic_cast<ImageAdvertisement*>(advertisement)) {
        throw invalid_argument("argument to content_handler is unsupported\n");
    }
}

void ContentHandler::add_metric_analyzer(MetricLogger* m) {
    loggers.emplace_back(m);
}

void ContentHandler::add_transformation(Transformation* t) {
    transformations.emplace_back(t);
}

void ContentHandler::set_metrics(vector<MetricLogger*>& metrics) {
    loggers = metrics;
}

void ContentHandler::set_transformers(vector<Transformation*>& trans) {
    transformations = trans;
}

void ContentHandler::analyze() {

}

void ContentHandler::transform() {

}