@echo off
setlocal

if "%~1"=="" (
    echo Missing subdirectory parameter.
    exit /b 1
)

if "%~2"=="" (
    echo Missing filename parameter.
    exit /b 1
)

set subdirectory=%1
set filename=%2

if not exist ".\optiune.exe" (
    echo optiune.exe not found. Exiting loop.
    exit /b 1
)

md "%subdirectory%"
cd "%subdirectory%"

:LOOP
if not exist "..\optiune.exe" (
    echo optiune.exe not found. Exiting loop.
    goto end
)

..\optiune
set "optiune_return=%ERRORLEVEL%"

if "%optiune_return%"=="1" (
    echo Started... > "%filename%.LOG"
) else if "%optiune_return%"=="2" (
    if exist "%filename%.LOG" (
        echo Adding data and time...
        echo %date% %time% >> "%filename%.LOG"
    ) else (
        echo The file %filename%.LOG does not exist, press 1.
    )
) else if "%optiune_return%"=="3" (
    if exist "%filename%.LOG" (
        type "%filename%.LOG"
    ) else (
        echo The file %filename%.LOG does not exist, press 1.
    )
) else if "%optiune_return%"=="4" (
    echo Exit...
    goto end
) else (
    echo Invalid option.
)

goto LOOP

:end
cd ..
endlocal
