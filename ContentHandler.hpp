/**
 * @file ContentHandler.hpp
 * @author Faisal Abdelmonem (fts@alumni.cmu.edu)
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

namespace ads_checker{
    class ContentHandler {
    protected:
        vector<shared_ptr<Transformation>> transformations;
        vector<shared_ptr<MetricLogger>> logger_functions;
        shared_ptr<AdvertisementBase> advertisement;
        shared_ptr<spdlog::logger> logger;
    public:
        ContentHandler() = default;
        ~ContentHandler() = default;

        void add_metric_analyzer(shared_ptr<MetricLogger>);
        void add_transformation(shared_ptr<Transformation>);

        void set_metrics(vector<shared_ptr<MetricLogger>>&);
        void set_transformers(vector<shared_ptr<Transformation>>&);

        template <typename T>
        void analyze(void) {
            string logged_text = advertisement->get_content_path() + ": ";
            for (auto m_logger : logger_functions){
                shared_ptr<T> ad = dynamic_pointer_cast<T>(advertisement);
                logged_text = logged_text + m_logger->log(ad) + ", ";
            }
            logger->info(logged_text.substr(0, logged_text.size() - 2));
        }

        void transform(void);
    };

    class ImageContentHandler final : public ContentHandler {
    public:
        ImageContentHandler(shared_ptr<AdvertisementBase>, shared_ptr<spdlog::logger>);
    };

    class VideoContentHandler final : public ContentHandler {
    public:
        VideoContentHandler(shared_ptr<AdvertisementBase>, shared_ptr<spdlog::logger>);
    };
}

#endif // _CONTENT_HANDLER_H_