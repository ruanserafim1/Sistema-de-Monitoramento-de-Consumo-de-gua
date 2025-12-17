#include "ModuloMonitoramento.h"
#include "Bridge.h"
#include "Observer.h"
#include "Decorator.h"
#include <vector>

class ModuloMonitoramento : public IObserver {
private:
    std::unique_ptr<EventDispatcher> eventDispatcher;
    
public:
    ModuloMonitoramento() {
        eventDispatcher = std::make_unique<EventDispatcher>();
    }
    
    void coletarDadosHidrometro(const std::string& hidrometroId) {
        // Coleta dados
        std::vector<double> dados = {10.5, 12.3, 11.8};
        
        // 2. PADRÃO BRIDGE USADO AQUI:
        // Análise com implementação flexível
        std::unique_ptr<IAnaliseMonitoramento> analise;
        
        if (hidrometroId.find("industrial") != std::string::npos) {
            analise = std::make_unique<AnaliseDetecaoVazamento>(
                std::make_unique<ImplementacaoML>()
            );
        } else {
            analise = std::make_unique<AnaliseDetecaoVazamento>(
                std::make_unique<ImplementacaoEstatistica>()
            );
        }
        
        double resultado = analise->executarAnalise(dados);
        
        // 3. PADRÃO OBSERVADOR USADO AQUI:
        // Notifica eventos de consumo
        ConsumoEvent evento{hidrometroId, resultado, "2025-12-10 10:30:00"};
        eventDispatcher->notify("consumo_anormal", &evento);
        
        // 6. PADRÃO DECORATOR USADO AQUI:
        // Processamento em cadeia de decoradores
        auto dadosBasicos = std::make_unique<DadosConsumoBasico>(resultado, "2025-12-10");
        auto dadosValidados = std::make_unique<DecoradorValidacao>(std::move(dadosBasicos));
        auto dadosNormalizados = std::make_unique<DecoradorNormalizacao>(std::move(dadosValidados));
        
        std::cout << dadosNormalizados->getInformacoes() << std::endl;
    }
    
    void update(const std::string& eventType, const void* eventData) override {
        // Implementação do Observer
    }
};
