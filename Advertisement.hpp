/**
 * @file check_advertisement.hpp
 * @author Faisal Abdelmonem (fts@alumni.cmu.edu)
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

namespace ads_checker{
    class AdvertisementBase {
    protected:
        string path_to_ad;
    public:
        virtual ~AdvertisementBase() = default;
        string get_content_path(void);
        int get_size(void);
    };

    template <typename T>
    class Advertisement : public AdvertisementBase {
    public:
        virtual T get_content(void) = 0;
        virtual void set_content(T) = 0;
        virtual void reset_content(void) = 0;
    };

    class VideoAdvertisement final : public Advertisement<cv::VideoCapture&> {
    private:
        shared_ptr<cv::VideoCapture> original_video;
        shared_ptr<cv::VideoCapture> current_video;
    public:
        VideoAdvertisement(string& vid_path);
        ~VideoAdvertisement();
        
        cv::VideoCapture& get_content(void) override;
        void set_content(cv::VideoCapture& new_video) override;
        void reset_content(void) override;

        int get_frames(void);
        double get_fps(void);
        pair<int, int> get_dimensions(void);
    };

    class ImageAdvertisement final : public Advertisement<cv::Mat&> {
    private:
        shared_ptr<cv::Mat> original_image;
        shared_ptr<cv::Mat> current_image;
    public:
        ImageAdvertisement(string& img_path);
        ~ImageAdvertisement();

        cv::Mat& get_content(void) override;
        void set_content(cv::Mat& new_image) override;
        void reset_content(void) override;

        pair<int, int> get_dimensions(void);
    };
}

#endif //_ADVERTISEMENT_H_