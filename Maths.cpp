#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Algebra {
public:
    void matrix() {
        int matrix[3][3] = {
            { 1, 2, 3 },
            { 4, 5, 6 },
            { 7, 8, 9 }
        };

        cout << "Matrix:" << endl;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void factorizeQuadraticEquation() {
        double a, b, c;
        cout << "Enter coefficients for a quadratic equation ax^2 + bx + c:" << endl;
        cout << "Enter coefficient a: ";
        cin >> a;
        cout << "Enter coefficient b: ";
        cin >> b;
        cout << "Enter coefficient c: ";
        cin >> c;

        double discriminant = b * b - 4 * a * c;

        if (discriminant < 0) {
            cout << "The equation has complex roots." << endl;
        } else if (discriminant == 0) {
            double root = -b / (2 * a);
            cout << "The equation has a repeated root: x = " << root << endl;
        } else {
            double root1 = (-b + sqrt(discriminant)) / (2 * a);
            double root2 = (-b - sqrt(discriminant)) / (2 * a);
            cout << "The roots of the equation are: x1 = " << root1 << ", x2 = " << root2 << endl;
        }
    }
};

class Series {
public:
    void generateFibonacciSeries() {
        int n;
        cout << "Enter the number of terms in the Fibonacci series: ";
        cin >> n;

        int a = 0, b = 1;
        cout << "Fibonacci Series: ";
        for (int i = 0; i < n; i++) {
            cout << a << " ";
            int temp = a + b;
            a = b;
            b = temp;
        }
        cout << endl;
    }

    void generateArithmeticSequence() {
        int firstTerm, commonDifference, numTerms;
        cout << "Enter the first term of the arithmetic sequence: ";
        cin >> firstTerm;
        cout << "Enter the common difference: ";
        cin >> commonDifference;
        cout << "Enter the number of terms in the arithmetic sequence: ";
        cin >> numTerms;

        cout << "Arithmetic Sequence: ";
        for (int i = 0; i < numTerms; i++) {
            cout << firstTerm << " ";
            firstTerm += commonDifference;
        }
        cout << endl;
    }

    void generateGeometricSequence() {
        int firstTerm, commonRatio, numTerms;
        cout << "Enter the first term of the geometric sequence: ";
        cin >> firstTerm;
        cout << "Enter the common ratio: ";
        cin >> commonRatio;
        cout << "Enter the number of terms in the geometric sequence: ";
        cin >> numTerms;

        cout << "Geometric Sequence: ";
        for (int i = 0; i < numTerms; i++) {
            cout << firstTerm << " ";
            firstTerm *= commonRatio;
        }
        cout << endl;
    }
};

class Statistics {
public:
    void calculateMean() {
        int numDataPoints;
        cout << "Enter the number of data points: ";
        cin >> numDataPoints;

        vector<double> dataPoints(numDataPoints);
        cout << "Enter the data points: ";
        for (int i = 0; i < numDataPoints; i++) {
            cin >> dataPoints[i];
        }

        double mean = accumulate(dataPoints.begin(), dataPoints.end(), 0.0) / numDataPoints;
        cout << "Mean: " << mean << endl;
    }

    void calculateMode() {
        int numDataPoints;
        cout << "Enter the number of data points: ";
        cin >> numDataPoints;

        vector<double> dataPoints(numDataPoints);
        cout << "Enter the data points: ";
        for (int i = 0; i < numDataPoints; i++) {
            cin >> dataPoints[i];
        }

        double mode = calculateModeValue(dataPoints);
        cout << "Mode: " << mode << endl;
    }

    double calculateModeValue(vector<double>& data) {
        sort(data.begin(), data.end());
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
        cout << "Enter the number of data points: ";
        cin >> numDataPoints;

        vector<double> dataPoints(numDataPoints);
        cout << "Enter the data points: ";
        for (int i = 0; i < numDataPoints; i++) {
            cin >> dataPoints[i];
        }

        double mean = accumulate(dataPoints.begin(), dataPoints.end(), 0.0) / numDataPoints;
        double variance = accumulate(dataPoints.begin(), dataPoints.end(), 0.0, [mean](double partial_sum, double val) {
            return partial_sum + pow(val - mean, 2);
        }) / numDataPoints;

        cout << "Variance: " << variance << endl;
    }

    void calculateMedian() {
        int numDataPoints;
        cout << "Enter the number of data points: ";
        cin >> numDataPoints;

        vector<double> dataPoints(numDataPoints);
        cout << "Enter the data points: ";
        for (int i = 0; i < numDataPoints; i++) {
            cin >> dataPoints[i];
        }

        sort(dataPoints.begin(), dataPoints.end());
        double median;
        if (numDataPoints % 2 == 0)
            median = (dataPoints[numDataPoints / 2 - 1] + dataPoints[numDataPoints / 2]) / 2.0;
        else
            median = dataPoints[numDataPoints / 2];

        cout << "Median: " << median << endl;
    }

    void calculateStandardDeviation() {
        int numDataPoints;
        cout << "Enter the number of data points: ";
        cin >> numDataPoints;

        vector<double> dataPoints(numDataPoints);
        cout << "Enter the data points: ";
        for (int i = 0; i < numDataPoints; i++) {
            cin >> dataPoints[i];
        }

        double mean = accumulate(dataPoints.begin(), dataPoints.end(), 0.0) / numDataPoints;
        double standardDeviation = sqrt(accumulate(dataPoints.begin(), dataPoints.end(), 0.0, [mean](double partial_sum, double val) {
            return partial_sum + pow(val - mean, 2);
        }) / numDataPoints);

        cout << "Standard Deviation: " << standardDeviation << endl;
    }
};

class Geometry {
public:
    void calculateCircleArea() {
        double radius;
        cout << "Enter the radius of the circle: ";
        cin >> radius;
        double area = M_PI * pow(radius, 2);
        cout << "Area of the circle: " << area << endl;
    }

    void calculateCylinderVolume() {
        double radius, height;
        cout << "Enter the radius of the cylinder: ";
        cin >> radius;
        cout << "Enter the height of the cylinder: ";
        cin >> height;
        double volume = M_PI * pow(radius, 2) * height;
        cout << "Volume of the cylinder: " << volume << endl;
    }

    void calculateSphereSurfaceArea() {
        double radius;
        cout << "Enter the radius of the sphere: ";
        cin >> radius;
        double surfaceArea = 4 * M_PI * pow(radius, 2);
        cout << "Surface Area of the sphere: " << surfaceArea << endl;
    }
};

int main() {
    Algebra algebra;
    Geometry geometry;
    Series series;
    Statistics statistics;

    int choice;

    while (true) {
        cout << "\n1. Algebra\n2. Geometry\n3. Series\n4. Statistics\n5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

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
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please Enter the correct choice" << endl;
            break;
        }
    }

    return 0;
}
