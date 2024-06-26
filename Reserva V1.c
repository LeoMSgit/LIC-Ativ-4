#include <stdio.h>
#include <stdlib.h>

// Declaração Funções
void fMostraMat(int m[20][14], char status[20][14]);
int fMenu();
void fCriaMat(int m[20][14], char status[20][14]);
void clearInputBuffer();
void fRealizarCheckIn(int m[20][14], char status[20][14]);
void fRealizarCheckOut(int m[20][14], char status[20][14]);
void fReserva(int m[20][14], char status[20][14]);
void fRealizarreserva(int m[20][14], char status[20][14]);
void fCancelarReserva(int m[20][14], char status[20][14]);

// Declaração Variáveis Globais
int n = 1;
int m[20][14];
char status[20][14]; // Matriz para armazenar o status dos quartos
int i;
int j; 
int menu = 0;
int quarto = 1;

// Estrutura Dados Hospede - Endereco
struct stendereco
{
    char rua[100];
    char numero[5];
    char bairro[40];
    char cidade[40];
    char uf[2];            
};

// Estrutura Dados Hospede
struct stquarto
{
    char status;
    char nome[50];
    char cpf[11];
    char telefone[11];
    struct stendereco ender;    // Estrutura Dados Hospede - Endereco Aninhada
};

// FUNCAO PRINCIPAL
int main (){
    fCriaMat(m, status);
    while (1){ // Loop continuo ate o usuario optar por sair
        if (fMenu() == 5) {
            printf("Saindo do sistema.\n");
            break; // Sai do loop e termina o programa
        }
    }
    return 0;
}

// CRIAR MATRIZ 
void fCriaMat(int m[20][14], char status[20][14]) {
    // Variavel para preencher a matriz
    int count = 1;

    // Preenchendo a matriz com quartos de 1 a 280 e status '.' (livre)
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 14; j++) {
            m[i][j] = count++;
            status[i][j] = '.'; // Todos os quartos comecam como livres
        }
    }
}

// MOSTRAR MATRIZ
void fMostraMat(int m[20][14], char status[20][14]) {
	printf("Quartos: ");
	for (int k = 0; k < 14; k++) {
        printf("\t%d", k + 1);}  		// Imprimindo o apartamento correspondente
    printf("\n");
	for (int i = 0; i < 20; i++) {
        printf("Andar %2d: ", 20 - i);  // Imprimindo o andar correspondente
        for (int j = 0; j < 14; j++) {
            printf("\t%c", status[19 - i][j]);
        }
        printf("\n");
    }
    printf("\n");
    system("pause");
    printf("\n--------------------------------------------------------------------------------------------------------------------------\n");
}


// FUNCAO MENU
int fMenu() {
    printf("\nMENU PRINCIPAL DO HOTEL\n\n");
    printf("1 - Mostrar Mapa; 2 \n");
    printf("2 - Check-in;\n");
    printf("3 - Check-out; \n");
    printf("4 - Reserva\n");
    printf("5 - Sair\n");
    printf("Escolha a opcao acima: ");


    if (scanf("%d", &menu) != 1) {
        clearInputBuffer();
        printf("Entrada invalida! Por favor, insira um numero.\n");
        return 0; // Retorna ao menu inicial
    }

    switch (menu) {
        case 1:
            printf("\nIMPRIMINDO MAPA...\n\n");
            fMostraMat(m, status);
            break;
        case 2:
            fRealizarCheckIn(m, status);
            break;
        case 3:
            fRealizarCheckOut(m, status);
            break;
        case 4:
            fReserva(m, status);
            break;
        case 5:
            return 5; // Indica que o programa deve terminar
        default:
            printf("Opcao invalida! Por favor, tente novamente.\n");
    }

    return 0; // Continua no menu
}

