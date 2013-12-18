
# Esta es la target que se ejecuta por defecto si se escribe "make" en la consola
all: release

# Compilación principal del ejecutable
release:
	@echo 'Compilando...'
	g++ -o salida main.cpp -lpthread

