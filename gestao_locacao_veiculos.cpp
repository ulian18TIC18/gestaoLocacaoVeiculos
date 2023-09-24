#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Cliente{

    string CPF, nome, DtNascimento, CNH;

};
struct Veiculo{
    string renavan, placaVeiculo, datHoraRetira, datHoraEntrega, lojaRetirada;

};

void incluirCliente(vector<Cliente> &clientes){
    //system("clear||cls");

    Cliente cliente;

    cout << "Digite o nome do cliente: ";
    getline(cin >> ws, cliente.nome);
    cout << "Digite o CPF do cliente: ";
    getline(cin >> ws, cliente.CPF);
    cout << "Digite a data de nascimento: ";
    getline(cin >> ws, cliente.DtNascimento);
    cout << "Digite a CNH do cliente: ";
    getline(cin >> ws, cliente.CNH);
    
    clientes.push_back(cliente);
    cout << "Cliente incluido com sucesso!" << endl;

   // system("pause");
}

void incluirVeiculo(vector<Veiculo> &veiculos){
    //system("clear||cls");

    Veiculo veiculo;

    cout << "Digite as informacoes do veiculo: ";
    cout << "Digite o renavan do veiculo: ";
    getline(cin >>ws, veiculo.renavan);
    cout << "Digite a placa do veiculo: ";
    getline(cin>>ws, veiculo.placaVeiculo);
    cout << "Digite a data e a hora de retirada (prevista): ";
    getline(cin>>ws, veiculo.datHoraRetira);
    cout << "Digite o data e a hora de entrega (prevista): ";
    getline(cin>>ws, veiculo.datHoraEntrega);
    cout << "Digite a loja de retirada do veicuki: ";
    getline(cin>>ws, veiculo.lojaRetirada);

    veiculos.push_back(veiculo);
    cout << "Cliente incluido com sucesso!" << endl;

    //system("pause");
}

void excluirCliente(vector<Cliente> &clientes){
    //system("clear||cls");
    
    string cpfExcluir;

    cout << "Digite o CPF a ser excluido: ";
    cin >> cpfExcluir;

    for (auto id = clientes.begin(); id != clientes.end(); id++){
        if(id -> CPF == cpfExcluir){

            clientes.erase(id);
            cout << "Cliente excluido com sucesso..." << endl;

            return;
        }
    }
    cout << "Cliente nao encontrado!" << endl;
    //system("pause");
}

