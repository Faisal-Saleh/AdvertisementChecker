#include "Advertisement.hpp"

/*****************************************************************************/
/******************* Implementation of AdvertisiementBase ********************/
/*****************************************************************************/

string AdvertisementBase::get_content_path() {
    return path_to_ad;
}

/*****************************************************************************/
/******************* Implementation of VideoAdvertisiement *******************/
/*****************************************************************************/

VideoAdvertisement::VideoAdvertisement(string& vid_path) {
    cv::VideoCapture video(vid_path);
    original_video = make_shared<cv::VideoCapture>(video);
    current_video = original_video;
    path_to_ad = vid_path;   
}

VideoAdvertisement::~VideoAdvertisement() {
    original_video.reset();
    current_video.reset();
}

cv::VideoCapture& VideoAdvertisement::get_content() {
    return *current_video;
}

void VideoAdvertisement::set_content(cv::VideoCapture& new_video) {
    current_video = make_shared<cv::VideoCapture>(new_video);
}

void VideoAdvertisement::reset_content() {
    current_video = original_video;
}


/*****************************************************************************/
/******************* Implementation of ImageAdvertisiement *******************/
/*****************************************************************************/

ImageAdvertisement::ImageAdvertisement(string& img_path) {
    original_image = make_shared<cv::Mat>(cv::imread(img_path, cv::IMREAD_UNCHANGED));
    current_image = original_image;
    path_to_ad = img_path;
}

ImageAdvertisement::~ImageAdvertisement() {
    original_image.reset();
    current_image.reset();
}

cv::Mat& ImageAdvertisement::get_content() {
    return *current_image;
}

void ImageAdvertisement::set_content(cv::Mat& new_image) {
    current_image = make_shared<cv::Mat>(new_image);
}

void ImageAdvertisement::reset_content() {
    current_image = original_image;
}