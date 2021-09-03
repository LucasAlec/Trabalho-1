#include "AlocarString2D.cpp"
#include "AlocarString2D.h"
#include "CriarDiretorio.cpp"
#include "CriarDiretorio.h"
#include "CriarArquivoDir.h"
#include "CriarArquivoDir.cpp"
#include "EscreverString2DArquivo.h"
#include "EscreverString2DArquivo.cpp"

using std::cout, std::endl, std::cin;

int main() {

  string newdir, arquivo, path;
	cout << "Diretorio atual\n";
	cout << fs::current_path() << endl;
	cout << "Digite o nome do diretorio a ser criado:\n";
	cin >> newdir;
	CriarDiretorio(newdir);
	cout << "Digite o nome do arquivo para ser colocado no diretorio /" << newdir << endl;
	cin >> arquivo;
	CriarArquivoDir(newdir, arquivo);
	path = "/" + newdir + "/" arquivo;
	int l = 2, c = 2;
	string** ptr = AlocarString2D(l, c);
	
	
	DealocarString2D(ptr, l, c)
  return 0;
}
