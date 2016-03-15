ECHO off
REM
Lab1_2.exe 3 8 2
IF ERRORLEVEL 1 GOTO err
FC /b output_test1.txt output.txt
IF ERRORLEVEL 1 GOTO err

REM
Lab1_2.exe 1 -2 -8.3
IF ERRORLEVEL 1 GOTO err
FC /b output_test2.txt output.txt
IF ERRORLEVEL 1 GOTO err

REM
Lab1_2.exe 5.1 10 -2.1
IF ERRORLEVEL 1 GOTO err
FC /b output_test3.txt output.txt
IF ERRORLEVEL 1 GOTO err

REM
Lab1_2.exe 1 10 1
IF ERRORLEVEL 1 GOTO err
FC /b output_test4.txt output.txt
IF ERRORLEVEL 1 GOTO err

ECHO Tests are successful.
EXIT /B
  
:err
ECHO Tests are unsuccessful.
EXIT /B