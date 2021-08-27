#ifndef _CTRABDIRARQ_H_
#define _CTRABDIRARQ_H_

#include <iostream>
using namespace std;
using std::string;


class CTrabDirArq
{
public:
	CTrabDirArq();
	CTrabDirArq
	(
		int NumDeDir_CTrabDirArq,
		int* NumArqDeCadaDir_CTrabDirArq,
		string* Dir_CTrabDirArq,
		string** ArqEmCadaDir_CTrabDirArq
	);

	~CTrabDirArq();


protected:



private:

	int NumDeDir_CTrabDirArq;
	int* NumArqDeCadaDir_CTrabDirArq;
	string* Dir_CTrabDirArq;
	string** ArqEmCadaDir_CTrabDirArq;



public:
	//Get
	int Get_NumDeDir_CTrabDirArq() const;
	int* Get_NumArqDeCadaDir_CTrabDirArq() const;
	string* Get_Dir_CTrabDirArq() const;
	string** Get_ArqEmCadaDir_CTrabDirArq() const;


	//Set
	void Set_NumDeDir_CTrabDirArq(int& NumdeDir);
	void Set_NumArqDeCadaDir_CTrabDirArq(int* NumArqdeCadaDir);
	void Set_Dir_CTrabDirArq(string* Dir);
	void Set_ArqEmCadaDir_CTrabDirArq(string** ArqEmCadaDir);
	
	/**
	//dealoc
	void Dealoc_NumDeDir_CTrabDirArq();
	void Dealoc_NumArqDeCadaDir_CTrabDirArq();
	void Dealoc_Dir_CTrabDirArq();
	void Dealoc_ArqEmCadaDir_CTrabDirArq(int& N)
	/**/




};




#endif