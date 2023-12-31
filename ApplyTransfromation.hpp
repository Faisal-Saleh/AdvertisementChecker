/**
 * @file ApplyTransformation.hpp
 * @author Faisal Abdelmonem (fts@alumni.cmu.edu)
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

namespace ads_checker{
    class Transformation {
    protected:
        string new_file_path;
    public:
        Transformation();
        ~Transformation();

        virtual void transform();
    };

    class Resize : public Transformation {
        void transform();
    };
}


#endif // _APPLY_TRANSFORMATION_H_