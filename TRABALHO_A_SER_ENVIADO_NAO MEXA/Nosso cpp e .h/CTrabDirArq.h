#pragma once
#ifndef _CTRABDIRARQ_
#define _CTRABDIRARQ_

#include <string>


using namespace std;

class CTrabDirArq
{
public:
	CTrabDirArq();
	~CTrabDirArq();

	//metodos para alocacao:
	//void Alocacao_din_dos_vetores(int);
	//metodos para dealocacao
	

	//metodos
	void CaracterProibidosDirArq(const int Ncarcter, string   CaracterProibido[]);
	bool ChecaDiscoValido(string& Disco);
	bool ChecaSeDirExiste(string& Dir);
	bool Cria_DirValido(string& DirValido);
	void EscreveEmArq(string& Dir, string& Arquivo, int& Ncomponente_Vet, int& NcasasDecimais, double        Vet[]);
	void InsereArqEmDir_CTrabComDir_0(string& Dir, int& NarquivoParaSerInserido_Max);
	void InsereArqEmDir_0(string& Dir, string& Arq);
	void ObtemCurrent_Directory(string& CurrentDir);
	void TrocaCaracterAporOutroB(string& StringDada, string& CaracterA, string& CaracterB, bool& FoiTrocado, string& NovaString);

	void GeraArqDadosNumericos_0_CTrabComDir_0(//Dados de entrada
		int& NumRegionsStringMaisDados,
		int* NumDeString,//----->
		string** ListaStringArq,
		//
		//-->ListaStringArq[i][j]; i está em {0,...,(NumRegionsStringMaisDados -1)} e j está em {0,...,NumDeString[i]}
		//-->Portanto deve ser alocado com o tamanho:  ListaStringArq = new string*[NumRegionsStringMaisDados] e 
		//-->ListaStringArq[i] = new string[NumDeString[i]+ 1]: para i = 0,.......,((NumRegionsStringMaisDados -1)
		//
		//OBS:--->Para todo i; última string a última string só deve ter caractere Espaço em Branco(Pode ter mais
		//
		string& DirOndeColocarArquivo,//----Exemplo: D:/pasta1/Pasta2
		string& NomeDoArquivo,//--Exemplos: ArqDado1.txt
		//
		//Retorna
		bool& Sucesso
	);
	void GeraArqDadosNumericos_1_CTrabComDir_0(//Dadose de entrada
		int& NumRegionsStringMaisDados,
		int* NumDeString,//----->
		string** ListaStringArq,
		//
		int* NdadosPorRegiao,
		double** Vetor,
		//
		//
		//-->ListaStringArq[i][j]; i está em {0,...,(NumRegionsStringMaisDados -1)} e j está em {0,...,NumDeString[i]}
		//-->Portanto deve ser alocado com o tamanho:  ListaStringArq = new string*[NumRegionsStringMaisDados] e 
		//-->ListaStringArq[i] = new string[NumDeString[i]+ 1]: para i = 0,.......,((NumRegionsStringMaisDados -1)
		//
		//OBS:--->Para todo i; última string a última string só deve ter caractere Espaço em Branco(Pode ter mais
		//
		string& DirOndeColocarArquivo,//----Exemplo: D:/pasta1/Pasta2
		string& NomeDoArquivo,//--Exemplos: ArqDado1.txt
		//
		//Retorna
		bool& Sucesso
	);

	void LendoEmArquivos(string& DirMaisArq, //----Dir+Arquivode Dados
	/////////////////////////////////////////////////int&        Nlinhas,//-----Número de dados double
		bool& SegundaLinhaEumaString,
		int& Limite,
		string& NomeDosDados,
		int& Nlinhas,
		double      Vet[]);


private:

	int NumDeDir_CTrabDirArq;
	int* NumArqDeCadaDir_CTrabDirArq;
	string* Dir_CTrabDirArq;
	string** ArqEmCadaDir_CTrabDirArq;

};



#endif // !_CTRABDIRARQ_
