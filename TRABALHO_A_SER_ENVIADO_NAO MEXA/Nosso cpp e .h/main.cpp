#include "windows.h"//-----Escrever Caracteres Latinos
#include <direct.h>/*Necessário para usar a função _mkdir(const char*)*/
#include <iostream>//-Vai usar cin e/ou cout
#include <fstream>//-----Usar Objetos "ofstream  Escrever em arquivos" e "ifstream ler em Arquivos
#include <cstdio>//----Usar exit(0): exit(1);...
#include <new>//-----Para alocação de vetor dinãmico

// include na classe
#include <CTrabDirArq.h>

using std::bad_alloc;// --Para tratamento de exceção
////////////////using std::cout;
////////////////using std::cin;
using namespace std;//Para dispensar std:: em cin e cout
//
//
//
int main()
{
	//Estanciando o Objeto da classe CTrabDirArq
	CTrabDirArq Obj_CTrabDirArq;

    string               Tecla;
	string               DiscoValido;
	string               DirValido;
	//
	string               DadaString, Tecla_0A,
		StringNova, CaracterB, 	CaracterA;//-------AQUI
	bool                 FoiTrocado;//-------AQUI
	//
	FoiTrocado = false;
	//
	bool                 DiscoNaoValido;
	DiscoNaoValido = false;

	//
	SetConsoleOutputCP(GetACP());
	//
	//
	//
	//
	//--------------Obtendo diretório corrente
	/*
	string     CurrentDir;
	cout << "\n";
	cout << "  Vai obter o diretório Corrente, que é o diretório onde está o arquivo com terminaça --->'vcxproj' <---- "  << "\n";
	cout << "\n";
	ObtemCurrent_Directory(CurrentDir);
	cout << " O corrente Diretório é Dir_Corrente   = " << CurrentDir << "\n";
	cout << "\n";
	cout << "Digite tecla par continuar" << "\n";
	cin >> Tecla;
	exit(1);
	//*/
	//--------------Obtendo diretório corrente
	//
	//
	//
	//
	//
	//
	//
	//*
	//--------Escrevendo vetores em arquivos de Dados Numéricos
	int             NumRegionsStringMaisDados;
	int*            NumDeString;
	string**        ListaStringArq;
	//
	int*            NdadosPorRegiao;
	double**        Vetor;
	//
	string          DirOndeColocarArquivo;
	string          NomeDoArquivo;
	bool           Sucesso;
	//
	NumRegionsStringMaisDados = 3;
	//
	try
	{
		NumDeString = new int[NumRegionsStringMaisDados];
		ListaStringArq = new string*[NumRegionsStringMaisDados];
		//
		NdadosPorRegiao = new int[NumRegionsStringMaisDados];
		Vetor = new double*[NumRegionsStringMaisDados];
	}
	catch (bad_alloc)
	{
		string    Tecla;
		cout << " ocorreu má alocação dinâmica . enviado de 'Gerando arquivos de Dados Numéricos--1 Programa vai terminar." << "\n";
		cout << "Tecla para continuar " << "\n";
		cin >> Tecla;
		exit(1);

	}
	for (int ia = 0; ia < NumRegionsStringMaisDados; ia++)
	{
		NumDeString[ia] = 2;
		NdadosPorRegiao[ia] = 3 + ia;
	}
	for (int ia = 0; ia < NumRegionsStringMaisDados; ia++)
	{
		try
		{
			ListaStringArq[ia] = new string[NumDeString[ia]];
			Vetor[ia] = new double[NdadosPorRegiao[ia]];
		}
		catch (bad_alloc)
		{
			string    Tecla;
			cout << " ocorreu má alocação dinâmica . enviado de 'Gerando arquivos de Dados Numéricos--2 Programa vai terminar." << "\n";
			cout << "Tecla para continuar " << "\n";
			cin >> Tecla;
			exit(1);

		}
	}
	//
	ListaStringArq[0][0] = "Valor     Da   Temperatura  no canal do reator   ";
	ListaStringArq[0][1] = "Seção   Z =   20 cmm";
	ListaStringArq[1][0] = "Valor     Da   Temperatura  no canal do reator   ";
	ListaStringArq[1][1] = "Seção   Z = 120 cmm";
	ListaStringArq[2][0] = "Valor     Da   Temperatura  no canal do reator ";
	ListaStringArq[2][1] = "Seção   Z = 180 cmm";
	//
	for (int ia = 0; ia < NumRegionsStringMaisDados; ia++)
	{
		for (int ib = 0; ib < NdadosPorRegiao[ia]; ib++)
		{
			Vetor[ia][ib] = 5.0000555555;
		}
		
	}
	//
	DirOndeColocarArquivo = "C:/ZZZ__SSSS";
	NomeDoArquivo = "Arquivo.txt";

	Obj_CTrabDirArq.GeraArqDadosNumericos_1_CTrabComDir_0(//Dadose de entrada
		NumRegionsStringMaisDados,
		NumDeString,//----->
		ListaStringArq,
		//
		NdadosPorRegiao,
		Vetor,
		//
		//
		//-->ListaStringArq[i][j]; i está em {0,...,(NumRegionsStringMaisDados -1)} e j está em {0,...,NumDeString[i]}
		//-->Portanto deve ser alocado com o tamanho:  ListaStringArq = new string*[NumRegionsStringMaisDados] e 
		//-->ListaStringArq[i] = new string[NumDeString[i]+ 1]: para i = 0,.......,((NumRegionsStringMaisDados -1)
		//
		//OBS:--->Para todo i; última string a última string só deve ter caractere Espaço em Branco(Pode ter mais
		//
		DirOndeColocarArquivo,//----Exemplo: D:/pasta1/Pasta2
		NomeDoArquivo,//--Exemplos: ArqDado1.txt
		//
		//Retorna
		Sucesso
	);
	
	if (Sucesso == true)
	{
		string    Tecla;
		cout << " Veja os resultados impressos em  " << (DirOndeColocarArquivo + "/" + NomeDoArquivo) << "\n";
		cout << " Digite tecla para terminar " << "\n";
		cin >> Tecla;
		//Dealocando
		for (int ia = 0; ia < NumRegionsStringMaisDados; ia++)
		{
			delete[] ListaStringArq[ia];
			delete[] Vetor[ia];
		}
		delete[] ListaStringArq;
		delete[] Vetor;
		delete[] NumDeString;
		delete[] NdadosPorRegiao;
		///Dealocado
		exit(1);
	}
	else
	{
		string    Tecla;
		cout << " Falha para escrever as STRINGS." << "\n";
		cout << " Digite tecla para terminar " << "\n";
		cin >> Tecla;
		//Dealocando
		for (int ia = 0; ia < NumRegionsStringMaisDados; ia++)
		{
			delete[] ListaStringArq[ia];
			delete[] Vetor[ia];
		}
		delete[] ListaStringArq;
		delete[] Vetor;
		delete[] NumDeString;
		delete[] NdadosPorRegiao;
		///Dealocado

		exit(1);
	}
	//
	//*/
	//--------Escrevendo vetores emarquivos de Dados Numéricos
	//
	//
	//
	//
	//
	//
	//
	//
	/*
	//--------Gerando arquivos de Dados Numéricos
	int             NumRegionsStringMaisDados;
	int*            NumDeString;
	string**        ListaStringArq;
	string          DirOndeColocarArquivo;
	string          NomeDoArquivo;
	bool           Sucesso;
	//
	NumRegionsStringMaisDados = 3;
	//
	try
	{ 
		NumDeString = new int [NumRegionsStringMaisDados];
		ListaStringArq = new string*[NumRegionsStringMaisDados];
	}
	catch (bad_alloc)
	{
		string    Tecla;
		cout << " ocorreu má alocação dinâmica . enviado de 'Gerando arquivos de Dados Numéricos--1 Programa vai terminar." << "\n";
		cout << "Tecla para continuar " << "\n";
		cin >> Tecla;
		exit(1);

	}
	for (int ia = 0; ia < NumRegionsStringMaisDados; ia++)
	{
		NumDeString[ia] = 2;
	}
	for (int ia = 0; ia < NumRegionsStringMaisDados; ia++)
	{
		try
		{
			ListaStringArq[ia] = new string[NumDeString[ia]];
		}
		catch (bad_alloc)
		{
			string    Tecla;
			cout << " ocorreu má alocação dinâmica . enviado de 'Gerando arquivos de Dados Numéricos--2 Programa vai terminar." << "\n";
			cout << "Tecla para continuar " << "\n";
			cin >> Tecla;
			exit(1);

		}
	}
	//
	ListaStringArq[0][0] = "AAAAAAAAA		BBBBBBBBBBBBBBBB		CCCCCCCCCCCCCCCC";
	ListaStringArq[0][1] = "XXXXXXXXX		BBBBBBBBBBBBBBBB		CCCCCCCCCCCCCCC";
	ListaStringArq[1][0] = "AAAAAAAAA		BBBBBBBBBBBBBBBB		XXXXXXXXXXXXXXXX";
	ListaStringArq[1][1] = "AAAAAAAAA		XXXXXXXXXXXXXXXX		CCCCCCCCCCCCCCCC";
	ListaStringArq[2][0] = "QQQQQQQQQ		BBBBBBBBBBBBBBBB		RRRRRRRRRRRRRRRR";
	ListaStringArq[2][1] = "MMMMMMMMM		ÇÇÇÇÇÇÇÇÇÇÇÇÇÇÇÇ		PPPPPPPPPPPPPPPP";
	//
	DirOndeColocarArquivo = "C:/ZZZ__ZZZZ";
	NomeDoArquivo = "Arquivo.txt";

	GeraArqDadosNumericos_0_CTrabComDir_0(//Dadose de entrada
		NumRegionsStringMaisDados,
		NumDeString,//----->
		ListaStringArq,
		//
		//-->ListaStringArq[i][j]; i está em {0,...,(NumRegionsStringMaisDados -1)} e j está em {0,...,NumDeString[j]}
		//-->Portanto deve ser alocado com o tamanho:  ListaStringArq = new string*[NumRegionsStringMaisDados] e 
		//-->ListaStringArq[i] = new string[NumDeString[i]+ 1]: para i = 0,.......,((NumRegionsStringMaisDados -1)
		//
		//OBS:--->Para todo i; última string a última string só deve ter caractere Espaço em Branco(Pode ter mais
		//
		DirOndeColocarArquivo,//----Exemplo: D:/pasta1/Pasta2
		NomeDoArquivo,//--Exemplos: ArqDado1.txt
		//
		//Retorna
		Sucesso
		);

	if (Sucesso == true)
	{
		string    Tecla;
		cout << " Veja os resultados impressos em  " << (DirOndeColocarArquivo + "/" + NomeDoArquivo) << "\n";
		cout << " Digite tecla para terminar " << "\n";
		cin >> Tecla;
		exit(1);
	}
	else
	{
		string    Tecla;
		cout << " Falha para escrever as STRINGS." << "\n";
		cout << " Digite tecla para terminar " << "\n";
		cin >> Tecla;
		exit(1);
	}
	//Dealocando
	for (int ia = 0; ia < NumRegionsStringMaisDados; ia++)
	{
		delete[] ListaStringArq[ia];
	}
	delete[] ListaStringArq;
	delete[] NumDeString;
	///Dealocado
	//
	//*/
	//--------Gerando arquivos de Dados Numéricos
	//
	//
	//
	//
	//
	//
	/*
	//-------------------------------------Inserindo Arquivos em DiretóRio Válido
	cout << "\n";
	cout << "  FORNEÇA  UM  DIRETÓRIO   VÁLIDO." << "\n";
	cout << "\n";
	cin >> DirValido;
	if (ChecaSeDirExiste(DirValido) == true)
	{
		cout << "Diretório = " << DirValido << "   Já existe!!!" << "\n";
		cout << "\n";
		//cout << "  DIGITE  UMA TECLA PARA TERMINAR O PROGRAMA" << "\n";
		cout << "  DIGITE  UMA TECLA PARA CONTINUAR O PROGRAMA" << "\n";
		cout << "\n";
		cin >> Tecla;
		///////////////////////////////////////////exit(1);
	}
	else
	{
		cout << "Diretório = " << DirValido << "   Não existe!!!" << "\n";
		cout << "Programa vai Cria-lo" << "\n";
		cout << "\n";
		cout << "  DIGITE  UMA TECLA PARA CONTINUAR O PROGRAMA" << "\n";
		cout << "\n";
		cin >> Tecla;
		//
		if (Cria_DirValido(DirValido) == true)
		{
			cout << "Diretório = " << DirValido << "   Criado com Sucesso" << "\n";
			cout << "\n";
			//
		}
		//
		cout << " Deseja Inserir Arquivos neste Diretório  ? " << "Digite 'S' ou 's' para SIM. " << "\n";
		cin >> Tecla;
		if (Tecla == "S" || Tecla == "s")
		{
			int          NarquivoParaSerInserido_Max;
			//
			cout << " Forneça o número Máximo de arquivos a ser inserido (Sempre Positivo) " << "n";
			//
			cin >> NarquivoParaSerInserido_Max;
			if (cin.fail())
			{
				string       Tecla;
				cout << " VoCê não forneceu um Inteiro Positivo!!  Programa será encerrado." << "\n";
				cout << " Digite tecla para encerrar o programa" << "\n";
				cin >> Tecla;
				exit(1);
			}
			//
			InsereArqEmDir_CTrabComDir_0(DirValido, NarquivoParaSerInserido_Max);
			//
		
		}
		else
		{
			string       Tecla;
			cout << " VoCê não especificou que deseja inserir arqiivos no diretório!!  Programa será encerrado." << "\n";
			cout << " Digite tecla para encerrar o programa" << "\n";
			cin >> Tecla;
			exit(1);
		}
		//
		//
		//
	}
	//-------------------------------------Inserindo Arquivos em DiretóRio Válido
	//
	exit(1);
	//
	//
	//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$		 
	//*















	//
	//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	/*
	//-------------------------------------------------------------------------TESTE--(Trocando Caracter)-----09/08/2021
	//////////////////////////////////////////SetConsoleOutputCP(GetACP());//----Escrever Caracteres Latinos
	cout << "\n";
	cout << " Forneça a STRING " << "\n";
	cout << "\n";
	//
	//
	//
	//////////////////////cin >> DadaString;
	//------------------------------------------------------------------------------------>IMPORTANTE--28/04/2021
	getline(std::cin, DadaString, '\n');//------>Ler string com caracter espaço em branco
	//------------------------------------------------------------------------------------>IMPORTANTE--28/04/2021
	//
	//
	//
	cout << "\n";
	cout << " Forneça o CARACTER para ser TROCADO" << "\n";
	cout << "\n";
	//
	//
	//////////////////cin >> CaracterA;
	//------------------------------------------------------------------------------------>IMPORTANTE--28/04/2021
	getline(std::cin, CaracterA, '\n');//------>Ler string com caracter espaço em branco
	//------------------------------------------------------------------------------------>IMPORTANTE--28/04/2021
	//
	//
	//
	//
	cout << "\n";
	cout << " Forneça o CARACTER NOVO para SUBSTITUIR o ANTIGO" << "\n";
	cout << "\n";
	//
	//
	//
	//////////////////////////cin >> CaracterB;
	//------------------------------------------------------------------------------------>IMPORTANTE--28/04/2021
	getline(cin, CaracterB, '\n');//------>Ler string com caracter espaço em branco
	//------------------------------------------------------------------------------------>IMPORTANTE--28/04/2021
	//
	//
	//
	//
	//
	TrocaCaracterAporOutroB(DadaString,
		CaracterA, CaracterB, FoiTrocado, StringNova);//Inserido em ---26/04/2021
	if (FoiTrocado == true)
	{
		string    Mens;
		//
		if (StringNova != DadaString)
		{
			Mens = "Foi trocado os caracteres com Sucesso";
			cout << Mens << "\n";
			cout << "\n";
			cout << "String  Antes  = " << DadaString << "\n";
			cout << "String  Depois  = " << StringNova << "\n";
			cout << " Digite uma tecla para continuar " << "\n";
			/////////////cin >> Tecla_0A;
			//------------------------------------------------------------------------------------>IMPORTANTE--28/04/2021
			getline(cin, Tecla_0A, '\n');//------>Ler string com caracter espaço em branco
			//------------------------------------------------------------------------------------>IMPORTANTE--28/04/2021
		}
		else
		{
			SetConsoleOutputCP(GetACP());//----Escrever Caracteres Latinos
			cout << "Não Foi trocado os Caracteres pois o caractere especificado para troca não pertence à string " << "\n";
			cout << "ou o caracter novo especificado é igual ao caracter espeficado para troca. " << "\n";
			cout << "\n";
			cout << "String  Antes  = " << DadaString << "\n";
			cout << "String  Depois  = " << StringNova << "\n";
			cout << " Digite  uma tecla para continuar " << "\n";
			///////////////cin >> Tecla_0A;
			//------------------------------------------------------------------------------------>IMPORTANTE--28/04/2021
			getline(cin, Tecla_0A, '\n');//------>Ler string com caracter espaço em branco
			//------------------------------------------------------------------------------------>IMPORTANTE--28/04/2021
		}

	}
	else
	{
		string    Mens;
		//
		Mens = "Falha para  trocar os caracteres ";
		cout << "\n";
		cout << " Digite uma tecla para continuar " << "\n";
		////////////////cin >> Tecla_0A;
		//------------------------------------------------------------------------------------>IMPORTANTE--28/04/2021
		getline(cin, Tecla_0A, '\n');//------>Ler string com caracter espaço em branco
		//------------------------------------------------------------------------------------>IMPORTANTE--28/04/2021
	}
	//
	exit(0);
	//-------------------------------------------------------------------------TESTE--(Trocando Caracter)------09/08/2021
	//*/
	//
	//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	//
	//
//
//












//

	//
	//------------------Lendo dados em Arquivo dentro de um Diretório.
	/*
	int                  Nlinhas;
	bool                 SegundaLinhaEumaString;
	int                  Nchances;
	string               NomeDosDados;
	double               Vet[1000];
	int                  Limite;
	Limite = 1000;
	//
	Nchances = 2;
	//DirValido = "c:/Z/Dados.txt";
	cout << " Forneça o Diretório + Arqivo onde estão os dados" << "\n";
	cin >> DirValido;
	cout << "A segunda Linha é uma string ? (Digite S ou s para SIM." << "\n";
	cin >> Tecla;
	if (Tecla == "S" || Tecla == "s")
	{
		cout << " Você disse que a Segunda Linha é uma string  ";
		cout << " Você confirma? Digite S ou s  para confirmar " << "\n";
		cin >> Tecla;
		if (Tecla != "S" && Tecla != "s")
		{
			cout << "  Você não confirmou!!  Programa será encerrad!!" << "\n";
			cout << " Digite tecla para encerrar o programa." << "\n";
			cin >> Tecla;
			exit(1);
		}
		SegundaLinhaEumaString = true;
	}
	else
	{
		cout << " Você disse que a Segunda Linha Não é uma string  ";
		cout << " Você confirma? Digite S ou s  para confirmar " << "\n";
		cin >> Tecla;
		if (Tecla != "S" && Tecla != "s")
		{
			cout << "  Você não confirmou!!  Programa será encerrad!!" << "\n";
			cout << " Digite tecla para encerrar o programa." << "\n";
			cin >> Tecla;
			exit(1);
		}
		SegundaLinhaEumaString = false;
	}
	LendoEmArquivos(DirValido,//----Dir+Arquivode Dados
		///////////////////////////////int&        Nlinhas,//-----Número de dados double
		SegundaLinhaEumaString,
		Limite,
		//
		NomeDosDados,
		Nlinhas,
		Vet);

	cout << " Digite tecla para encerrar o programa." << "\n";
	cin >> Tecla;
	exit(1);
	//*/
	//------------------Lendo dados em Arquivo dentro de um Diretório.
	//
	//
	//
	//
    //---------Fornecendo disco válidp   
    /*
	//
	cout << "  TESTANDO!!!!!" << "\n";
	cout << "\n";
	cout << "  FORNEÇA  UM  DISCO   VÁLIDO." <<"\n";
	cout << "\n";
	cin >>  DiscoValido;
	//
	DiscoNaoValido = ChecaDiscoValido(DiscoValido);
	//
	if( DiscoNaoValido == true)
	{
	     cout << " O DISCO  FORNECIDO NÃO É VÁLIDO. PROGRAMA SERÁ ENCERRADO" << "\n";
	}
	else
	{
	    cout << " O DISCO  FORNECIDO É VÁLIDO. DIRETÓRIO PODE SER CRIADO." << "\n";
	}
	cout << "\n";
	cout << "  DIGITE  UMA TECLA PARA CONTINUAR O PROGRAMA" <<"\n";
	cout << "\n";
	cin >>  Tecla;
	//---------Fornecendo disco válidp
	//*/
	//
	//

	//*
    //-------------------------------------Criando DiretóRio Válido
	cout << "\n";
	cout << "  FORNEÇA  UM  DIRETÓRIO   VÁLIDO." << "\n";
	cout << "\n";
	cin >> DirValido;
	if (Obj_CTrabDirArq.ChecaSeDirExiste(DirValido) == true)
	{
		cout << "Diretório = " << DirValido << "   Já existe!!!" << "\n";
		cout << "\n";
		//cout << "  DIGITE  UMA TECLA PARA TERMINAR O PROGRAMA" << "\n";
		cout << "  DIGITE  UMA TECLA PARA CONTINUAR O PROGRAMA" << "\n";
		cout << "\n";
		cin >> Tecla;
		///////////////////////////////////////////exit(1);
	}
	else
	{
		cout << "Diretório = " << DirValido << "   Não existe!!!" << "\n";
		cout << "Programa vai Cria-lo" << "\n";
		cout << "\n";
		cout << "  DIGITE  UMA TECLA PARA CONTINUAR O PROGRAMA" << "\n";
		cout << "\n";
		cin >> Tecla;
		//
		if (Obj_CTrabDirArq.Cria_DirValido(DirValido) == true)
		{
			cout << "Diretório = " << DirValido << "   Criado com Sucesso" << "\n";
			cout << "\n";
			//
			//
			//
			//
			//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$		 
			//*
			cout << " Deseja  Fornecer dados digitados no DOES em um arquivo inserido neste Diretório ?  Digite: (S ou s) para Sim " << "\n";
			cout << "\n";
			cin >> Tecla;
			if (Tecla == "S" || Tecla == "s")
			{ 
				//@@@@@@@@@@@@@@@@@@@@@@@@@@@
				//
				int         NcasasDecimais;
				int         Nvet;
				int         Nchance;
				int         iChance;
				bool        SaiDoWhile;
				Nchance = 2;
				string            Arquivo;
				cout << "Forneça o arquivo onde será inserido os dados(Rquivo: Nome.txt; Nome.Dat, ...etc)" << "\n";
				cout << "\n";
				cin >> Arquivo;
				//
				cout << "\n";
				cout << "\n";
				cout << "Forneça o número de dados double Menor  que 1000  a ser inserido no arquivo" << "\n";
				cin >> Nvet;
				const int   Nvet_0 = 1000;
				double      Vet[Nvet_0];
				if (Nvet >= Nvet_0)
				{
					iChance = 0;
					SaiDoWhile = false;

					//
					cout << "Você terá mais  " << Nchance <<   "      Chances!!!"  <<"\n";
					cout << "Digite  tecla  para continuar " <<"\n";
					cin >> Tecla;
					while (iChance < Nchance)
					{
						//
						cout << "Forneça o número de dados double Menor  que 1000  a ser inserido no arquivo" << "\n";
						cin >> Nvet;
						if (Nvet >= Nvet_0)
						{
							iChance++;
						}
						else
						{
							for (int i = 0; i < Nvet; i++)
							{
								cout << " Forneça o Valor de ordem  i = " << i << "\n";
								cin >> Vet[i];
								cout << "\n";
							}
							//
							cout << " Forneça o número de casas decimais para os doubles " << "\n";
							cin >> NcasasDecimais;
							//
							Obj_CTrabDirArq.EscreveEmArq(DirValido, Arquivo, Nvet, NcasasDecimais, Vet);
							//
							string     DirMaisArq = DirValido + "/" + Arquivo;
							cout << "  Veja seus dados no Diretório + arquivo:  " << DirMaisArq;
							cout << " Digite tecla para terminar o Programa" << "\n";
							cin >> Tecla;
							exit(1);
						}
					}
				}
				else
				{
					for (int i = 0; i < Nvet; i++)
					{
						cout << " Forneça o Valor de ordem  i = " << i << "\n";
						cin >> Vet[i];
						cout << "\n";
					}
					//
					cout << " Forneça o número de casas decimais para os doubles " << "\n";
					cin >> NcasasDecimais;
					//
					Obj_CTrabDirArq.EscreveEmArq(DirValido, Arquivo, Nvet, NcasasDecimais, Vet);
					//
					string     DirMaisArq = DirValido + "/" + Arquivo;
					cout << "  Veja seus dados no Diretório + arquivo:  " << DirMaisArq;
					cout << " Digite tecla para terminar o Programa" << "\n";
					cin >> Tecla;
					exit(1);
				}				
				//@@@@@@@@@@@@@@@@@@@@@@@@@@@
			}   
			else
			{
				cout << "  DIGITE  UMA TECLA PARA TERMINAR O PROGRAMA" << "\n";
				cout << "\n";
				cin >> Tecla;
				exit(1);
			}
			//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
			//*/
			//
			//
            //
		}
		else
		{
			cout << "  FALHA para CRIAR O  Diretório = " << DirValido << "\n";
			cout << "\n";
			cout << "  DIGITE  UMA TECLA PARA TERMINAR O PROGRAMA" << "\n";
			cout << "\n";
			cin >> Tecla;
			exit(1);
		}
		//
	}
	//-------------------------------------Criando DiretóRio Válido
	//
	//
	//
	return    0;
	//
}
