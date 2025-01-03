#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ALUNOS 30
#define MAX_INSTRUTORES 10
#define MAX_AULAS 100

typedef struct _Data{
    int dia, mes, ano;
} Data;

typedef struct _Hora{
    int hora, minuto;
} Hora;

typedef struct _Aluno{
    int numero;
    char nome[100];
    char morada[200];
    char email[100];
    Data dataNascimento;
    int  cartaConduçao;
    char cartaoCidadao[20];
    char nif[10];
    char rua[100];
    char codigoPostal[10];
    char localidade[100];
    char numeroPorta[6];
    unsigned short int ativo;
} Aluno;

typedef struct _Instrutor{
    int numero;
    char nome[100];
    char email[100];
    Data entradaEscola;
    char cartaoCidadao[20];   
    char nif[10];
    unsigned short int ativo;
} Instrutor;

Aluno alunos[MAX_ALUNOS];
Instrutor instrutores[MAX_INSTRUTORES];

/////////////////////////////////////////////////////////               structs             /////////////////////////////////////////////////////////////

int numAlunos = 0;
void menuInicial(void);
void menuGestaoAlunos(void);
void novoAluno(void);
void listarAlunos(void);
void pesquisarAlunosNome(void);
void alterarAlunos(void);
void consultarAluno(void); 
void alterarEstadoAluno(void);
//void pesquisarAlunosNome(void);


int numInstrutores = 0;
void menuGestaoInstrutores(void);
void inserirInstrutor(void);
void listarInstrutores(void);
void alterarInstrutor(void);
void pesquisarInstrutorNome(void);
void consultarInstrutor(void); 
void listaInstrutoresAtivos(void);
void ordenarInstrutoresPorNome(void);


int main() {
    menuInicial();
    return 0;
}

