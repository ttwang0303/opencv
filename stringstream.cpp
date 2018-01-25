/*批量读取图片，进行均值滤波处理，并保存至指定目录下*/
/*学习使用stringstream进行图片的批量读取与保存*/

#pragma GCC diagnostic error "-std=c++11"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
using namespace cv;
int main()
{
  string imageFileName;
  std::stringstream Strm;
  int image_count = 14;//图片数量
  std::cout << "开始均值滤波处理........" << endl;//便于控制台查看
  for (int i = 0; i!= image_count;i++)
  {
     std::cout << "第"<<i+1<<"张处理成功"<< endl;//便于控制台查看
     string filePath = "/home/ttwang/CameraCalibration/chess";//原图保存路径
     Strm<< i+1;
     Strm>>imageFileName;
     filePath+=imageFileName;
     filePath+=".bmp";
     Mat imageSource = imread(filePath);
     Mat newimage = imageSource.clone();
     
     blur(imageSource,newimage,Size(7,7));//均值滤波处理
     
     Strm.clear();
     filePath.clear();
     string SaveFilePath = "/home/ttwang/CameraCalibration/blur/p";//处理后的图片保存路径
     Strm << i+1;
     Strm >> imageFileName;
     SaveFilePath += imageFileName;
     SaveFilePath += "_d.jpg";
     imwrite(SaveFilePath,newimage);
   }
   std::cout << "保存结束" << endl;
   return 0;
}
