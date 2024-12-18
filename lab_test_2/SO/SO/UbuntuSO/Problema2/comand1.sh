#!/bin/bash


#Verifica daca sunt furnizati exact doi parametri
if [ "$#" -ne 2 ]; then
	echo "Utilizare: $0 <subdirector> <nume_fisier>"
	exit 1
fi

# Citirea parametrilor
SUBDIRECTOR="$1"
FILE="$2"


# Creeaza subdirector daca nu exista
if [ ! -d "$SUBDIRECTOR" ]; then
	mkdir "$SUBDIRECTOR"
	echo "Subdirectorul $SUBDIRECTOR a fost creat."
fi



# Schimba directorul curent in subdirectorul creat
cd "$SUBDIRECTOR" || exit 1
while :; do
	../OPTIUNE	
	RETURN_VAL=$?
	echo "Valoarea returnata de OPTIUNE: $RETURN_VAL"
	case $RETURN_VAL in
		1)
			
			echo "Introduceti continut in $FILE.TXT, apasand CTRL+D pentru a finaliza introducerea datelor"
			cat > "$FILE.TXT"
			echo "Fisierul $FILE.TXT a fost creat"
			;;
		2)
			if [ -f "$FILE.TXT" ]; then
				sort "$FILE.TXT" > "$FILE.SRT"
				echo "$FILE.TXT a fost sortat in $FILE.SRT"
			else
				echo "$FILE.TXT nu exista"
			fi
			;;
		3)
			if [ -f "$FILE.SRT" ]; then
				echo "Continutul fisierului $FILE.SRT"
				cat  "$FILE.SRT"
			else
				echo "Fisierul $FILE.SRT nu exista"
			fi
			;;
		0)
			echo "OPTIUNE a returnat 0. Iesire."
			break
			;;
		*)
			echo "Valoarea invalida!" 
			;;
	esac
done

echo "Directorul curent este: $(pwd)"


cd ..
echo "Am revenit in directorul parinte."

