#ifndef FACTORY_METHOD_H
#define FACTORY_METHOD_H

#include <memory>
#include <string>

// Produto abstrato
class IRelatorio {
public:
    virtual ~IRelatorio() = default;
    virtual void gerar() = 0;
    virtual std::string getFormato() = 0;
};

// Factory Method abstrato
class RelatorioFactory {
public:
    virtual ~RelatorioFactory() = default;
    virtual std::unique_ptr<IRelatorio> criarRelatorio() = 0;
    
};

// Fábricas concretas
class RelatorioConsumoFactory : public RelatorioFactory {
public:
    std::unique_ptr<IRelatorio> criarRelatorio() override;
};

class RelatorioFinanceiroFactory : public RelatorioFactory {
public:
    std::unique_ptr<IRelatorio> criarRelatorio() override;
};

// Produtos concretos
class RelatorioConsumo : public IRelatorio {
public:
    void gerar() override {
        // Implementação específica
    }
    
    std::string getFormato() override { return "PDF"; }
};

class RelatorioFinanceiro : public IRelatorio {
public:
    void gerar() override {
        // Implementação específica
    }
    
    std::string getFormato() override { return "Excel"; }
};

#endif
