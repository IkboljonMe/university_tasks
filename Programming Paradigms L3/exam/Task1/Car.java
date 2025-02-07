class Car {
    String brand;
    String model;
    int year;

    Car(String brand, String model, int year){
        this.brand = brand;
        this.model = model;
        this.year = year;
    }
    void display(){
        System.out.println("Brand:"+brand+", Model:" +model+", Year :" +year);
    }
    public static void main(String[] args){
        Car myCar = new Car("Toyota","Prius", 2015);
        myCar.display();
    }
}