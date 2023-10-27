cmake_minimum_required(VERSION 3.5)

project(Tic-Tak-Toe VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Sql)
find_package(Qt6 REQUIRED COMPONENTS Network)

set(PROJECT_SOURCES

        widget.cpp
        widget.h
        widget.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Tic-Tak-Toe
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}

        mainmenu.h mainmenu.cpp
        mainmenu.h mainmenu.cpp mainmenu.ui
        mainmenu.h mainmenu.cpp mainmenu.ui
        registrationdialog.h registrationdialog.cpp registrationdialog.ui

        connectiondialog.h connectiondialog.cpp connectiondialog.ui
        creationdialog.h creationdialog.cpp creationdialog.ui
        client.h client.cpp
        profile.h profile.cpp
        main.cpp
        bitboard.h bitboard.cpp
        statdialog.h statdialog.cpp statdialog.ui
        revengedialog.h revengedialog.cpp revengedialog.ui
        res.rs

    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Tic-Tak-Toe APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Tic-Tak-Toe SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Tic-Tak-Toe
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(Tic-Tak-Toe PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(Tic-Tak-Toe PRIVATE Qt6::Sql)
target_link_libraries(Tic-Tak-Toe PRIVATE Qt6::Network)

set_target_properties(Tic-Tak-Toe PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS Tic-Tak-Toe
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Tic-Tak-Toe)
endif()
