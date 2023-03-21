#include <stdio.h>//Bibliotecas usadas no programa
#include <string.h>
#include <stdlib.h>

// Alunos:
// Leonardo Casagrande UC21106140
// Vithor Felix        UC21200066

// Prototipo funcoes piloto
char *le_valida_nome_piloto();
char *le_valida_pais_piloto();
int le_valida_idade_piloto();
char le_valida_sexo_piloto();
int le_valida_id_piloto();

// Prototipo funcoes circuito
int le_valida_id_circuito(int qnt_circuitos, int id_circuito);
char *le_valida_nome_circuito();
int le_valida_Km();
int le_valida_id_piloto_menor_tempo();
char *le_valida_pais_circuito();
float le_valida_menor_tempo_circuito();

// Prototipo funcoes melhor volta
int le_valida_id_piloto_melhor_volta();
int le_valida_id_circuito_melhor_volta(int id_circuito);
int le_valida_dia_melhor_volta();
int le_valida_mes_melhor_volta();
int le_valida_ano_melhor_volta();
int le_valida_minutos_melhor_volta();
int le_valida_segundos_melhor_volta();
int le_valida_milissegundos_melhor_volta();
char *le_valida_nome_equipe_piloto();

void consultar_dados(int n_pilotos, int n_circuitos);
void consultar_piloto_pelo_nome(int n_pilotos);
void consultar_circuito(int n_circuitos);
void consultar_tempo(int n_circuitos);

//struct para as informacoes do piloto
struct Piloto {
    int id, idade;
    char nome[120], sexo, pais[120];
};
//struct para as informacoes da melhor volta
struct Melhor_volta {
    int id_piloto, id_circuito, dia, mes, ano, minutos, segundos, milissegundos;
    char nome_equipe[120];
};
//struct para as informacoes do circuito
struct Circuito {
    int id_circuito, km, id_piloto;
    char nome[120], pais[120];
    struct Melhor_volta melhor_volta;
};   



struct Piloto piloto[100];
struct Circuito circuito[20];
struct Melhor_volta melhor_volta[20];

//inicio do codigo
int main() {
	//variaveis do main
	int qnt_circuitos = 0;
	int id_circuito = 0;
    int opcao_menu = 0, i = 0, j = 0, k = 0, n_pilotos = 0, n_circuitos = 0;
    char *ponteiro;


    do {
        system("cls");
        printf("    >>> SELECIONE UMA OPCAO\n");
        printf("=======================================\n");
        printf("[ 1 ] - Cadastrar piloto\n");
        printf("[ 2 ] - Cadastrar circuito\n");
        printf("[ 3 ] - Cadastrar melhor volta\n");
        printf("[ 4 ] - Consultar todos os dados\n");
        printf("[ 5 ] - Pesquisar piloto\n");
        printf("[ 6 ] - Dados do circuito\n");
        printf("[ 7 ] - Pesquisar tempo de volta\n");
        printf("[ 8 ] - Encerrar programa\n");
        printf("=======================================\n");
        scanf("%d", &opcao_menu);

        switch (opcao_menu) {
            case 1: // Cadastra dados dos pilotos
                system("cls");
                printf("==== CADASTRAR PILOTO ====\n");
                piloto[i].id = le_valida_id_piloto();
                ponteiro = le_valida_nome_piloto();
                strcpy(piloto[i].nome, ponteiro);
                piloto[i].sexo = le_valida_sexo_piloto();
                ponteiro = le_valida_pais_piloto();
                strcpy(piloto[i].pais, ponteiro);
                piloto[i].idade = le_valida_idade_piloto();
                i++;
                n_pilotos++;
                break;            
            case 2: // Cadastra dados dos circuitos
                system("cls");
                printf("==== CADASTRAR CIRCUITO ====\n");
                circuito[j].id_circuito = le_valida_id_circuito(qnt_circuitos, id_circuito);
                ponteiro = le_valida_nome_circuito();
                strcpy(circuito[j].nome, ponteiro);
                circuito[j].km = le_valida_Km();
                circuito[j].id_piloto = le_valida_id_piloto_menor_tempo();
                ponteiro = le_valida_pais_circuito();
                strcpy(circuito[j].pais, ponteiro);
                j++;
                n_circuitos++;
                break;            
            case 3: // Cadastra dados das melhores voltas
                system("cls");
                printf("==== CADASTRAR MELHOR VOLTA ====\n");
                circuito[k].melhor_volta.id_piloto = le_valida_id_piloto_melhor_volta();
                circuito[k].melhor_volta.id_circuito = le_valida_id_circuito_melhor_volta(id_circuito);
                circuito[k].melhor_volta.dia = le_valida_dia_melhor_volta();
                circuito[k].melhor_volta.mes = le_valida_mes_melhor_volta();
                circuito[k].melhor_volta.ano = le_valida_ano_melhor_volta();
                circuito[k].melhor_volta.minutos = le_valida_minutos_melhor_volta();
                circuito[k].melhor_volta.segundos = le_valida_segundos_melhor_volta();
                circuito[k].melhor_volta.milissegundos = le_valida_milissegundos_melhor_volta();
                ponteiro = le_valida_nome_equipe_piloto();
                strcpy(circuito[k].melhor_volta.nome_equipe, ponteiro);
                k++;
                break;            
            case 4:
                system("cls");
                consultar_dados(n_pilotos, n_circuitos);
                system("pause");
                break;
            case 5:
                system("cls");
                consultar_piloto_pelo_nome(n_pilotos);
                system("pause");
                break;            
            case 6:
                system("cls");
                consultar_circuito(n_circuitos);
                system("pause");
                break;            
            case 7:
                system("cls");
                consultar_tempo(n_circuitos);
                system("pause");
                break;            
            case 8:
                system("cls");
                printf("OBRIGADO!\n\n");
                system("pause");
                return 0;
                break;            
        }
        opcao_menu = 0;
    } while (opcao_menu < 1 || opcao_menu > 10);
}

