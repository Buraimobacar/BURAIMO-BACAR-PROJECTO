#include <stdbool.h>
#include <windows.h>
#define STRTAM 30
#define limit 8
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void eixo_x_y(int x, int y);

struct fila_struct {
	int position[limit];
	int initial_position;
	int end_position;
};
struct fila_struct fila;
int num_atendimento = 0;
int num = 0;

int senha = 0;
bool sair = true;

void fila_increment(int senha);
void fila_decrement();
void exit();
void retirar_senha();
void painel();
int exit_program();
int validar();
void ver_fila();
void limpar_msg(int num);
int main(){
	fila.initial_position = 0;
	fila.end_position = 0;
	int opcao = 1, x = 4;
    system("cls");
    system("color 0F");
        eixo_x_y(50,1); printf("BURAIMO BACAR");
        eixo_x_y(0,3); printf("PAINEL DE CONSOLE MENU:");
    while(sair){
            eixo_x_y(2,4);  printf(" 1  PROXIMO CLIENTE");
            eixo_x_y(2,5);  printf(" 2  RETIRAR SENHA");
            eixo_x_y(2,6);  printf(" 3  ILUSTRAR FILA");
            eixo_x_y(2,7);  printf(" 4  SAIR");
        eixo_x_y(3,8); printf("INSIRA A OPCAO: %d", num_atendimento);
        system("pause>nul");
		if(GetAsyncKeyState(VK_DOWN) && x != 7) {
            eixo_x_y(0,x); printf("  ");
            x++;
            eixo_x_y(0,x); printf("->");
            opcao++;
            continue;
        }
		if(GetAsyncKeyState(VK_UP) && x != 4){
            eixo_x_y(0,x); printf("  ");
            x--;
            eixo_x_y(0,x); printf("->");
            opcao--;
            continue;
        }
		if(GetAsyncKeyState(VK_RETURN)){
            switch (opcao) {
            case 1:
                retirar_senha();
                break;
            case 2:
                fila_decrement();
                break;
            case 3:
                ver_fila();
                break;
            case 4:
                exit_program();
            }
        }
    }
    eixo_x_y(20,21);
	exit();
	return 0;
}
void eixo_x_y(int x, int y)
{
    HANDLE hCon;
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hCon,dwPos);

}
void fila_increment(int senha){
	if (fila.end_position == limit) {
		printf("Fila cheia.");
	}
	else {
		fila.position[fila.end_position] = senha;
		fila.end_position++;
	}
}
void fila_decrement(){
	if (fila.initial_position == fila.end_position) {
		eixo_x_y(30,15);
		printf("Fila vazia");
	}
	else {
		eixo_x_y(35,14);
		printf("               ");
		for (int i=0; i<limit; i++) {
			fila.position[i] = fila.position[i+1];
		}
		fila.position[fila.end_position] = 0;
		fila.end_position--;
		num_atendimento++;
		painel();
	}
	ver_fila();
	limpar_msg(0);
	limpar_msg(1);
}
void ver_fila() {
	painel();
	eixo_x_y(2,23);
	printf("Fila: ");
	eixo_x_y(9,23);
	for (int i=0; i<limit; i++){
		printf("%d, ", fila.position[i]);
	}
	eixo_x_y(20,25);
	printf("Atendimento: %d", num_atendimento);
	limpar_msg(0);
}
void exit(){
	printf("EXIT");
}
void retirar_senha(){
	int sua_senha;
	if (validar() == 1) {
		sua_senha = senha + 1;
		eixo_x_y(2,15);
		printf("SENHA NUMERO: %d", sua_senha);
		senha++;
		fila_increment(sua_senha);
	} else if(senha == 10) {
		eixo_x_y(30,17);
 		printf("A fila ja esta completa.");
	}
	ver_fila();
	limpar_msg(0);
}
int validar(){
	if (senha == limit) {
		return -1;
	}
	else if(senha <= limit) {
		return 1;
	}
}
void painel(){
	if (num_atendimento - 1 < 0){
		eixo_x_y(2,17);
		printf("SENHA ANTERIOR: 0\n");
	}
	else {
		eixo_x_y(2,17);
		printf("SENHA ANTERIOR: %d\n", num_atendimento -1);
	}
	eixo_x_y(2,18);
	printf("SENHA CHAMADA: %d \n", num_atendimento);
	eixo_x_y(2,19);
	printf("PROXIMO CLIENTE: %d\n",  num_atendimento + 1);
}
void limpar_msg(int num){
    if(num == 1){
		eixo_x_y(30,17);
 		printf("                                                               ");
	} else {
		eixo_x_y(30,16);
		printf("                                                              ");
	}
}
int exit_program(){
	if (fila.position[fila.initial_position] != 0){
		eixo_x_y(30,16);
		printf("Ainda ha pessoas!.");
		return 1;
	}
	else{
		sair = false;
		return sair;
	}

}
