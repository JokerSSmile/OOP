ECHO off
REM
Lab1_2.exe
IF NOT ERRORLEVEL 1 GOTO err

REM
Lab1_2.exe "" "" ""
IF NOT ERRORLEVEL 1 GOTO err

REM
Lab1_2.exe 0 1 -1
IF NOT ERRORLEVEL 1 GOTO err

REM
Lab1_2.exe 1.5 -5.2 3.0
IF ERRORLEVEL 1 GOTO err

ECHO Tests are finished successfully.
EXIT /B
  
:err
ECHO Tests are unsuccessful.
EXIT /B