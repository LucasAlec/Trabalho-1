#include "EscreverString2DArquivo.h"

#include <fstream>
//#include <string> em "EscreverString2DArquivo.h"

using std::string;
void EscreverString2DArquivo(const string** string2d, const string& path) {
  int l, c;
  l = string2d.size();
  c = string2[0].size;
  std::ofstream file;
  file.open(path);
  
  for (int i = 0; i < c; i++) {
    for (int j = 0; j < l; i++) {
    	file << string2d[i][j] << "		";
    }
    file << "\n";
  }
}
