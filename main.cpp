#include <iostream>
#include <memory>
#include <utility>

// Абстрактный класс "Пассажироперевозчик"
class PassengerCarrier {
public:
    virtual ~PassengerCarrier() = default;

    virtual void transport_passengers() = 0;
};

// Класс "Самолет"
class Airplane final : public PassengerCarrier {
public:
    Airplane(std::string airline, const int capacity) : airline(std::move(airline)), capacity(capacity) {
        std::cout << "Creating an airplane." << std::endl;
    }

    void transport_passengers() override {
        std::cout << "Flying passengers in an airplane. Airline: " << airline << ", Capacity: " << capacity <<
                std::endl;
    }

private:
    std::string airline;
    int capacity;
};

// Класс "Поезд"
class Train final : public PassengerCarrier {
public:
    Train(std::string train_company, const int num_cars) : train_company(std::move(train_company)), num_cars(num_cars) {
        std::cout << "Creating a train." << std::endl;
    }

    void transport_passengers() override {
        std::cout << "Transporting passengers by train. Train Company: " << train_company << ", Number of Cars: " <<
                num_cars << std::endl;
    }

private:
    std::string train_company;
    int num_cars;
};

// Класс "Автомобиль"
class Car final : public PassengerCarrier {
public:
    Car(std::string car_brand, const int num_seats) : car_brand(std::move(car_brand)), num_seats(num_seats) {
        std::cout << "Creating a car." << std::endl;
    }

    void transport_passengers() override {
        std::cout << "Driving passengers in a car. Car Brand: " << car_brand << ", Number of Seats: " << num_seats <<
                std::endl;
    }

private:
    std::string car_brand;
    int num_seats;
};

int main() {
    const std::unique_ptr<PassengerCarrier> airplane = std::make_unique<Airplane>("Airline A", 200);
    const std::unique_ptr<PassengerCarrier> train = std::make_unique<Train>("Train Company X", 10);
    const std::unique_ptr<PassengerCarrier> car = std::make_unique<Car>("Brand Y", 4);

    airplane->transport_passengers();
    train->transport_passengers();
    car->transport_passengers();

    return 0;
}
