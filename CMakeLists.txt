cmake_minimum_required(VERSION 3.12)
project(Duplicates)

set(Qt5Core_DIR "/usr/local/opt/qt/lib/cmake/Qt5Core/")
find_package(Qt5Core REQUIRED)
set(Qt5Widgets_DIR "/usr/local/opt/qt/lib/cmake/Qt5Widgets/")
find_package(Qt5Widgets REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I/usr/local/opt/qt/include")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_executable(Duplicates main.cpp
        gui/GuiConstants.h
        gui/MainWindow.cpp gui/MainWindow.h
        core/Visitor.cpp core/Visitor.h core/Stats.cpp core/Stats.h core/Log.h)
target_link_libraries(Duplicates Qt5::Widgets)