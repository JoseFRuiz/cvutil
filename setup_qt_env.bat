@echo off
set QTDIR=C:\Qt\6.9.0\msvc2022_64
set PATH=%QTDIR%\bin;%PATH%
set INCLUDE=%QTDIR%\include;%INCLUDE%
set LIB=%QTDIR%\lib;%LIB%

echo Qt environment variables have been set:
echo QTDIR=%QTDIR%
echo PATH has been updated to include Qt binaries
echo INCLUDE has been updated to include Qt headers
echo LIB has been updated to include Qt libraries 