// =========== FUNCOES ==============

// LE VALIDA PILOTO
int le_valida_id_piloto(){
    int id = 0, i = 0;
    do {
        printf("ID do piloto: ");
        scanf("%d", &id);
        if (id < 100 || id > 500){
            printf("\nERRO - INFORME UM ID ENTRE 100 E 500\n\n");
        }
        for (i = 0; i<100; i++){
            if (id == piloto[i].id){
                printf("ERRO - ID JA CADASTRADO\n\n");
                id = 0;
            }
            break;
        }
    } while (id < 100 || id > 500);
    return id;
}

int le_valida_idade_piloto(){
    int idade = 0;
    do {
        printf("Idade do piloto: ");
        scanf("%d", &idade);
        if (idade < 18 || idade > 100){
            printf("\nERRO - IDADE INVALIDA\n\n");
        }
    } while (idade < 18 || idade > 100);
    return idade;
}

char le_valida_sexo_piloto(){
    char sexo_piloto;
    do {
        printf("Sexo do piloto: [m/f]");
        scanf("%c", &sexo_piloto);
    } while (sexo_piloto != 'm' && sexo_piloto != 'f');
    return sexo_piloto;
}

char *le_valida_nome_piloto(){

    int i = 0, tam = 0;
    char nome_piloto[120], *ponteiro;
    do {
        printf("Informe o nome do piloto: ");
        fflush(stdin);
        scanf("%[^\n]s", &nome_piloto);
        tam = strlen(nome_piloto);
        if(tam < 3 || tam > 120){
            printf("ERRO - NOME INVALIDO.\n");
        }
    } while (tam < 3 || tam > 120);
    ponteiro = malloc(sizeof(char) * tam);
    for (i=0; i<tam; i++){
        fflush(stdin);
        ponteiro[i] = nome_piloto[i];
    }
    ponteiro[i] = '\0';
    return ponteiro;
}

