#include <iostream>
#include "core/Section.h"
#include "core/Material.h"

Section::Section() {

};

const bool Section::compressionTop()
{
    return compressionTop_;
};

void Section::updateCompressionTop(bool compressionTop)
{
    compressionTop_ = compressionTop;
};

// TODO: further implementation of section types