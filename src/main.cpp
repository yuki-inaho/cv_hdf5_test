#include <iostream>
#include <chrono>
#include <opencv2/opencv.hpp>
#include <opencv2/hdf/hdf5.hpp>

using namespace cv;

int main(int argc, char **argv) {
    cv::Ptr<cv::hdf::HDF5> h5io = cv::hdf::open("../lena.h5");                              

    std::string rgb_img_path = "/image/lena";
    cv::Mat rgb_img;
    bool img_path_existance = h5io->hlexists(rgb_img_path);
    if(img_path_existance){
        h5io->dsread(rgb_img, rgb_img_path);           
    }

    std::string number_data_path = "/image/lena_number";
    cv::Mat _lena_number;
    double lena_number;
    bool number_data_path_existance = h5io->hlexists(number_data_path);
    if(number_data_path_existance){
        h5io->dsread(_lena_number, number_data_path);           
        std::cout << _lena_number.at<double>(0,0) << std::endl;
    }
    h5io->close();    

    if(img_path_existance){
        while(cv::waitKey(10) != 27){
            cv::imshow("Image", rgb_img);
        }
        cv::destroyAllWindows();
    }else{
        std::cout << "Image doesn't exist" << std::endl;
    }
    
    return 0;
}
