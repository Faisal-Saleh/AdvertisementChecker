/**
 * @file metric_logging.hpp
 * @author Faisal Abdelmonem (fts@alumni.cmu.edu)
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

namespace ads_checker {
    using ImageAdv = shared_ptr<ImageAdvertisement>;
    using VideoAdv = shared_ptr<VideoAdvertisement>;

    class MetricLogger {
    public:
        virtual string log(shared_ptr<AdvertisementBase>);
        virtual string log(ImageAdv);
        virtual string log(VideoAdv);
    };

    class GetSize final : public MetricLogger {
        string log(shared_ptr<AdvertisementBase>) override;
        string log(ImageAdv ad) override { return GetSize::log(static_pointer_cast<AdvertisementBase>(ad)); }
        string log(VideoAdv ad) override { return GetSize::log(static_pointer_cast<AdvertisementBase>(ad)); }
    };

    class GetDimensions final : public MetricLogger {
        string log(ImageAdv) override;
        string log(VideoAdv) override;
    };

    class GetFrames final : public MetricLogger {
        string log(ImageAdv) override;
        string log(VideoAdv) override;
    };

    class GetDuration final : public MetricLogger {
        string log(VideoAdv) override;
    };

    class GetFPS final : public MetricLogger {
        string log(VideoAdv) override;
    };
}

#endif // _METRIC_LOGGER_H_