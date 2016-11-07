#ifndef _FACE_ALIGN_H_
#define _FACE_ALIGN_H_

#include <stdint.h>


#define MAX_FACE_NUM 3   // max face number of one image
#define FEATURE_POINT_SIZE 68 // feature point size


/***********************************************
 * load model
 * detecModel: file path of detect_model.dat
 * trackModel: file path of trackModel.dat
 ***********************************************/
int load_models(const char *detectModel, const char *trackModel);


/***********************************************
 * track face in video frame
 * img: frame data, gray image
 * width: frame width
 * height: frame height
 * stride: frame memory width
 * resShape: track result, in format [x00, y00, x01, y01, ..., x0n, y0n; x10, y10, ..., x1n, y1n; ...]
 * ptsSize: result point size
 * return value: detect face size
 ***********************************************/
int track_face_in_video_frame(uint8_t *img, int width, int height, int stride, float *resShape, int &ptsSize);


/***********************
 * release data
 ***********************/
void release_datas();

#endif
