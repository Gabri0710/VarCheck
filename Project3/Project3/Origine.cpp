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
#include "Origine.h"
#include "opencv2/core.hpp"
#include "opencv2/video.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"
#include <opencv2/videoio/videoio_c.h>
#include "opencv2/highgui.hpp"
#include <chrono>
#include <thread>
#include "Calcolo.h"
#include <windows.h>


using namespace cv;
using namespace std;

using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds

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

/*
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
   // transformed = Mat::zeros(cropRect.height + offsetSize,
   //     cropRect.width + offsetSize, CV_8UC3);
    transformed = Mat::zeros(cropRect.height,
             cropRect.width, CV_8UC3);
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

    // rectangle(img, cropRect, Scalar(0, 255, 0), 1, 8, 0);
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
        else if ((quad2_pts.size() == 2) && (t == 2)) {
            Point ppp1, ppp2;
            ppp1.x = quad2_pts[0].x + 30;
            ppp1.y = quad2_pts[0].y;
            ppp2.x = quad2_pts[1].x + 30;
            ppp2.y = quad2_pts[1].y;
            line(transformed, ppp1 , ppp2, Scalar(255, 0, 0),2, LINE_8);
        }
        break;

    //case EVENT_MOUSEMOVE:
    //    if (clicked) {
    //        P2.x = x;
     //       P2.y = y;
     //   }
     //   break;

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

int main(string s) {

    t = 0;
    rect_pts.clear();
    quad_pts.clear();
    quad2_pts.clear();
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

    //src = imread("C:/Users/pc/Desktop/immagine2.jpeg");
    src = imread(s);

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

*/


Mat src, transformed, img;          //immagini sorgente, trasformata e ausiliaria

Rect cropRect(0, 0, 0, 0);

Point P1(0, 0);
Point P2(0, 0);

int width = 1000;
int height = 512;

vector < Point2f > quad_pts;        
vector < Point2f > rect_pts = { Point(0, 0), Point(width, 0), Point(width, height), Point(0, height) };
vector < Point2f > quad2_pts;
vector<Mat> frames; 

int videofrm = 0;               //tiene conto di quale frame del video siamo arrivati
int t = 0;                      //indica se siamo nell'immagine sorgente o nella trasformata
int f_v = 0;                    //indica se abbiamo scelto una foto o un video
int f_vc = 0;                   //variabile ausiliaria che ci permette di spostarci tra i comandi per i video e i comandi per la foto
int check = 0;                  //variabile che ci permette di capire se acquisire l'immagine sorgente da quella passata o da quella scelta dal video

const char* winName = "ANALISI INCERTEZZA";
char imgName[15];

bool clicked = false;


Mat tmp2;

void prspectiveTransform() {

    Mat transmtx = getPerspectiveTransform(quad_pts, rect_pts);
   transformed = Mat::zeros(height,
              width, CV_8UC3);

    warpPerspective(src, transformed, transmtx, transformed.size());

    sprintf_s(imgName, 15, "t.jpg");
    imwrite(imgName, transformed);
    
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

    imshow(winName, img);
}

void showImage2() {
    img = transformed.clone();

    if (quad2_pts.size() == 1)
        circle(img, quad2_pts[0], 5, Scalar(0, 0, 255), 1.5, LINE_AA, 0);
    if (quad2_pts.size() == 2) {
        line(img, quad2_pts[0], quad2_pts[1], Scalar(0, 0, 255), 1, LINE_AA, 0);
        circle(img, quad2_pts[0], 5, Scalar(0, 0, 255), 1.5, LINE_AA, 0);
        circle(img, quad2_pts[1], 5, Scalar(0, 0, 255), 1.5, LINE_AA, 0);
    }
    imshow(winName, img);
}

void showImage3() {
    img = transformed.clone();
    imshow(winName, img);
}

void showLine() {
    img = tmp2.clone();
    imshow(winName, img);
}



