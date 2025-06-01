@echo off
set QTDIR=C:\Qt\6.9.0\msvc2022_64
set PATH=%QTDIR%\bin;%PATH%
set PATH=%QTDIR%\lib;%PATH%
set PATH=%QTDIR%\include;%PATH%

echo Qt environment set up for Qt 6.9.0 MSVC 2022 64-bit
echo Now you can run qmake and other Qt tools 