@Echo off
 
:m1
Echo Choose program:
Echo.
Echo 1 - euclid
Echo 2 - euclid with big integer
Echo 3 - extended euclid with big integer

echo.
Set /p choice="Your choice: "
if not defined choice goto m1
if "%choice%"=="1" (
    gcc euclid.c -o compiled_program
    compiled_program.exe 
)
if "%choice%"=="2" (
    gcc libs/big_int.c euclid_big_int.c -o compiled_program
    compiled_program.exe 
)
if "%choice%"=="3" (
    start_extended_euclid.bat
)

Echo.
Echo.
Echo.
goto m1
pause >nul