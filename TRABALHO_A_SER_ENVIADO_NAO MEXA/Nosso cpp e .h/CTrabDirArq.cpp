#include "CTrabDirArq.h"
#include "windows.h"//-----Escrever Caracteres Latinos
#include <direct.h> /*Necessário para usar a função _mkdir(const char*)*/
#include <iostream>//-Vai usar cin e/ou cout
#include <cstdio>//----Usar exit(0): exit(10;...
#include <fstream> //-----Usar Objetos "ofstream  Escrever em arquivos" e "ifstream ler em Arquivos
#include <iomanip> //-------Escrever double   com precisão especificada   
#include <new>//-----Para alocação de vetor dinãmico
#include <string>

using std::bad_alloc;// --Para tratamento de exceção
using std::setprecision;//-------Para especificara a precisão
using namespace std;

CTrabDirArq::CTrabDirArq()
{
}

CTrabDirArq::~CTrabDirArq()
{
	Dealocacao_din_dos_vetores_inteiros();
	Dealocacao_din_dos_vetores_string_1d();
	Dealocacao_din_dos_vetores_string_2d();
}

//metodos de alocacao:

int n = 5;

void CTrabDirArq::Alocacao_din_dos_vetores_inteiros(int& n) {
	
	try
	{
		NumArqDeCadaDir_CTrabDirArq = new int[n];
	}
	catch (bad_alloc)
	{
		cout << "Problema de alocacao.... Tente de novo..." << endl;
	}
};

void CTrabDirArq::Alocacao_din_dos_vetores_string_1d(int& n) {


	try
	{
		Dir_CTrabDirArq = new string[n];
	}
	catch (bad_alloc)
	{
		cout << "Problema de alocacao.... Tente de novo..." << endl;
	}
};

void CTrabDirArq::Alocacao_din_dos_vetores_string_2d(int& n, int& m) {

	try
	{
		ArqEmCadaDir_CTrabDirArq = new string*[n];
	}
	catch (bad_alloc)
	{
		cout << "Problema de alocacao.... Tente de novo..." << endl;
	}

	try
	{
		for (unsigned i = 0; i < ArqEmCadaDir_CTrabDirArq.size(); i++) {

			ArqEmCadaDir_CTrabDirArq[i] = new string[m];
		}
	}
	catch (bad_alloc)
	{
		cout << "Problema de alocacao.... Tente de novo..." << endl;
	}
};

//metodos de dealocacao:

void CTrabDirArq::Dealocacao_din_dos_vetores_inteiros() {
	delete[]NumArqDeCadaDir_CTrabDirArq;
};
void CTrabDirArq::Dealocacao_din_dos_vetores_string_1d() {
	delete[]Dir_CTrabDirArq;
};
void CTrabDirArq::Dealocacao_din_dos_vetores_string_2d() {

	unsigned size_of_array = ArqEmCadaDir_CTrabDirArq.size();
	for (unsigned i = 0; i < size_of_array; i++) {
		delete[]ArqEmCadaDir_CTrabDirArq[i];

	};
	delete[]ArqEmCadaDir_CTrabDirArq;
};




//metodos:

