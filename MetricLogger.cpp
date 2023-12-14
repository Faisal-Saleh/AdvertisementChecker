#include <opencv2/opencv.hpp>
#include <fstream>
#include "MetricLogger.hpp"

using namespace std;

int get_frames(cv::VideoCapture video) {
    return static_cast<int>(video.get(cv::CAP_PROP_FRAME_COUNT));
}

double get_fps(cv::VideoCapture video) {
    return video.get(cv::CAP_PROP_FPS);
}

string GetSize::log(AdvertisementBase* ad) {
    string file_path = ad->get_content_path();
    ifstream file(file_path, std::ios::binary | std::ios::ate);
    
    if (!file.is_open()) {
        cerr << "Error opening file: " << file_path << std::endl;
        return "";
    }

    streampos file_size = file.tellg();
    file.close();

    return "Size: " + to_string(file_size) + " bytes";
}

string img_get_dimensions(ImageAdvertisement* ad) {
    cv::Mat image = ad->get_content();

    // if (image.empty()) {
    //     std::cerr << "Error loading image.\n";
    //     return "";
    // }

    int image_width = image.cols;
    int image_height = image.rows;

    return "Dimensions: " + to_string(image_width) + "x" + to_string(image_height) + " pixels";
}

string vid_get_dimensions(VideoAdvertisement* ad) {
    cv::VideoCapture video = ad->get_content();

    if (!video.isOpened()) {
        std::cerr << "Error opening video file.\n";
        return "";
    }

    int video_width = static_cast<int>(video.get(cv::CAP_PROP_FRAME_WIDTH));
    int video_height = static_cast<int>(video.get(cv::CAP_PROP_FRAME_HEIGHT));

    return "Dimensions: " + to_string(video_width) + "x" + to_string(video_height) + " pixels";
}

// TODO: perhaps see if it is possible to overload on the input type so that
//       the helper functions are not needed.
string GetDimensions::log(AdvertisementBase* ad) {
    ImageAdvertisement* img = dynamic_cast<ImageAdvertisement*>(ad); 
    VideoAdvertisement* vid = dynamic_cast<VideoAdvertisement*>(ad); 
    if (img) {
        return img_get_dimensions(img);
    } else if (vid) {
        return vid_get_dimensions(vid);
    } else {
        return "Object passed is not supported";
    }
}

string GetFrames::log(AdvertisementBase* ad) {
    if (dynamic_cast<ImageAdvertisement*>(ad)) {
        return "Frames: 1";
    } else {
        VideoAdvertisement* video_obj = dynamic_cast<VideoAdvertisement*>(ad);
        assert(video_obj);
        
        cv::VideoCapture video = video_obj->get_content();
        if (!video.isOpened()) {
            std::cerr << "Error opening video file.\n";
            return "";
        }

        // Get the total number of frames in the video
        int total_frames = get_frames(video);

        // Display the result
        return "Frames: " + to_string(total_frames);

    }
    return "";
}

string GetFPS::log(AdvertisementBase* ad) {
    if (dynamic_cast<ImageAdvertisement*>(ad)) {
        cerr << "Can't get the fps of an image." << endl;
        return "";
    } else {
        VideoAdvertisement* video_obj = dynamic_cast<VideoAdvertisement*>(ad);
        assert(video_obj);
        
        cv::VideoCapture video = video_obj->get_content();
        if (!video.isOpened()) {
            std::cerr << "Error opening video file.\n";
            return "";
        }

        // Get the total number of frames in the video
        int fps = static_cast<int>(get_fps(video));

        // Display the result
        return "fps: " + to_string(fps);

    }
    return "";
}

string GetDuration::log(AdvertisementBase* ad) {
    if (dynamic_cast<ImageAdvertisement*>(ad)) {
        cerr << "Can't get the duration of an image." << endl;
        return "";
    } else {
        VideoAdvertisement* video_obj = dynamic_cast<VideoAdvertisement*>(ad);
        assert(video_obj);
        
        cv::VideoCapture video = video_obj->get_content();
        if (!video.isOpened()) {
            std::cerr << "Error opening video file.\n";
            return "";
        }

        // Get the total number of frames in the video
        double fps = get_fps(video);
        int total_frames = get_frames(video);

        double duration = total_frames / fps;

        // Display the result
        return "Seconds: " + to_string(duration);
    }
}