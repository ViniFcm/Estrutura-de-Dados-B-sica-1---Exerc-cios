#include <iostream>
#include <cassert>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;

struct Person
{
    string firstName;
    string lastName;
    string country;

    Person(string f, string l, string c) : firstName(f), lastName(l), country(c)
    {}
};

Person** readInput(const string, const int);

void sort(Person**, int);

int main(int argc, const char * argv[]) {
    if(argc != 2){
        cout << "Programa espera argumentos:\narg1 - indicando o caminho do arquivo de entrada" << endl;
        return -1;
    }
    
    const string path = argv[1];
    const int size = 10000;
    Person** people = readInput(path, size);
    if(people == nullptr)
    {
        cout << "Erro ao ler e criar vetor de entrada." << endl;
        return -1;
    }
    
    cout << "Entrada lida corretamente. Executando ordenação..." << endl;
    
    sort(people, size);

    cout << "Fim da ordenação." << endl;

    for( int i = 0; i < size; ++i )
    {
        Person *p = people[i];
        cout << p->country << "\t" << p->lastName << ", " << p->firstName << endl;
        delete p;
    }

    delete[] people;

    cout << "\n\nOrdenação está correta?" << endl;
    
    return 0;
}

Person** readInput(const string path, const int size){
    ifstream file(path);
    
    if(!file.is_open())
    {
        cout << "Não foi possível abrir o arquivo: " << path << endl;
        return nullptr;
    }
    
    int max;
    file >> max;

    if(size > max)
    {
        cout << "Não foi possível ler " << size << " linhas do arquivo de entrada. Número máximo de linhas é " << max << endl;
        return nullptr;
    }
    
    Person** people = new Person*[size];
    
    string line;
    for(int i = 0; i < size; ++i)
    {
        getline(file, line);
        
        std::istringstream buffer( line );

        string firstName, lastName, country;
        getline(buffer, firstName, ',');
        getline(buffer, lastName, ',');
        getline(buffer, country, ',');

        Person* p = new Person(firstName, lastName, country);
        people[i] = p;
    }
    
    file.close();
    
    return people;
}

int compare(Person* p1, Person* p2)
{
    return -1;
}

void sort(Person** people, int size)
{
    for(int i = 1; i < size; ++i)
    {
        Person* p = people[i];
        int j = i-1;
        while( j >= 0 && compare(p, people[j]) == -1 )
        {
            people[j+1] = people[j];
            --j;
        }
        people[j+1] = p;
    }
}
