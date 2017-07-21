@echo off
:1
data_making
correct
wrong
fc out_correct.txt out_wrong.txt 
if %errorlevel%==0 goto 1
pause