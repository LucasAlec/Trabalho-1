//
#include "InsereArqEmDir.h"
//
#include <fstream>//-----Usar Objetos "ofstream  Escrever em arquivos" e "ifstream ler em Arquivos
#include <iostream>//-Vai usar cin e/ou cout  Escrever na tela do DOES
#include <string>
#include "windows.h"//-----Escrever Caracteres Latinos
#include <cstdio>//----Usar exit(0): exit(1);...
#include <iomanip> //-------Escrever double   com precisão especificada   
using std::setprecision;//-------Para especificara a precisão
#include <new>//-----Para alocação de vetor dinãmico
using std::bad_alloc;// --Para tratamento de exceção
using namespace std;
//
void InsereArqEmDir_CTrabComDir_0(string&     Dir, int&       NarquivoParaSerInserido_Max)
//////////////////////void CTrabComDir_0::InsereArqEmDir_CTrabComDir_0(string&     Dir)
{
	string         ArqDir;
	int            NarquivoParaSerInserido;
	string         Tecla_0;
	string         Tecla;
	ofstream       Obj_ofstream;
	int            Ndimension;
	//
	SetConsoleOutputCP(GetACP());//----Escrever Caracteres Latinos
	//
	//const int NarquivoParaSerInserido_Max = 10;
	//
	///string         ArqParaSerInserido[NarquivoParaSerInserido_Max];
	string*        ArqParaSerInserido;
	//
	Ndimension = NarquivoParaSerInserido_Max;
	//
	try{
		ArqParaSerInserido = new string[Ndimension];
	
	}
	catch (bad_alloc){
		string        Tecla;
		cout << " Houve uma má alocação de memória. Isto aconteceu em 'InsereArqEmDir_CTrabComDir_0' " << "\n";
		cout << "Para a vatiável Dinãmica 'ArqParaSerInserido'.  Programa será encerrado." << "\n";
		cout << " Digite tecla para terminar o programa " << " \n";
		cin >> Tecla;
		exit(1);
	}
	//
	//
	int Ntentativa, Indice;
	//
	Ntentativa = 3;
	//
	//
	cout << "\n";
	cout << "Para sua Informação: O número máximo de arquivos a serem inseridos no Diretório é = " << NarquivoParaSerInserido_Max << "\n";
	cout << "\n";
	cout << " Você terá " << Ntentativa << "  Chances para fornecer um número permitido de Arquivos " << "\n";
	cout << "\n";
	//
	Indice = 0;
	while (Indice < Ntentativa)//-- - A
	{//---Início do while (Indice < Ntentativa)//---A
		/////////////////////////////////////SetConsoleOutputCP(GetACP());//----Escrever Caracteres Latinos
		cout << " Digite  um Número de arquivos (Menor ou igual Que " << NarquivoParaSerInserido_Max << " )" << "\n";
		cout << "para ser inserido no Diretório Criado " << "\n";
		cout << "\n";
		cin >> NarquivoParaSerInserido;
		//
		if (NarquivoParaSerInserido > NarquivoParaSerInserido_Max)
		{
			Indice++;
			if (Indice >= Ntentativa)
			{
				/////////////////////////SetConsoleOutputCP(GetACP());//----Escrever Caracteres Latinos
				cout << " Em  " << Ntentativa << " Você nã conseguiu fornecer o Número de arquivos Permitido" << "\n";
				cout << " Programa será Encerrado " << "\n";
				cout << "Digite uma tecla para encerrar o Programa." << "\n";
				/////////////////////////cin >> Tecla;
				//------------------------------------------------------------------------------------>IMPORTANTE--28/04/2021
				getline(cin, Tecla, '\n');//------>Ler string com caracter espaço em branco
				//------------------------------------------------------------------------------------>IMPORTANTE--28/04/2021
				exit(1);
			}
		}
		else
		{
			break;
		}
	}//---while (Indice < Ntentativa)//---A
	//
	//
	//----Início do escopo do "else"  do if (Sucesso == false)//----A
	//ArqParaSerInserido
	//
	string      Ponto;//-----Para verificar nome de arquivo
	bool        Cheaca_Ponto;
	int         NUMpto;
	Cheaca_Ponto = false;
	//
	for (int i = 0; i < NarquivoParaSerInserido; i++)//----A
	{//---Início do escopo do for (int i = 0; i < NarquivoParaSerInserido; i++)//----A
		if (i == 0)
		{
			cout << "\n";
			////////////////////////////////SetConsoleOutputCP(GetACP());//----Escrever Caracteres Latinos
			cout << "  Um Arquivo Válido é formado por : Uma string válida + a string '.' (Ponto) + uma terminação" << "\n";
			cout << "Exemplos:  Arq_0.txt; Arq_1.h; Arq_2.cpp; Arq_3.docx; Arq_4.txt;......" << "\n";
			cout << " Digite uma tecla para Continuar" << "\n";
			///////////////////////cin >> Tecla_0;
			//------------------------------------------------------------------------------------>IMPORTANTE--28/04/2021
			getline(cin, Tecla_0, '\n');//------>Ler string com caracter espaço em branco
			//------------------------------------------------------------------------------------>IMPORTANTE--28/04/2021
			cout << "\n";
			cout << "\n";
		}
		//////////////////////////////////////////////////////////SetConsoleOutputCP(GetACP());//----Escrever Caracteres Latinos
		cout << " Digite o Nome do arquivo de Ordem = " << i << "\n";
		cout << "\n";
		/////////////////////cin >> ArqParaSerInserido[i];
		//------------------------------------------------------------------------------------>IMPORTANTE--28/04/2021
		getline(cin, ArqParaSerInserido[i], '\n');//------>Ler string com caracter espaço em branco
		//------------------------------------------------------------------------------------>IMPORTANTE--28/04/2021
		cout << "\n";
		//
		//Checando se é um arquivo válido
		////int Nstring = ArqParaSerInserido[i].length();//---Fornece o número de Caracterfes da string   ArqParaSerInserido[i]
		//----Inserido em 26/04/2021
		int Nstring = static_cast<int>(ArqParaSerInserido[i].length());//---Fornece o número de Caracterfes da string   ArqParaSerInserido[i]
		//----Inserido em 26/04/2021
		//
		//Checando se o Caracter "." está presente
		Ponto = ".";
		NUMpto = 0;
		for (int ia = 0; ia < Nstring; ia++)
		{
			if (ArqParaSerInserido[i].at(ia) == Ponto.at(0))
			{
				NUMpto++;
			}
		}
		if (NUMpto == 1)
		{
			string     ArqDIR;
			ArqDIR = Dir;
			ArqDIR += "/";//---> Obrigatório Adicionar
			ArqDIR += ArqParaSerInserido[i];
			Obj_ofstream.open(ArqDIR.c_str());
			//
			if (Obj_ofstream.fail())
			{
				///////////////////////SetConsoleOutputCP(GetACP());//----Escrever Caracteres Latinos
				cout << " Falha para inserir o Arquivo  " << ArqParaSerInserido[i] << "\n";
				cout << " Digite qualquer Tecla para Continuar " << "\n";
				///////////////////cin >> Tecla_0;
				//------------------------------------------------------------------------------------>IMPORTANTE--28/04/2021
				getline(cin, Tecla_0, '\n');//------>Ler string com caracter espaço em branco
				//------------------------------------------------------------------------------------>IMPORTANTE--28/04/2021
			}
			else
			{
				Obj_ofstream.close();//------>Fechar para usaD:/(_DOES_/ConsoleApplication4/ConsoleApplication4r o mesmo Objeto "Obj_ofstream" para inserir os outros arquivos
			}

		}
		else
		{
			string      Tecla;
			cout << " Dado arquivo com mais de um caracter  PONTO  ('.') . Isto é um erro!! . Programa será encerrado!" << "\n";
			cout << " Digite tecla pa encerrar o programa. " << "\n";
			cin >> Tecla;

		}

	}//---Fim do escopo do for (int i = 0; i < NarquivoParaSerInserido; i++)//----A
	
	//
	cout << "Veja os arquivos inseridos no Diretório =    " << Dir << "'\n";
	cout << " Digite Tecla para continuar " << "\n";
	cin >> Tecla;

	//----------------------------------------------------------FINAL
	delete[] ArqParaSerInserido;
}
//