void excluirVeiculo(vector<Veiculo> &veiculos){
    //system("clear||cls");

    string placaExcluir;

    cout << "Digite a placa do carro a ser exluido: ";
    cin >> placaExcluir;

    for(auto excluir = veiculos.begin(); excluir != veiculos.end(); excluir++){
        if (excluir->placaVeiculo == placaExcluir){

            veiculos.erase(excluir);
            cout << "veiculo exluido com sucesso..." <<endl;

            return;
        }    
    }
    cout << "Veiculo nao encontrado!" << endl;
    //system("pause");

}
void alterarCliente(vector<Cliente> &clientes){
    //system("clear||cls");

    string alterarCliente;
    bool clienteEncontrado = false;

    cout << "Digite o CPF do cliente a ser alterado: ";
    cin >> alterarCliente;

    for (auto cliente = clientes.begin(); cliente != clientes.end(); cliente++){
       
        if (cliente->CPF == alterarCliente){
            
            clienteEncontrado = true;
            cout << "Cliente encontrado. Deseja alterar o nome? (S/N): ";
            char opcao;
            cin >> opcao;

            if (opcao == 'S' || opcao == 's'){
                cout << "Digite o novo nome: ";
                getline(cin >> ws, cliente->nome);                
            }
            cout << "Deseja alterar o CPF? (S/N)";
            cin >> opcao;

            if (opcao =='S' || opcao == 's'){
                cout << "Digite o novo CPF: ";
                getline(cin >> ws, cliente->CPF);
            }
            cout << "Deseja alterar a data de nascimento? (S/N)";
            cin >> opcao;

            if (opcao == 'S' || opcao == 's'){
                cout << "Digite a nova data de nascimento: ";
                getline(cin >> ws, cliente->DtNascimento);                
            }
            cout <<"Deseja alterar a CNH? (S/N)";
            cin >> opcao;

            if(opcao =='S' || opcao == 's'){
                cout << "Digite a nova CNH: ";
                getline(cin>> ws, cliente->CNH);

            }
            cout << "Cliente alterado com sucesso!";
            system("pause");

            return;
        }
    }

    if(!clienteEncontrado){
        cout << "Cliente não encontrado. Tente novamente.";
        //system("pause");
    }

}
void listarClientes(vector<Cliente> &clientes){
    //system("clear || cls");

    if (clientes.empty()){
        cout << "Nao ha clientes cadastrado." << endl;
    }

    else{
        cout << "Lista de clientes:" << endl;

        for(auto cliente = clientes.begin(); cliente != clientes.end(); cliente++){

        cout << "Nome: " << cliente->nome << endl;
        cout << "CPF: " << cliente->CPF << endl;
        cout << "Data de Nascimento: " << cliente->DtNascimento << endl;
        cout << "CNH: " << cliente->CNH << endl;
        cout << "-----------------------------" << endl;

    }
    
    //system("pause");
    
    }
}
void localizarCliente(vector<Cliente> &clientes){
    //system("clear||cls");
    
    string cpfEncontrado;
    
    cout << "Digite o CPF do cliente: ";
    cin >> cpfEncontrado;
    bool encontrado = false;

    for (auto cliente = clientes.begin(); cliente != clientes.end(); cliente++){
        if (cliente->CPF == cpfEncontrado){
            encontrado = true;

            cout << "Os dados do clinete sao: " << endl;
            cout << "Nome: " << cliente->nome << endl;
            cout << "CPF: " << cliente->CPF << endl;
            cout << "Data de Nascimento: " << cliente->DtNascimento << endl;
            cout << "CNH: " << cliente->CNH << endl;
        }
    if(!encontrado){
        cout << "Cliente nao encontrado. Faca uma nova busca" << endl;

    }
}
    
//system("pause");
}
void menuClientes (vector<Cliente> &clientes){
    while(true){
        //system("clear||cls");

        int opcoesCliente;

        cout << "-------Gestao de Clientes-------" << endl;
        cout << "Escolha uma das opcoes a seguir" << endl;
        cout << "1. Incluir" << endl;
        cout << "2. Excluir" << endl;
        cout << "3. Alterar (apenas por CPF)" << endl;
        cout << "4. Listar" << endl;
        cout << "5. Localizar (por CPF)" << endl;
        cout << "0. Sair" << endl;
        cin >> opcoesCliente;

        switch (opcoesCliente){
            case 1:
                incluirCliente(clientes);
                break;
            case 2:
                excluirCliente(clientes);
                break;
            case 3:
                alterarCliente(clientes);
                break;
            case 4:
                listarClientes(clientes);
                break;
            case 5:
                localizarCliente(clientes);
                break;
                return;
            case 0:
                cout << "Retornando ao Menu principal" << endl;
                break;
            default:
                cout <<"Opcao incorreta. Tente novamente." << endl;
                break;

        }
    //system("pause");
    }

}

void menuVeiculo(vector<Veiculo> &veiculos) {
    //system(clear||cls);
    
    while(true){
        int opcao_veiculo;

        cout << "-------Gestao de Veiculos-------" << endl;
        cout << "1. Digite o Renavan: " << endl;
        cout << "2. Placa do Veiculo: " << endl;
        cout << "3. Data e hora da Retirada (Prevista): " << endl;
        cout << "4. Data e hora da Entrega  (Prevista): " << endl;
        cout << "5. Loja de Retira da Veiculo: " << endl;
        cin >> opcao_veiculo;

        switch(opcao_veiculo){
            case 1:
            incluirVeiculo(veiculos);
                break;
            case 2: 
            //excluirVeiculo(veiculos);
                break;
            case 3:
            //alterarVeiculo(veiculos);
                break;
            case 4:
            //listarVeiculo(veiculos);
                break;
            case 5:
            //localizarVeiculos(veiculos);
                break;
            case 0:
            cout << "Retornando ao menu principal..." << endl;
                break;
            default:
            cout << "Opcao invalida. Tente novamente..." << endl;           
                break;
        }

    //system("pause");
    }

}

int main (){

vector<Cliente> clientes;
vector<Veiculo> veiculos;

    int operacoes;
    while (true){
        system("clear||cls");
        cout << "------ LOCAFINA S/A ------" << endl;
        cout << "1. Gestao de Clientes" << endl;
        cout << "2. Gestao de Veiculos" << endl;
        cout << "0. Sair" << endl;

        cin >> operacoes;

        switch (operacoes){
            case 1:
            menuClientes(clientes);
            break;
            case 2:
            menuVeiculo(veiculos);
            break;
            case 0:
            cout << "Saindo do programa de cadastos..." << endl;
            break;
        }


    }

return 0;
}