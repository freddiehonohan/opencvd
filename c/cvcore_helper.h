#include "core.h"

#ifdef __cplusplus
#include <opencv2/opencv.hpp>
extern "C" {
#endif

typedef struct RotatedRects {
    RotatedRect* rects;
    int length;
} RotatedRects;

typedef struct DoubleVector {
    double* val;
    int length;
} DoubleVector;

typedef struct Vec4f {
    float val1;
    float val2;
    float val3;
    float val4;
} Vec4f;

typedef struct Vec4fs {
    Vec4f* vec4fs;
    int length;
} Vec4fs;

typedef struct Vec3f {
    float val1;
    float val2;
    float val3;
} Vec3f;

typedef struct Vec3fs {
    Vec3f* vec3fs;
    int length;
} Vec3fs;

typedef struct Vec4i {
    int val1;
    int val2;
    int val3;
    int val4;
} Vec4i;

typedef struct Vec4is {
    Vec4i* vec4is;
    int length;
} Vec4is;

typedef struct Vec3i {
    int val1;
    int val2;
    int val3;
} Vec3i;

typedef struct Vec3is {
    Vec3i* vec3is;
    int length;
} Vec3is;

typedef struct Vec2f {
    float val1;
    float val2;
} Vec2f;

typedef struct Vec2fs {
    Vec2f* vec2fs;
    int length;
} Vec2fs;

typedef struct Vec6f {
    float val1;
    float val2;
    float val3;
    float val4;
    float val5;
    float val6;
} Vec6f;

typedef struct Vec6fs {
    Vec6f* vec6fs;
    int length;
} Vec6fs;

typedef struct Point2fs {
    Point2f* points;
    int length;
} Point2fs;

typedef struct Point2fss {
    Point2fs* point2fss;
    int length;
} Point2fss;

typedef struct Pointss {
    Points* pointss;
    int length;
    
    Points opIndex(int i){
        return pointss[i];
    }
} Pointss;

// Wrapper for std::vector<char>
typedef struct CharVector {
    char* val;
    int length;
} CharVector;

void Mat_SetToWithMask(Mat m, Scalar value, Mat mask);

RotatedRect New_RotatedRect(Point center, Size size, double angle);

void Close_Vec6fs(struct Vec6fs vec6fs);
void Close_Vec4fs(struct Vec4fs vec4fs);
void Close_Vec3fs(struct Vec3fs vec3fs);
void Close_Vec2fs(struct Vec2fs vec2fs);
void Close_Vec4is(struct Vec4is vec4is);
void Close_Vec3is(struct Vec3is vec3is);
void Close_IntVector(struct IntVector iv);
void Close_DoubleVector(struct DoubleVector iv);
void Close_FloatVector(struct FloatVector iv);
void Close_CharVector(struct CharVector chv);

int Mat_Dims(Mat m);
uchar* Mat_RowPtr(Mat m, int i);
uchar* Mat_RowPtr2(Mat m, int row, int col);
void* Mat_RowPtr3(Mat m, int i0, int i1, int i2);
void Mat_MultiplyInt(Mat m, int val);
void Mat_DivideInt(Mat m, int val);
void Mat_AddDouble(Mat m, double val);
void Mat_SubtractDouble(Mat m, double val);
void Mat_AddInt(Mat m, int val);
void Mat_SubtractInt(Mat m, int val);
void Mat_AddScalar(Mat m, Scalar scalar);

Mat Mat_EQInt(Mat m, int a);
Mat Mat_GTInt(Mat m, int a);
Mat Mat_GEInt(Mat m, int a);
Mat Mat_LTInt(Mat m, int a);
Mat Mat_LEInt(Mat m, int a);
Mat Mat_NEInt(Mat m, int a);

Mat Mat_EQDouble(Mat m, double a);
Mat Mat_GTDouble(Mat m, double a);
Mat Mat_GEDouble(Mat m, double a);
Mat Mat_LTDouble(Mat m, double a);
Mat Mat_LEDouble(Mat m, double a);
Mat Mat_NEDouble(Mat m, double a);

Mat Mat_ZerosFromRC(int rows, int cols, int type);
Mat Mat_ZerosFromSize(Size sz, int type);
Mat Mat_OnesFromRC(int rows, int cols, int type);
Mat Mat_OnesFromSize(Size sz, int type);
Mat Mat_FromArrayPtr(int rows, int cols, int type, void* data);
Mat Mat_FromFloatVector(FloatVector vec);
Mat Mat_FromIntVector(IntVector vec);
Mat Mat_HeaderFromRow(Mat src, int y);
Mat Mat_HeaderFromCol(Mat src, int x);
char* _type2str(int type);
void Mat_CompareWithScalar(Mat src1, Scalar src2, Mat dst, int ct);
double Mat_Dot(Mat m1, Mat m2);
Mat Mat_Diag(Mat src, int d);
Mat Mat_EyeFromRC(int rows, int cols, int type);
int Mat_FlatLength(Mat src);
void* Mat_DataPtrNoCast(Mat src);
Scalar Mat_ColorAt(Mat src, int row, int col);
void Mat_SetColorAt(Mat src, Scalar color, int row, int col);
int Mat_SizeFromInd(Mat m, int i);

void Mat_MultiplyDouble(Mat m, double val);

// wrapper for vector<Vec4i> hierarchy;
typedef struct Hierarchy {
    Scalar* scalars;
    int length;
} Hierarchy;

void Mat_convertTo2(Mat m, Mat dst, int rtype, double alpha, double beta);

void Mat_MinMaxLoc2(Mat a, double* minVal, double* maxVal, int* minIdx, int* maxIdx);

void Mat_Merge2(struct Mats mats, int count, Mat dst);

struct Mats Mat_Split2(Mat src);

bool Rect_Contains(Rect r, Point p);

Mat Mat_FromContour(Contour points);

int Mat_CV_MAKETYPE(int depth, int cn);

#ifdef __cplusplus
typedef cv::PCA* PCA;
#else
typedef void* PCA;
#endif

PCA PCA_New();
PCA PCA_NewWithMaxComp(Mat data, Mat mean, int flags, int maxComponents);
PCA PCA_NewWithRetVar(Mat data, Mat mean, int flags, double retainedVariance);
void PCA_BackProject(PCA pca, Mat vec, Mat result);
void PCA_Project(PCA pca, Mat vec, Mat result);
Mat PCA_Eigenvalues(PCA pca);
Mat PCA_Eigenvectors(PCA pca);
Mat PCA_Mean(PCA pca);

double Get_TermCriteria_Epsilon(TermCriteria tc);
int Get_TermCriteria_MaxCount(TermCriteria tc);
int Get_TermCriteria_Type(TermCriteria tc);
void TermCriteria_Close(TermCriteria tc);

double Kmeans(Mat data, int K, Mat bestLabels,
    TermCriteria criteria, int attempts, int flags, Mat centers);
double Kmeans2(Mat data, int K, Mat bestLabels,
    TermCriteria criteria, int attempts, int flags, Point2fs* centers);
Mat Mat_RowRange1(Mat src, int startrow, int endrow);
void Mat_Fill_Random(uint64_t state, Mat mat, int distType, Scalar a, Scalar b, bool saturateRange);
void Mat_RandShuffle(uint64_t state, Mat dst, double iterFactor);

#ifdef __cplusplus
}
#endif