void CTrabDirArq::CaracterProibidosDirArq(const int Ncarcter, string   CaracterProibido[]) {
	//	
	string      Tecla;
	const int Ncaracter_REAL = 30;
	//
	SetConsoleOutputCP(GetACP());//----Escrever Caracteres Latinos
	//
	if (Ncarcter < Ncaracter_REAL)
	{
		cout << " O número de Caracteres PROIBIDOS é  IGUAL a  " << Ncaracter_REAL << "\n";
		cout << " O número usado para especificar o Tamanho do VETOR  'CaracterProibido[]' (Primeiro argumento da função) " << "\n";
		cout << " Foi Menor que esse valor. Especifica um número Maior ou igual ao valor dado acima. " << "\n";
		cout << " Programa será terminado. " << "\n";
		cout << "Digite uma Tecla para Terminar" << "\n";
		/////////////cin >> Tecla;
		//------------------------------------------------------------------------------------>IMPORTANTE--28/04/2021
		getline(cin, Tecla, '\n');//------>Ler string com caracter espaço em branco
		//------------------------------------------------------------------------------------>IMPORTANTE--28/04/2021
		exit(0);
	}
	else
	{
		//
		CaracterProibido[0] = " ";
		CaracterProibido[1] = "'";
		CaracterProibido[2] = "!";
		CaracterProibido[3] = "@";
		CaracterProibido[4] = "#";
		CaracterProibido[5] = "$";
		CaracterProibido[6] = "%";
		CaracterProibido[7] = "¨";
		CaracterProibido[8] = "&";
		CaracterProibido[9] = "*";
		CaracterProibido[10] = "(";
		CaracterProibido[11] = ")";
		CaracterProibido[12] = "-";
		CaracterProibido[13] = "+";
		CaracterProibido[14] = "=";
		CaracterProibido[15] = "`";
		CaracterProibido[16] = "´";
		CaracterProibido[17] = "{";
		CaracterProibido[18] = "}";
		CaracterProibido[19] = "[";
		CaracterProibido[20] = "]";
		CaracterProibido[21] = "^";
		CaracterProibido[22] = "~";
		CaracterProibido[23] = "|";
		CaracterProibido[24] = "?";
		CaracterProibido[25] = "<";
		CaracterProibido[26] = ">";
		CaracterProibido[27] = ",";
		CaracterProibido[28] = ";";
		CaracterProibido[29] = " ";// ":";

		//	
		for (int ia = 0; ia < (Ncarcter - Ncaracter_REAL); ia++)
		{
			CaracterProibido[Ncaracter_REAL + ia] = " ";
		}

	}
};

bool CTrabDirArq::ChecaDiscoValido(string& Disco) {
	string          DiscoValido;
	string          Tecla;
	const char* Dicovalido_C;
	int             Nstring;
	bool            DirValido;
	//
	SetConsoleOutputCP(GetACP());
	//
	ofstream      Obj_00_ofstream;//----Estnaciando um objeto de ofstream	
	//	
	//----Inserido em 26/04/2021
	Nstring = static_cast<int>(Disco.length());//---Fornece o número de Caracterfes da string   Disco
	//----Inseridoe m 26/04/2021
	//	
	//
	if (Nstring != 1)
	{
		cout << " Um Disco válido deve ter SÓMENTE 1 CARACTER. iSSSO FOI VIOLADO. PROGRAMA SERÁ TERMINADO." << "\n";
		cout << "\n";
		cout << " Digite uma Tecla para terminar o program" << "\n";
		cout << "\n";
		cin >> Tecla;
		exit(1);
	}
	else
	{
		string         Disco_C;
		Disco_C = "C";
		string     Aux;
		Aux = Disco.at(0);
		if (Aux == Disco_C)
		{
			cout << " Disco especificado é o Disco    'C'       (C maiúsculo) padrão do Windows." << "\n";
			cout << "\n";
			cout << " Digite uma Tecla para continuar o program" << "\n";
			cout << "\n";
			cin >> Tecla;
			//
			bool            DirValido_C;
			DirValido_C = false;
			return        DirValido_C;
			//
		}
		else
		{
			if (Aux == "c")
			{
				//
				cout << " Disco especificado não é o Disco    'C'       (C maiúsculo) padrão do Windows." << "\n";
				cout << "\n";
				cout << " Provavelmente você digitou 'c'       (c  Minúsculo) Não padrão do Windows." << "\n";
				cout << "\n";
				cout << " Digite uma Tecla para Terminar o program" << "\n";
				cout << "\n";
				cin >> Tecla;
				//
				exit(1);
				//
			}
			//
		}
		//
	}
	DiscoValido = Disco;
	DiscoValido += ":/Arq.txt";//------>Adicionando um arquivo para teste
	//
	Dicovalido_C = DiscoValido.c_str();//----->Convertendo string C++  em const char*  do  C
	//
	Obj_00_ofstream.open(Dicovalido_C);
	//
	DirValido = Obj_00_ofstream.fail();
	//
	return    DirValido;
};

