#
#	Software by FernuDev for Antares Aerospace
#	2024
#

function presentation() {
	printf "\n\tIniciando el banco de pruebas Antares Aerospace "
    if [ -d "./Build" ]; then
        printf "\n\tExiste el directorio de binarios\n"
        # shellcheck disable=SC2164
        cd Build
        ./Banco_Pruebas
    else 
        printf "\n\t No existe el directorio de binarios"
        printf "\n\t Compilando programa ...\n"

        mkdir Build
        cd Build && cmake ..
        make
        ./Banco_Pruebas
    fi
    

	printf "\n\tFinalizando programa\n"
}

presentation
