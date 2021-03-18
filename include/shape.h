#ifndef __SHAPE_H__
#define __SHAPE_H__

#include <vector>

namespace shape
{
    std::vector<std::vector<double>> genHeart();
    std::vector<std::vector<double>> genEllipse(double a, double b, double radius);
    std::vector<std::vector<int>> genSimpleDiamond();
}

#endif // __SHAPE_H__