bool CTrabDirArq::ChecaSeDirExiste(string& Dir)
{
	bool          Veredito;
	string        DirValido;
	ofstream      Obj_Dir_ofstream;
	DirValido = Dir;
	string        DiscoValido;
	ofstream      Obj_00_ofstream;
	DiscoValido = Dir;
	DiscoValido += "/ArqParaTestarSeDirValido.txt";
	Obj_00_ofstream.open(DiscoValido.c_str());
	//
	if (Obj_00_ofstream.fail())
	{
		Veredito = false;//------Disco   não é um disco válido
	}
	else
	{
		//
		Obj_00_ofstream.close();
		//
		Veredito = true;//------Disco   é um disco válido
		//		
	}
	//
	return  Veredito;
};

bool CTrabDirArq::Cria_DirValido(string& DirValido)
{
	//
	bool          Sucesso;
	string        Dir;
	string        Barra;
	int    Nstring, RetornoDe_mkdir;
	//Nstring = DirValido.length();//---Fornece o número de Caracterfes da string   DirValido
	//
	//----Inserido em 26/04/2021
	Nstring = static_cast<int>(DirValido.length());//---Fornece o número de Caracterfes da string   DirValido
	//----Inseridoe m 26/04/2021
	//
	Sucesso = true;
	//
	Barra = "/";
	//
	Dir = "";
	//
	for (int ia = 0; ia < Nstring; ia++)
	{
		Dir += DirValido.at(ia);//------DirValido.at(ia)----Fornece o Caracter de ordem "ia"
		if (DirValido.at(ia) == Barra.at(0))
		{
			RetornoDe_mkdir = _mkdir(Dir.c_str());//------Criando o Diretório
			//
			/*
			if (RetornoDe_mkdir != 0)
			{
			Sucesso = false;
			break;
			}
			//*/
		}
	}
	//
	//////////////////if (Sucesso == true)
	{
		Dir += "/";
		RetornoDe_mkdir = _mkdir(Dir.c_str());//------Criando o Diretório
		//
		/*
		if (RetornoDe_mkdir != 0)
		{
		Sucesso = false;
		}
		//*/
	}
	//
	ChecaSeDirExiste(Dir);
	Sucesso = ChecaSeDirExiste(Dir);
	//
	return  Sucesso;
};

void CTrabDirArq::EscreveEmArq(string& Dir, string& Arquivo, int& Ncomponente_Vet, int& NcasasDecimais, double        Vet[])
{
	//
	string           Tecla;
	string           DirMaisArq;
	/////////////////////
	SetConsoleOutputCP(GetACP());//------Escrever caracter latino no DOES
	//
	ofstream         Obj_ofstream;//------Estanciando um objeto de ofstream, para escr4ever em arquivos
	//
	DirMaisArq = Dir;
	DirMaisArq += "/";
	DirMaisArq += Arquivo;
	//
	Obj_ofstream.open(DirMaisArq.c_str());//------DirMaisArq.c_str()//----Covertendo string do C++  em cnst char*  do C
	if (Obj_ofstream.fail())
	{
		cout << " Diretório  ou Diretório + Arquivo NÃO VÁLIDO. Digite uma tecla para encerrar o Programa." << "\n";
		cin >> Tecla;
		exit(1);
	}
	else
	{
		//
		int        CasaDecimaisReal;
		if (NcasasDecimais <= 5)
		{
			CasaDecimaisReal = 5;
		}
		else
		{
			CasaDecimaisReal = NcasasDecimais;
		}
		setprecision(CasaDecimaisReal);
		//
		Obj_ofstream << "" << "\n";
		Obj_ofstream << "   " << "ordem da Componenente     " << "     Valor  de  Vet           " << "\n";
		Obj_ofstream << "" << "\n";
		//
		for (int i = 0; i < Ncomponente_Vet; i++)
		{

			Obj_ofstream << "   " << "    " << i << "                     Vet[i]   =        " << setprecision(CasaDecimaisReal) << Vet[i] << "\n";
			Obj_ofstream << "" << "\n";
		}
		//
		Obj_ofstream.close();
		//
	}

};

