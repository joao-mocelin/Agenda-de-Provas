# 📅 Agenda de Provas em C

> Sistema de gerenciamento de exames e provas desenvolvido em linguagem C para terminal, focado em alocação dinâmica de memória, manipulação de arquivos e organização estruturada.

---

## 📌 Sobre o Projeto

O **Agenda de Provas** é um software de terminal leve e eficiente projetado para ajudar estudantes a organizarem seu calendário acadêmico. O programa permite registrar provas, validar datas/horários para evitar sobreposições, ordenar automaticamente o cronograma e persistir os dados em disco.

---

## ✨ Funcionalidades Principais

* **Alocação Dinâmica:** Gerenciamento eficiente de memória usando `malloc` e `realloc`.
* **Validação Rígida de Dados:**
  * Checagem de datas válidas (dias por mês e anos bissextos).
  * Validação de horários (formato 24h e término posterior ao início).
  * **Detecção de Conflitos:** Impede o cadastro de provas com sobreposição de horários no mesmo dia.
* **Ordenação Automática:** Implementação do algoritmo *Selection Sort* adaptado para comparar datas e horários cronologicamente.
* **Buscas Inteligentes:** Pesquisa por data exata ou por palavra-chave na descrição (case-insensitive).
* **Persistência de Dados:** Salvamento e carregamento automático via arquivo de texto (`agenda.txt`).

---

## 🛠️ Tecnologias Utilizadas

* **Linguagem:** C (Padrão C99 / C11)
* **Compilador:** GCC / Clang / MSVC
* **Plataforma:** Cross-platform (Windows / Linux / macOS)

---

## 📂 Estrutura dos Arquivos

```text
.
├── main.c        # Ponto de entrada e fluxo do menu principal
├── agenda.c      # Implementação das funções de cadastro, busca, ordenação e IO
├── agenda.h      # Protótipos das funções, estruturas de dados e include guards
└── agenda.txt    # Arquivo gerado automaticamente para persistência dos dados
```

---

## 🚀 Como Compilar e Executar
Pré-requisitos
Ter um compilador C instalado (como o GCC).

Compilando via Terminal (GCC)
# Clone o repositório ou baixe os arquivos
git clone [https://github.com/seu-usuario/agenda-de-provas.git](https://github.com/seu-usuario/agenda-de-provas.git)
cd agenda-de-provas

# Compile o projeto
gcc main.c agenda.c -o agenda

# Execute o programa
# No Windows:
agenda.exe

# No Linux/macOS:
./agenda

---

## 🗺️ Roadmap de Desenvolvimento
## 🟢 Concluído (Versão Atual)
[x] Estruturação modular em arquivos (main.c, agenda.c, agenda.h).

[x] Definição dos tipos abstratos de dados (struct data, struct horario, struct prova).

[x] Inclusão de Include Guards no arquivo de cabeçalho (#ifndef AGENDA_H).

[x] Gerenciamento dinâmico de memória com malloc, realloc e liberação correta com free.

[x] Persistência em arquivo (salva_arquivo e leitura no startup).

[x] Tratamento de erros de abertura e fechamento seguro de arquivo (fopen/fclose).

[x] Validação de entradas no scanf para prevenir loops infinitos em caso de texto/erro de digitação.

[x] Tratamento de anos bissextos na validação de datas.

[x] Algoritmo de prevenção contra sobreposição/conflito de horários de provas.

[x] Algoritmo de ordenação cronológica (Selection Sort) corrigido (menor_idx).

[x] Visualização formatada da lista de provas agendadas.

[x] Funcionalidades de busca (por data e por palavra-chave na descrição).

[x] Remoção de registros com realocação dinâmica de memória.

---

## 🟡 Ideias & Funcionalidades Futuras
⚙️ Melhorias de Código e Arquitetura
[ ] Migração do Algoritmo de Ordenação: Substituir o Selection Sort por um algoritmo O(N log N) como QuickSort (qsort da biblioteca padrão) ou MergeSort.

[ ] Persistência Binária: Migrar a gravação em disco de arquivo de texto simples para formato binário (.bin), melhorando a performance de leitura/escrita.

[ ] Tratamento da Acentuação UTF-8 Cross-platform: Substituir o uso de SetConsoleOutputCP(CP_UTF8) do Windows por uma solução portátil para Linux/Mac.

---

## 🎯 Novas Funcionalidades para o Usuário
[ ] Edição de Provas: Permitir que o usuário edite uma prova existente sem precisar removê-la e cadastrá-la novamente.

[ ] Sistema de Notificações / Alertas:

[ ] Exibir um aviso no menu inicial se houver provas agendadas para os próximos 3 dias.

[ ] Mostrar contagem regressiva ("Faltam X dias para a prova").

[ ] Filtros Avançados:

[ ] Filtrar provas por intervalo de datas (Ex: "Provas deste mês").

[ ] Filtrar ou categorizar por disciplina/matéria (adicionar campo disciplina na struct prova).

[ ] Sistema de Status / Notas:

[ ] Marcar prova como "Concluída", "Pendente" ou "Cancelada".

[ ] Registrar a nota obtida na prova após a realização.

[ ] Exportação de Dados:

[ ] Exportar agenda no formato .csv (para planilhas do Excel/Google Sheets).

[ ] Exportar no formato .ics (compatível com Google Agenda e Outlook).

---

## ✒️ Autor
Desenvolvido por João — Sinta-se à vontade para enviar PRs e sugestões de melhorias!