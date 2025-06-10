#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Deque.h"
#include <string>

TEST_CASE("Deque - Tamanho inicial deve ser zero") {
    Deque<int> deque(5);
    CHECK(deque.tamanho() == 0);
    CHECK(deque.vazia());
    CHECK_FALSE(deque.cheia());
}

TEST_CASE("Deque - Empurrar elementos atrás até a capacidade máxima (back)") {
    Deque<int> deque(3);
    deque.empurrar_atras(10); // frente { 10 } trás
    deque.empurrar_atras(20); // frente { 10 20 } trás
    deque.empurrar_atras(30); // frente { 10 20 30 } trás
    CHECK(deque.tamanho() == 3);
    CHECK(deque.cheia());
    CHECK(deque.daFrente() == 10);
    CHECK(deque.deTras() == 30);
}

TEST_CASE("Deque - Empurrar elementos atrás além da capacidade deve lançar exceção") {
    Deque<int> deque(2);
    deque.empurrar_atras(1);
    deque.empurrar_atras(2);
    CHECK_THROWS_AS(deque.empurrar_atras(3), std::overflow_error);
}

TEST_CASE("Deque - Empurrar elementos na frente até a capacidade máxima") {
    Deque<int> deque(3);
    deque.empurrar_frente(10); // {10}
    deque.empurrar_frente(20); // {20, 10}
    deque.empurrar_frente(30); // {30, 20, 10}
    CHECK(deque.tamanho() == 3);
    CHECK(deque.cheia());
    CHECK(deque.daFrente() == 30);
    CHECK(deque.deTras() == 10);
}

TEST_CASE("Deque - Empurrar elementos na frente além da capacidade deve lançar exceção") {
    Deque<int> deque(2);
    deque.empurrar_frente(1);
    deque.empurrar_frente(2);
    CHECK_THROWS_AS(deque.empurrar_frente(3), std::overflow_error);
}

TEST_CASE("Deque - Remover de trás e da frente na ordem correta") {
    Deque<int> deque(4);
    deque.empurrar_atras(5);    // {5}
    deque.empurrar_frente(10);  // {10, 5}
    deque.empurrar_atras(15);    // {10, 5, 15}
    deque.empurrar_frente(20);  // {20, 10, 5, 15}
    CHECK(deque.tamanho() == 4);

    // Ordem de remoção: front: 20, front: 10, back: 15, back: 5
    CHECK(deque.remover_frente() == 20);
    CHECK(deque.tamanho() == 3);
    CHECK(deque.remover_frente() == 10);
    CHECK(deque.tamanho() == 2);
    CHECK(deque.remover_atras() == 15);
    CHECK(deque.tamanho() == 1);
    CHECK(deque.remover_atras() == 5);
    CHECK(deque.vazia());
}

TEST_CASE("Deque - Remover de deque vazio deve lançar exceção") {
    Deque<int> deque(2);
    CHECK_THROWS_AS(deque.remover_frente(), std::underflow_error);
    CHECK_THROWS_AS(deque.remover_atras(), std::underflow_error);
}

TEST_CASE("Deque - Acessar frente e tras de deque vazio deve lançar exceção") {
    Deque<std::string> deque(2);
    CHECK_THROWS_AS(deque.daFrente(), std::underflow_error);
    CHECK_THROWS_AS(deque.deTras(), std::underflow_error);
}

TEST_CASE("Deque - Comportamento circular ao empurrar e remover (back e front)") {
    Deque<int> deque(3);
    deque.empurrar_atras(1);   // {1}
    deque.empurrar_atras(2);   // {1, 2}
    deque.empurrar_atras(3);   // {1, 2, 3}
    CHECK(deque.cheia());

    // Remove um do início e adiciona no fim para forçar wrap-around
    CHECK(deque.remover_frente() == 1); // {2, 3}
    deque.empurrar_atras(4);              // {2, 3, 4}

    CHECK(deque.daFrente() == 2);
    CHECK(deque.deTras() == 4);

    // Remove do fim e empurra no início para wrap-around inverso
    CHECK(deque.remover_atras() == 4);    // {2, 3}
    deque.empurrar_frente(5);           // {5, 2, 3}

    CHECK(deque.daFrente() == 5);
    CHECK(deque.deTras() == 3);

    // Esvaziar completamente
    CHECK(deque.remover_frente() == 5);
    CHECK(deque.remover_frente() == 2);
    CHECK(deque.remover_frente() == 3);
    CHECK(deque.vazia());
}

TEST_CASE("Deque - Impressão do deque deve refletir a ordem dos elementos") {
    Deque<int> deque(5);
    deque.empurrar_atras(100);     // {100}
    deque.empurrar_atras(200);     // {100, 200}
    deque.empurrar_frente(50);   // {50, 100, 200}
    deque.empurrar_atras(300);     // {50, 100, 200, 300}
    CHECK(deque.imprimir() == "{ 50 100 200 300 }");

    deque.remover_frente();      // {100, 200, 300}
    deque.empurrar_frente(25);   // {25, 100, 200, 300}
    CHECK(deque.imprimir() == "{ 25 100 200 300 }");
}

TEST_CASE("Deque - Teste com diferentes tipos (int, double, string)") {
    Deque<double> dequeD(3);
    dequeD.empurrar_atras(3.14);
    dequeD.empurrar_frente(2.71);
    CHECK(dequeD.daFrente() == doctest::Approx(2.71));
    CHECK(dequeD.deTras() == doctest::Approx(3.14));

    Deque<std::string> dequeS(3);
    dequeS.empurrar_atras("foo");
    dequeS.empurrar_frente("bar");
    CHECK(dequeS.daFrente() == "bar");
    CHECK(dequeS.deTras() == "foo");
}