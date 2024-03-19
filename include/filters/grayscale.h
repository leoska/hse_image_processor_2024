#pragma once

#include "filters/filter.h"

class GrayScale: Filter {
public:
    Image Apply(Image& image) override;
};