ECHO off
REM
Lab1_3.exe input_test1.txt
IF ERRORLEVEL 1 GOTO err
FC /b output_test1.txt output.txt
IF ERRORLEVEL 1 GOTO err

REM
Lab1_3.exe input_test2.txt
IF ERRORLEVEL 1 GOTO err
FC /b output_test2.txt output.txt
IF ERRORLEVEL 1 GOTO err

REM
Lab1_3.exe input_test3.txt
IF ERRORLEVEL 1 GOTO err
FC /b output_test3.txt output.txt
IF ERRORLEVEL 1 GOTO err

REM
Lab1_3.exe input_test4.txt
IF ERRORLEVEL 1 GOTO err
FC /b output_test4.txt output.txt
IF ERRORLEVEL 1 GOTO err

ECHO Tests are successful.
EXIT /B
  
:err
ECHO Tests are unsuccessful.
EXIT /B