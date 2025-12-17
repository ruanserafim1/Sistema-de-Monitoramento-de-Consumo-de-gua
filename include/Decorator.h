#ifndef DECORATOR_H
#define DECORATOR_H

#include <memory>

// Componente base
class IDadosConsumo {
public:
    virtual ~IDadosConsumo() = default;
    virtual double getValor() const = 0;
    virtual std::string getInformacoes() const = 0;
};

// Componente concreto
class DadosConsumoBasico : public IDadosConsumo {
private:
    double valor;
    std::string timestamp;
    
public:
    DadosConsumoBasico(double v, const std::string& ts) : valor(v), timestamp(ts) {}
    
    double getValor() const override { return valor; }
    
    std::string getInformacoes() const override {
        return "Valor: " + std::to_string(valor) + " | Timestamp: " + timestamp;
    }
};

// Decorator base
class DadosConsumoDecorator : public IDadosConsumo {
protected:
    std::unique_ptr<IDadosConsumo> dadosDecorados;
    
public:
    DadosConsumoDecorator(std::unique_ptr<IDadosConsumo> dados)
        : dadosDecorados(std::move(dados)) {}
    
    double getValor() const override {
        return dadosDecorados->getValor();
    }
    
    std::string getInformacoes() const override {
        return dadosDecorados->getInformacoes();
    }
};

// Decorators concretos
class DecoradorValidacao : public DadosConsumoDecorator {
public:
    DecoradorValidacao(std::unique_ptr<IDadosConsumo> dados)
        : DadosConsumoDecorator(std::move(dados)) {}
    
    std::string getInformacoes() const override {
        std::string base = DadosConsumoDecorator::getInformacoes();
        bool valido = validar();
        return base + " | Valido: " + (valido ? "SIM" : "NAO");
    }
    
private:
    bool validar() const {
        return dadosDecorados->getValor() >= 0;
    }
};

class DecoradorNormalizacao : public DadosConsumoDecorator {
public:
    DecoradorNormalizacao(std::unique_ptr<IDadosConsumo> dados)
        : DadosConsumoDecorator(std::move(dados)) {}
    
    double getValor() const override {
        return converterParaMetrosCubicos(dadosDecorados->getValor());
    }
    
    std::string getInformacoes() const override {
        std::string base = DadosConsumoDecorator::getInformacoes();
        return base + " | Normalizado: " + std::to_string(getValor()) + " m³";
    }
    
private:
    double converterParaMetrosCubicos(double valor) const {
        return valor; // Simplificação
    }
    
};

#endif
