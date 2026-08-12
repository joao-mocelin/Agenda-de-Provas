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
    char desc[150];
    char local[50];
};

void salva_arquivo(FILE *arquivo,struct prova *provas, int n);
struct prova *cadastra_prova(struct prova *agenda, int *quantidade_provas);
void mostra_provas(struct prova *agenda, int quantidade_provas);
struct prova *remover_prova(struct prova *agenda, int *quantidade_provas);
void pesquisa_data(struct prova *agenda, int quantidade_provas);


int check_data(struct data data_a_checar);
int compara_data(struct data data1, struct data data2);
int valida_horario(struct horario hora_a_checar);
int compara_horario(struct horario hora_ini, struct horario hora_fim);
int sobrepoe_horario(struct prova *agenda, int n_provas, struct prova prova_nova);
void limpa_buffer();
