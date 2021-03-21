#include <shape.h>
#include <iostream>
#include <input.h>

namespace shape
{
    // Create and return 2D vector of shape heart
    std::vector<Data> genHeart() 
    {
        // Heart Equation (Parametric):
        // x = 16sin^3(t)
        // y = 13cos(t) - 5cos(2t) - 2cos(3t) - cos(4t)
        // Domain: t = [-3, 3]

        std::vector<Data> coordinates;

        for (double i = -3.0f; i < 3.f; i += 0.6)
        {
            double dx = 48.0f * std::pow(std::sin(i), 2) * std::cos(i);
            double dy = -13.0f * std::sin(i) + 10.0f * sin(2.0f*i) + 6.0f * std::sin(3.0f*i) + 4.0f * std::sin(4.0f*i);

            coordinates.push_back(Data(-5*dx, -5*dy));
        }
        coordinates.push_back(Data(6, 0));

        return coordinates;
    }

    // Create and return 2D C Array of shape heart
    void genHeartArray(Data *coordinates)
    {
        // Heart Equation (Parametric):
        // x = 16sin^3(t)
        // y = 13cos(t) - 5cos(2t) - 2cos(3t) - cos(4t)
        // Domain: t = [-3, 3]

        int count = 0;
        for (double i = -3.0f; i < 3.1f; i += 0.6, count++)
        {
            double dx = 48.0f * std::pow(std::sin(i), 2) * std::cos(i);
            double dy = -13.0f * std::sin(i) + 10.0f * sin(2.0f*i) + 6.0f * std::sin(3.0f*i) + 4.0f * std::sin(4.0f*i);

            std::cout << "i: " << i << " | dx: " << dx << " | dy: " << dy << "\n";

            coordinates[count].dx = -5*dx;
            coordinates[count].dy = -5*dy;
        }

        coordinates[count].dx = 6;
        coordinates[count].dy = 0;
    }
    
    // Create and return 2D vector of shape ellipse
    std::vector<Data> genEllipse(double a, double b, double radius) 
    {
        // Equation: (x^2 / a^2) + (y^2 / b^2) = r^2
        // Equation (Parametric): x = rcos(t), y = rsin(t)
        // Domain: t = [-pi, pi]

        std::vector<Data> coordinates;

        // Circle
        for (double i = -3.f; i < 3.1f; i += 0.6)
        {
            double dx = radius * -std::sin(i);
            double dy = radius * std::cos(i);
            
            coordinates.push_back(Data((int)dx, (int)dy));
        }

        return coordinates;
    }
    
    std::vector<Data> genSimpleDiamond() 
    {
        // Creates simple diamond
        std::vector<Data> coordinates;

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