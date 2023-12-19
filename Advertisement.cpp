/**
 * @file Advertisement.cpp
 * @author Faisal Abdelmonem (fts@alumni.cmu.edu)
 * @brief 
 * @version 0.1
 * @date 2023-12-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "Advertisement.hpp"
#include <fstream>
using namespace ads_checker;

/*****************************************************************************/
/******************** Implementation of AdvertisementBase ********************/
/*****************************************************************************/

string AdvertisementBase::get_content_path(void) {
    return path_to_ad;
}

int AdvertisementBase::get_size(void) {
    ifstream file(path_to_ad, ios::binary | ios::ate);
    
    if (!file.is_open()) {
        cerr << "Error opening file: " << path_to_ad << std::endl;
        return -1;
    }

    streampos file_size = file.tellg();
    file.close();

    return file_size;
}


/****************************************************************************/
/******************* Implementation of ImageAdvertisement *******************/
/****************************************************************************/

ImageAdvertisement::ImageAdvertisement(string& img_path) {
    original_image = make_shared<cv::Mat>(cv::imread(img_path, cv::IMREAD_UNCHANGED));
    current_image = original_image;
    path_to_ad = img_path;
}

ImageAdvertisement::~ImageAdvertisement() {
    original_image.reset();
    current_image.reset();
}

cv::Mat& ImageAdvertisement::get_content(void) {
    return *current_image;
}

void ImageAdvertisement::set_content(cv::Mat& new_image) {
    current_image = make_shared<cv::Mat>(new_image);
}

void ImageAdvertisement::reset_content() {
    current_image = original_image;
}

pair<int, int> ImageAdvertisement::get_dimensions() {
    cv::Mat image = *current_image;
    int image_width = image.cols;
    int image_height = image.rows;

    return make_pair(image_width, image_height);
}

/****************************************************************************/
/******************* Implementation of VideoAdvertisement *******************/
/****************************************************************************/

VideoAdvertisement::VideoAdvertisement(string& vid_path) {
    cv::VideoCapture video(vid_path);
    if (video.isOpened()) {
        original_video = make_shared<cv::VideoCapture>(video);
        current_video = original_video;
        path_to_ad = vid_path;
    } else {
        cerr << "Video at path: " << vid_path <<  "is not opened" << endl;
    }   
}

VideoAdvertisement::~VideoAdvertisement() {
    original_video.reset();
    current_video.reset();
}

cv::VideoCapture& VideoAdvertisement::get_content(void) {
    return *current_video;
}

void VideoAdvertisement::set_content(cv::VideoCapture& new_video) {
    current_video = make_shared<cv::VideoCapture>(new_video);
}

void VideoAdvertisement::reset_content(void) {
    current_video = original_video;
}

int VideoAdvertisement::get_frames(void) {
    return static_cast<int>((*current_video).get(cv::CAP_PROP_FRAME_COUNT));
}

double VideoAdvertisement::get_fps(void) {
    return (*current_video).get(cv::CAP_PROP_FPS);
}

pair<int, int> VideoAdvertisement::get_dimensions(void) {
    cv::VideoCapture video = *current_video;
    int video_width = static_cast<int>(video.get(cv::CAP_PROP_FRAME_WIDTH));
    int video_height = static_cast<int>(video.get(cv::CAP_PROP_FRAME_HEIGHT)); 

    return make_pair(video_width, video_height);
}