/**
 * @file ContentHandler.cpp
 * @author Faisal Abdelmonem (fts@alumni.cmu.edu)
 * @brief 
 * @version 0.1
 * @date 2023-12-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "ContentHandler.hpp"
using namespace ads_checker;

void ContentHandler::add_metric_analyzer(shared_ptr<MetricLogger> m) {
    logger_functions.emplace_back(m);
}

void ContentHandler::add_transformation(shared_ptr<Transformation> t) {
    transformations.emplace_back(t);
}

void ContentHandler::set_metrics(vector<shared_ptr<MetricLogger>>& metrics) {
    logger_functions = metrics;
}

void ContentHandler::set_transformers(vector<shared_ptr<Transformation>>& trans) {
    transformations = trans;
}


/*****************************************************************************/
/******************* Implementation of ImageContentHandler *******************/
/*****************************************************************************/

ImageContentHandler::ImageContentHandler(shared_ptr<AdvertisementBase> ad, shared_ptr<spdlog::logger> l) {
    advertisement = ad;
    logger = l;
    logger_functions.emplace_back(make_shared<GetSize>(GetSize()));
    logger_functions.emplace_back(make_shared<GetDimensions>(GetDimensions()));
    logger_functions.emplace_back(make_shared<GetFrames>(GetFrames()));
}


/*****************************************************************************/
/******************* Implementation of VideoContentHandler *******************/
/*****************************************************************************/

VideoContentHandler::VideoContentHandler(shared_ptr<AdvertisementBase> ad, shared_ptr<spdlog::logger> l) {
    advertisement = ad;
    logger = l;
    logger_functions.emplace_back(make_shared<GetSize>(GetSize()));
    logger_functions.emplace_back(make_shared<GetDimensions>(GetDimensions()));
    logger_functions.emplace_back(make_shared<GetFrames>(GetFrames()));
    logger_functions.emplace_back(make_shared<GetFPS>(GetFPS()));
    logger_functions.emplace_back(make_shared<GetDuration>(GetDuration()));
}
