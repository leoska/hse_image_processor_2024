#include <iostream>
#include "io/image_format.h"
#include "io/bmp.h"
#include "filters/grayscale.h"

int main(int argc, const char *argv[])
{
    // TODO: научится обрабатывать argv, чтобы менять пути и устанавливать фильтры
    std::cout << argv[0] << std::endl;

    BMP image_format;

    std::string filename = "../flag_sharp.bmp";
    std::string save_filename = "../test.bmp";

    Image image = image_format.Load(filename);

    // TODO: фильтр может быть не один (возможно, нужна фабрика фильтров)
    GrayScale filter;

    Image newImage = filter.Apply(image);

    image_format.Save(newImage, save_filename);

    return 0;
}