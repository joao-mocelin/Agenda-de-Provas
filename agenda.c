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

struct prova *cadastra_prova(struct prova *agenda, int *quantidade_provas){
    struct prova copia;
    do{
        printf("\nInsira o dia:\n");
        scanf("%d",&copia.data.dia);
        printf("\nInsira o mês:\n");
        scanf("%d",&copia.data.mes);
        printf("\nInsira o ano:\n");
        scanf("%d",&copia.data.ano);
    }
    while(check_data(copia.data) != 0);

    do{
        printf("\nInsira o horário de início no formato (23 59):\n");
        scanf("%d %d",&copia.horario_ini.hora,&copia.horario_ini.minuto);
        printf("\nInsira o horário de término no formato (23 59):\n");
        scanf("%d %d",&copia.horario_fim.hora,&copia.horario_fim.minuto);
    }
    while(valida_horario(copia.horario_ini) != 0 || valida_horario(copia.horario_fim) != 0 || compara_horario(copia.horario_ini, copia.horario_fim) != 0 || sobrepoe_horario(agenda,*quantidade_provas,copia));

    printf("\nInsira a descrição da prova:\n");
    scanf(" %50[^\n]",copia.desc);

    printf("\nInsira o local da prova:\n");
    scanf(" %50[^\n]",copia.local);
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

int valida_horario(struct horario hora_a_checar){ //return 1 == Invalid horario; return 0 == valid horario
    if(hora_a_checar.hora > 23 || hora_a_checar.hora < 0){
        printf("\nHorário inválido!");
        return 1;
    }
    if(hora_a_checar.minuto > 59 || hora_a_checar.minuto < 0){
        printf("\nHorário inválido!");
        return 1;
    }
    return 0;
}

int compara_horario(struct horario hora_ini, struct horario hora_fim){//return 1 == inválido; return 0 == valido
    int horario_ini = (hora_ini.hora * 60) + hora_ini.minuto;
    int horario_fim = (hora_fim.hora * 60) + hora_fim.minuto;
    if(horario_ini >= horario_fim){
        printf("\nO horário de término deve ser após o horário de início!");
        return 1;
    }
    return 0;
}

int sobrepoe_horario(struct prova *agenda, int n_provas, struct prova prova_nova){ //return 1 == conflito; return 0 == sem conflito
    int prova_nova_ini = (prova_nova.horario_ini.hora * 60) + prova_nova.horario_ini.minuto;
    int prova_nova_fim = (prova_nova.horario_fim.hora * 60) + prova_nova.horario_fim.minuto;
    for(int i = 0; i < n_provas; i++){
        if(agenda[i].data.dia == prova_nova.data.dia &&
            agenda[i].data.mes == prova_nova.data.mes &&
            agenda[i].data.ano == prova_nova.data.ano){

            int prova_compara_ini = (agenda[i].horario_ini.hora * 60) + agenda[i].horario_ini.minuto;
            int prova_compara_fim = (agenda[i].horario_fim.hora * 60) + agenda[i].horario_fim.minuto;

            if(prova_nova_ini < prova_compara_fim && prova_compara_ini < prova_nova_fim){
                printf("\nHorário em conflito com outra prova já cadastrada no mesmo dia!");
                return 1; // tem conflito
            }
        }
    }
    return 0; //nao tem conflito
}
