#ifndef BRIDGE_H
#define BRIDGE_H

#include <memory>

// Implementador (Implementor)
class IImplementacaoAnalise {
public:
    virtual ~IImplementacaoAnalise() = default;
    virtual double analisarConsumo(const std::vector<double>& dados) = 0;
    virtual std::string getTipoImplementacao() = 0;
};

// Implementações concretas
class ImplementacaoML : public IImplementacaoAnalise {
public:
    double analisarConsumo(const std::vector<double>& dados) override {
        // Implementação com Machine Learning
        return 0.0; // simplificado
    }
    
    std::string getTipoImplementacao() override { return "ML"; }
};

class ImplementacaoEstatistica : public IImplementacaoAnalise {
public:
    double analisarConsumo(const std::vector<double>& dados) override {
        // Implementação estatística
        return 0.0; // simplificado
    }
    
    std::string getTipoImplementacao() override { return "Estatistica"; }
};

// Abstração (Abstraction)
class IAnaliseMonitoramento {
protected:
    std::unique_ptr<IImplementacaoAnalise> implementador;
    
public:
    IAnaliseMonitoramento(std::unique_ptr<IImplementacaoAnalise> impl)
        : implementador(std::move(impl)) {}
    
    virtual ~IAnaliseMonitoramento() = default;
    virtual double executarAnalise(const std::vector<double>& dados) = 0;
    
    // PADRÃO BRIDGE IMPLEMENTADO AQUI:
    // Separação entre abstração (interface) e implementação (algoritmos)
};

// Abstrações refinadas
class AnaliseDetecaoVazamento : public IAnaliseMonitoramento {
public:
    AnaliseDetecaoVazamento(std::unique_ptr<IImplementacaoAnalise> impl)
        : IAnaliseMonitoramento(std::move(impl)) {}
    
    double executarAnalise(const std::vector<double>& dados) override {
        return implementador->analisarConsumo(dados);
    }
};

class AnalisePrevisaoDemanda : public IAnaliseMonitoramento {
public:
    AnalisePrevisaoDemanda(std::unique_ptr<IImplementacaoAnalise> impl)
        : IAnaliseMonitoramento(std::move(impl)) {}
    
    double executarAnalise(const std::vector<double>& dados) override {
        return implementador->analisarConsumo(dados);
    }
};

#endif
