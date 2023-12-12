/**
 * @file check_advertisement.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef _ADVERTISEMENT_H_
#define _ADVERTISEMENT_H_

#include <opencv2/opencv.hpp>
#include <string>
#include <vector>

using namespace std;

template <typename T>
class Advertisement {
protected:
    string path_to_ad;
    string path_to_log_file;
public:
    Advertisement();
    ~Advertisement();

    string get_content_path() { return path_to_ad; }
    void change_log_file(string new_path) { path_to_log_file = new_path; }

    virtual T get_content() = 0;
    virtual void set_content(T) = 0;
    virtual void reset_content(void) = 0;
};

class VideoAdvertisement : public Advertisement<cv::VideoCapture&> {
private:
    shared_ptr<cv::VideoCapture> original_video;
    shared_ptr<cv::VideoCapture> current_video;
public:
    VideoAdvertisement(string& vid_path, string& log_path);

    cv::VideoCapture& get_content() override;

    void set_content(cv::VideoCapture& new_video) override;

    void reset_content(void) override;


};

class ImageAdvertisement : public Advertisement<cv::Mat&> {
private:
    shared_ptr<cv::Mat> original_image;
    shared_ptr<cv::Mat> current_image;
public:
    ImageAdvertisement(string& img_path, string& log_path);

    cv::Mat& get_content() override;

    void set_content(cv::Mat& new_video) override;

    void reset_content(void) override;

};

#endif //_ADVERTISEMENT_H_