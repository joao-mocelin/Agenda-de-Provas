#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data{
    int dia, mes, ano;
};

struct horario{
    int hora,minuto;
};

struct prova{
    struct data data;
    struct horario horario_ini;
    struct horario horario_fim;
    char desc[50];
    char local[50];
};

void salva_arquivo(FILE *arquivo,struct prova **provas, int n);
struct prova *cadastra_prova(struct prova *agenda, int quantidade_provas);

int check_data(struct data data_a_checar);
int valida_horario(struct horario hora_a_checar);