#pragma GCC diagnostic error "-std=c++11"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <fstream>    //使用ifstream，需要增加头文件fstream
#include <iostream>
#include <string>

using namespace std;
using namespace cv;

int main()
{
  ifstream fin("/home/ttwang/images/calibdata.txt");//读取指定目录下实现生成的txt文件
  int image_count = 0;
  Size image_size; //opencv中图片尺寸定义，成员有width和height
  string filename;  
  while(getline(fin,filename)) //使用getline函数，用法参见 c++ primer P79 3.2.2节
  {
    image_count++;
    cout << "processing: " << filename << endl; //打印读取结果，直观看文件是否读取成功
    filename = "/home/ttwang/images/"+filename;//图片路径
    Mat imageInput = imread(filename);//读图片
    if(image_count == 1) //打印第一幅图片的长和宽
    {
      image_size.width = imageInput.cols;
      image_size.height = imageInput.rows;
      cout << "image_size.width = " << image_size.width << endl;
      cout << "image_size.height = " << image_size.height << endl;
    }
  }
  return 0;
}
