
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

class Algebra;
class Geometry;
class Series;
class Statistics;

class Maths {
public:
    void run() {
        Algebra algebra;
        Geometry geometry;
        Series series;
        Statistics statistics;

        int choice;

        while (true) {
            std::cout << "\n1. Algebra\n2. Geometry\n3. Series\n4. Statistics\n5. Exit" << std::endl;
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice) {
                case 1:
                    algebra.matrix();
                    algebra.factorizeQuadraticEquation();
                    break;
                case 2:
                    geometry.calculateCylinderVolume();
                    geometry.calculateSphereSurfaceArea();
                    geometry.calculateCircleArea();
                    break;
                case 3:
                    series.generateFibonacciSeries();
                    series.generateArithmeticSequence();
                    series.generateGeometricSequence();
                    break;
                case 4:
                    statistics.calculateMean();
                    statistics.calculateMode();
                    statistics.calculateVariance();
                    statistics.calculateMedian();
                    statistics.calculateStandardDeviation();
                    break;
                case 5:
                    std::cout << "Exiting..." << std::endl;
                    return;
                default:
                    std::cout << "Invalid choice. Please Enter the correct choice" << std::endl;
                    break;
            }
        }
    }
};

class Algebra : public Maths {
public:
    void matrix() {
        const int matrix[3][3] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };

        std::cout << "Matrix:" << std::endl;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    void factorizeQuadraticEquation() {
        double a, b, c;

        std::cout << "Enter coefficients for a quadratic equation ax^2 + bx + c:" << std::endl;
        std::cout << "Enter coefficient a: ";
        std::cin >> a;
        std::cout << "Enter coefficient b: ";
        std::cin >> b;
        std::cout << "Enter coefficient c: ";
        std::cin >> c;

        double discriminant = b * b - 4 * a * c;

        if (discriminant < 0) {
            std::cout << "The equation has complex roots." << std::endl;
        } else if (discriminant == 0) {
            double root = -b / (2 * a);
            std::cout << "The equation has a repeated root: x = " << root << std::endl;
        } else {
            double root1 = (-b + sqrt(discriminant)) / (2 * a);
            double root2 = (-b - sqrt(discriminant)) / (2 * a);
            std::cout << "The roots of the equation are: x1 = " << root1 << ", x2 = " << root2 << std::endl;
        }
    }
};

class Series : public Maths {
public:
    void generateFibonacciSeries() {
        int n;

        std::cout << "Enter the number of terms in the Fibonacci series: ";
        std::cin >> n;

        int a = 0, b = 1;
        std::cout << "Fibonacci Series: ";
        for (int i = 0; i < n; i++) {
            std::cout << a << " ";
            int temp = a + b;
            a = b;
            b = temp;
        }
        std::cout << std::endl;
    }

    void generateArithmeticSequence() {
        int firstTerm, commonDifference, numTerms;

        std::cout << "Enter the first term of the arithmetic sequence: ";
        std::cin >> firstTerm;
        std::cout << "Enter the common difference: ";
        std::cin >> commonDifference;
        std::cout << "Enter the number of terms in the arithmetic sequence: ";
        std::cin >> numTerms;

        std::cout << "Arithmetic Sequence: ";
        for (int i = 0; i < numTerms; i++) {
            std::cout << firstTerm << " ";
            firstTerm += commonDifference;
        }
        std::cout << std::endl;
    }

    void generateGeometricSequence() {
        int firstTerm, commonRatio, numTerms;

        std::cout << "Enter the first term of the geometric sequence: ";
        std::cin >> firstTerm;
        std::cout << "Enter the common ratio: ";
        std::cin >> commonRatio;
        std::cout << "Enter the number of terms in the geometric sequence: ";
        std::cin >> numTerms;

        std::cout << "Geometric Sequence: ";
        for (int i = 0; i < numTerms; i++) {
            std::cout << firstTerm << " ";
            firstTerm *= commonRatio;
        }
        std::cout << std::endl;
    }
};

class Statistics : public Maths {
public:
    void calculateMean() {
        int numDataPoints;

        std::cout << "Enter the number of data points: ";
        std::cin >> numDataPoints;

        std::vector<double> dataPoints(numDataPoints);
        std::cout << "Enter the data points: ";
        for (int i = 0; i < numDataPoints; i++) {
            std::cin >> dataPoints[i];
        }

        double mean = std::accumulate(dataPoints.begin(), dataPoints.end(), 0.0) / numDataPoints;
        std::cout << "Mean: " << mean << std::endl;
    }

