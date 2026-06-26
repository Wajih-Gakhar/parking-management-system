#include <QApplication>
#include "parking_app.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    ParkingApp parkingApp;
    parkingApp.setWindowTitle("Parking Management System");
    parkingApp.resize(900, 600);
    parkingApp.show();

    return app.exec();
}
