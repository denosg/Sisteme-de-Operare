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

:: Cream subdirectorul ?i schimbam directorul curent
mkdir "%SUBDIRECTOR%"
cd "%SUBDIRECTOR%"

:loop
:: Apelam programul C meniu.exe
if not exist "D:\SO\Test\Problema1\optiune.exe" (
    echo optiune.exe not found. Exiting loop.
    goto end
)

"D:\SO\Test\Problema1\optiune.exe"
set "MENIU_RET=%ERRORLEVEL%"

:: In func?ie de op?iunea selectata, executam ac?iunile
if "%MENIU_RET%"=="1" (
    echo Opera?iune Œnceputa > "%FISIER%.LOG"
) else if "%MENIU_RET%"=="2" (
    if exist "%FISIER%.LOG" (
        echo Adaugare data si ora in fisier...
        echo %date% %time% >> "%FISIER%.LOG"
    ) else (
        echo Fi?ierul %FISIER%.LOG nu exista, relua?i pasul 1.
    )
) else if "%MENIU_RET%"=="3" (
    if exist "%FISIER%.LOG" (
        type "%FISIER%.LOG"
    ) else (
        echo Fi?ierul %FISIER%.LOG nu exista, relua?i pasul 1.
    )
) else if "%MENIU_RET%"=="4" (
    echo Iesire.
    goto end
) else (
    echo Optiune invalida. Reincercati.
)

goto loop

:end
:: Afi?am directorul curent ?i revenim Œn directorul parinte
cd ..
endlocal