void onMouse(int event, int x, int y, int f, void*) {

        switch (event) {

        case EVENT_RBUTTONDOWN:
            if (t == 0) {                      //controlla se siamo nell'immagine sorgente
                if (quad_pts.size() < 4) {                  //controlla se i punti inseriti sono meno di 4
                    quad_pts.push_back(Point(x, y));
                //   SetCursor(LoadCursor(NULL, IDC_HAND));
                    }
                else {
                    cout << "Maximum allowd point is 4, Try to remove by pressing 'r' "
                        << endl;
                }
                break;
            }
        //    else if (t==2){                     //controlla se siamo nell'immagine trasformata
         //       if (quad2_pts.size() < 2)                   //controlla se i punti inseriti sono meno di 2
         //           quad2_pts.push_back(Point(x, y));
          //      else
           //         cout << "Maximum allowd point is 2, Try to remove by pressing 'r' "
           //         << endl;
           //     break;
           // }
        


        case EVENT_LBUTTONDOWN:
             if (f_v == 2) {             //se siamo in un video
                f_v = 1;                //e ho selezionato un frame, lo "estraggo" e mi sposto ai comandi per le foto
                break;
            }
            else {
                if ((rect_pts.size() == 4) && (quad_pts.size() == 4) && (t == 0)) {                     //se siamo nell'immagine sorgente e ho selezionato i 4 punti
                    prspectiveTransform();                              
                    showImage2();
                    t = 1;                  
                }
              //  else if ((quad2_pts.size() == 2) && (t == 2)) {                     //se siamo nell'immagine trasformata e ho fissato i 2 punti
                else if(t==2){
                //    quad2_pts.push_back(Point(x, y));
                //    Point ppp1, ppp2;
                    double offs = getris();                     //ottengo l'incertezza
                 //   ppp1.x = quad2_pts[0].x + (offs/5);
                //    ppp1.y = quad2_pts[0].y;
                //    ppp2.x = quad2_pts[1].x + (offs/5);
                //    ppp2.y = quad2_pts[1].y;


                    Mat tmp = transformed.clone();                  //clono per ottenere l'effetto trasparenza del rettangolo
                 //   rectangle(tmp, quad2_pts[0], ppp2, cv::Scalar(255, 0, 0), FILLED);
                    line(transformed, Point(x, 0), Point(x, height), Scalar(255, 0, 0), 1, LINE_AA, 0);
                    rectangle(tmp, Point(x, 0), Point(x + (offs / 5), height), cv::Scalar(255, 0, 0), FILLED);
                    addWeighted(tmp, 0.3, transformed, 1 - 0.3, 0, transformed);                                  
                    t = 3;                                          //lo pongo uguale a 3 per non permettere più ai comandi di funzionare
                }
                else if (t == 4) {
                //    quad2_pts.push_back(Point(x, y));
                 //   Point ppp1, ppp2;
                    
                    line(transformed, Point(x, 0), Point(x, height), Scalar(0, 0, 255), 1, LINE_AA, 0);
                    t = 2;
                }
                break;
            }

     //   case EVENT_MOUSEWHEEL:
     //       if (getMouseWheelDelta(f) > 0) {
      //          xs += 5;
       //         ys += 5;
             //   cv::Range rows(1, xs);
             //   cv::Range cols(1, ys);
             //   dst = src(rows, cols);
      
                //pyrUp(dst, dst, Size(dst.cols * 2, dst.rows * 2));
      //          resize(dst, dst, Size(dst.cols * 1.5, dst.rows * 1.5));
       //         t = 13;
      //      }
        //    if (getMouseWheelDelta(f) < 0) {
             //   xs -= 5;
             //   ys -= 5;
             //   Rect crop(x, y, xs, ys);
             //   dst = src(crop);
                
                //pyrDown(dst, dst, Size(dst.cols / 2, dst.rows / 2));
         //       resize(dst, dst, Size(dst.cols / 1.5, dst.rows / 1.5));
        //    }
                

        default:
            break;
        }
  

        if (t == 0)
            showImage();
        else if (t == 2 || t == 4) {
            showImage2();
            tmp2 = transformed.clone();
            if(t==2)
                line(tmp2, Point(x, 0), Point(x,height), Scalar(255, 0, 0), 1, LINE_AA, 0);
            else if(t==4)
                line(tmp2, Point(x, 0), Point(x, height), Scalar(0, 0, 255), 1, LINE_AA, 0);
            showLine();
        }
        else if (t == 3) {
            showImage3();
        }

        if (t == 1) {
            setMouseCallback(winName, onMouse, NULL);
            t = 2;
        }

        
}




//VIDEO
void extract_frames(string videoFilePath) {
    
    VideoCapture cap(videoFilePath);
       
    if (!cap.isOpened()) {
        cout << "Can not open Video file";
        exit(1);
    }
        
        
    for (int frameNum = 0; frameNum < cap.get(CV_CAP_PROP_FRAME_COUNT); frameNum+=2){
            Mat frame;
            cap >> frame;           // ottiene il prossimo frame dal video

            frames.push_back(frame);      
        }
    
}

void showVideo() {
    imshow(winName, frames[videofrm%frames.size()]);
}



int main(string s, int fv) {

    f_v = fv;
    check = 0;


    if (f_v == 3) {                 //se analizzo un'immagine presa dal video
        f_v = 1;
        check = 2;
    }

    if (f_v == 1) {                 //se analizzo un'immagine
        
        t = 0;
        quad_pts.clear();
        quad2_pts.clear();

        if (check == 0) src = imread(s);
        else if(check==2) src = frames[videofrm%frames.size()];


        namedWindow(winName, 1);
        setMouseCallback(winName, onMouse, NULL);
        imshow(winName, src); 
        f_vc = 1;

        while (1) {
            char c = waitKey();
            if (c == 'r') {
                if (t == 0) {
                    if (quad_pts.size() > 0) {
                        quad_pts.pop_back();
                        showImage();
                    }
                }
            //    else if (t == 2) {
              //      if (quad2_pts.size() > 0) {
              //          quad2_pts.pop_back();
              //          showImage2();
              //      }

             //   }

            }
            else if (c == '1') {
                if (t == 2 || t == 4) {
                    t = 2;
                    showLine();
                }     
            }
            else if (c == '2') {
                if (t == 2 || t == 4) {
                    t = 4;
                    showLine();
                }
        
            }
        }
    }
    else if (f_v == 2) {                //se analizzo un video

        videofrm = 0;                   //riazzero il frame di partenza
        f_vc = 2;
        
        extract_frames(s);
        showVideo();
        
        
        
        while (f_v==2) {
            char c = waitKey();
            if (c == 'd') {
                videofrm += 1;
                showVideo();
            }   

            if (c == 'a') {
                videofrm -= 1;
                showVideo();
            }

            if (c == 'o') {             
                f_v = 1;                    //ho selezionato l'immagine di interesse, esco dall'analisi video      
            }
        }
        main(s, 3);                 //inserisco 3 per indicare che si tratta di un'immagine estratta da un video
    }
    

    return 0;
}