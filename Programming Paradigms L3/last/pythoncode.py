# 1. Class and Object
class Student:
    def __init__(self, name, roll_number, marks):
        self.name = name
        self.roll_number = roll_number
        self.marks = marks  # Dictionary with subject names as keys

    def calculate_average(self):
        return sum(self.marks.values()) / len(self.marks)

    def display_details(self):
        print(f"Name: {self.name}, Roll Number: {self.roll_number}, Marks: {self.marks}")

    def update_marks(self, subject, new_marks):
        if subject in self.marks:
            self.marks[subject] = new_marks
        else:
            print(f"Subject {subject} not found.")

# Example usage
student = Student("John", 101, {"Math": 85, "Science": 90, "English": 88})
student.display_details()
print("Average Marks:", student.calculate_average())
student.update_marks("Math", 95)
student.display_details()


# 2. Encapsulation
class SecureVault:
    def __init__(self):
        self.__passwords = []

    def add_password(self, password):
        self.__passwords.append(password)

    def validate_password(self, password):
        return password in self.__passwords

# Example usage
vault = SecureVault()
vault.add_password("secure123")
print(vault.validate_password("secure123"))
print(vault.validate_password("wrongpassword"))


# 3. Inheritance
class Vehicle:
    def __init__(self, make, model, year):
        self.make = make
        self.model = model
        self.year = year

    def display_info(self):
        print(f"Make: {self.make}, Model: {self.model}, Year: {self.year}")

class Car(Vehicle):
    def __init__(self, make, model, year, seating_capacity):
        super().__init__(make, model, year)
        self.seating_capacity = seating_capacity

    def display_info(self):
        super().display_info()
        print(f"Seating Capacity: {self.seating_capacity}")

class Bike(Vehicle):
    def __init__(self, make, model, year, bike_type):
        super().__init__(make, model, year)
        self.bike_type = bike_type

    def display_info(self):
        super().display_info()
        print(f"Bike Type: {self.bike_type}")

class Truck(Vehicle):
    def __init__(self, make, model, year, load_capacity):
        super().__init__(make, model, year)
        self.load_capacity = load_capacity

    def display_info(self):
        super().display_info()
        print(f"Load Capacity: {self.load_capacity} tons")

# Example usage
car = Car("Toyota", "Camry", 2020, 5)
car.display_info()


# 4. Polymorphism
from abc import ABC, abstractmethod

class Employee(ABC):
    @abstractmethod
    def calculate_salary(self):
        pass

class FullTimeEmployee(Employee):
    def __init__(self, monthly_salary):
        self.monthly_salary = monthly_salary

    def calculate_salary(self):
        return self.monthly_salary

class PartTimeEmployee(Employee):
    def __init__(self, hourly_rate, hours_worked):
        self.hourly_rate = hourly_rate
        self.hours_worked = hours_worked

    def calculate_salary(self):
        return self.hourly_rate * self.hours_worked

class Freelancer(Employee):
    def __init__(self, project_rate):
        self.project_rate = project_rate

    def calculate_salary(self):
        return self.project_rate

# Example usage
employees = [
    FullTimeEmployee(3000),
    PartTimeEmployee(20, 80),
    Freelancer(500)
]

for employee in employees:
    print(employee.calculate_salary())


# 5. Abstraction
from abc import ABC, abstractmethod

class Appliance(ABC):
    @abstractmethod
    def turn_on(self):
        pass

    @abstractmethod
    def turn_off(self):
        pass

class WashingMachine(Appliance):
    def turn_on(self):
        print("Washing Machine is now ON.")

    def turn_off(self):
        print("Washing Machine is now OFF.")

class Refrigerator(Appliance):
    def turn_on(self):
        print("Refrigerator is now ON.")

    def turn_off(self):
        print("Refrigerator is now OFF.")

class AirConditioner(Appliance):
    def turn_on(self):
        print("Air Conditioner is now ON.")

    def turn_off(self):
        print("Air Conditioner is now OFF.")

# Example usage
appliances = [WashingMachine(), Refrigerator(), AirConditioner()]

for appliance in appliances:
    appliance.turn_on()
    appliance.turn_off()
