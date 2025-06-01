QT += core gui widgets charts opengl openglwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# CUDA configuration
CUDA_DIR = "C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v11.8"
CUDA_ARCH = sm_50
CUDA_INC = $$CUDA_DIR/include
CUDA_LIB = $$CUDA_DIR/lib/x64

TARGET = cvutil
TEMPLATE = app

SOURCES += \
    cvutil_core.cpp \
    cvutil_figure.cpp \
    MainWindow/BatchProcessor.cpp \
    MainWindow/FeatureExtractorThread.cpp \
    MainWindow/GraphicsScene.cpp \
    MainWindow/InteractiveExtractorThread.cpp \
    MainWindow/MainWindow.cpp

HEADERS += \
    MainWindow/BatchProcessor.h \
    MainWindow/FeatureExtractorThread.h \
    MainWindow/GraphicsScene.h \
    MainWindow/InteractiveExtractorThread.h \
    MainWindow/MainWindow.h

# Fix paths with spaces
CUDA_PATH = "C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v11.8"
OPENCV_PATH = "C:/opencv/build"
QT_PATH = "C:/Qt/6.9.0/msvc2022_64"

# Project include paths
INCLUDEPATH += \
    ../PluginManager/include \
    ../RoiManager/include \
    $$OPENCV_PATH/include \
    $$CUDA_PATH/include \
    $$CUDA_INC \
    $$QT_PATH/include \
    $$QT_PATH/include/QtCore \
    $$QT_PATH/include/QtGui \
    $$QT_PATH/include/QtWidgets \
    $$QT_PATH/include/QtCharts \
    $$QT_PATH/include/QtOpenGL \
    $$QT_PATH/include/QtOpenGLWidgets

LIBS += -L../build/PluginManager/lib -lPluginManager \
        -L../build/RoiManager/lib -lRoiManager \
        -L$$OPENCV_PATH/x64/vc15/lib -lopencv_world412 \
        -L$$CUDA_PATH/lib/x64 -lcudart \
        -L$$CUDA_LIB \
        -L$$QT_PATH/lib

# Qt6 specific settings
QT6_MAJOR_VERSION = 6
QT6_MINOR_VERSION = 9
QT6_PATCH_VERSION = 0

# Enable Qt6 features
CONFIG += qt6

# Additional compiler flags
QMAKE_CXXFLAGS += -D_CRT_SECURE_NO_WARNINGS
QMAKE_CXXFLAGS += -D_SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING

# Force include paths to be absolute
QMAKE_INCDIR_QT = $$QT_PATH/include
QMAKE_LIBDIR_QT = $$QT_PATH/lib 