    void calculateMode() {
        int numDataPoints;

        std::cout << "Enter the number of data points: ";
        std::cin >> numDataPoints;

        std::vector<double> dataPoints(numDataPoints);
        std::cout << "Enter the data points: ";
        for (int i = 0; i < numDataPoints; i++) {
            std::cin >> dataPoints[i];
        }

        double mode = calculateModeValue(dataPoints);
        std::cout << "Mode: " << mode << std::endl;
    }

    double calculateModeValue(std::vector<double>& data) {
        double mode = data[0];
        int maxCount = 1;

        for (int i = 0; i < data.size(); i++) {
            double value = data[i];
            int count = 1;

            for (int j = i + 1; j < data.size(); j++) {
                if (data[j] == value) {
                    count++;
                }
            }

            if (count > maxCount) {
                mode = value;
                maxCount = count;
            }
        }

        return mode;
    }

    void calculateVariance() {
        int numDataPoints;

        std::cout << "Enter the number of data points: ";
        std::cin >> numDataPoints;

        std::vector<double> dataPoints(numDataPoints);
        std::cout << "Enter the data points: ";
        for (int i = 0; i < numDataPoints; i++) {
            std::cin >> dataPoints[i];
        }

        double mean = std::accumulate(dataPoints.begin(), dataPoints.end(), 0.0) / numDataPoints;
        double variance = std::accumulate(dataPoints.begin(), dataPoints.end(), 0.0, 
            [mean](double acc, double x) { return acc + pow(x - mean, 2); }) / numDataPoints;

        std::cout << "Variance: " << variance << std::endl;
    }

    void calculateMedian() {
        int numDataPoints;

        std::cout << "Enter the number of data points: ";
        std::cin >> numDataPoints;

        std::vector<double> dataPoints(numDataPoints);
        std::cout << "Enter the data points: ";
        for (int i = 0; i < numDataPoints; i++) {
            std::cin >> dataPoints[i];
        }

        double median = calculateMedianValue(dataPoints);
        std::cout << "Median: " << median << std::endl;
    }

    double calculateMedianValue(std::vector<double>& data) {
        std::sort(data.begin(), data.end());
        int n = data.size();
        return n % 2 == 0 ? (data[n / 2 - 1] + data[n / 2]) / 2.0 : data[n / 2];
    }

    void calculateStandardDeviation() {
        int numDataPoints;

        std::cout << "Enter the number of data points: ";
        std::cin >> numDataPoints;

        std::vector<double> dataPoints(numDataPoints);
        std::cout << "Enter the data points: ";
        for (int i = 0; i < numDataPoints; i++) {
            std::cin >> dataPoints[i];
        }

        double mean = std::accumulate(dataPoints.begin(), dataPoints.end(), 0.0) / numDataPoints;
        double variance = std::accumulate(dataPoints.begin(), dataPoints.end(), 0.0,
            [mean](double acc, double x) { return acc + pow(x - mean, 2); }) / numDataPoints;

        double standardDeviation = sqrt(variance);
        std::cout << "Standard Deviation: " << standardDeviation << std::endl;
    }
};

class Geometry : public Maths {
public:
    void calculateCircleArea() {
        double radius;

        std::cout << "Enter the radius of the circle: ";
        std::cin >> radius;

        double area = M_PI * pow(radius, 2);
        std::cout << "Area of the circle: " << area << std::endl;
    }

    void calculateCylinderVolume() {
        double radius, height;

        std::cout << "Enter the radius of the cylinder: ";
        std::cin >> radius;
        std::cout << "Enter the height of the cylinder: ";
        std::cin >> height;

        double volume = M_PI * pow(radius, 2) * height;
        std::cout << "Volume of the cylinder: " << volume << std::endl;
    }

    void calculateSphereSurfaceArea() {
        double radius;

        std::cout << "Enter the radius of the sphere: ";
        std::cin >> radius;

        double surfaceArea = 4 * M_PI * pow(radius, 2);
        std::cout << "Surface Area of the sphere: " << surfaceArea << std::endl;
    }
};

int main() {
    Maths math;
    math.run();

    return 0;
}
