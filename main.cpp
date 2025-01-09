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

            // popular vertices
            listaDeVertices.resize(numVertices);
            for (int i = 0; i < numVertices; ++i) {
                file >> listaDeVertices[i].x >> listaDeVertices[i].y >> listaDeVertices[i].z;
            }

            //popular faces e vertices das faces
            listaDeFaces.resize(numFaces);
            for (int i = 0; i < numFaces; ++i) {
                int numVerticesFace;
                file >> numVerticesFace ;

                listaDeFaces[i].verticesDaFace.resize(numVerticesFace);
                for (int j = 0; j < numVerticesFace; ++j) {
                    file >> listaDeFaces[i].verticesDaFace[j];
                }
            }



            return true;
        }

        void apresentarDados(){
            int indiceVertices;
            //apresentar vertices
            std::cout << "\nVertices\n\n "<< endl;
            std::cout << "(identificacao) Vertice: " << "X-Y-Z\n" << endl;
            for(const auto& vertice : listaDeVertices){
                std::cout << "Vertice_" << indiceVertices++ << ": "<<vertice.x << "-" << vertice.y << "-" << vertice.z << endl;
            }

            //apresentar faces e vertices da face
            std::cout << "\nFaces\n\n";
            std::cout << "(identificacao) Vertices da Face\n" << std::endl;
            for (size_t i = 0; i < listaDeFaces.size(); ++i) {
                std::cout << "Face_" << i << ": ";
                for (const auto& verticeIndice : listaDeFaces[i].verticesDaFace) {
                    std::cout << verticeIndice << " ";
                }
                std::cout << std::endl;
            }

        };
};



int main()
{
    malhaGrafica malha;
    std::string arquivo = "triangles.off";

    if(malha.lerArquivo(arquivo)){
        malha.apresentarDados();

    }else{
        std::cerr << "arquivo nao encontrado" << std::endl;
    }

    return 0;
}


