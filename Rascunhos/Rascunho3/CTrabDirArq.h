#ifndef CTRABDIRARQ_H
#define CTRABDIRARQ_H
#include <string>
using std::string;
class CTrabDirArq
{
    public:
        string Ncarcter;
        string CaracterProibido[];
        string Disco;
        string DirValido;
        string Arquivo;
        int Ncomponente_Vet;
        int NcasasDecimais;
        double Vet[];
        int DimVetor;
        double* VarX;
        double* Vetor;
        string DirParaERRO;
        int Precisao;
        bool Sucesso;
        int NumRegionsStringMaisDados;
        int* NumDeString;
        string** ListaStringArq;
        string DirOndeColocarArquivo;
        string NomeDoArquivo;
        int* NdadosPorRegiao;
        int NarquivoParaSerInserido_Max;
        string DirMaisArq;
        bool SegundaLinhaEumaString;
        int Limite;
        string NomeDosDados;
        int Nlinhas;
        string CurrentDir;
        string StringDada;
        string CaracterA;
        string CaracterB;
        bool FoiTrocado;
        string NovaString;

    public:
        void CaracterProibidosDirArq();
        bool ChecaDiscoValido(string& Disco);
        bool ChecaSeDirExiste(string& Dir);
        bool Cria_DirValido(string& DirValido);
        void EscreveEmArq(string& Dir, string& Arquivo, int& Ncomponente_Vet, int& NcasasDecimais, double Vet[]);
        void EscreveVetor1EmArq(int& DimVetor, double* VarX, double* Vetor, string& Dir, string& Arquivo, string& DirParaERRO, int& Precisao,  bool& Sucesso);
        void GeraArqDadosNumericos_0_CTrabComDir_0( int& NumRegionsStringMaisDados, int* NumDeString, string** ListaStringArq, string& DirOndeColocarArquivo, string& NomeDoArquivo, bool& Sucesso);
        void GeraArqDadosNumericos_1_CTrabComDir_0( int& NumRegionsStringMaisDados, int* NumDeString, string** ListaStringArq, int* NdadosPorRegiao, double** Vetor, string& DirOndeColocarArquivo,
                                                   string& NomeDoArquivo, bool& Sucesso);
        void InsereArqEmDir_CTrabComDir_0(string& Dir, int& NarquivoParaSerInserido_Max);
        void InsereArqEmDir_0(string& Dir, string& Arq);
        void LendoEmArquivos(string& DirMaisArq, bool& SegundaLinhaEumaString, int& Limite, string& NomeDosDados, int& Nlinhas, double Vet[]);
        void ObtemCurrent_Directory(string& CurrentDir);
        void TrocaCaracterAporOutroB(string& StringDada, string& CaracterA, string& CaracterB, bool& FoiTrocado, string& NovaString);
    public:
        ~CTrabDirArq();

};
#endif //CTRABDIRARQ_H
