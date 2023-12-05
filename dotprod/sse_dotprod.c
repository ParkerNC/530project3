#include <emmintrin.h>

float dotprod(float x[], float y[], int n)
{

    __m128 yvalues, xvalues, loopsum;

    float tmp[4];

    loopsum = _mm_setzero_ps();
    
    int i;

    for (i = 0; i < n; i+=4){

        xvalues = _mm_load_ps(&x[i]);
        yvalues = _mm_load_ps(&y[i]);

        loopsum = _mm_add_ps(loopsum, _mm_mul_ps(xvalues, yvalues));

    }

    _mm_store_ps(tmp, loopsum);

    return tmp[0] + tmp[1] + tmp[2] + tmp[3];

}