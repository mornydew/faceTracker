#ifndef _FACE_ALIGN_H_
#define _FACE_ALIGN_H_

#include <stdint.h>


#define MAX_FACE_NUM 3
#define PTS_SIZE 68

int load_models(const char *detectModel, const char *trackModel);
int track_face_in_video_frame(uint8_t *img, int width, int height, int stride, float *resShape, int &ptsSize);
void release_datas();

#endif