// REALIZAR CHECK-IN
void fRealizarCheckIn(int m[20][14], char status[20][14]) {
    int andarQuarto;
    int numeroQuarto;
    int count = 0;
    
    while (count == 0){
    printf("\nDigite o numero do andar para check-in (0 para retornar ao Menu): ");

    if (scanf("%d", &andarQuarto) != 1) {
        clearInputBuffer();
        printf("Entrada invalida! Por favor, insira um numero.\n");
    }
    // Retorno Menu Principal
    if (andarQuarto == 0){
    	return;
	}
    // Validar se o número do andar
    if (andarQuarto < 1 || andarQuarto > 20) {
        printf("Numero do andar invalido! Por favor, tente novamente.\n");
    }
    
    printf("\nDigite o numero do quarto para check-in (0 para retornar ao Menu): ");
    if (scanf("%d", &numeroQuarto) != 1) {
        clearInputBuffer();
        printf("Entrada invalida! Por favor, insira um numero.\n");
    }
    
    // Retorno Menu Principal
    if (numeroQuarto == 0){
    	return;}
    
    // Validar se o número do quarto é válido
    if (numeroQuarto < 1 || numeroQuarto > 14) {
        printf("Numero do quarto invalido! Por favor, tente novamente.\n");
    }

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 14; j++) {
            if (i == (andarQuarto-1) && j == (numeroQuarto-1)) {
                if (status[i][j] == '.') {
                    status[i][j] = 'O';  // Ocupado
                    printf("Check-in realizado com sucesso no quarto %d%d.\n", andarQuarto, numeroQuarto);
                } else {
                    printf("O quarto %d ja esta ocupado.\n", numeroQuarto);
                }
                return;
            }
        }
    }
    count = count + 1;
    printf("Quarto %d nao encontrado.\n", numeroQuarto);
}
}

// SUBMENU CHECK-OUT
void fCheckOut(int m[20][14], char status[20][14]) {
    int subMenu;
    while (1) {
        printf("\nSUB MENU CHECK-OUT\n");
        printf("1 - Realizar Check-out; 2 - Mostrar Quartos Ocupados; 3 - Voltar ao Menu Anterior\n");

        if (scanf("%d", &subMenu) != 1) {
            clearInputBuffer();
            printf("Entrada invalida! Por favor, insira um numero.\n");
            continue;
        }

        switch (subMenu) {
            case 1:
                fRealizarCheckOut(m, status);
                break;
            case 2:
                fMostraMat(m, status);
                break;
            case 3:
                return; // Retorna ao menu principal
            default:
                printf("Opcao invalida! Por favor, tente novamente.\n");
        }
    }
}

// REALIZAR CHECK-OUT
void fRealizarCheckOut(int m[20][14], char status[20][14]) {
    int andarQuarto;
    int numeroQuarto;
    printf("\nDigite o numero do andar para check-out: ");

    if (scanf("%d", &andarQuarto) != 1) {
        clearInputBuffer();
        printf("Entrada invalida! Por favor, insira um numero.\n");
        return;
    }

    // Validar se o número do andar é válido
    if (andarQuarto < 1 || andarQuarto > 20) {
        printf("Numero do andar invalido! Por favor, tente novamente.\n");
        return;
    }

	printf("\nDigite o numero do quarto para check-out: ");
	    if (scanf("%d", &numeroQuarto) != 1) {
	        clearInputBuffer();
	        printf("Entrada invalida! Por favor, insira um numero.\n");
	        return;
	    }
	    
	// Validar se o número do quarto é válido
	if (numeroQuarto < 1 || numeroQuarto > 14) {
	    printf("Numero do quarto invalido! Por favor, tente novamente.\n");
	    return;
	    }
	
	    for (int i = 0; i < 20; i++) {
	        for (int j = 0; j < 14; j++) {
	            if (i == (andarQuarto-1) && j == (numeroQuarto-1)) {
	                if (status[i][j] == 'O') {	// Ocupado
	                    status[i][j] = '.';  	// Vago
	                    printf("Check-out realizado com sucesso no quarto %d%d.\n", andarQuarto, numeroQuarto);
	                } else {
	                    printf("O quarto %d ja esta livre.\n", numeroQuarto);
	                }
	                return;
	            }
	        }
	    }
	    printf("Quarto %d nao encontrado.\n", numeroQuarto);
}

