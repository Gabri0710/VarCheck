#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <vector>
#include <opencv2/core/mat.hpp>
#include <opencv2/core/types.hpp>
#include <cstdlib>



using namespace cv;
using namespace std;


/*
Mat src, img, ROI;
Rect cropRect(0, 0, 0, 0);
Point P1(0, 0);
Point P2(0, 0);
std::vector < Point2f > quad_pts;
std::vector < Point2f > rect_pts;

const char* winName = "Crop Image";
bool clicked = false;
int i = 0;
char imgName[15];

void prspectiveTransform() {

    Mat transmtx = getPerspectiveTransform(quad_pts, rect_pts);
    int offsetSize = 150;
    Mat transformed = Mat::zeros(cropRect.height + offsetSize,
        cropRect.width + offsetSize, CV_8UC3);
    warpPerspective(src, transformed, transmtx, transformed.size());

    imshow("quadrilateral", transformed);
}
void checkBoundary() {
    // check croping rectangle exceed image boundary
    if (cropRect.width > img.cols - cropRect.x)
        cropRect.width = img.cols - cropRect.x;

    if (cropRect.height > img.rows - cropRect.y)
        cropRect.height = img.rows - cropRect.y;

    if (cropRect.x < 0)
        cropRect.x = 0;

    if (cropRect.y < 0)
        cropRect.height = 0;
}

void showImage() {
    img = src.clone();
    checkBoundary();

    if (quad_pts.size() == 1)
        circle(img, quad_pts[0], 5, Scalar(0, 0, 255), 1.5, LINE_AA, 0);
    if (quad_pts.size() > 1) {
        for (int i = 0; i < quad_pts.size() - 1; i++) {
            line(img, quad_pts[i], quad_pts[i + 1], Scalar(0, 0, 255), 1, LINE_AA, 0);
            circle(img, quad_pts[i], 5, Scalar(0, 0, 255), 1.5, LINE_AA, 0);
            circle(img, quad_pts[i + 1], 5, Scalar(0, 0, 255), 1.5, LINE_AA, 0);
        }
    }

    if (quad_pts.size() == 4)
        line(img, quad_pts[0], quad_pts[3], Scalar(0, 0, 255), 1, LINE_AA, 0);

    rectangle(img, cropRect, Scalar(0, 255, 0), 1, 8, 0);
    imshow(winName, img);
}

void onMouse(int event, int x, int y, int f, void*) {

    switch (event) {

    case EVENT_RBUTTONDOWN:
        if (quad_pts.size() < 4)
            quad_pts.push_back(Point(x, y));
        else
            cout << "Maximum allowd point is 4, Try to remove by pressing 'r' "
            << endl;
        break;

    case EVENT_LBUTTONDOWN:
        clicked = true;

        P1.x = x;
        P1.y = y;
        P2.x = x;
        P2.y = y;
        break;

    case EVENT_LBUTTONUP:
        P2.x = x;
        P2.y = y;
        clicked = false;
        break;

    case EVENT_MOUSEMOVE:
        if (clicked) {
            P2.x = x;
            P2.y = y;
        }
        break;

    default:
        break;
    }

    if (clicked) {
        if (P1.x > P2.x) {
            cropRect.x = P2.x;
            cropRect.width = P1.x - P2.x;
        }
        else {
            cropRect.x = P1.x;
            cropRect.width = P2.x - P1.x;
        }

        if (P1.y > P2.y) {
            cropRect.y = P2.y;
            cropRect.height = P1.y - P2.y;
        }
        else {
            cropRect.y = P1.y;
            cropRect.height = P2.y - P1.y;
        }

        rect_pts.clear();
        rect_pts.push_back(Point(cropRect.x, cropRect.y));
        rect_pts.push_back(Point(cropRect.x + cropRect.width, cropRect.y));
        rect_pts.push_back(
            Point(cropRect.x + cropRect.width, cropRect.y + cropRect.height));
        rect_pts.push_back(Point(cropRect.x, cropRect.y + cropRect.height));
    }

    if ((rect_pts.size() == 4) && (quad_pts.size() == 4))
        prspectiveTransform();
    showImage();
}
int main() {

    cout << "Right click each corner of card to select the point to be "
        "trasnformed."
        << endl
        << endl;
    cout << "Click and drag for Selection" << endl << endl;
    cout << "------> Press 's' to save" << endl << endl;

    cout << "------> Press '8' to move up" << endl;
    cout << "------> Press '2' to move down" << endl;
    cout << "------> Press '6' to move right" << endl;
    cout << "------> Press '4' to move left" << endl << endl;

    cout << "------> Press 'w' increas top" << endl;
    cout << "------> Press 'x' increas bottom" << endl;
    cout << "------> Press 'd' increas right" << endl;
    cout << "------> Press 'a' increas left" << endl << endl;

    cout << "------> Press 't' decrease top" << endl;
    cout << "------> Press 'b' decrease bottom" << endl;
    cout << "------> Press 'h' decrease right" << endl;
    cout << "------> Press 'f' decrease left" << endl << endl;

    cout << "------> Press 'r' to reset quad points" << endl;
    cout << "------> Press 'Esc' to quit" << endl << endl;

    src = imread("C:/Users/pc/Desktop/immagine2.jpeg");

    namedWindow(winName, 1);
    setMouseCallback(winName, onMouse, NULL);
    imshow(winName, src);

    while (1) {
        char c = waitKey();
        if (c == 's' && ROI.data) {
           // sprintf(imgName, "%d.jpg", i++);
            imwrite(imgName, ROI);
            cout << "  Saved " << imgName << endl;
        }
        if (c == '6')
            cropRect.x++;
        if (c == '4')
            cropRect.x--;
        if (c == '8')
            cropRect.y--;
        if (c == '2')
            cropRect.y++;

        if (c == 'w') {
            cropRect.y--;
            cropRect.height++;
        }
        if (c == 'd')
            cropRect.width++;
        if (c == 'x')
            cropRect.height++;
        if (c == 'a') {
            cropRect.x--;
            cropRect.width++;
        }

        if (c == 't') {
            cropRect.y++;
            cropRect.height--;
        }
        if (c == 'h')
            cropRect.width--;
        if (c == 'b')
            cropRect.height--;
        if (c == 'f') {
            cropRect.x++;
            cropRect.width--;
        }

        if (c == 27)
            break;
        if (c == 'r') {
            if (quad_pts.size() > 0) {
                quad_pts.pop_back();
                showImage();
            }
        }
    }

    return 0;
}

*/



