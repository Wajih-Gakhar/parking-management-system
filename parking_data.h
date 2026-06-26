#ifndef PARKING_DATA_H
#define PARKING_DATA_H

#include <QLabel>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class ParkingData {
public:
    ParkingData();

    void parkVehicle(int vehicleType, QLabel *statusLabel);
    QString displayData() const;
    void resetData(QLabel *statusLabel);
    void saveData() const;
    void loadData(QLabel *statusLabel);

private:
    int number;
    int amount;
    int bike;
    int rickshaw;
    int car;
    int bus;
};

#endif // PARKING_DATA_H
