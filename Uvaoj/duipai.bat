@echo off
:1
fc out.txt out_correct.txt
if %errorlevel%==0 goto 1
pause