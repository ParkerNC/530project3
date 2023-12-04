#include <emmintrin.h>

float dotprod(float x[], float y[], int n)
{

    __m128 xvalues, yvalues, loopsum;

    float loopx[4] __attribute__ ((aligned (16)));
    float loopy[4] __attribute__ ((aligned (16)));

    float zero = 0;
    loopsum = _mm_load1_ps(&zero);
    
    int i, j;

    for (i = 0; i < n; i+=4){
        for (j = 0; j < 4; j++){
            loopx[j] = x[i+j];
            loopy[j] = y[i+j];
        }
        xvalues = _mm_load_ps(&loopx[0]);
        yvalues = _mm_load_ps(&loopy[0]);

        loopsum = _mm_add_ps(loopsum, _mm_mul_ps(xvalues, yvalues));

    }

    _mm_store_ps(&xvalues, loopsum);

    return xvalues[0] + xvalues[1] + xvalues[2] + xvalues[3];

}