//função SUBMENU Reserva
void fReserva(int m[20][14], char status[20][14]){
	int subMenu;
      while (1) {
        printf("\nSUB MENU Reservas\n");
        printf("1 - Realizar Reserva; 2 - Mostrar Quartos Ocupados; 3 - Cancelar reserva;4 - Voltar ao Menu Anterior\n");

        if (scanf("%d", &subMenu) != 1) {
            clearInputBuffer();
            printf("Entrada invalida! Por favor, insira um numero.\n");
            continue;
        }

        switch (subMenu) {
            case 1:
                fRealizarreserva(m, status);
                break;
            case 2:
                fMostraMat(m, status);
                break;
            case 3:
                fCancelarReserva(m, status);
                break;
            case 4:
                return;  // Retorna ao menu principal
            default:
                printf("Opcao invalida! Por favor, tente novamente.\n");
        }
    }
}

//Função Realizar Reserva 
void fRealizarreserva(int m[20][14], char status[20][14]) {
    int andarQuarto;
    int numeroQuarto;
    int count = 0;
    
    while (count == 0){
    printf("\nDigite o numero do andar para a Reserva (0 para retornar ao Menu): ");

    if (scanf("%d", &andarQuarto) != 1) {
        clearInputBuffer();
        printf("Entrada invalida! Por favor, insira um numero.\n");
    }
    // Retorno Menu Principal
    if (andarQuarto == 0){
    	return;
	}
    // Validar se o número do andar
    if (andarQuarto < 1 || andarQuarto > 20) {
        printf("Numero do andar invalido! Por favor, tente novamente.\n");
    }
    
    printf("\nDigite o numero do quarto para a Reserva (0 para retornar ao Menu): ");
    if (scanf("%d", &numeroQuarto) != 1) {
        clearInputBuffer();
        printf("Entrada invalida! Por favor, insira um numero.\n");
    }
    
    // Retorno Menu Principal
    if (numeroQuarto == 0){
    	return;}
    
    // Validar se o número do quarto é válido
    if (numeroQuarto < 1 || numeroQuarto > 14) {
        printf("Numero do quarto invalido! Por favor, tente novamente.\n");
    }

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 14; j++) {
            if (i == (andarQuarto-1) && j == (numeroQuarto-1)) {
                if (status[i][j] == '.') {
                    status[i][j] = 'R';  // Ocupado
                    printf("Reserva realizado com sucesso no quarto %d%d.\n", andarQuarto, numeroQuarto);
                } else {
                    printf("O quarto %d ja esta ocupado.\n", numeroQuarto);
                }
                return;
            }
        }
    }
    count = count + 1;
    printf("Quarto %d nao encontrado.\n", numeroQuarto);
}
}

//Função cancelar Reserva
void fCancelarReserva(int m[20][14], char status[20][14]) {
    int andarQuarto;
    int numeroQuarto;
    printf("\nDigite o numero do andar para cancelar a Reseva: ");

    if (scanf("%d", &andarQuarto) != 1) {
        clearInputBuffer();
        printf("Entrada invalida! Por favor, insira um numero.\n");
        return;
    }

    // Validar se o número do andar é válido
    if (andarQuarto < 1 || andarQuarto > 20) {
        printf("Numero do andar invalido! Por favor, tente novamente.\n");
        return;
    }

	printf("\nDigite o numero do quarto para cancelar a Reserva: ");
	    if (scanf("%d", &numeroQuarto) != 1) {
	        clearInputBuffer();
	        printf("Entrada invalida! Por favor, insira um numero.\n");
	        return;
	    }
	    
	// Validar se o número do quarto é válido
	if (numeroQuarto < 1 || numeroQuarto > 14) {
	    printf("Numero do quarto invalido! Por favor, tente novamente.\n");
	    return;
	    }
	
	    for (int i = 0; i < 20; i++) {
	        for (int j = 0; j < 14; j++) {
	            if (i == (andarQuarto-1) && j == (numeroQuarto-1)) {
	                if (status[i][j] == 'R') {	// Ocupado
	                    status[i][j] = '.';  	// Vago
	                    printf("Reserva cancelada com sucesso no quarto %d%d.\n", andarQuarto, numeroQuarto);
	                } else {
	                    printf("O quarto %d ja esta livre.\n", numeroQuarto);
	                }
	                return;
	            }
	        }
	    }
	    printf("Quarto %d nao encontrado.\n", numeroQuarto);
}


// Funcao para limpar o buffer de entrada
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}
