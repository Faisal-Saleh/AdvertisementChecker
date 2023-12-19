/**
 * @file MetricLogger.cpp
 * @author Faisal Abdelmonem (fts@alumni.cmu.edu)
 * @brief 
 * @version 0.1
 * @date 2023-12-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <opencv2/opencv.hpp>
#include <fstream>
#include "MetricLogger.hpp"

using namespace std;
using namespace ads_checker;

/*****************************************************************************/
/*********************** Implementation of MetricLogger **********************/
/*****************************************************************************/

string MetricLogger::log(shared_ptr<AdvertisementBase>) {
    return "object type is not supported";
} 

string MetricLogger::log(ImageAdv) {
    return "imgAd default implementation of log is called";
}

string MetricLogger::log(VideoAdv) {
    return "vidAd default implementation of log is called";
}

/*****************************************************************************/
/********************* Implementation of Derived Classes *********************/
/*****************************************************************************/

string GetSize::log(shared_ptr<AdvertisementBase> ad) {
    int file_size = ad->get_size();
    
    return "Size: " + to_string(file_size) + " bytes";
}


string GetDimensions::log(ImageAdv img) {
    auto dims = img->get_dimensions();
    return "Dimensions: " + to_string(dims.first) + "x" + to_string(dims.second) + " pixels";
}

string GetDimensions::log(VideoAdv vid) {
    auto dims = vid->get_dimensions();
    return "Dimensions: " + to_string(dims.first) + "x" + to_string(dims.second) + " pixels";
}

string GetFrames::log(ImageAdv) {
    return "Frames: 1";
}

string GetFrames::log(VideoAdv ad) {
    VideoAdv video_obj = dynamic_pointer_cast<VideoAdvertisement>(ad);
    assert(video_obj);
    
    int total_frames = video_obj->get_frames();

    return "Frames: " + to_string(total_frames);

}

string GetFPS::log(VideoAdv video_obj) {
    assert(video_obj);
    
    int fps = static_cast<int>(video_obj->get_fps());

    return "fps: " + to_string(fps);
}

string GetDuration::log(VideoAdv video_obj) {
    assert(video_obj);

    // Get the total number of frames in the video
    double fps = video_obj->get_fps();
    int total_frames = video_obj->get_frames();

    double duration = total_frames / fps;

    stringstream time;
    time << fixed << setprecision(2) << duration;

    // Display the result
    return "Seconds: " + time.str();
}