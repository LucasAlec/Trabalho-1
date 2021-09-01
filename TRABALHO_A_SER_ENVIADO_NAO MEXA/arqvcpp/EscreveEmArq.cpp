//
//
#include "EscreveEmArq.h"
//
#include <fstream>//-----Usar Objetos "ofstream  Escrever em arquivos" e "ifstream ler em Arquivos
#include <iostream>//-Vai usar cin e/ou cout  Escrever na tela do DOES
#include <string>
#include "windows.h"//-----Escrever Caracteres Latinos
#include <cstdio>//----Usar exit(0): exit(1);...
#include <iomanip> //-------Escrever double   com precisão especificada   
using std::setprecision;//-------Para especificara a precisão
using namespace std;
//
//
void EscreveEmArq(string&              Dir, string&     Arquivo, int&          Ncomponente_Vet, int&         NcasasDecimais, double        Vet[])
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
			
			Obj_ofstream << "   " << "    " << i << "                     Vet[i]   =        " << setprecision(CasaDecimaisReal) <<Vet[i] << "\n";
			Obj_ofstream << "" << "\n";
		}
		//
		Obj_ofstream.close();
		//
	}

}
