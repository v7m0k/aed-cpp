#include <iostream>
#include <iomanip>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <cctype>
#include <locale.h>
#include <fstream>

using namespace std;

FILE* openFile(const char* filename, const char* mode) {
    FILE* file = fopen(filename, mode);
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }
    return file;
}

FILE *PontLivros;
FILE *PontAutores;
FILE *PontFornecedores;
FILE *PontClientes;

typedef struct {
    int dia, mes, ano;
} Reg_Data;

typedef struct {
    char Titulo[100];
    long int Codigo;
    int Estoque;
    float PrecoCusto, PrecoVenda;
    long int CodAutor;
    Reg_Data DataCadastro;
} Reg_Livro;

typedef struct {
    char Nome[50];
    long int Codigo;
    Reg_Data DataCadastro;
} Reg_Autor;

typedef struct {
    char Nome[50];
    long int Codigo;
    Reg_Data DataCadastro;
} Reg_Fornecedor;

typedef struct {
    char Nome[50];
    long int Codigo;
    Reg_Data DataCadastro;
} Reg_Cliente;

// Prototipação de funções
void Login();
void Menu_Principal();
void Menu_Gerenc_Cadastros();
void Menu_Gerenc_Relatorios();
void Cadastro_Livros();
void Cadastro_Autores();
void Cadastro_Fornecedores();
void Cadastro_Clientes();
void Relatorio_Geral_Livros();
void Relatorio_Geral_Autores();
void Relatorio_Geral_Fornecedores();
void Relatorio_Geral_Clientes();
void Atualiza_Estoque();
void Busca_Livro();
void Busca_Autor();
void Busca_Fornecedor();
void Busca_Cliente();
void Relatorio_Sumario();
void Backup_Dados();
long int Busca_Livro_Cod(long int cod);
long int Busca_Autor_Cod(long int cod);
long int Busca_Fornecedor_Cod(long int cod);
long int Busca_Cliente_Cod(long int cod);
void Imprime_Data(Reg_Data D);
Reg_Data DataAtual();

// dados do login
const string user = "admin";
const string password = "admin";

