#include <iostream>
#include "MonitoramentoFacade.h"
#include "FactoryMethod.h"
#include "Singleton.h"

void demonstrarPadroes() {
    std::cout << "=== DEMONSTRAÇÃO DOS 6 PADRÕES DE PROJETO ===\n\n";
    
    // 1. PADRÃO FACADE
    std::cout << "1. FACADE: Interface unificada do sistema\n";
    auto& facade = MonitoramentoFacade::getInstance();
    
    // 2. PADRÃO SINGLETON
    std::cout << "2. SINGLETON: Instância única da fachada\n";
    auto& mesmaInstancia = MonitoramentoFacade::getInstance();
    
    // 3. PADRÃO FACTORY METHOD
    std::cout << "3. FACTORY METHOD: Criação de relatórios\n";
    RelatorioConsumoFactory factoryConsumo;
    auto relatorio = factoryConsumo.criarRelatorio();
    
    // 4. PADRÃO BRIDGE
    std::cout << "4. BRIDGE: Separação abstração/implementação\n";
    auto analiseML = std::make_unique<AnaliseDetecaoVazamento>(
        std::make_unique<ImplementacaoML>()
    );
    
    // 5. PADRÃO DECORATOR
    std::cout << "5. DECORATOR: Enriquecimento progressivo de dados\n";
    auto dados = std::make_unique<DadosConsumoBasico>(150.5, "2025-12-10");
    auto dadosEnriquecidos = std::make_unique<DecoradorNormalizacao>(
        std::make_unique<DecoradorValidacao>(std::move(dados))
    );
    
    // 6. PADRÃO OBSERVADOR
    std::cout << "6. OBSERVADOR: Sistema de eventos assíncrono\n";
    // Implementado nos módulos internos
}

int main() {
    demonstrarPadroes();
    return 0;
}
