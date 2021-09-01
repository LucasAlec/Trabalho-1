#include "CTrabDirArq.cpp"

int main() {
    SetConsoleOutputCP(GetACP());
	system("tree");
	CTrabDirArq objCTrabDirArq;
	cout << objCTrabDirArq.checaDiscoValido_CTrabDirArq("d");
	cout << objCTrabDirArq.criaDir_CTrabDirArq("asd");
	cout << objCTrabDirArq.checaSeDirExiste_CTrabDirArq("asd");
	cout << objCTrabDirArq.criarArquivo_CTrabDirArq("arqteste.txt");
	cout << objCTrabDirArq.criarArquivo_CTrabDirArq("arqtest2.txt");
	cout << objCTrabDirArq.criarArquivo_CTrabDirArq("arqteste3.txt");
	int num[2][5] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}}, l = 2, c = 5;
	string nome = "arqteste.txt";
	string noem2  = "arqtest2.txt";
	string nome3 = "arqteste3.txt";
	objCTrabDirArq.escreveVetor2DArq_CTrabDirArq(num, nome, l, c);

	double dob[1][2] = {1.12321412312123, 432.123211324123};
	l = 1;
	c = 2;
	objCTrabDirArq.escreveVetor2DArq_CTrabDirArq(dob, noem2, l , c);

	string ListaStringArq[3][2];
    ListaStringArq[0][0] = "Valor     Da   Temperatura  no canal do reator ";
	ListaStringArq[0][1] = "Seção   Z = 20 cmm";
	ListaStringArq[1][0] = "Valor     Da   Temperatura  no canal do reator ";
	ListaStringArq[1][1] = "Seção   Z = 120 cmm";
	ListaStringArq[2][0] = "Valor     Da   Temperatura  no canal do reator ";
	ListaStringArq[2][1] = "Seção   Z = 180 cmm";
	l = 3;
	c = 2;
	objCTrabDirArq.escreveVetor2DArq_CTrabDirArq(ListaStringArq, nome3, l, c);
	// Loop NumeroDeArqDeCadaDir_CTrabDirArq
    /*int NumDeArqDeCadaDir[NumeroDeDir_CTrabDirArq];
    for (int i = 0; i < NumeroDeDir_CTrabDirArq; i++)
    {
        int j;
        std::cin >> j;
        NumDeArqDeCadaDir[i] = j;
    }*/
        //int NumDeArqDeCadaDir[NumeroDeDir_CTrabDirArq];
    /*for (int i = 0; i < NumeroDeDir_CTrabDirArq; i++)
    {
        int j;
        std::cin >> j;
        NumDeArqDeCadaDir[i] = j;
    }
    NumeroDeArqDeCadaDir_CTrabDirArq = NumDeArqDeCadaDir;*/
    return 0;
}
