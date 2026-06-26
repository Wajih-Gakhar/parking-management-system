#ifndef PARKING_APP_H
#define PARKING_APP_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QPropertyAnimation>
#include "parking_data.h"

class ParkingApp : public QWidget {
    Q_OBJECT

public:
    explicit ParkingApp(QWidget *parent = nullptr);

private:
    ParkingData parking;

    void animateWidget(QWidget *widget);
    void setStyles(); // Apply custom styles
};

#endif // PARKING_APP_H