/*
Mat src, img, ROI;
Rect cropRect(0, 0, 0, 0);
Point P1(0, 0);
Point P2(0, 0);
std::vector < Point2f > quad_pts;
std::vector < Point2f > rect_pts;

const char* winName = "Crop Image";
bool clicked = false;
int i = 0;
char imgName[15];

int t = 0;

void prspectiveTransform() {

    Mat transmtx = getPerspectiveTransform(quad_pts, rect_pts);
    int offsetSize = 150;
    Mat transformed = Mat::zeros(cropRect.height + offsetSize,
        cropRect.width + offsetSize, CV_8UC3);
    warpPerspective(src, transformed, transmtx, transformed.size());

    destroyWindow(winName);
//    imshow("quadrilateral", transformed);
    sprintf_s(imgName, 15, "t.jpg");
    imwrite(imgName, transformed);

    Point ppp1(0, 0), ppp2(100, 100);
    line(transformed, ppp1, ppp2, Scalar(255, 0, 0),
        4, LINE_8);
    imshow("quadrilateral", transformed);
}
void checkBoundary() {
    // check croping rectangle exceed image boundary
    if (cropRect.width > img.cols - cropRect.x)
        cropRect.width = img.cols - cropRect.x;

    if (cropRect.height > img.rows - cropRect.y)
        cropRect.height = img.rows - cropRect.y;

    if (cropRect.x < 0)
        cropRect.x = 0;

    if (cropRect.y < 0)
        cropRect.height = 0;
}

void showImage() {
    img = src.clone();
    checkBoundary();

    if (quad_pts.size() == 1)
        circle(img, quad_pts[0], 5, Scalar(0, 0, 255), 1.5, LINE_AA, 0);
    if (quad_pts.size() > 1) {
        for (int i = 0; i < quad_pts.size() - 1; i++) {
            line(img, quad_pts[i], quad_pts[i + 1], Scalar(0, 0, 255), 1, LINE_AA, 0);
            circle(img, quad_pts[i], 5, Scalar(0, 0, 255), 1.5, LINE_AA, 0);
            circle(img, quad_pts[i + 1], 5, Scalar(0, 0, 255), 1.5, LINE_AA, 0);
        }
    }

    if (quad_pts.size() == 4)
        line(img, quad_pts[0], quad_pts[3], Scalar(0, 0, 255), 1, LINE_AA, 0);

    rectangle(img, cropRect, Scalar(0, 255, 0), 1, 8, 0);
    imshow(winName, img);
}

void onMouse(int event, int x, int y, int f, void*) {

    switch (event) {

    case EVENT_RBUTTONDOWN:
        if (quad_pts.size() < 4)
            quad_pts.push_back(Point(x, y));
        else
            cout << "Maximum allowd point is 4, Try to remove by pressing 'r' "
            << endl;
        break;

    case EVENT_LBUTTONDOWN:
        clicked = true;

        P1.x = x;
        P1.y = y;
        P2.x = x;
        P2.y = y;
        break;

    case EVENT_LBUTTONUP:
        P2.x = x;
        P2.y = y;
        clicked = false;
        break;

    case EVENT_MOUSEMOVE:
        if (clicked) {
            P2.x = x;
            P2.y = y;
        }
        break;

    default:
        break;
    }

    if (clicked) {
        if (P1.x > P2.x) {
            cropRect.x = P2.x;
            cropRect.width = P1.x - P2.x;
        }
        else {
            cropRect.x = P1.x;
            cropRect.width = P2.x - P1.x;
        }

        if (P1.y > P2.y) {
            cropRect.y = P2.y;
            cropRect.height = P1.y - P2.y;
        }
        else {
            cropRect.y = P1.y;
            cropRect.height = P2.y - P1.y;
        }

        cropRect.x = 0;
        cropRect.width = 1000;
        cropRect.y = 0;
        cropRect.height = 512;

        rect_pts.clear();
        rect_pts.push_back(Point(cropRect.x, cropRect.y));
        rect_pts.push_back(Point(cropRect.x + cropRect.width, cropRect.y));
        rect_pts.push_back(
            Point(cropRect.x + cropRect.width, cropRect.y + cropRect.height));
        rect_pts.push_back(Point(cropRect.x, cropRect.y + cropRect.height));
    }

    if ((rect_pts.size() == 4) && (quad_pts.size() == 4)) {
        prspectiveTransform();
        t = 1;
    }
    else
        showImage();
}
int main() {

    cout << "Right click each corner of card to select the point to be "
        "trasnformed."
        << endl
        << endl;
    cout << "Click and drag for Selection" << endl << endl;
    cout << "------> Press 's' to save" << endl << endl;

    cout << "------> Press '8' to move up" << endl;
    cout << "------> Press '2' to move down" << endl;
    cout << "------> Press '6' to move right" << endl;
    cout << "------> Press '4' to move left" << endl << endl;

    cout << "------> Press 'w' increas top" << endl;
    cout << "------> Press 'x' increas bottom" << endl;
    cout << "------> Press 'd' increas right" << endl;
    cout << "------> Press 'a' increas left" << endl << endl;

    cout << "------> Press 't' decrease top" << endl;
    cout << "------> Press 'b' decrease bottom" << endl;
    cout << "------> Press 'h' decrease right" << endl;
    cout << "------> Press 'f' decrease left" << endl << endl;

    cout << "------> Press 'r' to reset quad points" << endl;
    cout << "------> Press 'Esc' to quit" << endl << endl;

    src = imread("C:/Users/pc/Desktop/immagine2.jpeg");

    namedWindow(winName, 1);
    setMouseCallback(winName, onMouse, NULL);
    imshow(winName, src);

    while (1) {
        char c = waitKey();
        if (c == 's' && ROI.data) {
            sprintf_s(imgName, 15, "%d.jpg", i++);
            imwrite(imgName, ROI);
            cout << "  Saved " << imgName << endl;
        }
        if (c == '6')
            cropRect.x++;
        if (c == '4')
            cropRect.x--;
        if (c == '8')
            cropRect.y--;
        if (c == '2')
            cropRect.y++;

        if (c == 'w') {
            cropRect.y--;
            cropRect.height++;
        }
        if (c == 'd')
            cropRect.width++;
        if (c == 'x')
            cropRect.height++;
        if (c == 'a') {
            cropRect.x--;
            cropRect.width++;
        }

        if (c == 't') {
            cropRect.y++;
            cropRect.height--;
        }
        if (c == 'h')
            cropRect.width--;
        if (c == 'b')
            cropRect.height--;
        if (c == 'f') {
            cropRect.x++;
            cropRect.width--;
        }

        if (c == 27)
            break;
        if (c == 'r') {
            if (quad_pts.size() > 0) {
                quad_pts.pop_back();
                showImage();
            }
        }
    }

    return 0;
}
*/


