#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct vertice {
    float x,y,z;
};

struct face {
    std::vector<int> verticesDaFace;
};

class malhaGrafica {
    private:
        std::vector<vertice> listaDeVertices;
        std::vector<face> listaDeFaces;
    public:
        //implementacao de leitura do arquivo OFF
        bool lerArquivo(string arquivo){
            std::ifstream file(arquivo);

            if(!file.is_open()){
                return false;
            }

            std::string line;

            //ignorando a primeira linha
            std::getline(file, line);

            // Lê a linha com o número de vértices e faces
            std::getline(file, line);
            std::stringstream ss(line);
            int numVertices, numFaces, numEdges;
            ss >> numVertices >> numFaces >> numEdges;

            std::cout <<"quantidade vertices: "<< numVertices <<endl;
            std::cout <<"quantidade faces: "<< numFaces <<endl;
            std::cout <<"quantidade edges: "<< numEdges <<endl;



            return true;
        }

        void apresentarDados(){

        };
};



int main()
{
    malhaGrafica malha;
    std::string arquivo = "triangles.off"; // Replace with your OFF file name

    if(malha.lerArquivo(arquivo)){
        std::cout << "arquivo lido com sucesso!" << std::endl;

    }else{
        std::cerr << "arquivo nao encontrado" << std::endl;
    }

    return 0;
}
