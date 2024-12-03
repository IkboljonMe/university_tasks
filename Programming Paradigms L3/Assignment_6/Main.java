abstract class Employee {
    String name;
    String designation;

    public Employee(String name, String designation) {
        this.name = name;
        this.designation = designation;
    }

    abstract double calculateSalary();

    public void getDetails() {
        System.out.println("Name: " + name + ", Designation: " + designation);
    }
}

class FullTimeEmployee extends Employee {
    double baseSalary;
    double bonuses;

    public FullTimeEmployee(String name, String designation, double baseSalary, double bonuses) {
        super(name, designation);
        this.baseSalary = baseSalary;
        this.bonuses = bonuses;
    }

    @Override
    double calculateSalary() {
        return baseSalary + bonuses;
    }
}

class ContractEmployee extends Employee {
    double hourlyRate;
    int hoursWorked;

    public ContractEmployee(String name, String designation, double hourlyRate, int hoursWorked) {
        super(name, designation);
        this.hourlyRate = hourlyRate;
        this.hoursWorked = hoursWorked;
    }

    @Override
    double calculateSalary() {
        return hourlyRate * hoursWorked;
    }
}

public class Main {
    public static void main(String[] args) {
        Employee[] employees = new Employee[2];
        employees[0] = new FullTimeEmployee("Alice", "Manager", 50000, 10000);
        employees[1] = new ContractEmployee("Bob", "Developer", 50, 160);

        for (Employee employee : employees) {
            employee.getDetails();
            System.out.println("Salary: " + employee.calculateSalary());
            System.out.println();
        }
    }
}
