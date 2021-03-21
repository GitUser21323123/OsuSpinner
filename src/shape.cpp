#include <shape.h>
#include <iostream>
#include <input.h>

namespace shape
{
    // Create and return 2D vector of shape heart
    std::vector<Data> genHeart() 
    {
        std::cout << "Created heart shape (Vector)\n";

        // Heart Equation (Parametric):
        // x = 16sin^3(t)
        // y = 13cos(t) - 5cos(2t) - 2cos(3t) - cos(4t)
        // Domain: t = [-3, 3]

        std::vector<Data> coordinates;

        for (double i = -3.0f; i < 3.f; i += 0.15)
        {
            double x = 16.0f * std::pow(std::sin(i), 3);
            double y = 13.0f * std::cos(i) - 5.0f * std::cos(2.0f*i) - 2.0f * std::cos(3.0f*i) - std::cos(4.0f*i);

            double dx = 48.0f * std::pow(std::sin(i), 2) * std::cos(i);
            double dy = -13.0f * std::sin(i) + 10.0f * sin(2.0f*i) + 6.0f * std::sin(3.0f*i) + 4.0f * std::sin(4.0f*i);

            coordinates.push_back(Data((int)dx, (int)dy));
        }

        return coordinates;
    }

    // Create and return 2D C Array of shape heart
    void genHeartArray(Data *coordinates)
    {
        std::cout << "Creating heart shape (Array)\n";

        // Heart Equation (Parametric):
        // x = 16sin^3(t)
        // y = 13cos(t) - 5cos(2t) - 2cos(3t) - cos(4t)
        // Domain: t = [-3, 3]

        for (int i = 0; i < 45; ++i)
        {
            coordinates[i].dx = 0;
            coordinates[i].dy = 0;
        }

        int count = 0;
        for (double i = -3.0f; i < 3.f; i += 0.3, count++)
        {
            double x = 16.0f * std::pow(std::sin(i), 3);
            double y = 13.0f * std::cos(i) - 5.0f * std::cos(2.0f*i) - 2.0f * std::cos(3.0f*i) - std::cos(4.0f*i);

            double dx = 48.0f * std::pow(std::sin(i), 2) * std::cos(i);
            double dy = -13.0f * std::sin(i) + 10.0f * sin(2.0f*i) + 6.0f * std::sin(3.0f*i) + 4.0f * std::sin(4.0f*i);

            coordinates[count].dx = -dx;
            coordinates[count].dy = -dy;
        }
    }
    
    // Create and return 2D vector of shape ellipse
    std::vector<std::vector<double>> genEllipse(double a, double b, double radius) 
    {
        std::cout << "Created ellipse shape\n";

        // Equation: (x^2 / a^2) + (y^2 / b^2) = r^2
        // Equation (Parametric): x = rcos(t), y = rsin(t)


        // Domain: t = [-pi, pi]

        std::vector<std::vector<double>> coordinates;

        // Circle
        for (double i = -3.14; i < 3.14f; i += 0.2)
        {
            double dx = radius * -std::sin(i);
            double dy = radius * std::cos(i);
            
            coordinates.push_back({dx, dy});
        }

        return coordinates;
    }
    
    std::vector<std::vector<int>> genSimpleDiamond() 
    {
        std::cout << "Created diamond shape\n";

        // Creates simple diamond
        std::vector<std::vector<int>> coordinates;

        for (int i = 0; i < 10; ++i)
        {
            coordinates.push_back({10, -10});
        }
        for (int i = 0; i < 10; ++i)
        {
            coordinates.push_back({-10, -10});
        }
        for (int i = 0; i < 10; ++i)
        {
            coordinates.push_back({-10, 10});
        }
        for (int i = 0; i < 10; ++i)
        {
            coordinates.push_back({10, 10});
        }

        return coordinates;
    }
}