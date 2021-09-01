//
//
#include "TrocaCarecter_AporB.h"
#include <string>
#include <fstream>//-----Usar Objetos "ofstream  Escrever em arquivos" e "ifstream ler em Arquivos
#include <iostream>//-Vai usar cin e/ou cout  Escrever na tela do DOES
#include "windows.h"//-----Escrever Caracteres Latinos
#include <cstdio>//----Usar exit(0): exit(1);...
#include <iomanip> //-------Escrever double   com precisão especificada   
using std::setprecision;//-------Para especificara a precisão
//
using namespace std;



void TrocaCaracterAporOutroB(string&  StringDada,
	string&  CaracterA, string&  CaracterB, bool&  FoiTrocado, string&  NovaString)//Inserido em ---26/04/2021
{
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
}
