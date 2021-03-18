#ifndef __SHAPE_H__
#define __SHAPE_H__

#include <vector>

namespace shape
{
    class Data
    {
    public:
        int dx;
        int dy;

        // Constructors
        Data() { dx = 0; dy = 0; }
        Data(int a, int b) { dx = a; dy = b; }
    };

    std::vector<std::vector<double>> genHeart();
    std::vector<std::vector<double>> genEllipse(double a, double b, double radius);
    std::vector<std::vector<int>> genSimpleDiamond();
}

#endif // __SHAPE_H__