void CTrabDirArq::GeraArqDadosNumericos_0_CTrabComDir_0(int& NumRegionsStringMaisDados, int* NumDeString, string** ListaStringArq, string& DirOndeColocarArquivo, string& NomeDoArquivo, bool& Sucesso){
	string       DirMaisArq;
	ofstream     Obj_ofstream;
	bool         Veredito;
	//
	SetConsoleOutputCP(GetACP());
	//
	Veredito = ChecaSeDirExiste(DirOndeColocarArquivo);
	//
	if (Veredito == true)
	{
		DirMaisArq = DirOndeColocarArquivo;
		DirMaisArq += "/";
		DirMaisArq += NomeDoArquivo;
	}
	else
	{
		Veredito = Cria_DirValido(DirOndeColocarArquivo);
		if (Veredito == true)
		{
			DirMaisArq = DirOndeColocarArquivo;
			DirMaisArq += "/";
			DirMaisArq += NomeDoArquivo;
		}
		else
		{
			string     Tecla;
			//
			cout << " Arquivo para dados Numéricos não pode ser Criado porque O Diretório especificado para colocar " << "\n";
			cout << " o Arquivo não é Válido. Enviado de GeraArqDadosNumericos_0_CTrabComDir_0--1. " << "\n";
			cout << "Digite Tecla para continuar" << "\n";
			cin >> Tecla;
			Sucesso = false;
		}
	}
	//	
	//
	Sucesso = true;
	//
	Obj_ofstream.open(DirMaisArq.c_str());
	if (Obj_ofstream.fail())
	{
		string      Tecla;
		cout << " " << "\n";
		cout << " Falha para abrir o Dir+Arquivo = " << DirMaisArq << "\n";
		cout << " " << "\n";
		cout << " Enviado de: GeraArqDadosNumericos_0_CTrabComDir_0. Digite uma Tecla para continuar " << "\n";
		cout << " " << "\n";
		cin >> Tecla;
		Sucesso = false;
		return;
	}
	else
	{
		for (int ir = 0; ir < NumRegionsStringMaisDados; ir++)
		{
			for (int in = 0; in < NumDeString[ir]; in++)
			{
				Obj_ofstream << ListaStringArq[ir][in] << "\n";


			}
			//
			Obj_ofstream << "" << "\n";
			Obj_ofstream << "" << "\n";
			//
		}
	}
};

void CTrabDirArq::GeraArqDadosNumericos_1_CTrabComDir_0( int& NumRegionsStringMaisDados, int* NumDeString, string** ListaStringArq, int* NdadosPorRegiao, double** Vetor, string& DirOndeColocarArquivo, string& NomeDoArquivo, bool& Sucesso ){
	string       DirMaisArq;
	ofstream     Obj_ofstream;
	bool         Veredito;
	//
	SetConsoleOutputCP(GetACP());
	//
	Veredito = ChecaSeDirExiste(DirOndeColocarArquivo);
	//
	if (Veredito == true)
	{
		DirMaisArq = DirOndeColocarArquivo;
		DirMaisArq += "/";
		DirMaisArq += NomeDoArquivo;
	}
	else
	{
		Veredito = Cria_DirValido(DirOndeColocarArquivo);
		if (Veredito == true)
		{
			DirMaisArq = DirOndeColocarArquivo;
			DirMaisArq += "/";
			DirMaisArq += NomeDoArquivo;
		}
		else
		{
			string     Tecla;
			//
			cout << " Arquivo para dados Numéricos não pode ser Criado porque O Diretório especificado para colocar " << "\n";
			cout << " o Arquivo não é Válido. Enviado de GeraArqDadosNumericos_0_CTrabComDir_0--1. " << "\n";
			cout << "Digite Tecla para continuar" << "\n";
			cin >> Tecla;
			Sucesso = false;
		}
	}
	//	
	//
	Sucesso = true;
	//
	Obj_ofstream.open(DirMaisArq.c_str());
	if (Obj_ofstream.fail())
	{
		string      Tecla;
		cout << " " << "\n";
		cout << " Falha para abrir o Dir+Arquivo = " << DirMaisArq << "\n";
		cout << " " << "\n";
		cout << " Enviado de: GeraArqDadosNumericos_0_CTrabComDir_0. Digite uma Tecla para continuar " << "\n";
		cout << " " << "\n";
		cin >> Tecla;
		Sucesso = false;
		return;
	}
	else
	{
		for (int ir = 0; ir < NumRegionsStringMaisDados; ir++)
		{
			for (int in = 0; in < NumDeString[ir]; in++)
			{
				Obj_ofstream << ListaStringArq[ir][in] << "\n";
			}
			//
			Obj_ofstream << "" << "\n";
			Obj_ofstream << "" << "\n";
			//
			for (int ia = 0; ia < NdadosPorRegiao[ir]; ia++)
			{
				Obj_ofstream << "    ordem  do Vetor  = " << ia << setprecision(10) << "     Valor  do  Vetor  =  " << Vetor[ir][ia] << "\n";
				Obj_ofstream << "" << "\n";
			}
		}
	}
};