char *le_valida_pais_piloto(){
    char paises[120][5], *ponteiro;
    int opcao = 0, tam = 0;
    strcpy(paises[0], "Espanha");
    strcpy(paises[1], "Brasil");
    strcpy(paises[2], "Monaco");
    strcpy(paises[0], "Inglaterra");
    strcpy(paises[1], "Alemanha");
    do {
        printf("Pais de origem do piloto:\n");
        printf("[ 1 ] - Espanha\n");
        printf("[ 2 ] - Brasil\n");
        printf("[ 3 ] - Monaco\n");
        printf("[ 4 ] - Inglaterra\n");
        printf("[ 5 ] - Alemanha\n");
        scanf("%d", &opcao);
        if(opcao < 1 || opcao > 5){
            printf("ERRO - opcao invalida\n");
        }
    } while (opcao < 1 || opcao > 5);
    switch (opcao){
        case 1:
            tam = strlen(paises[0]);
            ponteiro = malloc(sizeof(char) * tam);
            strcpy(ponteiro, "Espanha");
            break;
        case 2:
            tam = strlen(paises[1]);
            ponteiro = malloc(sizeof(char) * tam);
            strcpy(ponteiro, "Brasil");
            break;
        case 3:
            tam = strlen(paises[2]);
            ponteiro = malloc(sizeof(char) * tam);
            strcpy(ponteiro, "Monaco");
            break;
        case 4:
            tam = strlen(paises[3]);
            ponteiro = malloc(sizeof(char) * tam);
            strcpy(ponteiro, "Inglaterra");
            break;
        case 5:
            tam = strlen(paises[4]);
            ponteiro = malloc(sizeof(char) * tam);
            strcpy(ponteiro, "Alemanha");
            break;
    }
}

// LE VALIDA CIRCUITO

int le_valida_id_circuito(int qnt_circuitos, int id_circuito){
    int id = 0;
    if (qnt_circuitos == 0){ // Se for o primeiro circuito cadastrado, pede o id ao usuário
        printf("ID do circuito: ");
        scanf("%d", &id);
        id_circuito = id;
        qnt_circuitos++;
        return id;
    } else { ; // Se nao, incrementa sozinho
        id_circuito++;
        id = id_circuito;
        printf("ID do circuito: %d\n", id);
        return id;
    }
}

char *le_valida_nome_circuito(){

    int i = 0, tam = 0;
    char nome_circuito[120], *ponteiro;
    do {
        printf("Informe o nome do circuito: ");
        fflush(stdin);
        scanf("%[^\n]s", &nome_circuito);
        tam = strlen(nome_circuito);
        if(tam < 3 || tam > 120){
            system("cls");
            printf("ERRO - NOME INVALIDO.\n");
        }
    } while (tam < 3 || tam > 120);
    ponteiro = malloc(sizeof(char) * tam);
    for (i=0; i<tam; i++){
        fflush(stdin);
        ponteiro[i] = nome_circuito[i];
    }
    ponteiro[i] = '\0';
    return ponteiro;
}

int le_valida_Km(){
    int Km=0;

    do{
    printf("Informe a Km do circuito: ");
    scanf("%d", &Km);
    if(Km<1 || Km>20){
    printf("--ERRO--\n");
    }
    }while(Km<1 || Km>20);
    return Km;
}

int le_valida_id_piloto_menor_tempo(){
    int id = 0, i = 0;
    do {
        printf("ID do piloto com menor tempo: ");
        scanf("%d", &id);
        for (i = 0; i<100; i++){
            if (id == piloto[i].id){
                return id;
            } else {
                if (i == 99){
                    printf("ERRO - piloto nao cadastrado\n");
                    id = 0;
                }
            }
        }
    } while (id < 100 || id > 500);
}

char *le_valida_pais_circuito(){
    char paises[120][5], *ponteiro;
    int opcao = 0, tam = 0;
    strcpy(paises[0], "Espanha");
    strcpy(paises[1], "Brasil");
    strcpy(paises[2], "Monaco");
    strcpy(paises[3], "Inglaterra");
    strcpy(paises[4], "Alemanha");
    do {
        printf("Pais sede do circuito:\n");
        printf("[ 1 ] - Espanha\n");
        printf("[ 2 ] - Brasil\n");
        printf("[ 3 ] - Monaco\n");
        printf("[ 4 ] - Inglaterra\n");
        printf("[ 5 ] - Alemanha\n");
        scanf("%d", &opcao);
        if(opcao < 1 || opcao > 5){
            printf("ERRO - opcao invalida\n");
        }
    } while (opcao < 1 || opcao > 5);
    switch (opcao){
        case 1:
            tam = strlen(paises[0]);
            ponteiro = malloc(sizeof(char) * tam);
            strcpy(ponteiro, "Espanha");
            break;
        case 2:
            tam = strlen(paises[1]);
            ponteiro = malloc(sizeof(char) * tam);
            strcpy(ponteiro, "Brasil");
            break;
        case 3:
            tam = strlen(paises[2]);
            ponteiro = malloc(sizeof(char) * tam);
            strcpy(ponteiro, "Monaco");
            break;
        case 4:
            tam = strlen(paises[3]);
            ponteiro = malloc(sizeof(char) * tam);
            strcpy(ponteiro, "Inglaterra");
            break;
        case 5:
            tam = strlen(paises[4]);
            ponteiro = malloc(sizeof(char) * tam);
            strcpy(ponteiro, "Alemanha");
            break;
    }
}

