/**
 * @file main.cpp
 * @author Faisal Abdelmonem (fts@alumni.cmu.edu)
 * @brief 
 * @version 0.1
 * @date 2023-12-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <filesystem>
#include <string>
#include <opencv2/opencv.hpp>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>
#include "Advertisement.hpp"
#include "ContentHandler.hpp"

using namespace std;
using namespace ads_checker;
namespace fs = filesystem;

bool ends_with(const string& full_string, const string& suffix) {
    if (full_string.length() >= suffix.length()) {
        return (full_string.substr(full_string.length() - suffix.length()) == suffix);
    } else {
        return false;
    }
}

bool is_image(const string& file_path) {
    cv::Mat image = cv::imread(file_path, cv::IMREAD_UNCHANGED);
    return !image.empty() || ends_with(file_path, "svg");
}

bool is_video(const string& file_path) {
    cv::VideoCapture video(file_path);
    return video.isOpened();
}

int main(int argc, const char* argv[]) {
    if (argc != 4) {
        cerr << "Usage: " << argv[0] << " <path_to_folder>" << " <image_log>" << " <video_log>" << endl;
        return 1;
    }

    string directory_path = argv[1];
    auto img_logger = spdlog::basic_logger_mt("image_logger", argv[2]);
    auto vid_logger = spdlog::basic_logger_mt("video_logger", argv[3]);

    // Iterate through the folder and its subdirectories
    for (const auto& entry : fs::recursive_directory_iterator(directory_path)) {
        if (entry.is_regular_file()) {
            // Check if the file has a valid extension
            string path = entry.path();
            if (is_image(entry.path())) {
                shared_ptr<ImageAdvertisement> img = make_shared<ImageAdvertisement>(ImageAdvertisement(path));
                unique_ptr<ImageContentHandler> img_handler = make_unique<ImageContentHandler>(ImageContentHandler(img , img_logger));
                img_handler->analyze<ImageAdvertisement>();
            } else if (is_video(entry.path())) {
                shared_ptr<VideoAdvertisement> vid = make_shared<VideoAdvertisement>(VideoAdvertisement(path));
                unique_ptr<VideoContentHandler> vid_handler = make_unique<VideoContentHandler>(VideoContentHandler(vid , vid_logger));
                vid_handler->analyze<VideoAdvertisement>();
            } else {
                cerr << "file type is unsupported" << endl;
            }
        }
    }

}
