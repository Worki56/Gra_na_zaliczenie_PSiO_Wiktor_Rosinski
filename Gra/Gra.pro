 QT -= core
TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt
INCLUDEPATH += "C:/SFML-2.5.1/include"
SOURCES += \
        fun.cpp \
        ksztalt.cpp \
        kwadrat.cpp \
        main.cpp \
        plansza.cpp \
        ustalone.cpp


LIBS += -L"C:/SFML-2.5.1/lib"
LIBS += -lOpenGL32 -lglu32
CONFIG(debug, debug|release){
    LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-system-d -lsfml-window-d
} else {
    LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
}



HEADERS += \
    fun.hpp \
    ksztalt.hpp \
    kwadrat.hpp \
    plansza.hpp \
    ustalone.hpp \

