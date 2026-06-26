#include "parking_app.h"
#include <QMessageBox>

ParkingApp::ParkingApp(QWidget *parent) : QWidget(parent), parking() {
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QLabel *statusLabel = new QLabel("Welcome to Parking Management System", this);
    statusLabel->setAlignment(Qt::AlignCenter);
    statusLabel->setObjectName("statusLabel"); // Set object name for styling
    mainLayout->addWidget(statusLabel);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    QPushButton *bikeButton = new QPushButton("Park Bike", this);
    QPushButton *rickshawButton = new QPushButton("Park Rickshaw", this);
    QPushButton *carButton = new QPushButton("Park Car", this);
    QPushButton *busButton = new QPushButton("Park Bus", this);
    buttonLayout->addWidget(bikeButton);
    buttonLayout->addWidget(rickshawButton);
    buttonLayout->addWidget(carButton);
    buttonLayout->addWidget(busButton);
    mainLayout->addLayout(buttonLayout);

    QPushButton *displayButton = new QPushButton("Show Data", this);
    QPushButton *resetButton = new QPushButton("Reset Data", this);
    QPushButton *saveButton = new QPushButton("Save Data", this);
    QPushButton *loadButton = new QPushButton("Load Data", this);
    mainLayout->addWidget(displayButton);
    mainLayout->addWidget(resetButton);
    mainLayout->addWidget(saveButton);
    mainLayout->addWidget(loadButton);

    connect(bikeButton, &QPushButton::clicked, this, [=]() {
        parking.parkVehicle(1, statusLabel);
    });
    connect(rickshawButton, &QPushButton::clicked, this, [=]() {
        parking.parkVehicle(2, statusLabel);
    });
    connect(carButton, &QPushButton::clicked, this, [=]() {
        parking.parkVehicle(3, statusLabel);
    });
    connect(busButton, &QPushButton::clicked, this, [=]() {
        parking.parkVehicle(4, statusLabel);
    });
    connect(displayButton, &QPushButton::clicked, this, [=]() {
        QMessageBox::information(this, "Parking Data", parking.displayData());
    });
    connect(resetButton, &QPushButton::clicked, this, [=]() {
        parking.resetData(statusLabel);
    });
    connect(saveButton, &QPushButton::clicked, this, [=]() {
        parking.saveData();
        statusLabel->setText("Data saved successfully.");
    });
    connect(loadButton, &QPushButton::clicked, this, [=]() {
        parking.loadData(statusLabel);
    });

    animateWidget(statusLabel);

    // Apply styles
    setStyles();
}

void ParkingApp::animateWidget(QWidget *widget) {
    // Set the minimum size for the status label to ensure the text fits
    widget->setMinimumSize(500, 50); // Adjust size according to your needs

    QPropertyAnimation *animation = new QPropertyAnimation(widget, "geometry");
    animation->setDuration(1000);
    animation->setStartValue(QRect(0, 0, 200, 50));  // Start with a smaller width
    animation->setEndValue(QRect(50, 50, 400, 50));  // End with a larger width to fit the text
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}


void ParkingApp::setStyles() {
    // Set application-level stylesheet
    this->setStyleSheet(
        "QWidget { background-color: #282C34; }"
        "QLabel#statusLabel { "
        "   color: #61AFEF; "
        "   font-size: 20px; "
        "   font-weight: bold; "
        "   margin: 10px; "
        "}"
        "QPushButton { "
        "   background-color: #98C379; "
        "   color: #FFFFFF; "
        "   font-size: 16px; "
        "   border-radius: 8px; "
        "   padding: 8px; "
        "   margin: 5px; "
        "}"
        "QPushButton:hover { "
        "   background-color: #56B6C2; "
        "}"
        "QPushButton:pressed { "
        "   background-color: #E06C75; "
        "}"
        );
}
