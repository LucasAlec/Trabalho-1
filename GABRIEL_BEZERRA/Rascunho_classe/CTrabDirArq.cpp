#include "CTrabDirArq.h"
/**/
// Construtoras
CTrabDirArq::CTrabDirArq()
{
	NumDeDir_CTrabDirArq = 0;
	NumArqDeCadaDir_CTrabDirArq = 0;
	Dir_CTrabDirArq = 0;
	ArqEmCadaDir_CTrabDirArq = 0;
	
}
/**/

CTrabDirArq::CTrabDirArq
(
	int NumDeDir_CTrabDirArq_const,
	int* NumArqDeCadaDir_CTrabDirArq_const,
	string* Dir_CTrabDirArq_const,
	string** ArqEmCadaDir_CTrabDirArq_const
)
{
	NumDeDir_CTrabDirArq = NumDeDir_CTrabDirArq_const;
	NumArqDeCadaDir_CTrabDirArq = NumArqDeCadaDir_CTrabDirArq_const;
	Dir_CTrabDirArq = Dir_CTrabDirArq_const;
	ArqEmCadaDir_CTrabDirArq = ArqEmCadaDir_CTrabDirArq_const;

}

//destrutora chama funções dealocadoras
CTrabDirArq::~CTrabDirArq()
{
	
}

//Get
int CTrabDirArq::Get_NumDeDir_CTrabDirArq() const
{
	return NumDeDir_CTrabDirArq;
}

int* CTrabDirArq::Get_NumArqDeCadaDir_CTrabDirArq() const
{
	return NumArqDeCadaDir_CTrabDirArq;
}


string* CTrabDirArq::Get_Dir_CTrabDirArq() const
{
	return Dir_CTrabDirArq;
}


string** CTrabDirArq::Get_ArqEmCadaDir_CTrabDirArq() const
{
	return ArqEmCadaDir_CTrabDirArq;
}


//Set

void CTrabDirArq::Set_NumDeDir_CTrabDirArq(int& NumdeDir)
{
	NumDeDir_CTrabDirArq = NumdeDir;
}


void CTrabDirArq::Set_NumArqDeCadaDir_CTrabDirArq(int* NumArqdeCadaDir)
{
	NumArqDeCadaDir_CTrabDirArq = NumArqdeCadaDir;
}


void CTrabDirArq::Set_Dir_CTrabDirArq(string* Dir)
{
	Dir_CTrabDirArq = Dir;
}


void CTrabDirArq::Set_ArqEmCadaDir_CTrabDirArq(string** ArqEmCadaDir)
{
	ArqEmCadaDir_CTrabDirArq = ArqEmCadaDir;
}
