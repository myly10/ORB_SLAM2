#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <climits>
using namespace std;

int main(int argc, char **argv){
	if (argc<2) return 1;
	ifstream vocIn(argv[1]);
	ofstream vocOutBin((string(argv[1])+".bin").c_str(), ios::binary);
	int id;
	unsigned char n;
	for (int i=0;i!=4;++i){
		vocIn>>id;
		vocOutBin.write((const char*)&id, sizeof(id));
	}
	double nd;
	int min=INT_MAX, max=INT_MIN;
	while (vocIn>>id){
		vocOutBin.write((const char*)&id, sizeof(id));
		for (int i=0;i!=33;++i){
			vocIn>>id;
			n=id;
			vocOutBin.write((const char*)&n, sizeof(n));
			if (n>max) max=n;
			if (n<min) min=n;
		}
		vocIn>>nd;
		vocOutBin.write((const char*)&nd, sizeof(nd));
	}
	cout<<min<<" "<<max<<endl;
	return 0;
}