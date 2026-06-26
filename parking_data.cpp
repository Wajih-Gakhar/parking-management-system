#include "parking_data.h"
#include <QFile>
#include <QTextStream>

ParkingData::ParkingData() : number(0), amount(0), bike(0), rickshaw(0), car(0), bus(0) {}

void ParkingData::parkVehicle(int vehicleType, QLabel *statusLabel) {
    if (number < 50) {
        number++;
        switch (vehicleType) {
        case 1:
            bike++;
            amount += 50;
            statusLabel->setText("Bike is parked.");
            break;
        case 2:
            rickshaw++;
            amount += 100;
            statusLabel->setText("Rickshaw is parked.");
            break;
        case 3:
            car++;
            amount += 150;
            statusLabel->setText("Car is parked.");
            break;
        case 4:
            bus++;
            amount += 200;
            statusLabel->setText("Bus is parked.");
            break;
        default:
            statusLabel->setText("Invalid vehicle type.");
        }
    } else {
        statusLabel->setText("Parking is full.");
    }
}

QString ParkingData::displayData() const {
    QString data;
    data += "<font color='white'>Total Amount = " + QString::number(amount) + "</font><br>";
    data += "<font color='white'>Number of vehicles = " + QString::number(number) + "</font><br>";
    data += "<font color='white'>Number of Bikes = " + QString::number(bike) + "</font><br>";
    data += "<font color='white'>Number of Rickshaws = " + QString::number(rickshaw) + "</font><br>";
    data += "<font color='white'>Number of Cars = " + QString::number(car) + "</font><br>";
    data += "<font color='white'>Number of Buses = " + QString::number(bus) + "</font><br>";
    return data;
}

void ParkingData::resetData(QLabel *statusLabel) {
    amount = 0;
    number = 0;
    bike = 0;
    rickshaw = 0;
    car = 0;
    bus = 0;
    statusLabel->setText("RECORD DELETED");
}

void ParkingData::saveData() const {
    QFile file("parking_data.txt");
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream out(&file);
        out << number << "\n" << amount << "\n"
            << bike << "\n" << rickshaw << "\n"
            << car << "\n" << bus << "\n";
        file.close();
    }
}

void ParkingData::loadData(QLabel *statusLabel) {
    QFile file("parking_data.txt");
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream in(&file);
        in >> number >> amount >> bike >> rickshaw >> car >> bus;
        file.close();
        statusLabel->setText("Data loaded successfully.");
    } else {
        statusLabel->setText("No data to load.");
    }
}
