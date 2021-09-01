//
#ifndef  _ESCREVEVETOR1EMARQ_H_
#define  _ESCREVEVETOR1EMARQ_H_

#include <string>
using std::string;//C++Padrão

void EscreveVetor1EmArq(//Dados de Entrada
	                    int&          DimVetor, 
	                    double*       VarX, 
	                    double*       Vetor, 
	                    string&       Dir,
	                    string&       Arquivo, 
						string&       DirParaERRO, 
						int&          Precisao,
						//Reorna
						bool&  Sucesso );

#endif //---_ESCREVEVETOR1EMARQ_H_
