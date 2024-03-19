#include "data/image.h"

Image::Image() {}

Image::Image(size_t width, size_t height, const Pixel &fill_value) : width_(width), height_(height), data(width * height, fill_value) {}

size_t Image::GetWidth() const {
    return width_;
}

size_t Image::GetHeight() const {
    return height_;
}

void Image::SetPixel(size_t col, size_t row, const Pixel &pixel) {
    data[GetRepresentationDimension(col, row)] = pixel;
}

Pixel Image::GetPixel(size_t col, size_t row) const {
    return data[GetRepresentationDimension(col, row)];
}

size_t Image::GetRepresentationDimension(size_t col, size_t row) const {
    return row * width_ + col;
}