Mat transformed;
Mat src, img, ROI;
Rect cropRect(0, 0, 0, 0);
Point P1(0, 0);
Point P2(0, 0);
std::vector < Point2f > quad_pts;
std::vector < Point2f > rect_pts;
std::vector < Point2f > quad2_pts;

const char* winName = "Crop Image";
bool clicked = false;
int i = 0;
char imgName[15];

int t = 0;

void prspectiveTransform() {

    Mat transmtx = getPerspectiveTransform(quad_pts, rect_pts);
    int offsetSize = 150;
    transformed = Mat::zeros(cropRect.height + offsetSize,
        cropRect.width + offsetSize, CV_8UC3);
    warpPerspective(src, transformed, transmtx, transformed.size());

    destroyWindow(winName);
    //    imshow("quadrilateral", transformed);
    sprintf_s(imgName, 15, "t.jpg");
    imwrite(imgName, transformed);

    //   Point ppp1(0, 0), ppp2(100, 100);
    //   line(transformed, ppp1, ppp2, Scalar(255, 0, 0),
    //       4, LINE_8);
    //   imshow("quadrilateral", transformed);
}
void checkBoundary() {
    // check croping rectangle exceed image boundary
    if (cropRect.width > img.cols - cropRect.x)
        cropRect.width = img.cols - cropRect.x;

    if (cropRect.height > img.rows - cropRect.y)
        cropRect.height = img.rows - cropRect.y;

    if (cropRect.x < 0)
        cropRect.x = 0;

    if (cropRect.y < 0)
        cropRect.height = 0;
}

