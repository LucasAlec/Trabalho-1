//
//
#include "EscreveVetor1EmArq.h"
#include "ChecaSeDirExiste.h"//----->Para poder chamar 'bool ChecaSeDirExiste(string&  Dir)'
#include "InsereArqEmDir_0.h"//----Para poder usar 'InsereArqEmDir_CTrabComDir_0(string&     Dir, int&       NarquivoParaSerInserido_Max)'
//

#include "windows.h"//-----Escrever Caracteres Latinos
#include <iostream>//-Vai usar cin e/ou cout
#include <fstream>//-----Usar Objetos "ofstream  Escrever em arquivos" e "ifstream ler em Arquivos
#include <cstdio>//----Usar exit(0): exit(10;...
//
#include <iomanip>//----Trabalha com precisão qualquer com double
using std::setprecision;//----Especificar precisão para double
using namespace std;
//




void EscreveVetor1EmArq( /* dados de entrada*/
						 int&        DimVetor, 
						 double*     VarX, 
						 double*     Vetor, 
						 string&     Dir,
	                     string&     Arquivo, 
						 string&     DirParaERRO, 
						 int&        Precisao,
						 //Retorna variavel lógica indicando sucesso (true) ou falha(false)
						 bool&       Sucesso)
{
	/*
	VarX[DimVetor]
	Vetor[DimVetor]
	*/
	//
	SetConsoleOutputCP(GetACP());//----Escrever Caracteres Latinos
    //
	string     DirMaisArquivo;
	//
	bool       Veredito;
	DirMaisArquivo = Dir;
	DirMaisArquivo += "/";
	DirMaisArquivo += Arquivo;
	//
	//----Estanciando Objeto "ofstream"
	ofstream       Obj_00_ofstream;
	//---Abrindo Dir+Arq
	//
	Veredito = ChecaSeDirExiste(Dir);
	//
	if (Veredito == false)
	{
		string         Tecla;
		string         DirMaisArqERRO_0;
		ofstream       Obj_00_N_ofstream;
		//
		//
		string         LOG_EscreveVetor1EmArq;
		string         Dir_Log;
		bool           Veredito_0;
		//
		LOG_EscreveVetor1EmArq = "LOG_EscreveVetor1EmArq.txt";
		Dir_Log = DirParaERRO;
		//
		Veredito_0 = ChecaSeDirExiste(Dir_Log);
		//
		//
		if (Veredito_0 == false)
		{
			cout << " Fornecido um Diretório não válido para arquivos de erro  (LOG) = " << Dir_Log << "\n";
			cout << "Digite Tecla para continuar " << "\n";
			//////////cin >> Tecla;
			//------------------------------------------------------------------------------------>IMPORTANTE--28/04/2021
			getline(cin, Tecla, '\n');//------>Ler string com caracter espaço em branco
			//------------------------------------------------------------------------------------>IMPORTANTE--28/04/2021
			//////////////////Sucesso = false;
			//			
			Obj_00_N_ofstream << " Também foi Fornecido um Diretório + Arquivo não válido para para escrever os dados " << DirMaisArquivo << "\n";
			cout << "Digite Tecla para continuar " << "\n";
			//////////////////////cin >> Tecla;
			//------------------------------------------------------------------------------------>IMPORTANTE--28/04/2021
			getline(cin, Tecla, '\n');//------>Ler string com caracter espaço em branco
			//------------------------------------------------------------------------------------>IMPORTANTE--28/04/2021
			Sucesso = false;
			///////exit(0);
		}
		else
		{
			//
			InsereArqEmDir_0(Dir_Log, LOG_EscreveVetor1EmArq);
			//
			string         DirAux;
			//
			DirAux = Dir_Log;
			DirAux += "/";
			DirAux += LOG_EscreveVetor1EmArq;
			//
			Obj_00_N_ofstream.open(DirAux.c_str());
			//
			Obj_00_N_ofstream << " Fornecido um Diretório + Arquivo não válido para para escrever os dados " << DirMaisArquivo << "\n";
			//
			cout << "Digite Tecla para continuar " << "\n";
			//////////cin >> Tecla;
			//------------------------------------------------------------------------------------>IMPORTANTE--28/04/2021
			getline(cin, Tecla, '\n');//------>Ler string com caracter espaço em branco
			//------------------------------------------------------------------------------------>IMPORTANTE--28/04/2021
			Sucesso = false;
			Obj_00_N_ofstream.close();//----Fechando arquivo
			////////////exit(0);
		}
		
	}
	else
	{
		//
		Obj_00_ofstream.open(DirMaisArquivo.c_str());
		//
		Obj_00_ofstream << "   VALOR  DE  X     " << "          VALOR  DA  SOLUÇÃO    " << "\n";
		Obj_00_ofstream << "\n";
		for (int i = 0; i < DimVetor; i++)
		{
			//#######################################
			Obj_00_ofstream << std::fixed << setprecision(Precisao) << "  " << VarX[i] << "                 " << Vetor[i] << "\n";
			/*
			Escrevendo o vetor com a precisão especificada
			*/
			//#######################################
		}
		//
		Sucesso = true;//------Disco + Arquivo  é um disco válido
		//	
		Obj_00_ofstream.close();//----Fechando arquivo
		//
	}
	//

}
