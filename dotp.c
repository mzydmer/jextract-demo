#include <stdio.h>
#include <stdlib.h>
#include <immintrin.h>

inline float horizontal_add(__m512 a) {
    __m512 tmp = _mm512_add_ps(a,_mm512_shuffle_f32x4(a,a,_MM_SHUFFLE(0,0,3,2)));
    __m128 r = _mm512_castps512_ps128(_mm512_add_ps(tmp,_mm512_shuffle_f32x4(tmp,tmp,_MM_SHUFFLE(0,0,0,1))));
    r = _mm_hadd_ps(r,r);
    return _mm_cvtss_f32(_mm_hadd_ps(r,r));
}

inline float dotp_AVX512(float *a, float *b, int length) {
    int i =0;
	float result = 0;
	__m512 c512 = _mm512_setzero_ps();
    for(i=0; i<= length - 16; i+=16) {
        __m512 a512 = _mm512_loadu_ps((__m512*)&a[i]);
        __m512 b512 = _mm512_loadu_ps((__m512*)&b[i]);
		c512 = _mm512_fmadd_ps(a512, b512, c512);	
    }

    return horizontal_add(c512);
}

void myMain(double dd[])
{
	float *a = NULL;
	float *b = NULL;
	float result = 0;
	int length = 1024;
	int loop = 1000;
	for(int j = 0; j < 10; j++){
		printf（"double:%lf\n", d[j]）;
	}
	printf("Vector length=%d, loop = %d\n", length, loop);

	a = (float *)aligned_alloc(64, sizeof(float) * length);
	b = (float *)aligned_alloc(64, sizeof(float) * length);

	for (int i = 0; i < length; i++){
		a[i] = i * 0.1;
		b[i] = i * 0.2;
	}


	for (int i = 0; i < loop; i++){
		result = dotp_AVX512(a, b, length);
	}

	printf("result = %f\n", result);

	return 0;
}
