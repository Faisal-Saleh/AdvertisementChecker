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
#include <spdlog/spdlog.h>

#include "Advertisement.hpp"
#include "MetricLogger.hpp"
#include "ApplyTransfromation.hpp"

class ContentHandler {
protected:
    vector<Transformation*> transformations;
    vector<MetricLogger*> logger_functions;
    AdvertisementBase* advertisement;
    shared_ptr<spdlog::logger> logger;
public:
    ContentHandler() = default;
    ~ContentHandler() = default;

    void add_metric_analyzer(MetricLogger*);
    void add_transformation(Transformation*);

    void set_metrics(vector<MetricLogger*>&);
    void set_transformers(vector<Transformation*>&);

    void analyze(void) {
        string logged_text = advertisement->get_content_path() + ": ";
        for (auto m_logger : logger_functions){
            logged_text = logged_text + m_logger->log(advertisement) + ", ";
        }
        logger->info(logged_text.substr(0, logged_text.size() - 2));
    }

    void transform(void);
};

class ImageContentHandler : public ContentHandler {
public:
    ImageContentHandler(AdvertisementBase* ad, shared_ptr<spdlog::logger> log);
};

class VideoContentHandler : public ContentHandler {
public:
    VideoContentHandler(AdvertisementBase*, shared_ptr<spdlog::logger>);
};

#endif // _CONTENT_HANDLER_H_