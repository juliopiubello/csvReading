#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>


using namespace std;

int main()
{
    string situation[6] ={"Rep Nota", "Rep Freq", "Aprovado", "Cancelado", "Trancado", "Testando"};
    string arquivoTurmas = "cursos.csv";
    std::ifstream c(arquivoTurmas.c_str());
    int k=0;
    string q;
    while(c.is_open()){
        while(c.good()){
            getline(c,q,'\n');
            k++;
        }
    c.close();
    k--;
    }
    std::cout << "Número de cursos" << k;
    static std::vector<std::string> cursos;
    static std::vector<std::string> codigos;

    std::ifstream b(arquivoTurmas.c_str());
    if(!b.is_open()) std::cout << "ERROR: File Open" << '\n';
    int i = 0;
    while(b.is_open()){
    string aux3, aux4;
    while(b.good()){
            getline(b,aux3,';');
            cursos.push_back(aux3);
            getline(b,aux4,'\n');
            codigos.push_back(aux4);
            i++;
        }
    b.close();
    }

    int numCursos = cursos.size() - 1;

    string arquivoTurmas2 = "turmas.csv";

    static std::vector<std::string> turmas;

    std::ifstream arquivo(arquivoTurmas2.c_str());
    string aux3;
    while(arquivo.is_open()){
        while(arquivo.good()){
            getline(arquivo,aux3,'\n');
            turmas.push_back(aux3);
            std::cout <<"";
        }
        arquivo.close();
    }



    int numTurmas = turmas.size();
    int j;
    int turma;
    int semestre;
    string inutil, inutil2, inutil3, inutil4, inutil5, inutil6, inutil7;
    string matriculas[numTurmas][150];
    string situacao[numTurmas][150];
    int alunosTurma[numTurmas];
    i=0;
    int conta=0;
    int ab=0;
    int h;
    int contador2;
    string aux;
    for(j=0;j<numTurmas;j++){
        i=0;
        ab=0;
        std:ifstream a(turmas[j].c_str());
        while(a.good()){
            getline(a,matriculas[conta][i], ',');
            getline(a,inutil,',');
            getline(a,inutil2,',');
            getline(a,inutil3,',');
            getline(a,inutil4,',');
            getline(a,inutil5,',');
            getline(a,inutil6,',');
            getline(a,inutil7,',');
            getline(a,situacao[conta][i],'\n');
            i++;
            ab++;
            contador2++;
        }
        a.close();
        alunosTurma[conta] = ab-1;
        std::cout << "turma " << turmas[conta][7] << " ano " << turmas[conta][9] << turmas[conta][10] << turmas[conta][11] << turmas[conta][12] <<
        " semestre " << turmas[conta][14] << " alunosTotal " << i << " alunos desta turma " << alunosTurma[conta] <<  '\n';
        conta++;
    }

    string aux2;
    for(h=0;h<numTurmas;h++){
        for(i=0;i<alunosTurma[h];i++){
            aux = matriculas[h][i][4];
            aux2 = matriculas[h][i][5];
            matriculas[h][i] = aux + aux2;
        }
    }

    int x,y,w,z;
    int contagem[numTurmas][numCursos][numCursos]= {};
    int contador=0;
    for(z=0;z<numTurmas;z++){
        for(x=0;x<=alunosTurma[z];x++){
                if(matriculas[z][x][1] == NULL ){
                    x=150;
                }
            for(y=0; y<numCursos+1; y++){
                w=0;
                while(matriculas[z][x][w] == codigos[y][w]){
                    w++;
                    if(w == 3 ){
                        if(situacao[z][x] == "Rep Nota"){
                            contagem[z][y][0]++;
                            contador++;
                        }else if(situacao[z][x] == "Rep Freq"){
                            contagem[z][y][1]++;
                            contador++;
                        }else if(situacao[z][x]== "Aprovado"){
                            contagem[z][y][2]++;
                            contador++;
                        }else if(situacao[z][x] == "Cancelado"){
                            contagem[z][y][3]++;
                            contador++;
                        }else if(situacao[z][x]== "Trancado"){
                            contagem[z][y][4]++;
                            contador++;
                        }else{
                            contagem[z][y][5]++;
                        }
                    }
                }
            }
        }
    }
    ofstream myfile;
    myfile.open("planilhaDeTurmas.csv", ios::ate);

    for(z=0;z<numTurmas;z++){
        for(h=0;h<numCursos;h++){
            myfile << cursos[h] << ";" << turmas[z][9] << turmas[z][10] << turmas[z][11] << turmas[z][12] << ";" << turmas[z][14] << ";" <<
            codigos[h] << ";" << turmas[z][7] <<  ";" << contagem[z][h][0] << ";" << contagem[z][h][1] << ";" << contagem[z][h][2] << ";"<<
            contagem[z][h][3] << ";" << contagem[z][h][4] << ";" << contagem[z][h][5] << '\n';
        }
    }

    for(z=0;z<14;z++){
        std::cout << "turma " << turmas[z][7] << " ano " << turmas[z][9] <<
        turmas[z][10] << turmas[z][11] << turmas[z][12] <<
        " semestre " << turmas[z][14]  << " alunos desta turma " << alunosTurma[z] <<  '\n';
        for(h=0;h<numCursos;h++){
        std::cout << "curso " << cursos[h] << '\n';
            for(x=0; x<numCursos; x++){
                    std::cout << "situacao "<< situation[x] << " "  << contagem[z][h][x] << '\n';
            }
        }
    }
        std::cout << "CONTADOR" << contador << '\n';
        std::cout << "Nummero Cursos" << numCursos;
    return 0;
}
