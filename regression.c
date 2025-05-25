#include <stdint.h>
#include <stdio.h>

#define N 7
static const uint16_t x[N] = {140, 155, 159, 179, 192, 200, 212};
static const uint16_t y[N] = {60, 62, 67, 70, 71, 72, 75};

int main(void) {

    uint32_t sx=0, sy=0;
    uint64_t sxy=0, sx2=0, sy2=0;

    double b0=0, b1=0;

    for(size_t count=0; count<N; ++count) {
        sx += *(x+count);
        sy += *(y+count);

        sxy += *(x+count)**(y+count);

        sx2 += *(x+count)**(x+count);
        sy2 += *(y+count)**(y+count);

    }
    
    b0 = ((double)sy*sx2 - (double)sx*sxy) / (N*(double)sx2 - (double)sx*sx);
    b1 = (((N*(double)sxy) - ((double)sx*sy)) / ((N*(double)sx2 - (double)sx*sx)));

    printf("SX:%d SY:%d\n", sx, sy);
    printf("SX2:%ld SY2:%ld SXY:%ld", sx2, sy2, sxy);
    printf("\ny = %f + %fx\n", b0, b1);




    return 0;
}
