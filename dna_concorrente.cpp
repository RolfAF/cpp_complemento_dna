#include <omp.h>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
using std::string;
using std::cout;
using std::map;

string complemento_dna(string sequencia_dna){
    string complemento_dna = sequencia_dna;
    map<char, char> complemento;
        complemento['A'] = 'T';    complemento['C'] = 'G';
        complemento['G'] = 'C';    complemento['T'] = 'A';
    for(int i = 0; i < sequencia_dna.length(); i++){
        complemento_dna[i] = complemento[sequencia_dna[i]];
    }
    return complemento_dna;
}

int main(int argc, char *argv[]){
    string path = "/home/rolf/Desktop/2023_02/programacao_alto_desempenho/openmp/atividade_dna/arquivosDNA/";
    double start, end;
    start = omp_get_wtime();
    for(int i = 0; i < 10; i++){
        std::ifstream arquivo_dna; arquivo_dna.open(path+"dna-"+std::to_string(i)+".txt");
        std::ofstream arquivo_comp; arquivo_comp.open(path+"comp-"+std::to_string(i)+".txt");
        string sequencia_dna;
        string sequencia_comp;
        if(arquivo_dna.is_open()){
            while(arquivo_dna.good()){
                arquivo_dna >> sequencia_dna;
                sequencia_comp = complemento_dna(sequencia_dna);
                //cout << sequencia_comp;
                arquivo_comp << sequencia_comp+"\n";
            }
        }
        printf("Complemento %d feito\n",i);
    }
    end = omp_get_wtime();
    printf("Tempo decorrido: %f segundos\n",end - start);
    //printf("Precisão: %f"\n,omp_get_wtick());
	return 0;
}
