import java.util.Scanner;
import java.util.Arrays;


public class Maths {
    public static void main(String[] args) {
        Algebra algebra = new Algebra();
        Geometry geometry = new Geometry();
        Series series = new Series();
        Statistics statistics = new Statistics();
        Scanner sc = new Scanner(System.in);

        int choice;

        while (true) {
            System.out.println("\n1. Algebra\n2. Geometry\n3. Series\n4. Statistics\n5. Exit");
            System.out.print("Enter your choice: ");
            choice = sc.nextInt();

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
                    System.out.println("Exiting...");
                    System.exit(0);
                    break;
                default:
                    System.out.println("Invalid choice. Please Enter the correct choice");
                    break;
            }
        }
    }
}


class Algebra extends Maths
{
    public void matrix() {
        final int[][] matrix = {
            { 1, 2, 3 },
            { 4, 5, 6 },
            { 7, 8, 9 }
        };

        System.out.println("Matrix:");
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
    }

    public void factorizeQuadraticEquation() {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter coefficients for a quadratic equation ax^2 + bx + c:");
        System.out.print("Enter coefficient a: ");
        double a = sc.nextDouble();
        System.out.print("Enter coefficient b: ");
        double b = sc.nextDouble();
        System.out.print("Enter coefficient c: ");
        double c = sc.nextDouble();

        double discriminant = b * b - 4 * a * c;

        if (discriminant < 0) {
            System.out.println("The equation has complex roots.");
        } else if (discriminant == 0) {
            double root = -b / (2 * a);
            System.out.println("The equation has a repeated root: x = " + root);
        } else {
            double root1 = (-b + Math.sqrt(discriminant)) / (2 * a);
            double root2 = (-b - Math.sqrt(discriminant)) / (2 * a);
            System.out.println("The roots of the equation are: x1 = " + root1 + ", x2 = " + root2);
        }
    }
}


class Series extends Maths
{
    public void generateFibonacciSeries() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of terms in the Fibonacci series: ");
        int n = sc.nextInt();

        int a = 0, b = 1;
        System.out.print("Fibonacci Series: ");
        for (int i = 0; i < n; i++) {
            System.out.print(a + " ");
            int temp = a + b;
            a = b;
            b = temp;
        }
        System.out.println();
    }

    public void generateArithmeticSequence() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the first term of the arithmetic sequence: ");
        int firstTerm = sc.nextInt();
        System.out.print("Enter the common difference: ");
        int commonDifference = sc.nextInt();
        System.out.print("Enter the number of terms in the arithmetic sequence: ");
        int numTerms = sc.nextInt();

        System.out.print("Arithmetic Sequence: ");
        for (int i = 0; i < numTerms; i++) {
            System.out.print(firstTerm + " ");
            firstTerm += commonDifference;
        }
        System.out.println();
    }

    public void generateGeometricSequence() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the first term of the geometric sequence: ");
        int firstTerm = sc.nextInt();
        System.out.println("Enter the common ratio: ");
        int commonRatio = sc.nextInt();
        System.out.println("Enter the number of terms in the geometric sequence: ");
        int numTerms = sc.nextInt();

        System.out.print("Geometric Sequence: ");
        for (int i = 0; i < numTerms; i++) {
            System.out.print(firstTerm + " ");
            firstTerm *= commonRatio;
        }
        System.out.println();
    }
}

class Statistics extends Maths
{
    public void calculateMean() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of data points: ");
        int numDataPoints = sc.nextInt();

        double[] dataPoints = new double[numDataPoints];
        System.out.print("Enter the data points: ");
        for (int i = 0; i < numDataPoints; i++) {
            dataPoints[i] = sc.nextDouble();
        }

        double mean = Arrays.stream(dataPoints).average().orElse(0);
        System.out.println("Mean: " + mean);
    }

    public void calculateMode() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of data points: ");
        int numDataPoints = sc.nextInt();

        double[] dataPoints = new double[numDataPoints];
        System.out.print("Enter the data points: ");
        for (int i = 0; i < numDataPoints; i++) {
            dataPoints[i] = sc.nextDouble();
        }

        double mode = calculateModeValue(dataPoints);
        System.out.println("Mode: " + mode);
    }

    private double calculateModeValue(double[] data) {
        double mode = data[0];
        int maxCount = 1;

        for (int i = 0; i < data.length; i++) {
            double value = data[i];
            int count = 1;

            for (int j = i + 1; j < data.length; j++) {
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

    public void calculateVariance() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of data points: ");
        int numDataPoints = sc.nextInt();

        double[] dataPoints = new double[numDataPoints];
        System.out.print("Enter the data points: ");
        for (int i = 0; i < numDataPoints; i++) {
            dataPoints[i] = sc.nextDouble();
        }

        double variance = Arrays.stream(dataPoints).map(x -> Math.pow(x - calculateMeanValue(dataPoints), 2)).average().orElse(0);
        System.out.println("Variance: " + variance);
    }

    public void calculateMedian() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of data points: ");
        int numDataPoints = sc.nextInt();

        double[] dataPoints = new double[numDataPoints];
        System.out.print("Enter the data points: ");
        for (int i = 0; i < numDataPoints; i++) {
            dataPoints[i] = sc.nextDouble();
        }

        double median = calculateMedianValue(dataPoints);
        System.out.println("Median: " + median);
    }

    private double calculateMedianValue(double[] data) {
        Arrays.sort(data);
        int n = data.length;
        return n % 2 == 0 ? (data[n / 2 - 1] + data[n / 2]) / 2.0 : data[n / 2];
    }

    public void calculateStandardDeviation() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of data points: ");
        int numDataPoints = sc.nextInt();

        double[] dataPoints = new double[numDataPoints];
        System.out.print("Enter the data points: ");
        for (int i = 0; i < numDataPoints; i++) {
            dataPoints[i] = sc.nextDouble();
        }

        double standardDeviation = Math.sqrt(Arrays.stream(dataPoints).map(x -> Math.pow(x - calculateMeanValue(dataPoints), 2)).average().orElse(0));
        System.out.println("Standard Deviation: " + standardDeviation);
    }

    private double calculateMeanValue(double[] data) {
        return Arrays.stream(data).average().orElse(0);
    }
}


class Geometry extends Maths
{
    public void calculateCircleArea() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the radius of the circle: ");
        double radius = sc.nextDouble();
        double area = Math.PI * Math.pow(radius, 2);
        System.out.println("Area of the circle: " + area);
    }

    public void calculateCylinderVolume() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the radius of the cylinder: ");
        double radius = sc.nextDouble();
        System.out.print("Enter the height of the cylinder: ");
        double height = sc.nextDouble();
        double volume = Math.PI * Math.pow(radius, 2) * height;
        System.out.println("Volume of the cylinder: " + volume);
    }

    public void calculateSphereSurfaceArea() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the radius of the sphere: ");
        double radius = sc.nextDouble();
        double surfaceArea = 4 * Math.PI * Math.pow(radius, 2);
        System.out.println("Surface Area of the sphere: " + surfaceArea);
    }
}

