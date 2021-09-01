#ifndef CTRABDIRARQ_H
#define CTRABDIRARQ_H
#include <string>
using std::string;

/**
 * Classe CTrabDirArq.
 * @since 27/08/21
 */
class CTrabDirArq {

	public:// Faltar montar construtores
        CTrabDirArq();
	private:
		int         NumeroDeDir_CTrabDirArq;/** variables description **/
		int*        NumeroDeArqDeCadaDir_CTrabDirArq;/** variables description **/
		//string*     NomeDir_CTrabDirArq;
		string**    NomeArqDir_CTrabDirArq;/** variables description **/

	public:
		// Setters
		void setNumeroDeDir_CTrabDirArq(const int& NumeroDeDir);
		void setNumeroDeArqDeCadaDir_CTrabDirArq(int* NumDeArqDeCadaDir);
		void setNomeArqDir_CTrabDirArq();

		// Metodos
		bool checaDiscoValido_CTrabDirArq(const string& LetraDisco);
		bool checaSeDirExiste_CTrabDirArq(const string& NomeDir);
		bool criaDir_CTrabDirArq(const string& NomeDir);
		bool criarArquivo_CTrabDirArq(const string& NomeArq);
		//bool trocarDisco(const string& LetraDisco);
		bool escreveVetor2DArq_CTrabDirArq(string* string2D, const string& nomeArq, const int& linhas, const int& colunas);
		template<typename T>
		bool escreveVetor2DArq_CTrabDirArq(T* numerico2D, const string& nomeArq, const int& linhas, const int& colunas);
		bool montar_CTrabDirArq(); // Pega tudo e cria os diretorios com arquivos no path atual

		//Destruidores
		~CTrabDirArq();
		void destruidorNomeArqDir_CTrabDirArq();
};
#endif // CTRABDIRARQ_H