float le_valida_menor_tempo_circuito(){
    float menor_tempo = 0;
    do {
        printf("Menor tempo no circuito: ");
        scanf("%f", &menor_tempo);
    } while (menor_tempo < 1);
    return menor_tempo;
}

// LE VALIDA MELHOR VOLTA

int le_valida_id_piloto_melhor_volta(){
    int id = 0, i = 0;
    do {
        printf("ID do piloto: ");
        scanf("%d", &id);
        for (i = 0; i<100; i++){
            if (id == piloto[i].id){
                return id;
            } else {
                if (i == 99){
                    printf("ERRO - piloto nao cadastrado\n");
                    id = 0;
                }
            }
        }
    } while (id < 100 || id > 500);
}

int le_valida_id_circuito_melhor_volta(int id_circuito){
    int id = 0, i = 0;
    do {
        printf("ID do circuito: ");
        scanf("%d", &id);
        for (i = 0; i<100; i++){
            if (id == circuito[i].id_circuito){
                return id;
            } else {
                if (i == 99){
                    printf("ERRO - circuito nao cadastrado\n");
                    id = 0;
                }
            }
        }
    } while (id < 100 || id > 500);
}

int le_valida_dia_melhor_volta(){
    int dia = 0;
    do {
        printf("Dia: ");
        scanf("%d", &dia);
    } while (dia < 1 || dia > 31);
    return dia;
}
int le_valida_mes_melhor_volta(){
    int mes = 0;
    do {
        printf("Mes: ");
        scanf("%d", &mes);
    } while (mes < 1 || mes > 12);
    return mes;
}
int le_valida_ano_melhor_volta(){
    int ano = 0;
    do {
        printf("Ano: ");
        scanf("%d", &ano);
    } while (ano < 2000 || ano > 2022);
    return ano;
}

int le_valida_minutos_melhor_volta(){
    int minutos = 0;
    do {
        printf("Minutos: ");
        scanf("%d", &minutos);
    } while (minutos < 1 || minutos > 60);
}
int le_valida_segundos_melhor_volta(){
    int segundos = 0;
    do {
        printf("Segundos: ");
        scanf("%d", &segundos);
    } while (segundos < 0 || segundos > 60);
}
int le_valida_milissegundos_melhor_volta(){
    int milissegundos = 0;
    do {
        printf("Milissegundos: ");
        scanf("%d", &milissegundos);
    } while (milissegundos < 0 || milissegundos > 100);
}

char *le_valida_nome_equipe_piloto(){
    int i = 0, tam = 0;
    char nome_equipe[120], *ponteiro;
    do {
        printf("Informe o nome da equipe do piloto: ");
        fflush(stdin);
        scanf("%[^\n]s", &nome_equipe);
        tam = strlen(nome_equipe);
        if(tam < 3 || tam > 120){
            system("cls");
            printf("ERRO - NOME INVALIDO.\n");
        }
    } while (tam < 3 || tam > 120);
    ponteiro = malloc(sizeof(char) * tam);
    for (i=0; i<tam; i++){
        fflush(stdin);
        ponteiro[i] = nome_equipe[i];
    }
    ponteiro[i] = '\0';
    return ponteiro;
}

