ECHO off
REM
Lab1.exe
IF NOT ERRORLEVEL 1 GOTO err

REM
Lab1.exeabc zxc
IF NOT ERRORLEVEL 1 GOTO err

REM
Lab1.exe incorrectName.txt output.txt pa papa
IF NOT ERRORLEVEL 1 GOTO err

REM
Lab1.exe input_test1.txt output.txt book film
IF ERRORLEVEL 1 GOTO err
FC /b output_test1.txt output.txt
IF ERRORLEVEL 1 GOTO err

REM
Lab1.exe input_test2.txt output.txt ma mama
IF ERRORLEVEL 1 GOTO err
FC /b output_test2.txt output.txt
IF ERRORLEVEL 1 GOTO err

REM
Lab1.exe input_test3.txt output.txt nothing nothing1
IF ERRORLEVEL 1 GOTO err
FC /b output_test3.txt output.txt
IF ERRORLEVEL 1 GOTO err

ECHO Tests are successful.
EXIT /B
  
:err
ECHO Tests are unsuccessful.
EXIT /B