void showImage() {
    img = src.clone();
    checkBoundary();

    if (quad_pts.size() == 1)
        circle(img, quad_pts[0], 5, Scalar(0, 0, 255), 1.5, LINE_AA, 0);
    if (quad_pts.size() > 1) {
        for (int i = 0; i < quad_pts.size() - 1; i++) {
            line(img, quad_pts[i], quad_pts[i + 1], Scalar(0, 0, 255), 1, LINE_AA, 0);
            circle(img, quad_pts[i], 5, Scalar(0, 0, 255), 1.5, LINE_AA, 0);
            circle(img, quad_pts[i + 1], 5, Scalar(0, 0, 255), 1.5, LINE_AA, 0);
        }
    }

    if (quad_pts.size() == 4)
        line(img, quad_pts[0], quad_pts[3], Scalar(0, 0, 255), 1, LINE_AA, 0);

    rectangle(img, cropRect, Scalar(0, 255, 0), 1, 8, 0);
    imshow(winName, img);
}

void showImage2() {
    img = transformed.clone();
    //    checkBoundary();

    if (quad2_pts.size() == 1)
        circle(img, quad2_pts[0], 5, Scalar(0, 0, 255), 1.5, LINE_AA, 0);
    if (quad2_pts.size() == 2) {
        line(img, quad2_pts[0], quad2_pts[1], Scalar(0, 0, 255), 1, LINE_AA, 0);
        circle(img, quad2_pts[0], 5, Scalar(0, 0, 255), 1.5, LINE_AA, 0);
        circle(img, quad2_pts[1], 5, Scalar(0, 0, 255), 1.5, LINE_AA, 0);
    }
    imshow(winName, img);
}

