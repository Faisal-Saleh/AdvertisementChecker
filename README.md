# AdsAnalyzer

## Description
The application takes as input a directory that contains some elements they want to analyze or transform. The analysis phase is basically logging any metrics (like size, dimensions, frames, ...) while the transformation phase is applying any functions to the content (like resizing and cropping).

The output of the application is logfiles (currently img_log and vid_log) in the logs are the requested metrics for analysis of all the content given in the input directory.

## Compilation
Provided in the project is the Makefile to compile all the files. The project uses opencv and spdlog so please install them locally inorder for the code to compile. after downloading these libraries the user can run `make` and `make clean` note that the compiler used in the makefile is g++17, usage of a different version might result in compilation errors.

## Documentation
For more detailed information about the code please refer to the header files of the classes.

### Code Structure
The code has the following classes:
- Advertisement (Advertisement.cpp and Advertisement.hpp)
- MetricLogger  (MetricLogger.cpp and MetricLogger.hpp)
- Transformation (ApplyTransformation.cpp and ApplyTransformation.hpp)
- ContentHandler (ContentHandler.cpp and ContentHandler.hpp)

```cpp
class Advertisement {
    // wrapper to a content object that the user wants to analyze
};

class MetricLogger {
    virtual string log() = 0;
    // the user shall inherit from this class and override the log function (examples provided in the code).
};

class Transformation {
    // similar to MetricLogger (not yet implemented though).
};

class ContentHandler {
    Advertisement* adv;
    vector<MetricLogger*> metrics;
    vector<Transformation*> trans;
public:
    // runs metrics on the adv object and stores everything in the log file.
    void analyze();

    // applies the transformations on the adv object.
    void transform();
};
```

### Usage Example
```cpp
shared_ptr<ImageAdvertisement> img = make_shared<ImageAdvertisement>(ImageAdvertisement(path));
unique_ptr<ImageContentHandler> img_handler = make_unique<ImageContentHandler>(ImageContentHandler(img , img_logger));
img_handler->analyze<ImageAdvertisement>();
```

## Roadmap
Currently The code does not have any default transformations but the user can create their own on demand. Transformations will be added in future updates to the project.