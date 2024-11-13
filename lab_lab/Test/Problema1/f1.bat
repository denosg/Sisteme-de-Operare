@echo off
setlocal

:: Verificam parametrii
if "%~1"=="" (
    echo Missing subdirectory parameter.
    exit /b 1
)

if "%~2"=="" (
    echo Missing filename parameter.
    exit /b 1
)

set SUBDIRECTOR=%1
set FISIER=%2

:: Verificam daca optiune.exe exista in directorul curent (inainte de a schimba directorul)
if not exist ".\optiune.exe" (
    echo optiune.exe not found. Exiting loop.
    exit /b 1
)

:: Cream subdirectorul si schimbam directorul curent
mkdir "%SUBDIRECTOR%"
cd "%SUBDIRECTOR%"

:loop
:: Apelam programul C meniu.exe
if not exist "..\optiune.exe" (
    echo optiune.exe not found. Exiting loop.
    goto end
)

..\optiune
set "MENIU_RET=%ERRORLEVEL%"

:: In functie de optiunea selectata, executam actiunile
if "%MENIU_RET%"=="1" (
    echo Operatiune inceputa > "%FISIER%.LOG"
) else if "%MENIU_RET%"=="2" (
    if exist "%FISIER%.LOG" (
        echo Adaugare data si ora in fisier...
        echo %date% %time% >> "%FISIER%.LOG"
    ) else (
        echo Fisierul %FISIER%.LOG nu exista, reluati pasul 1.
    )
) else if "%MENIU_RET%"=="3" (
    if exist "%FISIER%.LOG" (
        type "%FISIER%.LOG"
    ) else (
        echo Fisierul %FISIER%.LOG nu exista, reluati pasul 1.
    )
) else if "%MENIU_RET%"=="4" (
    echo Iesire.
    goto end
) else (
    echo Optiune invalida. Reincercati.
)

goto loop

:end
:: Afisam directorul curent si revenim in directorul parinte
cd ..
endlocal
