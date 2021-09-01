//
#ifndef  _GERAARQDADOSNUMERICO_1_H_
#define  _GERAARQDADOSNUMERICO_1_H_

#include <string>
using std::string;//C++Padrão

void GeraArqDadosNumericos_1_CTrabComDir_0(//Dados de entrada
	                                       int&            NumRegionsStringMaisDados,
	                                       int*            NumDeString,
	                                       string**        ListaStringArq,
										   //
										   int*            NdadosPorRegiao,
										   double**        Vetor,
										   //
	                                       string&         DirOndeColocarArquivo,//----Exemplo: D:/pasta1/Pasta2
	                                       string&         NomeDoArquivo,//--Exemplos: ArqDado1.txt
	                                       //
	                                       //Retorna
	                                       bool&           Sucesso
	                                      );



#endif //---_GERAARQDADOSNUMERICO_1_H_
