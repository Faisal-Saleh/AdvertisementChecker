/**
 * @file apply_transformation.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef _APPLY_TRANSFORMATION_H_
#define _APPLY_TRANSFORMATION_H_

using namespace std;

#include <string>

class ApplyTransformation {
protected:
    string new_file_path;
public:
    ApplyTransformation();
    ~ApplyTransformation();

    virtual void transform();
};

class Resize : public ApplyTransformation {
    void transform();
};


#endif // _APPLY_TRANSFORMATION_H_