void consultar_dados(int n_pilotos, int n_circuitos){
    int i = 0;
    printf("    >>> PILOTOS CADASTRADOS:\n\n");
    if (n_pilotos == 0){
        printf(" - Nenhum piloto cadastrado\n");
    } else {
        for (i = 0; i<n_pilotos; i++){
            printf("ID: %d\n", piloto[i].id);
            printf("Nome: %s\n", piloto[i].nome);
            printf("Pais: %s\n", piloto[i].pais);
            printf("Idade: %d\n", piloto[i].idade);
            printf("Sexo: %c\n", piloto[i].sexo);
            printf("----------\n");
        }
    }
    printf("======================\n");
    printf("    >>> CIRCUITOS\n\n");
    if (n_circuitos == 0){
        printf(" - Nenhum circuito cadastrado\n");
    } else {
        for (i=0; i<n_circuitos; i++){
            printf("ID: %d\n", circuito[i].id_circuito);
            printf("Nome: %s\n", circuito[i].nome);
            printf("Pais: %s\n", circuito[i].pais);
            printf("KM: %d\n", circuito[i].km);
            printf("Data melhor volta: %d/%d/%d\n", circuito[i].melhor_volta.dia, circuito[i].melhor_volta.mes, circuito[i].melhor_volta.ano);
            printf("Tempo melhor volta: %d:%d:%d\n", circuito[i].melhor_volta.minutos, circuito[i].melhor_volta.segundos, circuito[i].melhor_volta.ano);
            printf("ID piloto com menor tempo: %d\n", circuito[i].id_piloto);
            printf("----------\n");
        }
    }
}

void consultar_piloto_pelo_nome(int n_pilotos){
	char nome_piloto[120];
	int i = 0;
    if (n_pilotos == 0){
        printf(" - Nenhum piloto cadastrado");
    } else {
        printf("Digite o nome do piloto que deseja pesquisar: ");
        fflush(stdin);
        scanf("%[^\n]s", &nome_piloto);
        for (i=0; i<n_pilotos; i++){
            if (strcmp(nome_piloto, piloto[i].nome) == 0){
                printf("=== DADOS PILOTO %s ===\n", nome_piloto);
                printf("ID: %d\n", piloto[i].id);
                printf("IDADE: %d\n", piloto[i].idade);
                printf("PAIS: %d\n", piloto[i].pais);
            }
        }
	}
}

void consultar_circuito(int n_circuitos){
    char nome_circuito[120];
    int i = 0;
    printf("Digite o nome do circuito: ");
    fflush(stdin);
    scanf("%[^\n]s", &nome_circuito);
    for(i=0; i<n_circuitos; i++){
        if (strcmp(circuito[i].nome, nome_circuito) == 0){
            printf("    >>> CIRCUITO %s\n", nome_circuito);
            printf("ID piloto da melhor volta: %d\n", circuito[i].id_piloto);
            printf("DATA: %d/%d/%d\n", circuito[i].melhor_volta.dia, circuito[i].melhor_volta.mes, circuito[i].melhor_volta.ano);
            printf("TEMPO: %d:%d:%d\n", circuito[i].melhor_volta.minutos, circuito[i].melhor_volta.segundos, circuito[i].melhor_volta.milissegundos);
        }
    }
} 
 
void consultar_tempo(int n_circuitos){
    int minutos = 0, segundos = 0, milissegundos = 0, i = 0, existe = 0;

    printf("Minutos: ");
    scanf("%d", &minutos);
    printf("Segundos: ");
    scanf("%d", &segundos);
    printf("Milissegundos: ");
    scanf("%d", &milissegundos);
    for (i=0; i<n_circuitos; i++){
        if (circuito[i].melhor_volta.minutos <= minutos){
            printf("    >>> CIRCUITO %s\n", circuito[i].nome);
            printf("ID do piloto: %d\n", circuito[i].id_piloto);
            printf("Nome da equipe do piloto: %s\n", circuito[i].melhor_volta.nome_equipe);
            printf("Tempo: %d:%d:%d\n", circuito[i].melhor_volta.minutos, circuito[i].melhor_volta.segundos, circuito[i].melhor_volta.milissegundos);
            existe = 1;
        }
    }
    if (existe == 0){
        printf("Nao existe nenhum tempo menor do que o informado\n");
    }
}
