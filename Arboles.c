#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int crear_nodo(int dato);
void insertar(int nodos, int dato);
void inorden(int nodo);
void postorden(int nodo);
void preorden(int nodo);

int nodos = 0, c = 0;
int clave[50], izq[50], der[50];

void main(){
    int dato = 0;
    int rep = 0;

    dato = 0;
    printf("Ingresa el primer nodo:");
    scanf("%i", &clave[nodos]);
    izq[nodos] = -1;
    der[nodos] = -1;
    nodos++;

    while (rep == 0){
        printf("Ingresa el siguiente dato: ");
        scanf("%i", &dato);

        insertar(nodos, dato);

        printf("\nNumero de datos: %i\n\n", nodos);
        printf("-------------------------------------------------------------------------------------------------------------------\n");
        printf("|                                                    Tabulado                                                     |\n");
        printf("-------------------------------------------------------------------------------------------------------------------\n");
		printf("| Nod |");
        
        int rep0 = 0;
        while(rep0 < nodos){
        	if ((nodos-rep0) == 1){
            	printf(" %.4i |\n", rep0);
            }
            else {
            	printf(" %.4i |", rep0);
            }
            rep0++;
		}
        
        printf("-------------------------------------------------------------------------------------------------------------------\n");
		printf("| Cla |");

        int rep1 = 0;
        while (rep1 < nodos){
            if ((nodos-rep1) == 1){
            	if (clave[rep1] < 0){
            		printf(" %.3i |\n", clave[rep1]);
				}
                else{
                	printf(" %.4i |\n", clave[rep1]);
				}
            }
            else {
            	if (clave[rep1] < 0){
            		printf(" %.3i |", clave[rep1]);
				}
                else{
                	printf(" %.4i |", clave[rep1]);
				}
            }
            rep1++;
        }
        
        printf("-------------------------------------------------------------------------------------------------------------------\n");
		printf("| izq |");
        
        int rep2 = 0;
        while (rep2 < nodos){
            if ((nodos-rep2) == 1){
            	if (izq[rep2] < 0){
            		printf(" %.3i |\n", izq[rep2]);
				}
                else{
                	printf(" %.4i |\n", izq[rep2]);
				}
            }
            else {
            	if (izq[rep2] < 0){
            		printf(" %.3i |", izq[rep2]);
				}
                else{
                	printf(" %.4i |", izq[rep2]);
				}
            }
            rep2++;
        }
        
        printf("-------------------------------------------------------------------------------------------------------------------\n");
		printf("| der |");
        
        int rep3 = 0;
        while (rep3 < nodos){
            if ((nodos-rep3) == 1){
            	if(der[rep3] < 0){
            		printf(" %.3i |\n", der[rep3]);
				}
                else{
                	printf(" %.4i |\n", der[rep3]);
				}
            }
            else {
            	if (der[rep3] < 0){
            		printf(" %.3i |", der[rep3]);
				}
                else{
                	printf(" %.4i |", der[rep3]);
				}
            }
            rep3++;
        }
        
        printf("-------------------------------------------------------------------------------------------------------------------\n\n");
        
        printf("Recorrido Inorden: ");
        inorden(nodos);
        c = 0;
        
        printf("Recorrido Postorden: ");
        postorden(nodos);
        c = 0;
        
        printf("Recorrido Preorden: ");
        preorden(nodos);
        c = 0;

        printf ("\nSi desea agregar mas datos ingrese 0: ");
        scanf("%i", &rep);
        system("cls");
    }

getch();
}

int crear_nodo(int dato){
    clave[nodos] = dato;
    izq[nodos] = -1;
    der[nodos] = -1;
    return nodos++;
}

void insertar(int nodos, int dato){
    if(clave[nodos] > dato){
        if(izq[nodos] == -1){
            izq[nodos] = crear_nodo(dato);
        }
        else{
            insertar(izq[nodos], dato);
        }
    }
    else {
        if(der[nodos] == -1){
            der[nodos] = crear_nodo(dato);
        }
        else{
            insertar(der[nodos], dato);
        }
    }
}

void inorden(int nodo){
	if(nodo == -1){
		return;
	}
	else{
		inorden(izq[nodo]);
		if (c < nodos){
			if ((nodos-c) == 1){
				printf("%i\n", clave[nodo]);
			}
			else{
				printf("%i, ", clave[nodo]);
			}
		}
		c++;
		inorden(der[nodo]);
	}
}

void postorden(int nodo){
	if(nodo == -1){
		return;
	}
	else{
		postorden(izq[nodo]);
		postorden(der[nodo]);
		if (c < nodos){
			if ((nodos-c) == 1){
				printf("%i\n", clave[nodo]);
			}
			else{
				printf("%i, ", clave[nodo]);
			}
		}
		c++;
	}
}

void preorden(int nodo){
	if(nodo == -1){
		return;
	}
	else{
		if (c <= nodos){
			if (c == nodos){
				printf("%i\n", clave[nodo]);
			}
			else{
				if (c != 0){
					printf("%i, ", clave[nodo]);
				}
			}
		}
		c++;
		preorden(izq[nodo]);
		preorden(der[nodo]);
	}
}