void Login() {
    string usuario, senha;

    cout << "\n===== LOGIN =====\n";
    cout << "Usuário: ";
    cin >> usuario;
    cout << "Senha: ";
    cin >> senha;

    if (usuario == user && senha == password) {
        cout << "\nLogin bem-sucedido!\n";
    } else {
        cout << "\nUsuário ou senha incorretos. Tente novamente.\n";
        Login();
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    Login();
    
    Menu_Principal();
    return 0;
}

void Menu_Principal() {
    int op;
    do {
        system("cls");
        cout << "\n ----------------------------";
        cout << "\n ===== BIBLIOTECA VIRTUAL ====";
        cout << "\n ----------------------------" << endl;
        cout << "\n 1 - GERENCIAMENTO DE CADASTROS";
        cout << "\n 2 - GERENCIAMENTO DE RELATÓRIOS" << endl;
        cout << "\n =====================";
        cout << "\n 3 - ATUALIZAR ESTOQUE";
        cout << "\n 4 - BUSCAR LIVRO";
        cout << "\n 5 - BUSCAR AUTOR";
        cout << "\n 6 - BUSCAR FORNECEDOR";
        cout << "\n 7 - BUSCAR CLIENTE";
        cout << "\n =====================";
        cout << "\n 8 - SUMARIO";
        cout << "\n 9 - BACKUP DE DADOS";
        cout << "\n =====================" << endl;
        cout << "\n 0 - SAIR DO SISTEMA\n";
        cout << "\n ESCOLHA OPÇÃO: ";
        cin >> op;
        switch (op) {
            case 1:
                Menu_Gerenc_Cadastros();
                break;
            case 2:
                Menu_Gerenc_Relatorios();
                break;
            case 3:
                Atualiza_Estoque();
                break;
            case 4:
                Busca_Livro();
                break;
            case 5:
                Busca_Autor();
                break;
            case 6:
                Busca_Fornecedor();
                break;
            case 7:
                Busca_Cliente();
                break;
            case 8:
                Relatorio_Sumario();
                break;
            case 9:
                Backup_Dados();
                break;
        }
    } while (op != 0);
}

void Relatorio_Sumario() {
    system("cls");
    cout << "\n ----------------------------";
    cout << "\n ==== RELATÓRIO SUMÁRIO ====";
    cout << "\n ----------------------------\n";

    int totalAutores = 0, totalFornecedores = 0, totalClientes = 0, totalLivros = 0;
    double valorTotalEstoque = 0.0;
    Reg_Autor Autor;
    Reg_Fornecedor Fornecedor;
    Reg_Cliente Cliente;
    Reg_Livro Livro;

    // AUTORES
    FILE* file = fopen("Autores.dat", "rb");
    if (file != nullptr) {
        while (fread(&Autor, sizeof(Autor), 1, file)) totalAutores++;
        fclose(file);
    } else {
        perror("Erro ao abrir o arquivo Autores.dat");
    }

    // FORNECEDORES
    file = fopen("Fornecedores.dat", "rb");
    if (file != nullptr) {
        while (fread(&Fornecedor, sizeof(Fornecedor), 1, file)) totalFornecedores++;
        fclose(file);
    } else {
        perror("Erro ao abrir o arquivo Fornecedores.dat");
    }

    // CLIENTES
    file = fopen("Clientes.dat", "rb");
    if (file != nullptr) {
        while (fread(&Cliente, sizeof(Cliente), 1, file)) totalClientes++;
        fclose(file);
    } else {
        perror("Erro ao abrir o arquivo Clientes.dat");
    }

    // LIVROS
    file = fopen("Livros.dat", "rb");
    if (file != nullptr) {
        while (fread(&Livro, sizeof(Livro), 1, file)) {
            totalLivros++;
            valorTotalEstoque += Livro.PrecoVenda * Livro.Estoque;
        }
        fclose(file);
    } else {
        perror("Erro ao abrir o arquivo Livros.dat");
    }

    cout << "\n Total de Autores: " << totalAutores;
    cout << "\n Total de Fornecedores: " << totalFornecedores;
    cout << "\n Total de Clientes: " << totalClientes;
    cout << "\n Total de Livros: " << totalLivros;
    cout << "\n Valor Total do Estoque: R$ " << valorTotalEstoque << endl;

    system("pause");
}

void Backup_Dados() {
    system("cls");
    cout << "\n ----------------------------";
    cout << "\n ==== BACKUP DE DADOS ====";
    cout << "\n ----------------------------\n";
    
    ifstream src;
    ofstream dest;

    const char* files[] = {"Autores.dat", "Fornecedores.dat", "Clientes.dat", "Livros.dat"};
    const char* backupFiles[] = {"Autores.bak", "Fornecedores.bak", "Clientes.bak", "Livros.bak"};

    for (int i = 0; i < 4; ++i) {
        src.open(files[i], ios::binary);
        dest.open(backupFiles[i], ios::binary);

        if (src.is_open() && dest.is_open()) {
            dest << src.rdbuf();  // Copy the file content
            cout << "Backup realizado para " << files[i] << endl;
        } else {
            cout << "Falha ao criar backup para " << files[i] << endl;
        }

        src.close();
        dest.close();
    }

    cout << "\n Backup concluído.\n";
    system("pause");
}

void Menu_Gerenc_Cadastros() {
    int op;
    do {
        system("cls");
        cout << "\n ----------------------------";
        cout << "\n ==== CADASTRO DE DADOS ====";
        cout << "\n ----------------------------";
        cout << "\n 1 - CADASTRO DE LIVROS";
        cout << "\n 2 - CADASTRO DE AUTORES";
        cout << "\n 3 - CADASTRO DE FORNECEDORES";
        cout << "\n 4 - CADASTRO DE CLIENTES";
        cout << "\n 0 - VOLTAR AO MENU PRINCIPAL\n";
        cout << "\n ESCOLHA OPÇÃO: "; 
        cin >> op;
        switch (op) {
            case 1:
                Cadastro_Livros();
                break;
            case 2:
                Cadastro_Autores();
                break;
            case 3:
                Cadastro_Fornecedores();
                break;
            case 4:
                Cadastro_Clientes();
                break;
        }
    } while (op != 0);
}

void Menu_Gerenc_Relatorios() {
    int op;
    do {
        system("cls");
        cout << "\n ----------------------------";
        cout << "\n     ==== RELATÓRIOS ====";
        cout << "\n ----------------------------";
        cout << "\n 1 - RELATÓRIO DE LIVROS";
        cout << "\n 2 - RELATÓRIO DE AUTORES";
        cout << "\n 3 - RELATÓRIO DE FORNECEDORES";
        cout << "\n 4 - RELATÓRIO DE CLIENTES";
        cout << "\n 0 - VOLTAR AO MENU PRINCIPAL";
        cout << "\n ESCOLHA OPÇÃO: "; 
        cin >> op;
        switch (op) {
            case 1:
                Relatorio_Geral_Livros();
                break;
            case 2:
                Relatorio_Geral_Autores();
                break;
            case 3:
                Relatorio_Geral_Fornecedores();
                break;
            case 4:
                Relatorio_Geral_Clientes();
                break;
        }
    } while (op != 0);
}

Reg_Data DataAtual() {
    Reg_Data D;
    time_t mytime = time(NULL);
    struct tm tm = *localtime(&mytime);
    D.dia = tm.tm_mday;
    D.mes = tm.tm_mon + 1;
    D.ano = tm.tm_year + 1900;
    return D;
}

void Imprime_Data(Reg_Data D) {
    cout << setw(2) << setfill('0') << D.dia << "/";
    cout << setw(2) << setfill('0') << D.mes << "/";
    cout << D.ano;
}

void Cadastro_Livros() {
    char opcao;
    Reg_Livro Livro;
    long int cod;
    system("cls");
    cout << "\n ---------------------------";
    cout << "\n ==== CADASTRO DE LIVROS ====";
    cout << "\n ---------------------------\n";
    do {
        cout << "\n Código: "; 
        cin >> cod;
        if (Busca_Livro_Cod(cod) != -1) {
            cout << "\n LIVRO JÁ CADASTRADO\n";
        } else {
            Livro.Codigo = cod;
            cin.ignore();  
            cout << " Título: "; 
            cin.getline(Livro.Titulo, sizeof(Livro.Titulo));
            cout << " Estoque: ";  
            cin >> Livro.Estoque;
            cout << " Preço de Custo: "; 
            cin >> Livro.PrecoCusto;
            cout << " Preço de Venda: "; 
            cin >> Livro.PrecoVenda;
            cout << " Código do Autor: "; 
            cin >> Livro.CodAutor;
            Livro.DataCadastro = DataAtual();  
            cout << "\n CONFIRMA CADASTRO? - [S] para confirmar: "; 
            char op; 
            cin >> op;
            if (toupper(op) == 'S') {
                PontLivros = fopen("Livros.dat", "ab");
                if (PontLivros == NULL) {
                    perror("Erro ao abrir o arquivo Livros.dat");
                    exit(1);
                }
                fwrite(&Livro, sizeof(Livro), 1, PontLivros);
                fclose(PontLivros);
            }
        }
        cout << "\n ADICIONAR OUTRO LIVRO? - [S] para adicionar: "; 
        cin >> opcao;
    } while (toupper(opcao) == 'S');
}

void Cadastro_Autores() {
    char opcao;
    Reg_Autor Autor;
    long int cod;
    system("cls");
    cout << "\n ----------------------------";
    cout << "\n ==== CADASTRO DE AUTORES ====";
    cout << "\n ----------------------------\n";
    do {
        cout << "\n Código: "; 
        cin >> cod;
        if (Busca_Autor_Cod(cod) != -1) {
            cout << "\n AUTOR JÁ CADASTRADO\n";
        } else {
            Autor.Codigo = cod;
            cin.ignore();  
            cout << " Nome: "; 
            cin.getline(Autor.Nome, sizeof(Autor.Nome));
            Autor.DataCadastro = DataAtual();  
            cout << "\n CONFIRMA CADASTRO? - [S] para confirmar: "; 
            char op; 
            cin >> op;
            if (toupper(op) == 'S') {
                PontAutores = fopen("Autores.dat", "ab");
                if (PontAutores == NULL) {
                    perror("Erro ao abrir o arquivo Autores.dat");
                    exit(1);
                }
                fwrite(&Autor, sizeof(Autor), 1, PontAutores);
                fclose(PontAutores);
            }
        }
        cout << "\n ADICIONAR OUTRO AUTOR? - [S] para adicionar: "; 
        cin >> opcao;
    } while (toupper(opcao) == 'S');
}

void Cadastro_Fornecedores() {
    char opcao;
    Reg_Fornecedor Fornecedor;
    long int cod;
    system("cls");
    cout << "\n ---------------------------";
    cout << "\n === CADASTRO DE FORNECEDORES ===";
    cout << "\n ---------------------------\n";
    do {
        cout << "\n Código: "; 
        cin >> cod;
        if (Busca_Fornecedor_Cod(cod) != -1) {
            cout << "\n FORNECEDOR JÁ CADASTRADO\n";
        } else {
            Fornecedor.Codigo = cod;
            cin.ignore();  
            cout << " Nome: "; 
            cin.getline(Fornecedor.Nome, sizeof(Fornecedor.Nome));
            Fornecedor.DataCadastro = DataAtual();  
            cout << "\n CONFIRMA CADASTRO? - [S] para confirmar: "; 
            char op; 
            cin >> op;
            if (toupper(op) == 'S') {
                PontFornecedores = fopen("Fornecedores.dat", "ab");
                if (PontFornecedores == NULL) {
                    perror("Erro ao abrir o arquivo Fornecedores.dat");
                    exit(1);
                }
                fwrite(&Fornecedor, sizeof(Fornecedor), 1, PontFornecedores);
                fclose(PontFornecedores);
            }
        }
        cout << "\n ADICIONAR OUTRO FORNECEDOR? - [S] para adicionar: "; 
        cin >> opcao;
    } while (toupper(opcao) == 'S');
}

void Cadastro_Clientes() {
    char opcao;
    Reg_Cliente Cliente;
    long int cod;
    system("cls");
    cout << "\n ---------------------------";
    cout << "\n === CADASTRO DE CLIENTES ===";
    cout << "\n ---------------------------\n";
    do {
        cout << "\n Código: "; 
        cin >> cod;
        if (Busca_Cliente_Cod(cod) != -1) {
            cout << "\n CLIENTE JÁ CADASTRADO\n";
        } else {
            Cliente.Codigo = cod;
            cin.ignore();  
            cout << " Nome: "; 
            cin.getline(Cliente.Nome, sizeof(Cliente.Nome));
            Cliente.DataCadastro = DataAtual();  
            cout << "\n CONFIRMA CADASTRO? - [S] para confirmar: "; 
            char op; 
            cin >> op;
            if (toupper(op) == 'S') {
                PontClientes = fopen("Clientes.dat", "ab");
                if (PontClientes == NULL) {
                    perror("Erro ao abrir o arquivo Clientes.dat");
                    exit(1);
                }
                fwrite(&Cliente, sizeof(Cliente), 1, PontClientes);
                fclose(PontClientes);
            }
        }
        cout << "\n ADICIONAR OUTRO CLIENTE? - [S] para adicionar: "; 
        cin >> opcao;
    } while (toupper(opcao) == 'S');
}

void Relatorio_Geral_Livros() {
    Reg_Livro Livro;
    system("cls");
    cout << "\n ----------------------------";
    cout << "\n ==== RELATÓRIO DE LIVROS ====";
    cout << "\n ----------------------------\n";
    PontLivros = fopen("Livros.dat", "rb");
    if (PontLivros == NULL) {
        perror("Erro ao abrir o arquivo Livros.dat");
        exit(1);
    }
    while (fread(&Livro, sizeof(Livro), 1, PontLivros)) {
        cout << "\n Código: " << Livro.Codigo;
        cout << "\n Título: " << Livro.Titulo;
        cout << "\n Estoque: " << Livro.Estoque;
        cout << "\n Preço de Custo: " << Livro.PrecoCusto;
        cout << "\n Preço de Venda: " << Livro.PrecoVenda;
        cout << "\n Código do Autor: " << Livro.CodAutor;
        cout << "\n Data de Cadastro: "; 
        Imprime_Data(Livro.DataCadastro);
        cout << endl;
    }
    fclose(PontLivros);
    system("pause");
}

void Relatorio_Geral_Autores() {
    Reg_Autor Autor;
    system("cls");
    cout << "\n ----------------------------";
    cout << "\n ==== RELATÓRIO DE AUTORES ====";
    cout << "\n ----------------------------\n";
    PontAutores = fopen("Autores.dat", "rb");
    if (PontAutores == NULL) {
        perror("Erro ao abrir o arquivo Autores.dat");
        exit(1);
    }