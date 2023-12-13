#include <iostream>
#include <filesystem>
#include <string>
#include <opencv2/opencv.hpp>
// #include "Common.h"
#include "Advertisement.hpp"

using namespace std;
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
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " path_to_folder" << endl;
        return 1;
    }

    string directory_path = argv[1];

    // Iterate through the folder and its subdirectories
    for (const auto& entry : fs::recursive_directory_iterator(directory_path)) {
        if (entry.is_regular_file()) {
            // Check if the file has a valid extension
            if (is_image(entry.path())) {
                cout << "the file at: " << entry << " is an image." << endl;
            } else if (is_video(entry.path())) {
                cout << "the file at: " << entry << " is a video." << endl;
            } else {
                cout << "the file at: " << entry << " is unsupported" << endl;
            }
        }
    }
}