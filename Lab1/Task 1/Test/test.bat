ECHO off
SET program="%1"
if %program% == "" goto err

REM
%program%
IF NOT ERRORLEVEL 1 GOTO err

REM
%program% abc zxc
IF NOT ERRORLEVEL 1 GOTO err

REM
%program% incorrectName.txt output.txt pa papa
IF NOT ERRORLEVEL 1 GOTO err

REM
%program% input_test1.txt output.txt book film
IF ERRORLEVEL 1 GOTO err
FC output_test1.txt output.txt
IF ERRORLEVEL 1 GOTO err

REM
%program% input_test2.txt output.txt ma mama
IF ERRORLEVEL 1 GOTO err
FC /b output_test2.txt output.txt
IF ERRORLEVEL 1 GOTO err

REM
%program% input_test3.txt output.txt nothing nothing1
IF ERRORLEVEL 1 GOTO err
FC /b output_test3.txt output.txt
IF ERRORLEVEL 1 GOTO err

ECHO Tests are finished successfully.
EXIT /B
  
:err
ECHO Tests are unsuccessful.
EXIT /B