void onMouse(int event, int x, int y, int f, void*) {


    switch (event) {

    case EVENT_RBUTTONDOWN:
        if (t == 0) {
            if (quad_pts.size() < 4)
                quad_pts.push_back(Point(x, y));
            else {
                cout << "Maximum allowd point is 4, Try to remove by pressing 'r' "
                    << endl;
            }
            break;
        }
        else {
            cout << "ECC";
            if (quad2_pts.size() < 2)
                quad2_pts.push_back(Point(x, y));
            else
                cout << "Maximum allowd point is 2, Try to remove by pressing 'r' "
                << endl;
            break;
        }


    case EVENT_LBUTTONDOWN:
        clicked = true;
        P1.x = x;
        P1.y = y;
        P2.x = x;
        P2.y = y;
        break;

    case EVENT_LBUTTONUP:
        P2.x = x;
        P2.y = y;
        clicked = false;
        if ((rect_pts.size() == 4) && (quad_pts.size() == 4) && (t == 0)) {
            prspectiveTransform();
            showImage2();
            t = 1;
        }
        break;

    case EVENT_MOUSEMOVE:
        if (clicked) {
            P2.x = x;
            P2.y = y;
        }
        break;

    default:
        break;
    }


    if (clicked) {
        cropRect.x = 0;
        cropRect.width = 1000;
        cropRect.y = 0;
        cropRect.height = 512;

        rect_pts.clear();
        rect_pts.push_back(Point(cropRect.x, cropRect.y));
        rect_pts.push_back(Point(cropRect.x + cropRect.width, cropRect.y));
        rect_pts.push_back(
            Point(cropRect.x + cropRect.width, cropRect.y + cropRect.height));
        rect_pts.push_back(Point(cropRect.x, cropRect.y + cropRect.height));
    }


    if (t == 0)
        showImage();
    else if (t == 2) {
        showImage2();
    }

    if (t == 1) {
        setMouseCallback(winName, onMouse, NULL);
        t = 2;
    }
}

int main() {

    cout << "Right click each corner of card to select the point to be "
        "trasnformed."
        << endl
        << endl;
    cout << "Click and drag for Selection" << endl << endl;
    cout << "------> Press 's' to save" << endl << endl;

    cout << "------> Press '8' to move up" << endl;
    cout << "------> Press '2' to move down" << endl;
    cout << "------> Press '6' to move right" << endl;
    cout << "------> Press '4' to move left" << endl << endl;

    cout << "------> Press 'w' increas top" << endl;
    cout << "------> Press 'x' increas bottom" << endl;
    cout << "------> Press 'd' increas right" << endl;
    cout << "------> Press 'a' increas left" << endl << endl;

    cout << "------> Press 't' decrease top" << endl;
    cout << "------> Press 'b' decrease bottom" << endl;
    cout << "------> Press 'h' decrease right" << endl;
    cout << "------> Press 'f' decrease left" << endl << endl;

    cout << "------> Press 'r' to reset quad points" << endl;
    cout << "------> Press 'Esc' to quit" << endl << endl;

    src = imread("C:/Users/pc/Desktop/immagine2.jpeg");

    namedWindow(winName, 1);
    setMouseCallback(winName, onMouse, NULL);
    imshow(winName, src);

    while (1) {
        char c = waitKey();
        if (c == 's' && ROI.data) {
            sprintf_s(imgName, 15, "%d.jpg", i++);
            imwrite(imgName, ROI);
            cout << "  Saved " << imgName << endl;
        }
        if (c == '6')
            cropRect.x++;
        if (c == '4')
            cropRect.x--;
        if (c == '8')
            cropRect.y--;
        if (c == '2')
            cropRect.y++;

        if (c == 'w') {
            cropRect.y--;
            cropRect.height++;
        }
        if (c == 'd')
            cropRect.width++;
        if (c == 'x')
            cropRect.height++;
        if (c == 'a') {
            cropRect.x--;
            cropRect.width++;
        }

        if (c == 't') {
            cropRect.y++;
            cropRect.height--;
        }
        if (c == 'h')
            cropRect.width--;
        if (c == 'b')
            cropRect.height--;
        if (c == 'f') {
            cropRect.x++;
            cropRect.width--;
        }

        if (c == 27)
            break;
        if (c == 'r') {
            if (t == 0) {
                if (quad_pts.size() > 0) {
                    quad_pts.pop_back();
                    showImage();
                }
            }
            else if (t == 2) {
                if (quad2_pts.size() > 0) {
                    quad2_pts.pop_back();
                    showImage2();
                }

            }

        }
    }

    return 0;
}