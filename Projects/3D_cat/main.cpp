#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <fstream>

using namespace cv;
using namespace std;

struct Point3d
{
    float x;
    float y;
    float z;
};

void projectPoints(Mat &img, const vector<Point3f> points, float alpha, float beta, float radius) {
    
    Point3f camera_pos;
    
    camera_pos.x = sin(beta) * cos(alpha);
    camera_pos.y = cos(beta);
    camera_pos.z = sin(alpha) * sin(beta);

    
    // transformation from  world to camera
    Mat R = Mat::eye(3,3,CV_32F);
    Mat T = Mat(-1.0* radius * camera_pos);
    Mat C = Mat:: eye(3,3, CV_32F);
    Mat T2(3,1,CV_32F);
    T2.at<float>(0,0) = T.at<float>(0,0);
    T2.at<float>(1,0) = T.at<float>(0,1);
    T2.at<float>(2,0) = T.at<float>(0,2);

    C.at<float>(0,0) = C.at<float>(1,1) = 300.0f;
    C.at<float>(0,2) = 400.0f;
    C.at<float>(1,2) = 300.0f;


    //axes
    Point3f up(0.0f,1.0f,0.0f);
    int angle=(int)floor(beta/3.1415);
    Point3f P = camera_pos;
    
    P = -P/norm(P);
    //cout<<P<<endl;
    Point3f right = P.cross(up);
    right /= norm(right);
    Point3f down = P.cross(right);
    down /=norm(down);
    if (!(angle%2))
        P = -P;
    
    
    /*
    cout<<camera_pos<<endl;
    cout<<P<<endl;
    cout<<up<<endl;
    cout<<right<<endl;
    cout <<down<<endl;
    */
    //Right vector
    R.at<float>(0,0)= right.x;
    R.at<float>(1,0)= right.y;
    R.at<float>(2,0)= right.z;

    //Down vector
    R.at<float>(0,1)= down.x;
    R.at<float>(1,1)= down.y;
    R.at<float>(2,1)= down.z;

    //-p/||p|| vector
    R.at<float>(0,2)= P.x;
    R.at<float>(1,2)= P.y;
    R.at<float>(2,2)= P.z;
    R= R.inv();
    for (const auto &p:points) {
        Mat invP(3,1,CV_32F);
        invP.at<float>(0,0) = p.x;
        invP.at<float>(1,0) = p.y;
        invP.at<float>(2,0) = p.z;
        Mat p_camera = R * (invP + T2);
        p_camera = C* p_camera;
        p_camera /= p_camera.at<float>(2,0);
        circle(img, Point(round(p_camera.at<float>(0,0)),round(p_camera.at<float>(1,0))), 1, Scalar(255,0,0));
        
    }
    
}

int main(int argc, char* argv[]) {
    ifstream structure;
    std::vector<Point3f> points;
    Point3f temp;

    double temp1 = 0, temp2 = 0, temp3 = 0;
     
    structure.open("/Users/pingguo/Desktop/Affine_transformation/Structure.txt");
     
    for(int i = 0; !structure.eof(); i++)
    {
        //读取txt文件的坐标值
        structure >> temp1 >>temp2 >>temp3;
        temp.x = temp1;
        temp.y = temp2;
        temp.z = temp3;
        points.push_back(temp);
    }
    Mat img;
    img = Mat::zeros(600,800,CV_8UC3);
    float alpha = 1, beta = 0.5;
    float radius = 100.0;
    
    projectPoints(img, points, alpha, beta, radius);
    namedWindow("w1", WINDOW_AUTOSIZE);
    imshow("w1", img);
    
    char key;
    while(true) {
        key=waitKey(0);
        if(key==27) break;
        switch(key) {
            case 'a':
                alpha +=0.1;
                break;
            case 'd':
                alpha -=0.1;
                break;
            case 'w':
                beta +=0.1;
                break;
            case 's':
                beta -=0.1;
                break;
            case 'i':
                radius *=1.1;
                break;
            case 'o':
                radius /=1.1;
                break;
        }
        img = Mat::zeros(600,800,CV_8UC3);
        projectPoints(img, points, alpha, beta, radius);
        imshow("w1", img);
    }
    return 0;
}