void menuInicial() {
    int opcao;
    do {
        printf("\n===== MarTranquilo - Escola de Condução =====\n");
        printf("1 - Gestão de Alunos\n");
        printf("2 - Gestão de Instrutores\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                menuGestaoAlunos();
                break;
            case 2:
                menuGestaoInstrutores();
                break;
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);
}

void menuGestaoInstrutores() {
    int opcao;
    do {
        printf("\n=== Gestão de Instrutores ===\n");
        printf("1 - Registar novo Instrutor\n");
        printf("2 - Listar Instrutores\n");
        printf("3 - Pesquisar Instrutor por Nome\n");
        printf("4 - Alterar Informações de um Aluno\n");
        printf("5 - Consultar Dados de um Instrutor\n");
        printf("6 - Consultar lista de instrutores ativos\n");
        printf("7 - Ordenar Instrutores por Nome\n"); 
        printf("0 - Voltar ao menu inicial\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                inserirInstrutor();
                break;
            case 2:
                listarInstrutores();
                break;
            case 3:
                pesquisarInstrutorNome();
                break;
            case 4:
                alterarInstrutor();
                break;
            case 5:
                consultarInstrutor();
                break;
            case 6:
                listaInstrutoresAtivos();
                break;
            case 7:
                ordenarInstrutoresPorNome();
                break;
            case 0:
                printf("Voltando ao menu inicial...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);
}

void inserirInstrutor() {
    if (numInstrutores >= MAX_INSTRUTORES) {
        printf("\nNúmero máximo de Instrutores atingido. Não é possível adicionar mais alunos.\n");
        return;
    }
    Instrutor novoInstrutor;
    novoInstrutor.numero = numInstrutores + 1;

    printf("\n=== Registar Novo Instrutor ===\n");
    printf("Nome:");
    getchar();

    fgets(novoInstrutor.nome, 100, stdin);
    novoInstrutor.nome[strcspn(novoInstrutor.nome, "\n")] = 0;
   
    printf("Email:");
    fgets(novoInstrutor.email, 100, stdin);
    novoInstrutor.email[strcspn(novoInstrutor.email, "\n")] = 0;
    printf("Data de entrada na escola (DD MM AAAA):");
    scanf("%d %d %d", &novoInstrutor.entradaEscola.dia, &novoInstrutor.entradaEscola.mes, &novoInstrutor.entradaEscola.ano);
   
    printf("Cartao Cidadao:");
    scanf("%s", novoInstrutor.cartaoCidadao);

    printf("(1 = ativo, 0 = nao ativo): ");
    scanf("%hu", &novoInstrutor.ativo);

    instrutores [numInstrutores++] = novoInstrutor;
    printf("\nInstrutor inserido com sucesso!\n");
}

void  listarInstrutores() {
    if (numInstrutores == 0) {
        printf("\nNão há Instrutores cadastrados.\n");
        return;
    }
    printf("\n=== Lista de instrutores ===\n");
    for (int i = 0; i < numInstrutores; i++) {
        Instrutor b = instrutores[i];
        printf("\nNúmero: %d\n", b.numero);

        printf("Nome: %s\n", b.nome);

        printf("Email: %s\n", b.email);

        printf("Data de Nascimento: %02d/%02d/%04d\n", b.entradaEscola.dia, b.entradaEscola.mes, b.entradaEscola.ano);

        printf("Cartão de Cidadão: %s\n",b.cartaoCidadao);

        printf("Ativo: %d\n",b.ativo);

    }

}

void alterarInstrutor() {
    if (numInstrutores == 0) {
        printf("\nNão há instrutores cadastrados.\n");
        return;
    }

    char nomePesquisa[100];
    printf("\nDigite o nome do instrutor que deseja alterar: ");
    getchar(); // Limpa o buffer
    fgets(nomePesquisa, 100, stdin);
    nomePesquisa[strcspn(nomePesquisa, "\n")] = 0;

    for (int i = 0; i < numInstrutores; i++) {
        if (strcasecmp(instrutores[i].nome, nomePesquisa) == 0) {
            printf("\n=== Alterar Informações ===\n");

            printf("Nome atual: %s\nNovo nome: ", instrutores[i].nome);
            fgets(instrutores[i].nome, 100, stdin);
            instrutores[i].nome[strcspn(instrutores[i].nome, "\n")] = 0;

            printf("Cartão de cidadão atual: %s\nNovo cartão: ", instrutores[i].cartaoCidadao);
            fgets(instrutores[i].cartaoCidadao, 20, stdin);
            instrutores[i].cartaoCidadao[strcspn(instrutores[i].cartaoCidadao, "\n")] = 0;

            printf("Email atual: %s\nNovo email: ", instrutores[i].email);
            fgets(instrutores[i].email, 100, stdin);
            instrutores[i].email[strcspn(instrutores[i].email, "\n")] = 0;

            printf("Data de entrada na escola atual: %02d/%02d/%04d\n",
                   instrutores[i].entradaEscola.dia,
                   instrutores[i].entradaEscola.mes,
                   instrutores[i].entradaEscola.ano);
            printf("Nova data de entrada (DD MM AAAA): ");
            scanf("%d %d %d",
                  &instrutores[i].entradaEscola.dia,
                  &instrutores[i].entradaEscola.mes,
                  &instrutores[i].entradaEscola.ano);

            printf("Estado atual: %s\nNovo estado (1 para ativo, 0 para inativo): ",
                   instrutores[i].ativo ? "Ativo" : "Inativo");
            scanf("%hu", &instrutores[i].ativo);

            printf("\nInformações alteradas com sucesso!\n");
            return;
        }
    }
    printf("\nNenhum instrutor encontrado com o nome '%s'.\n", nomePesquisa);
}


void pesquisarInstrutorNome() {
    if (numInstrutores == 0) {
        printf("\nNão há instrutores cadastrados.\n");
        return;
    }

    char nomePesquisa[100];
    printf("\nDigite o nome do instrutor que deseja pesquisar: ");
    getchar(); // Limpa o buffer
    fgets(nomePesquisa, 100, stdin);
    nomePesquisa[strcspn(nomePesquisa, "\n")] = 0;

    printf("\n=== Resultados da Pesquisa ===\n");
    int encontrado = 0;
    for (int i = 0; i < numInstrutores; i++) {
        if (strncasecmp(instrutores[i].nome, nomePesquisa, strlen(nomePesquisa)) == 0) {
            Instrutor a = instrutores[i];
            printf("\nNúmero: %d\n", a.numero);
            printf("Nome: %s\n", a.nome);
            printf("Email: %s\n", a.email);
            printf("Data de Entrada: %02d/%02d/%04d\n", 
                   a.entradaEscola.dia, 
                   a.entradaEscola.mes, 
                   a.entradaEscola.ano);
            printf("Cartão de Cidadão: %s\n", a.cartaoCidadao);
            printf("Ativo: %s\n", a.ativo ? "Sim" : "Não");
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("\nNenhum instrutor encontrado com o nome '%s'.\n", nomePesquisa);
    }
}

void consultarInstrutor() {
    if (numInstrutores == 0) {
        printf("\nNão há instrutores cadastrados.\n");
        return;
    }

    char nomePesquisa[100];
    printf("\nDigite o nome completo do instrutor que deseja pesquisar: ");
    getchar(); // Limpa o buffer
    fgets(nomePesquisa, 100, stdin);
    nomePesquisa[strcspn(nomePesquisa, "\n")] = 0;

    printf("\n=== Resultados da Pesquisa ===\n");
    int encontrado = 0;
    for (int i = 0; i < numInstrutores; i++) {
        // Compara a string inteira com insensibilidade a maiúsculas e minúsculas
        if (strcasecmp(instrutores[i].nome, nomePesquisa) == 0) {
            Instrutor a = instrutores[i];
            printf("\nNúmero: %d\n", a.numero);
            printf("Nome: %s\n", a.nome);
            printf("Email: %s\n", a.email);
            printf("Data de Entrada: %02d/%02d/%04d\n", 
                   a.entradaEscola.dia, 
                   a.entradaEscola.mes, 
                   a.entradaEscola.ano);
            printf("Cartão de Cidadão: %s\n", a.cartaoCidadao);
            printf("Ativo: %s\n", a.ativo ? "Sim" : "Não");
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("\nNenhum instrutor encontrado com o nome '%s'.\n", nomePesquisa);
    }
}

void listaInstrutoresAtivos() {
    if (numInstrutores == 0) {
        printf("\nNão há instrutores cadastrados.\n");
        return;
    }
    
    int encontrado = 0;
    printf("\n=== Lista de Instrutores Ativos ===\n");
    for (int i = 0; i < numInstrutores; i++) {
        if (instrutores[i].ativo == 1) {  // Verifica se o instrutor está ativo
            Instrutor b = instrutores[i];
            printf("\nNúmero: %d\n", b.numero);
            printf("Nome: %s\n", b.nome);
            printf("Email: %s\n", b.email);
            printf("Data de Entrada: %02d/%02d/%04d\n", 
                   b.entradaEscola.dia, 
                   b.entradaEscola.mes, 
                   b.entradaEscola.ano);
            printf("Cartão de Cidadão: %s\n", b.cartaoCidadao);
            printf("Ativo: Sim\n");
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("\nNenhum instrutor ativo encontrado.\n");
    }
}

int compararInstrutores(const void *a, const void *b) {
    Instrutor *instrutorA = (Instrutor *)a;
    Instrutor *instrutorB = (Instrutor *)b;
    return strcasecmp(instrutorA->nome, instrutorB->nome);
}

void ordenarInstrutoresPorNome() {
    if (numInstrutores > 0) {
        qsort(instrutores, numInstrutores, sizeof(Instrutor), compararInstrutores);
        printf("\nInstrutores ordenados por nome com sucesso!\n");
    } else {
        printf("\nNão há instrutores para ordenar.\n");
    }
}

void menuGestaoAlunos() {
    int opcao;
    do {
        printf("\n=== Gestão de Alunos ===\n");
        printf("1 - Registar novo aluno\n");
        printf("2 - Alterar Estado do Aluno\n");
        printf("3 - Pesquisar aluno por nome\n");
        printf("4 - Alterar dados de lunos\n");
        printf("5 - Consultar Dados de um aluno\n");
        printf("0 - Voltar ao menu inicial\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                novoAluno();
                break;
            case 2:
                alterarEstadoAluno();
                break;
            case 3:
                pesquisarAlunosNome();
                break;
            case 4:
                alterarAlunos();
                 break;
            case 5:
                consultarAluno();
                break;
          //  case 6:
                
            //    break;
            case 0:
                printf("Voltando ao menu inicial...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);
}























void novoAluno() {
    if (numAlunos >= MAX_ALUNOS) {
        printf("\nNúmero máximo de alunos atingido. Não é possível adicionar mais alunos.\n");
        return;
    }
    Aluno novoAluno;
    novoAluno.numero = numAlunos + 1;
    printf("\n=== Registar Novo Aluno ===\n");
    printf(" \n");

    printf("Nome: ");
        getchar();
        fgets(novoAluno.nome, 100, stdin);
        novoAluno.nome[strcspn(novoAluno.nome, "\n")] = 0;
        printf(" \n");

    printf("Morada: ");
        fgets(novoAluno.morada, 200, stdin);
        novoAluno.morada[strcspn(novoAluno.morada, "\n")] = 0;
        printf(" \n");

    printf("Email: ");
        fgets(novoAluno.email, 100, stdin);
        novoAluno.email[strcspn(novoAluno.email, "\n")] = 0;
        printf(" \n");

    printf("Data de nascimento (DD MM AAAA): ");
        scanf("%d %d %d", &novoAluno.dataNascimento.dia, &novoAluno.dataNascimento.mes, &novoAluno.dataNascimento.ano);
        printf(" \n");

    printf("Cartão de cidadão: ");
        scanf("%s", novoAluno.cartaoCidadao);
        printf(" \n");

    printf("NIF: ");
        scanf("%s", novoAluno.nif);
        printf(" \n");

    printf("Numero da carta de condução: ");
        scanf("%d", &novoAluno.cartaConduçao);
        printf(" \n");
        
    printf("Endereço:\n");
    printf(" \n");
    printf("\tRua: ");
    scanf(" %99[^\n]", novoAluno.rua);
    printf("\tNº Porta: ");
    scanf(" %99[^\n]", novoAluno.numeroPorta);
    printf("\tCodigo postal: ");
    scanf(" %99[^\n]", novoAluno.codigoPostal);
    printf("\tLocalidade: ");
    scanf(" %99[^\n]", novoAluno.localidade);

    printf("(1 = ativo, 0 = nao ativo): ");
    scanf("%hu", &novoAluno.ativo);

    novoAluno.ativo = 1;// por a perguntar ao utilisador se quer que o aluno esteja ativo ou não
    alunos[numAlunos++] = novoAluno;                    
    printf("\nAluno inserido com sucesso!\n");
}

void alterarEstadoAluno() {
    int numeroAluno;
    int novoEstado;

    if (numAlunos == 0) {
        printf("\nNão há alunos cadastrados.\n");
        return;
    }
    printf("\n=== Alterar Estado do Aluno ===\n");
    printf("Digite o número do aluno: ");
    scanf("%d", &numeroAluno);

    int encontrado = 0;
    for (int i = 0; i < numAlunos; i++) {
        if (alunos[i].numero == numeroAluno) {
            encontrado = 1;

            printf("\nAluno encontrado: %s\n", alunos[i].nome);
            printf("Estado atual: %s\n", alunos[i].ativo ? "Ativo" : "Não Ativo");

            printf("Digite o novo estado (1 para Ativo, 0 para Não Ativo): ");
            scanf("%d", &novoEstado);

            if (novoEstado == 0 || novoEstado == 1) {
                alunos[i].ativo = novoEstado;
                printf("\nEstado do aluno atualizado com sucesso!\n");
            } else {
                printf("\nEstado inválido. Por favor, insira 1 para Ativo ou 0 para Não Ativo.\n");
            }
            break;
        }
    }

    if (!encontrado) {
        printf("\nAluno com número %d não encontrado.\n", numeroAluno);
    }
}

void pesquisarAlunosNome() {
    if (numAlunos == 0) {
        printf("\nNão há alunos cadastrados.\n");
        return;
    }
    char nomePesquisa[100];
    printf("\nDigite o nome do instrutor que deseja pesquisar: ");
    getchar(); // Limpa o buffer
    fgets(nomePesquisa, 100, stdin);
    nomePesquisa[strcspn(nomePesquisa, "\n")] = 0;

    printf("\n=== Resultados da Pesquisa ===\n");
    int encontrado = 0;
    for (int i = 0; i < numAlunos; i++) {
        if (strncasecmp(nomePesquisa, alunos[i].nome, strlen(nomePesquisa)) == 0) {
            Aluno a = alunos[i];
            printf("\nNúmero: %d\n",a.numero);
            printf("Nome: %s\n",a.nome);
            printf("Morada: %s\n",a.morada);
            printf("Email: %s\n",a.email);
            printf("Data de nascimento atual: %02d/%02d/%04d\n",
                alunos[i].dataNascimento.dia,
                alunos[i].dataNascimento.mes,
                alunos[i].dataNascimento.ano);
            printf("Cartão de Cidadão: %s\n",a.cartaoCidadao);
            printf("NIF: %s\n",a.nif);
            printf("Ativo: %s\n",a.ativo ? "Sim" : "Não");
            encontrado = 1;
        }
    }
    if (!encontrado) {
        printf("\nNenhum aluno encontrado com o nome '%s'.\n", nomePesquisa);
    }
} 

void alterarAlunos() {
    if (numAlunos == 0) {
        printf("\nNão há instrutores cadastrados.\n");
        return;
    }

    char nomePesquisa[100];
    printf("\nDigite o nome do alunos que deseja alterar: ");
    getchar(); 
    fgets(nomePesquisa, 100, stdin);
    nomePesquisa[strcspn(nomePesquisa, "\n")] = 0;

    for (int i = 0; i < numAlunos; i++) {
        if (strcasecmp(alunos[i].nome, nomePesquisa) == 0) {
            printf("\n=== Alterar Informações ===\n");

            printf("Nome atual: %s\nNovo nome: ", alunos[i].nome);
            fgets(alunos[i].nome, 100, stdin);
            alunos[i].nome[strcspn(alunos[i].nome, "\n")] = 0;

            printf("Cartão de cidadão atual: %s\nNovo cartão: ", alunos[i].cartaoCidadao);
            fgets(alunos[i].cartaoCidadao, 20, stdin);
            alunos[i].cartaoCidadao[strcspn(alunos[i].cartaoCidadao, "\n")] = 0;

            printf("Email atual: %s\nNovo email: ", alunos[i].email);
            fgets(alunos[i].email, 100, stdin);
            alunos[i].email[strcspn(alunos[i].email, "\n")] = 0;

            printf("Data de nascimento atual: %02d/%02d/%04d\n",
                   alunos[i].dataNascimento.dia,
                   alunos[i].dataNascimento.mes,
                   alunos[i].dataNascimento.ano);
            printf("Nova data de nascimento (DD MM AAAA): ");
            scanf("%d %d %d",
                  &alunos[i].dataNascimento.dia,
                  &alunos[i].dataNascimento.mes,
                  &alunos[i].dataNascimento.ano);

            printf("Estado atual: %s\nNovo estado (1 para ativo, 0 para inativo): ",
                   alunos[i].ativo ? "Ativo" : "Inativo");
            scanf("%hu", &alunos[i].ativo);

            printf("\nInformações alteradas com sucesso!\n");
            return;
        }
    }
    printf("\nNenhum aluno encontrado com o nome '%s'.\n", nomePesquisa);
}

void consultarAluno () {
    if (numAlunos == 0) {
        printf("\nNão há alunos cadastrados.\n");
        return;
    }

    char nomePesquisa[100];
    printf("\nDigite o nome completo do aluno que deseja pesquisar: ");
    getchar(); 
    fgets(nomePesquisa, 100, stdin);
    nomePesquisa[strcspn(nomePesquisa, "\n")] = 0;

    printf("\n=== Resultados da Pesquisa ===\n");
    int encontrado = 0;
    for (int i = 0; i < numAlunos; i++) {

        if (strcasecmp(alunos[i].nome, nomePesquisa) == 0) {
            Aluno a = alunos[i];
            printf("\nNúmero: %d\n", a.numero);
            printf("Nome: %s\n", a.nome);
            printf("Email: %s\n", a.email);
            printf("Data de Entrada: %02d/%02d/%04d\n", 
                   a.dataNascimento.dia, 
                   a.dataNascimento.mes, 
                   a.dataNascimento.ano);
            printf("Cartão de Cidadão: %s\n", a.cartaoCidadao);
            printf("Ativo: %s\n", a.ativo ? "Sim" : "Não");
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("\nNenhum aluno encontrado com o nome '%s'.\n", nomePesquisa);
    }
}