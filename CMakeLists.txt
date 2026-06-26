cmake_minimum_required(VERSION 3.16)

project(Parking_Management_System VERSION 0.1 LANGUAGES CXX)

# Enable automatic handling of Qt-specific files
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Qt libraries
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

# Define source and header files
set(PROJECT_SOURCES
    main.cpp
    parking_app.cpp
    parking_app.h
    parking_data.cpp
    parking_data.h
)

# Handle executable creation based on Qt version
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Parking_Management_System
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    add_executable(Parking_Management_System
        ${PROJECT_SOURCES}
    )
endif()

# Link Qt libraries to the project
target_link_libraries(Parking_Management_System PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Install the executable
install(TARGETS Parking_Management_System
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Finalize executable for Qt 6
if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Parking_Management_System)
endif()
