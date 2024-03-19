#include "filters/grayscale.h"

Image GrayScale::Apply(Image& image)
{
    Image result = image;
    Pixel grayScale = Pixel{0.2126f, 0.7152f, 0.0722f};
    for(size_t row = 0; row != image.GetHeight(); ++row) {
        for (size_t col = 0; col != image.GetWidth(); ++col) {
            auto current = image.GetPixel(col, row);
            Pixel weighted_color = current * grayScale;
            float brightness = weighted_color.red + weighted_color.green + weighted_color.blue;
            result.SetPixel(col, row, Pixel{brightness, brightness, brightness});
        }
    }
    return result;
}
