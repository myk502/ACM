@echo off
:1
datas
"hdu1175 correct"
hdu1175_new
fc out.txt out2.txt 
if %errorlevel%==0 goto 1
pause