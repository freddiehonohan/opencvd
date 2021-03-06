#include <stdbool.h>

// functions not wrapped in gocv

#ifdef __cplusplus
#include <opencv2/opencv.hpp>
extern "C" {
#endif

#include "core.h"
#include "cvcore_helper.h"
#include "imgproc.h"


void Watershed(Mat src, Mat markers );

int FloodFill(  Mat 	image,
                Mat 	mask,
                Point 	seedPoint,
                Scalar 	newVal,
                Rect 	rect,
                Scalar 	loDiff,
                Scalar 	upDiff,
                int 	flags 
                );

int FloodFill2(Mat image, Point seedPoint, Scalar newVal, Rect rect, Scalar loDiff, Scalar upDiff, int flags);
	
struct Contours FindContoursWithHier(Mat src, Hierarchy* chierarchy, int mode, int method);

void Canny2(Mat dx, Mat dy, Mat edges, double threshold1, double threshold2, bool L2gradient);
void Canny3(Mat image, Mat edges, double threshold1, double threshold2, int apertureSize, bool L2gradient);

Mat GetStructuringElementWithAnchor(int shape, Size ksize, Point anchor);

void DrawContours2(
            Mat image,
            Contours contours,
            int contourIdx,
            Scalar color,
            int thickness,
            int lineType,
            Hierarchy hierarchy,
            int maxLevel,
            Point offset);

struct Points ConvexHull2(Contour points, bool clockwise);
struct IntVector ConvexHull3(Contour points, bool clockwise);

void CalcHist1(Mat images, int nimages, int* channels,
    Mat mask, Mat hist, int dims, int* histSize, const float** ranges, bool uniform, bool accumulate);

void CalcHist2(Mat dst, Mat mask, Mat hist, int* histSize);

void Rectangle2(Mat img, Point pt1, Point pt2, Scalar color, int thickness, int lineType, int shift);	

Vec3fs HoughCircles3(Mat image, int method, double dp,
                  double minDist, double param1, double param2, int minRadius, int maxRadius);

void Circle2(Mat img, Point center, int radius, Scalar color, int thickness, int shift);

void HoughLines2(Mat image, Vec2fs *lines, double rho, double theta,
            int threshold, double srn, double stn, double min_theta, double max_theta);

void HoughLinesP2(Mat image, Vec4is *lines, double rho, double theta,
            int threshold, double minLineLength, double maxLineGap);
void Line2(Mat img, Point pt1, Point pt2, Scalar color, int thickness, int lineType, int shift);

void DistanceTransform(Mat src, Mat dst, Mat labels, int distanceType,
            int maskSize, int labelType);

void DistanceTransform2(Mat src, Mat dst, int distanceType, int maskSize, int dstType);

#ifdef __cplusplus
typedef cv::Subdiv2D* Subdiv2D;
#else
typedef void* Subdiv2D;
#endif

Subdiv2D Subdiv2d_New();
Subdiv2D Subdiv2d_NewFromRect(Rect r);
void Subdiv2D_Close(Subdiv2D sd);
void Subdiv2D_Insert(Subdiv2D sd, Point2f p);
void Subdiv2D_InsertMultiple(Subdiv2D sd, Point2fs ptvec);
struct Vec6fs Subdiv2D_GetTriangleList(Subdiv2D sd);
Point2fss Subdiv2D_GetVoronoiFacetList(Subdiv2D sd, IntVector idx, Point2fs* faceCenters);
int Subdiv2D_EdgeOrg(Subdiv2D sd, int edge, Point2f** orgpt);
int Subdiv2D_EdgeDst(Subdiv2D sd, int edge, Point2f** dstpt);
int Subdiv2D_GetEdge(Subdiv2D sd, int edge, int nextEdgeType);
int Subdiv2D_NextEdge(Subdiv2D sd, int edge);
int Subdiv2D_RotateEdge(Subdiv2D sd, int edge, int rotate);
int Subdiv2D_SymEdge(Subdiv2D sd, int edge);
int Subdiv2D_FindNearest(Subdiv2D sd, Point2f pt, Point2f** _nearestPt);
struct Vec4fs Subdiv2D_GetEdgeList(Subdiv2D sd);
struct IntVector Subdiv2D_GetLeadingEdgeList(Subdiv2D sd);
int Subdiv2D_Locate(Subdiv2D sd, Point2f pt, int &edge, int &vertex);
int Subdiv2D_FindNearest(Subdiv2D sd, Point2f pt, Point2f** nearestPt);
Point2f Subdiv2D_GetVertex(Subdiv2D sd, int vertex, int *firstEdge);
void Subdiv2D_InitDelaunay(Subdiv2D sd, Rect rect);

void FillConvexPoly(Mat img, Points points, Scalar color, int lineType, int shift);
void Polylines(Mat img, Points pts, bool isClosed, Scalar color, int thickness, int lineType, int shift);
void Polylines2ss(Mat img, Pointss pts, bool isClosed, Scalar color, int thickness, int lineType, int shift);

struct RotatedRect FitEllipse(Points points);
struct RotatedRect FitEllipse2(Mat points);
struct RotatedRect FitEllipseAMS(Points points);
struct RotatedRect FitEllipseAMS2(Mat points);
struct RotatedRect FitEllipseDirect(Points points);
struct RotatedRect FitEllipseDirect2(Mat points);
void Ellipse2(Mat img, RotatedRect box, Scalar color, int thickness, int lineType);
void PyrMeanShiftFiltering(Mat src, Mat dst, double sp, double sr, int maxLevel, TermCriteria termcrit);

double CLAHE_GetClipLimit(CLAHE c);
Size CLAHE_GetTilesGridSize(CLAHE c);
void CLAHE_SetClipLimit(CLAHE c, double clipLimit);
void CLAHE_SetTilesGridSize (CLAHE c, Size tileGridSize);

void Dilate2(Mat src, Mat dst, Mat kernel, Point anchor, int iterations);
void Erode2(Mat src, Mat dst, Mat kernel, Point anchor, int iterations);

#ifdef __cplusplus
}
#endif
