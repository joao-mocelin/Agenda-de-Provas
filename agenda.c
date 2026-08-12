#include "agenda.h"

void salva_arquivo(FILE *arquivo,struct prova *provas, int n){
    if(arquivo == NULL){
        printf("\nErro ao salvar arquivo!");
        return;
    }
    fprintf(arquivo,"%d\n",n);
    for(int i = 0; i < n; i++){
        fprintf(arquivo,"%d %d %d\n",provas[i].data.dia,provas[i].data.mes,provas[i].data.ano);
        fprintf(arquivo,"%d %d\n",provas[i].horario_ini.hora,provas[i].horario_ini.minuto);
        fprintf(arquivo,"%d %d\n",provas[i].horario_fim.hora,provas[i].horario_fim.minuto);
        fprintf(arquivo,"%s\n",provas[i].desc);
        fprintf(arquivo,"%s\n",provas[i].local);
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
    scanf(" %149[^\n]",copia.desc);
    limpa_buffer();
    printf("\nInsira o local da prova:\n");
    scanf(" %49[^\n]",copia.local);
    limpa_buffer();
    (*quantidade_provas) += 1;
    struct prova *temp = realloc(agenda,sizeof(struct prova) * (*quantidade_provas));
    if(temp == NULL){
        (*quantidade_provas) -= 1;
        printf("\nFalha ao alocar memória!");
        return agenda;
    }
    agenda = temp;
    int i = (*quantidade_provas) - 1;
    agenda[i] = copia;
    printf("\nProva cadastrada com sucesso.\n");
    system("pause");
    return agenda;
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

void limpa_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void mostra_provas(struct prova *agenda, int quantidade_provas){
    if(quantidade_provas <= 0){
        printf("\nNão há provas agendadas.\n");
        return;
    }
    for(int i = 0; i < quantidade_provas; i++){
        printf("\n%d Data: %02d %02d %04d", i + 1, agenda[i].data.dia, agenda[i].data.mes, agenda[i].data.ano);
        printf("\n  Horário de início: %02d %02d",agenda[i].horario_ini.hora,agenda[i].horario_ini.minuto);
        printf("\n  Horário de término: %02d %02d",agenda[i].horario_fim.hora,agenda[i].horario_fim.minuto);
        printf("\n  Descrição: %s",agenda[i].desc);
        printf("\n  Local: %s\n",agenda[i].local);
    }
}

struct prova *remover_prova(struct prova *agenda, int *quantidade_provas){
    int index_prova;
    if(agenda == NULL || quantidade_provas == NULL){
        printf("\nAgenda vazia, impossível remover elementos!");
        return NULL;
    }
    mostra_provas(agenda,*quantidade_provas);
    do{
        printf("\nDigite o número correspondente à prova que deseja remover ou 0 para cancelar:\n-> ");
        scanf("%d",&index_prova);
        limpa_buffer();
    }while(index_prova < 0 || index_prova > *quantidade_provas);
    if(index_prova == 0){
        printf("\nRemoção de prova cancelada!\n");
        system("pause");
        return agenda;
    }
    index_prova -= 1;
    for(index_prova; index_prova < (*quantidade_provas) - 1; index_prova++){
        agenda[index_prova] = agenda[index_prova + 1];
    }
    (*quantidade_provas) -= 1;
    if(*quantidade_provas == 0){
        free(agenda);
        printf("\nProva removida com sucesso.\n");
        system("pause");
        return NULL;
    }
    struct prova *copia = realloc(agenda, sizeof(struct prova) * (*quantidade_provas));
    if(copia == NULL){
        printf("\nFalha ao alocar memória!");
        return agenda;
    }
    printf("\nProva removida com sucesso.\n");
    system("pause");
    return copia;
}

void pesquisa_data(struct prova *agenda, int quantidade_provas){
    if(agenda == NULL || quantidade_provas <= 0){
        printf("\nNão há provas cadastradas.\n");
        system("pause");
        return;
    }
    struct data data_pesquisa = {0,0,0};
    do{
        printf("\nInsira o dia:\n");
        scanf("%d",&data_pesquisa.dia);
        limpa_buffer();
        printf("\nInsira o mês:\n");
        scanf("%d",&data_pesquisa.mes);
        limpa_buffer();
        printf("\nInsira o ano:\n");
        scanf("%d",&data_pesquisa.ano);
        limpa_buffer();
    }while(check_data(data_pesquisa) != 0);
    for(int i = 0; i < quantidade_provas; i++){
        if(compara_data(agenda[i].data, data_pesquisa) == 1){
            printf("\n%d Data: %02d %02d %04d", i + 1, agenda[i].data.dia, agenda[i].data.mes, agenda[i].data.ano);
            printf("\n  Horário de início: %02d %02d",agenda[i].horario_ini.hora,agenda[i].horario_ini.minuto);
            printf("\n  Horário de término: %02d %02d",agenda[i].horario_fim.hora,agenda[i].horario_fim.minuto);
            printf("\n  Descrição: %s",agenda[i].desc);
            printf("\n  Local: %s\n",agenda[i].local);
        }
    }
    system("pause");
}

int compara_data(struct data data1, struct data data2){ //return 1 == datas iguais; return 0 == datas diferentes
    if(data1.ano == data2.ano && data1.mes == data2.mes && data1.dia == data2.dia){
        return 1;
    }
    return 0;
}
