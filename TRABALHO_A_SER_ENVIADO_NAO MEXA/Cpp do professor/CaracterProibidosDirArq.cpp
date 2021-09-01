//
//
#include "CaracterProibidosDirArq.h"
#include "windows.h"//-----Escrever Caracteres Latinos
#include <iostream>//-Vai usar cin e/ou cout
#include <cstdio>//----Usar exit(0): exit(10;...
using namespace std;
//
//
//
void CaracterProibidosDirArq(/*Dado*/ 
	                         const int Ncarcter, 
							 /*Retorna Vetor string com os caracteres proibidos*/ 
							 string   CaracterProibido[])
{
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
	//
	//
}
