#ifndef CTRABDIRARQ_H
#define CTRABDIRARQ_H
#include <string>
using std::string;
// Falta colocar o negocio de caracteres latinos
class CTrabDirArq {

    CTrabDirArq();
    private:
        int         NumeroDeDir_CTrabDirArq;
        int*        NumeroDeArqDeCadaDir_CTrabDirArq;
        //string*     NomeDir_CTrabDirArq;
        string**    NomeArqDir_CTrabDirArq;

    public:
        //bool checaSeDirExiste_CTrabDirArq(const string& NomeDir); // Da pra fazer com _mkdir <- ja retorna true ou false
       // bool criaDir_CTrabDirArq(const string& NomeDir);
        //bool criarArquivo_CTrabDirArq(const string& NomeArq);
        //void escreveVetorString2DEmArq_CTrabDirArq(const string& NomeArq, const string** VetorString2D); // Usar get path para escrever no path  desejado ou atual
       // void escreveVetorNumericoEmArq_CTrabDirArq(const string& NomeArq, const NUMERICO** VetorNumerico);
        //bool trocaDisco_CTrabDirArq(string& PathAtual);
        //string* alocarVetorString1D_CTrabDirArq(const int& Linhas, const int& Colunas); //-> Dir_CtrabDriArq...
        //string** alocarVetorString2D_CTrabDirArq(const int& Linhas, const int& Colunas); //-> NumDeDir_CTrabDirArq, ArqDeCada Dir..
        //bool trocarDisco(const string& LetraDisco);

        //montarDirArq_CTrabDirArq();

        // Setters
        void setNumeroDeDir_CTrabDirArq(const int& NumeroDeDir);
        void setNumeroDeArqDeCadaDir_CTrabDirArq(int* NumDeArqDeCadaDir);
        void setNomeArqDir_CTrabDirArq();
        void destruidorNomeArqDir_CTrabDirArq(/*string** ptr, const int& x, const int& y*/);
        void montar(); // Terminar...
        //~CTrabDirArq();
        //Dealocar vetores dinamicos criados.

        ~CTrabDirArq();
};


#endif // CTRABDIRARQ_H
