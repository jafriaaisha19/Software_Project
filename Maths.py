import math

class Maths:
    pass

class Algebra(Maths):
    def matrix(self):
        matrix = [
            [1, 2, 3],
            [4, 5, 6],
            [7, 8, 9]
        ]
        print("Matrix:")
        for row in matrix:
            print(" ".join(map(str, row)))

    def factorize_quadratic_equation(self):
        a = float(input("Enter coefficient a: "))
        b = float(input("Enter coefficient b: "))
        c = float(input("Enter coefficient c: "))

        discriminant = b**2 - 4 * a * c

        if discriminant < 0:
            print("The equation has complex roots.")
        elif discriminant == 0:
            root = -b / (2 * a)
            print(f"The equation has a repeated root: x = {root}")
        else:
            root1 = (-b + math.sqrt(discriminant)) / (2 * a)
            root2 = (-b - math.sqrt(discriminant)) / (2 * a)
            print(f"The roots of the equation are: x1 = {root1}, x2 = {root2}")


class Series(Maths):
    def generate_fibonacci_series(self):
        n = int(input("Enter the number of terms in the Fibonacci series: "))
        a, b = 0, 1
        print("Fibonacci Series:", end=" ")
        for _ in range(n):
            print(a, end=" ")
            a, b = b, a + b
        print()

    def generate_arithmetic_sequence(self):
        first_term = int(input("Enter the first term of the arithmetic sequence: "))
        common_difference = int(input("Enter the common difference: "))
        num_terms = int(input("Enter the number of terms in the arithmetic sequence: "))
        print("Arithmetic Sequence:", end=" ")
        for _ in range(num_terms):
            print(first_term, end=" ")
            first_term += common_difference
        print()

    def generate_geometric_sequence(self):
        first_term = int(input("Enter the first term of the geometric sequence: "))
        common_ratio = int(input("Enter the common ratio: "))
        num_terms = int(input("Enter the number of terms in the geometric sequence: "))
        print("Geometric Sequence:", end=" ")
        for _ in range(num_terms):
            print(first_term, end=" ")
            first_term *= common_ratio
        print()


class Statistics(Maths):
    def calculate_mean(self):
        num_data_points = int(input("Enter the number of data points: "))
        data_points = [float(input("Enter data point: ")) for _ in range(num_data_points)]
        mean = sum(data_points) / num_data_points
        print(f"Mean: {mean}")

    def calculate_mode(self):
        num_data_points = int(input("Enter the number of data points: "))
        data_points = [float(input("Enter data point: ")) for _ in range(num_data_points)]
        mode = max(set(data_points), key=data_points.count)
        print(f"Mode: {mode}")

    def calculate_variance(self):
        num_data_points = int(input("Enter the number of data points: "))
        data_points = [float(input("Enter data point: ")) for _ in range(num_data_points)]
        mean = sum(data_points) / num_data_points
        variance = sum((x - mean) ** 2 for x in data_points) / num_data_points
        print(f"Variance: {variance}")

    def calculate_median(self):
        num_data_points = int(input("Enter the number of data points: "))
        data_points = [float(input("Enter data point: ")) for _ in range(num_data_points)]
        sorted_data = sorted(data_points)
        n = len(sorted_data)
        median = (sorted_data[n // 2] + sorted_data[(n - 1) // 2]) / 2 if n % 2 == 0 else sorted_data[n // 2]
        print(f"Median: {median}")

    def calculate_standard_deviation(self):
        num_data_points = int(input("Enter the number of data points: "))
        data_points = [float(input("Enter data point: ")) for _ in range(num_data_points)]
        mean = sum(data_points) / num_data_points
        variance = sum((x - mean) ** 2 for x in data_points) / num_data_points
        standard_deviation = math.sqrt(variance)
        print(f"Standard Deviation: {standard_deviation}")


class Geometry(Maths):
    def calculate_circle_area(self):
        radius = float(input("Enter the radius of the circle: "))
        area = math.pi * radius ** 2
        print(f"Area of the circle: {area}")

    def calculate_cylinder_volume(self):
        radius = float(input("Enter the radius of the cylinder: "))
        height = float(input("Enter the height of the cylinder: "))
        volume = math.pi * radius ** 2 * height
        print(f"Volume of the cylinder: {volume}")

    def calculate_sphere_surface_area(self):
        radius = float(input("Enter the radius of the sphere: "))
        surface_area = 4 * math.pi * radius ** 2
        print(f"Surface Area of the sphere: {surface_area}")


if __name__ == "__main__":
    algebra = Algebra()
    geometry = Geometry()
    series = Series()
    statistics = Statistics()

    while True:
        print("\n1. Algebra\n2. Geometry\n3. Series\n4. Statistics\n5. Exit")
        choice = int(input("Enter your choice: "))

        if choice == 1:
            algebra.matrix()
            algebra.factorize_quadratic_equation()
        elif choice == 2:
            geometry.calculate_cylinder_volume()
            geometry.calculate_sphere_surface_area()
            geometry.calculate_circle_area()
        elif choice == 3:
            series.generate_fibonacci_series()
            series.generate_arithmetic_sequence()
            series.generate_geometric_sequence()
        elif choice == 4:
            statistics.calculate_mean()
            statistics.calculate_mode()
            statistics.calculate_variance()
            statistics.calculate_median()
            statistics.calculate_standard_deviation()
        elif choice == 5:
            print("Exiting...")
            break
        else:
            print("Invalid choice. Please Enter the correct choice")
