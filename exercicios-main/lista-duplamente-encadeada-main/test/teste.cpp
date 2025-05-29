#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "ListaDuplamenteEncadeada.h"

TEST_CASE("Inserir no Início") 
{
    ListaDuplamenteEncadeada lista;
    
    std::string v[] = {"alpha","bravo","charlie","delta","echo","fox","golf","hotel","india","juliet"};
    
    for(auto s : v)
    {
        int tamanhoAntes = lista.tamanho();
        
        auto valorInserido = s;

        CHECK(lista.checarConsistencia() == OK);
                
        bool inseriu = lista.inserirInicio( valorInserido );

        CHECK(inseriu);

        CHECK(lista.checarConsistencia() == OK);
        
        auto primeiroValor = lista.primeiroElemento();

        CHECK(primeiroValor == valorInserido);
        
        int tamanhoDepois = lista.tamanho();

        CHECK(tamanhoDepois == tamanhoAntes+1);
    }
}

TEST_CASE("Inserir no Fim") 
{
    ListaDuplamenteEncadeada lista;
    
    std::string v[] = {"alpha","bravo","charlie","delta","echo","fox","golf","hotel","india","juliet"};
    
    for(auto s : v)
    {
        int tamanhoAntes = lista.tamanho();
        
        auto valorInserido = s;

        CHECK(lista.checarConsistencia() == OK);
                
        bool inseriu = lista.inserirFim( valorInserido );

        CHECK(inseriu);

        CHECK(lista.checarConsistencia() == OK);
        
        auto ultimoValor = lista.ultimoElemento();

        CHECK(ultimoValor == valorInserido);
        
        int tamanhoDepois = lista.tamanho();

        CHECK(tamanhoDepois == tamanhoAntes+1);
    }
}

TEST_CASE("Acessar elemento da i-ésima posição da lista") 
{
    ListaDuplamenteEncadeada lista;
    
    std::string v[] = {"alpha","bravo","charlie","delta","echo","fox","golf","hotel","india","juliet"};
    
    for(auto s : v)
    {
        CHECK( lista.inserirFim( s ) ); 
    }

    int i = 1;
    for(auto s : v)
    {
        CHECK( lista.elementoNaPosicao(i) == s );
        ++i;
    }
}

TEST_CASE("Inserir na i-ésima posição da lista") 
{
    ListaDuplamenteEncadeada lista;
    
    std::string v[] = {"alpha","bravo","charlie","delta","echo","fox","golf","hotel","india","juliet"};
    
    int tamanhoAntes = lista.tamanho();
    bool inseriu = lista.inserir( 1, v[0] );
    
    CHECK(inseriu);
    
    int tamanhoDepois = lista.tamanho();
    
    CHECK(tamanhoAntes+1 == tamanhoDepois);

    auto verificada = lista.checarConsistencia();

    CHECK(verificada == OK);
    
    int i = 1;
    for(auto s : v)
    {
        int tamanhoAntes = lista.tamanho();
        
        std::string valorInserido = s;
        
        int indice = i % 2 == 0 ? 2 : 1;
        
        verificada = lista.checarConsistencia();
        CHECK(verificada == OK);
        
        inseriu = lista.inserir(indice, valorInserido);
        CHECK(inseriu);
        
        auto valorRetornado = lista.elementoNaPosicao(indice);

        CHECK(valorRetornado == valorInserido);
        
        int tamanhoDepois = lista.tamanho();
        CHECK(tamanhoAntes+1 == tamanhoDepois);

        ++i;
    }
}

TEST_CASE("Remover elemento do início")
{
    ListaDuplamenteEncadeada lista;
    
    std::string v[] = {"alpha","bravo","charlie","delta","echo","fox","golf","hotel","india","juliet"};
    
    for(auto s : v)
    {
        auto valorInserido = s;
        lista.inserirInicio( valorInserido );
    }
    
    for(int i = 0; i < 10; ++i)
    {
        auto verificada = lista.checarConsistencia();
        CHECK( verificada == OK );
        
        int tamanhoAntes = lista.tamanho();
        auto valorRemovido = lista.removerInicio();
        int tamanhoDepois = lista.tamanho();
        
        CHECK( tamanhoDepois == tamanhoAntes-1 );
        
        auto valorEsperado = v[9-i];

        CHECK( valorRemovido == valorEsperado );
    }
}

TEST_CASE("Remover elemento do fim")
{
    ListaDuplamenteEncadeada lista;
    
    std::string v[] = {"alpha","bravo","charlie","delta","echo","fox","golf","hotel","india","juliet"};
    
    for(auto s : v)
    {
        auto valorInserido = s;
        lista.inserirFim( valorInserido );
    }
    
    for(int i = 0; i < 10; ++i)
    {
        auto verificada = lista.checarConsistencia();
        CHECK( verificada == OK );
        
        int tamanhoAntes = lista.tamanho();
        auto valorRemovido = lista.removerFim();
        int tamanhoDepois = lista.tamanho();
        
        CHECK( tamanhoDepois == tamanhoAntes-1 );
        
        auto valorEsperado = v[9-i];

        CHECK( valorRemovido == valorEsperado );
    }
}

TEST_CASE("Remover elemento da i-ésima posição da lista")
{
    ListaDuplamenteEncadeada lista;
    
    std::string v[] = {"alpha","bravo","charlie","delta","echo","fox","golf","hotel","india","juliet"};
    
    for(auto s : v)
    {
        auto valorInserido = s;
        lista.inserirInicio( valorInserido );
    }
    
    for(int i = 0; i < 10; ++i)
    {
        auto verificada = lista.checarConsistencia();
        CHECK( verificada == OK );
        
        int tamanhoAntes = lista.tamanho();
        auto valorRemovido = lista.remover(1);
        int tamanhoDepois = lista.tamanho();
        
        CHECK( tamanhoDepois == tamanhoAntes-1 );
        
        auto valorEsperado = v[9-i];

        CHECK( valorRemovido == valorEsperado );
    }
}

TEST_CASE("Buscar elemento na lista")
{
    ListaDuplamenteEncadeada lista;
    
    std::string v[] = {"alpha","bravo","charlie","delta","echo","fox","golf","hotel","india","juliet"};
    
    for(auto s : v)
    {
        auto valorInserido = s;
        lista.inserirFim(valorInserido);
    }
    
    for(int i = 0; i < 10; ++i)
    {
        auto valorBuscado = v[i];
        int indiceRetornado = lista.buscar(valorBuscado);

        CHECK(indiceRetornado == i+1);
        
        auto verificada = lista.checarConsistencia();

        CHECK( verificada == OK );
    }
    
    std::string inexistentes[] = {"0", "50", "100", "200"};
    
    for(int i = 0; i < 4; i++)
    {
        int indiceRetornado = lista.buscar(inexistentes[i]);
        CHECK( indiceRetornado == -1 );
        
        auto verificada = lista.checarConsistencia();
        CHECK( verificada == OK );
    } 
}