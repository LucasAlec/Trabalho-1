#ifndef CTRABDIRARQ_H
#define CTRABDIRARQ_H

#include <string>
using std::string;
string caracteresProibidos = "<>:;\"/|?*'!@#$¨&%^*()-+=`'{}[]?Žš";

class CTrabDirArq {

	private:
		string novo_dir;
		string path; // Path atual
		//string** 
		//string arquivo;
		//string path;
		
	public:
		string** alocarString2D_CTrabDirArq(const int& linhas, const int& colunas);
		void dealocarString2D_CTrabDirArq(string** ptr, const int& linhas, const int& colunas);
		void criarDiretorio_CTrabDirArq();
		void mostrarDiretorioAtual_CTrabDirArq();
		void mostrarTree_CTrabDirArq();
		void setNovoDir_CTrabDirArq(string& texto_dir);
		string getNovoDir_CTrabDirArq();
		void setNovoArq_CTrabDirArq(string& texto_arq);
		string getNovoArq_CTrabDirArq();
		void setPathAtual_CTrabDirArq(string& texto_path);
		string getPathAtual_CTrabDirArq();
		
		//~CTrabDirArq();
};

#endif //CTRABDIRARQ_H
