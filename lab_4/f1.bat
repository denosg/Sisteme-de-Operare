@echo off
md %1
cd %1

set FISIER=%2.txt
set SORTAT=%2.srt

:MENIUL
..\meniu_c\meniu
if ERRORLEVEL 3 GOTO TREI
if ERRORLEVEL 2 GOTO DOI
if ERRORLEVEL 1 GOTO UNU
if ERRORLEVEL 0 GOTO STOP

:UNU
echo "Ati ales 1"
copy con %FISIER%
GOTO MENIUL

:DOI
echo "Ati ales 2"
if exist %FISIER% (
    SORT <%FISIER% > %SORTAT%
) else (
    echo "Fisierul %FISIER% nu exista!"
)
GOTO MENIUL

:TREI
echo "Ati ales 3"
if exist %SORTAT% (
    type %SORTAT%
) else (
    echo "Fisierul %SORTAT% nu exista!"
)
GOTO MENIUL

:STOP 
echo "Final" 
cd..
