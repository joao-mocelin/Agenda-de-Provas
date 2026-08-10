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
    int mes[7] = {1,3,5,7,8,10,12};
    int eh_bissexto = 0;
    if(data_a_checar.ano < 1900 || data_a_checar.ano > 2100){
        printf("\nAno inválido!");
        return 1;
    }
    if((data_a_checar.ano % 4 == 0 && data_a_checar.ano % 100 != 0) || data_a_checar.ano % 400 == 0){
        eh_bissexto = 1;
    }
    if(data_a_checar.mes < 1 || data_a_checar.mes > 12){
        printf("\nMês inválido!");
        return 1;
    }
    int max_dias = 30;
    if(data_a_checar.mes == 2){
        if(eh_bissexto == 1){
            max_dias = 29;
        }
        else{
            max_dias = 28;
        }
    }
    for (int i = 0; i < 7; i++)
    {
        if(data_a_checar.mes == mes[i]){
            max_dias = 31;
        }
    }
    if(data_a_checar.dia < 1 || data_a_checar.dia > max_dias){
        printf("\nDia inválido!");
        return 1;
    }
    return 0;
}