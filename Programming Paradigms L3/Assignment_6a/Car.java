public class Car extends Vehicle {
    String model;
    int year;

    // Constructor to initialize brand, model, and year
    public Car(String brand, String model, int year) {
        // Using super to call the Vehicle constructor and initialize the brand
        super(brand);
        this.model = model;
        this.year = year;
    }

    // Method to display details including brand, model, and year
    public void displayDetails() {
        super.displayBrand();  // Call to Vehicle's displayBrand method
        System.out.println("Model: " + model);
        System.out.println("Year: " + year);
    }
}