void CTrabDirArq::InsereArqEmDir_CTrabComDir_0(string& Dir, int& NarquivoParaSerInserido_Max)
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
	string* ArqParaSerInserido;
	//
	Ndimension = NarquivoParaSerInserido_Max;
	//
	try {
		ArqParaSerInserido = new string[Ndimension];

	}
	catch (bad_alloc) {
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
};

void CTrabDirArq::InsereArqEmDir_0(string& Dir, string& Arq) {
	string         DirArq;
	ofstream       Obj_ofstream;
	string         Tecla_0;
	DirArq = Dir;
	DirArq += "/";
	DirArq += Arq;
	Obj_ofstream.open(DirArq.c_str());
	//
	if (Obj_ofstream.fail())
	{
		SetConsoleOutputCP(GetACP());//----Escrever Caracteres Latinos
		cout << " Falha para inserir o Arquivo  " << Arq << "\n";
		cout << " Digite qualquer Tecla para Continuar " << "\n";
		////////////////cin >> Tecla_0;
		//------------------------------------------------------------------------------------>IMPORTANTE--28/04/2021
		getline(cin, Tecla_0, '\n');//------>Ler string com caracter espaço em branco
		//------------------------------------------------------------------------------------>IMPORTANTE--28/04/2021
	}
	else
	{
		Obj_ofstream.close();//------>Fechar para usaD:/(_DOES_/ConsoleApplication4/ConsoleApplication4r o mesmo Objeto "Obj_ofstream" para inserir os outros arquivos
	}
};

void CTrabDirArq::LendoEmArquivos(string& DirMaisArq, bool& SegundaLinhaEumaString, int& Limite, string& NomeDosDados, int& Nlinhas, double      Vet[]){
	
	ifstream          Obj_ifstream;//---DEstanciando um objeto do tipo ifstream
	string            Tecla;
	//
	//
	Obj_ifstream.open(DirMaisArq.c_str());//----Cpnvertendo string C++   em cont char* do  C
	if (Obj_ifstream.fail())
	{
		cout << "    Falha para abrir o Dir+Arq  = " << DirMaisArq << "\n";
		cout << " Digite tecla para terminar o programa " << "\n";
		cin >> Tecla;
		exit(1);
	}
	//
	Obj_ifstream >> Nlinhas;
	//
	if (Nlinhas > Limite)
	{
		cout << " Seu arquivo tem Nlinhas = " << Nlinhas << "maior que o valor máximo permitido   que é  " << Limite << "\n";
		cout << " Digite Tecla para terminar o programa " << "\n";
		cin >> Tecla;
		exit(1);
	}
	//
	if (SegundaLinhaEumaString == true)
	{

		Obj_ifstream >> NomeDosDados;
		cout << "\n";
		cout << "Nome dos dados LIDO  = " << NomeDosDados << "\n";
		cout << "\n";

		for (int lin = 1; lin < Nlinhas; lin++)
		{
			Obj_ifstream >> Vet[lin];

			if (Obj_ifstream.fail())
			{
				//*
				cout << "Falha para ler dados--de ordem  " << lin << "---1--- enviado de 'LendoEmArquivos'" << "\n";
				cout << " digite tecla para terminar o programa " << "\n";
				cin >> Tecla;
				exit(1);
				//*/
			}

			cout << "Lin  =  " << lin << "      Vet[Lin]   =  " << Vet[lin] << "\n";

		}
	}
	else
	{
		for (int lin = 0; lin < Nlinhas; lin++)
		{
			Obj_ifstream >> Vet[lin];
			if (Obj_ifstream.fail())
			{
				//*
				cout << "Falha para ler dados--de ordem  " << lin << "---3--- enviado de 'LendoEmArquivos'" << "\n";
				cout << " digite tecla para terminar o programa " << "\n";
				cin >> Tecla;
				exit(1);
				//*/

			}
		}
	}
};

