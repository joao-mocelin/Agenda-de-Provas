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