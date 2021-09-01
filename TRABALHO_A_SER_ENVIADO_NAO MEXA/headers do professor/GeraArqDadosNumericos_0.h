//
#ifndef  _GERAARQDADOSNUMERICO_0_H_
#define  _GERAARQDADOSNUMERICO_0_H_

#include <string>
using std::string;//C++Padrão

void GeraArqDadosNumericos_0_CTrabComDir_0(//Dados de entrada
	                                       int&            NumRegionsStringMaisDados,
	                                       int*            NumDeString,
	                                       string**        ListaStringArq,
	                                       string&         DirOndeColocarArquivo,//----Exemplo: D:/pasta1/Pasta2
	                                       string&         NomeDoArquivo,//--Exemplos: ArqDado1.txt
	                                       //
	                                       //Retorna
	                                       bool&           Sucesso
	                                      );



#endif //---_GERAARQDADOSNUMERICO_0_H_
