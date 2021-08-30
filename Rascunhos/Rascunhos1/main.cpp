//#include <iostream> em CppTrabDirArq.cpp
//#include <string> em CTrabDirArq.h
//#include <new> em CppTrabDirArq.cpp
//#include <cstdlib> em CppTrabDirArq.cpp
//#include <fstream> em CppTrabDirArq.cpp
//#include <filesystem> em CppTrabDirArq.cpp

//using namespace std; em CppTrabDirArq.cpp
//namespace fs = std::filesystem; em CppTrabDirArq.cpp

// mostrar pwd e tree
// mudar de diretorio -> muda a variavel path
// ter opcao de sair do programa
// Editar arquivos
// 
#include "CTrabDirArq.cpp"

int main() {

	short opcao;
	bool loopExterno = true;
	CTrabDirArq manipulador;
	// Criar funcao loop externo;
	while (loopExterno) {

		cout << "1. Mostrar path atual e diretorios\n2. Criar diretorio\n3. Criar arquivo no diretorio especificado\n";
	
		cin >> opcao;
		
		if (opcao == 1) {
			// mostra as coisas seguindo a variavel path
			//manipulador.mostrarDiretorioAtual_CTrabDirArq();
			//manipulador.mostrarTree_CTrabDirArq();
		}
		
		
		if (opcao == 2) {
			
			short dentro = 1;
			while (dentro == 1) {
				string nome, dir;
				cout << "Digite o nome do diretorio" << endl;
				cin >> nome;
				manipulador.setNovoDir_CTrabDirArq(nome); 
				manipulador.criarDiretorio_CTrabDirArq();
				cout << "Repetir? [1/0]" << endl;
				cin >> dentro;
				if (dentro == 0) {system("tree -ph -D");}
			}
		}
		
		
		if (opcao == 3) {
		
		}
	
	
	else {
		cout << "Digite opcao valida!" << endl;
		break;
	}
	}
	return 0;
}
