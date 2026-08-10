#include "agenda.h"

void salva_arquivo(FILE *arquivo,struct prova **provas, int n){
    if(arquivo == NULL){
        printf("\nErro ao salvar arquivo!");
        return;
    }
    fprintf(arquivo,"%d\n",n);
    for(int i = 0; i < n; i++){
        fprintf(arquivo,"%d %d %d\n",provas[i]->data.ano,provas[i]->data.mes,provas[i]->data.dia);
        fprintf(arquivo,"%d %d\n",provas[i]->horario_ini.hora,provas[i]->horario_ini.minuto);
        fprintf(arquivo,"%d %d\n",provas[i]->horario_fim.hora,provas[i]->horario_fim.minuto);
        fprintf(arquivo,"%s\n",provas[i]->desc);
        fprintf(arquivo,"%s\n",provas[i]->local);
    }
}

struct prova *cadastra_prova(struct prova *agenda, int quantidade_provas){
    struct prova copia;
    printf("\nInsira o dia:\n");
    scanf("%d",&copia.data.dia);
    printf("\nInsira o mês:\n");
    scanf("%d",&copia.data.mes);
    printf("\nInsira o ano:\n");
    scanf("%d",&copia.data.ano);

}

int check_data(struct data data_a_checar){ //return 1 == Invalid data; return 0 == valid data
    int mes[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if(data_a_checar.ano < 1900 || data_a_checar.ano > 2100){
        printf("\nAno inválido!");
        return 1;
    }
    if((data_a_checar.ano % 4 == 0 && data_a_checar.ano % 100 != 0) || data_a_checar.ano % 400 == 0){
        mes[1] = 29;
    }
    if(data_a_checar.mes < 1 || data_a_checar.mes > 12){
        printf("\nMês inválido!");
        return 1;
    }
    int max_dias = mes[data_a_checar.mes - 1];
    if(data_a_checar.dia < 1 || data_a_checar.dia > max_dias){
        printf("\nDia inválido!");
        return 1;
    }
    return 0;
}
