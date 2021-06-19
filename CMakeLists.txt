cmake_minimum_required(VERSION 3.5)

if(WIN32)
    project(dvkbuntu-easy-menu VERSION "4.17")
else()
    project(dvkbuntu-easy-menu LANGUAGES CXX VERSION "4.17")
endif()

set(CMAKE_INCLUDE_CURRENT_DIR ON)

if(WIN32)
    set(CMAKE_PREFIX_PATH "C:\\Qt\\5.15.2\\msvc2019_64")
elseif(UNIX AND NOT APPLE)
    #set(CMAKE_PREFIX_PATH "/home/paul/Qt/5.15.2/gcc_64/lib/cmake")
else()
    set(CMAKE_PREFIX_PATH "/Users/paulw/Qt/5.15.2/clang_64/lib/cmake")
endif()

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

if(APPLE)
set(CMAKE_MACOSX_BUNDLE ON)
endif()

if (UNIX)
    set(CMAKE_CXX_STANDARD 14)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall -O2")
endif()

find_package(QT NAMES Qt5 COMPONENTS Core REQUIRED)
find_package(QT NAMES Qt5 COMPONENTS Gui REQUIRED)
find_package(QT NAMES Qt5 COMPONENTS Svg REQUIRED)
find_package(QT NAMES Qt5 COMPONENTS WebEngineWidgets REQUIRED)
find_package(QT NAMES Qt5 COMPONENTS Multimedia REQUIRED)
find_package(QT NAMES Qt5 COMPONENTS Widgets REQUIRED)
find_package(QT NAMES Qt5 COMPONENTS TextToSpeech REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Gui REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Svg REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS WebEngineWidgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Multimedia REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS TextToSpeech REQUIRED)

set(PROJECT_SOURCES
        src/main.cpp
        src/mainwindow.cpp
        src/mainwindow.h
        src/mainwindow.ui
        src/controlmenudiscord.cpp
        src/controlmenudiscord.h
        src/controlmenudiscord.ui
        src/controlmenuweb.cpp
        src/controlmenuweb.h
        src/controlmenuweb.ui
        src/controlmenumail.cpp
        src/controlmenumail.h
        src/controlmenumail.ui
        src/controlmenumusic.cpp
        src/controlmenumusic.h
        src/controlmenumusic.ui
        src/controlmenuoffice.cpp
        src/controlmenuoffice.h
        src/controlmenuoffice.ui
        src/controlmenucalc.cpp
        src/controlmenucalc.h
        src/controlmenucalc.ui
        src/controlmenumain.cpp
        src/controlmenumain.h
        src/controlmenumain.ui
        src/options.cpp
        src/options.h
        src/options.ui
        src/mywebenginepage.cpp
        src/mywebenginepage.h
        src/resource.qrc
        src/icon.rc)

if (WIN32)
    qt5_add_resources(src/icon.rc)
endif()

if(WIN32)
    SET(GUI_TYPE WIN32)
else()
    SET(GUI_TYPE )
endif()

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(dvkbuntu-easy-menu
            ${PROJECT_SOURCES}
            )
else()
    if(ANDROID)
        add_library(dvkbuntu-easy-menu SHARED
                ${PROJECT_SOURCES}
                )
    else()
        add_executable(dvkbuntu-easy-menu
                ${GUI_TYPE}
                ${PROJECT_SOURCES}
                )
    endif()
endif()

target_link_libraries(dvkbuntu-easy-menu
        PRIVATE
        Qt${QT_VERSION_MAJOR}::Core
        Qt${QT_VERSION_MAJOR}::Gui
        Qt${QT_VERSION_MAJOR}::Svg
        Qt${QT_VERSION_MAJOR}::WebEngineWidgets
        Qt${QT_VERSION_MAJOR}::Multimedia
        Qt${QT_VERSION_MAJOR}::Widgets
        Qt${QT_VERSION_MAJOR}::TextToSpeech)

if (UNIX AND NOT APPLE)
    install(TARGETS dvkbuntu-easy-menu
            RUNTIME DESTINATION bin)
    install(FILES src/dvkbuntu-easy-menu.desktop DESTINATION share/applications)
    install(FILES Images/dvkbuntu-easy-menu.svg DESTINATION share/icons/hicolor/scalable/apps)
    install(FILES Calculator/scripts/script.js DESTINATION share/Calculator/scripts)
    install(FILES Calculator/styles/dark.css DESTINATION share/Calculator/styles)
    install(FILES Calculator/styles/light.css DESTINATION share/Calculator/styles)
    install(FILES Calculator/index.html DESTINATION share/Calculator)
endif()
