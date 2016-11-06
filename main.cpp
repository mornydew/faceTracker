#include "face_align.h"

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <stdio.h>



int main(int argc, char **argv){
    if(argc < 2){
        printf("Usage: %s [video]\n", argv[0]);
        return 1;
    }

    int ret = load_models("detect_model.dat", "align_model.dat");

    if(ret != 0) return 2;

    cv::VideoCapture cap(argv[1]);
    if(!cap.isOpened()){
        printf("Can't open video %s\n", argv[1]);
        return 3;
    }

    cv::Mat frame, gray;
    char key = 'n';

    int cols, rows;
    int ptsSize;


    float resShape[MAX_FACE_NUM * PTS_SIZE * 2];
    while(key != 'q'){
        cap >> frame;

        if(frame.empty())
            continue;

        cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);

        int rsize = track_face_in_video_frame(gray.data, gray.cols, gray.rows, gray.step, resShape, ptsSize);


        for(int r = 0; r < rsize; r++){
            float *kpts =  resShape + r * ptsSize * 2;

            for(int p = 0; p < ptsSize; p++){
                int j = p << 1;
                cv::circle(frame, cv::Point2f(kpts[j], kpts[j + 1]), 4, cv::Scalar(0, 0, 255), -1);
            }
        }

        cv::imshow("frame", frame);
        key = cv::waitKey(1);
    }

    release_datas();

    return 0;
}