void CTrabDirArq::ObtemCurrent_Directory(string& CurrentDir) {
	//------Obtendo o Diretório Atual//---------IMPORTANTE---Para Windows
	//
	//----Diretório onde está o arquivo  terminado por :   ".vcxproj"
	//
	//
	char buff[FILENAME_MAX]; //create string buffer to hold path
	_getcwd(buff, FILENAME_MAX);
	string current_working_dir(buff);
	CurrentDir = current_working_dir;//--Diretório atual
	//
	/*
	string  Tecla_00A;
	cout << " CurrentDir = " << CurrentDir << "\n";
	cout << " digite tecla para continuar" << "\n";
	//////////cin >> Tecla_00A;
	//------------------------------------------------------------------------------------>IMPORTANTE--28/04/2021
	getline(cin, Tecla_00A, '\n');//------>Ler string com caracter espaço em branco
	//------------------------------------------------------------------------------------>IMPORTANTE--28/04/2021
	//*/
	//
	//------Obtidodo o Diretório Atual//---------IMPORTANTE---Para Windows
};

void CTrabDirArq::TrocaCaracterAporOutroB(string& StringDada, string& CaracterA, string& CaracterB, bool& FoiTrocado, string& NovaString){
	//
	int    Nstring_CaracterA, Nstring_CaracterB;
	//
	Nstring_CaracterA = static_cast<int>(CaracterA.length());//---Fornece o número de Caracterfes da string   CaracterA
	Nstring_CaracterB = static_cast<int>(CaracterB.length());//---Fornece o número de Caracterfes da string   CaracterB
	//
	FoiTrocado = true;
	//
	if (Nstring_CaracterA != 1 || Nstring_CaracterB != 1)
	{
		string        Tecla;
		FoiTrocado = false;
		//
		string       Mens;
		//
		Mens = " A segunda e/ou terceira string do argumento não têm somente UM Caracter.";
		SetConsoleOutputCP(GetACP());//----Escrever Caracteres Latinos
		cout << Mens << "\n";
		cout << "\n";
		Mens = " Elas têm que ter um e somente um caracter.";
		SetConsoleOutputCP(GetACP());//----Escrever Caracteres Latinos
		cout << Mens << "\n";
		cout << "\n";
		cout << " Digite uma tecla para continuar" << "\n";
		////////////////cin >> Tecla;
		//------------------------------------------------------------------------------------>IMPORTANTE--28/04/2021
		getline(cin, Tecla, '\n');//------>Ler string com caracter espaço em branco
		//------------------------------------------------------------------------------------>IMPORTANTE--28/04/2021
		//
		return;//------Usando adequadamente "return'  em função "void"
		//
	}
	//
	NovaString = "";
	//
	int   Nstring;
	//
	Nstring = static_cast<int>(StringDada.length());//---Fornece o número de Caracterfes da string   StringDada
	//
	if (Nstring >= 1)
	{
		//
		for (int ia = 0; ia < Nstring; ia++)
		{
			//
			if (StringDada.at(ia) == CaracterA.at(0))
			{
				NovaString += CaracterB;
			}
			else
			{
				NovaString += StringDada.at(ia);
			}
			//
		}
		//
	}
	//
};