#include <Magick++.h>
#include <iostream>

using namespace Magick;
using namespace std;

int main(int argc, char **argv)
{
    try
    {
        InitializeMagick(*argv);
        Image img("C:/test.bmp");
        ColorRGB rgb(img.pixelColor(0, 0)); // ie. pixel at pos x=0, y=0
        cout << "red: " << rgb.red();
        cout << ", green: " << rgb.green();
        cout << ", blue: " << rgb.blue() << endl;
    }
    catch (Magick::Exception &error)
    {
        cerr << "Caught Magick++ exception: " << error.what() << endl;
    }
    return 0;
}