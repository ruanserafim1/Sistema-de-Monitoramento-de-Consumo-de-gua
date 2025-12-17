#ifndef MONITORAMENTO_FACADE_H
#define MONITORAMENTO_FACADE_H

#include <string>
#include <memory>
#include "Singleton.h"

// Subsistemas
class ModuloDominio;
class ModuloAutenticacao;
class ModuloServicos;
class ModuloMonitoramento;
class ModuloInfraestrutura;
class ModuloAlertas;

class MonitoramentoFacade : public Singleton<MonitoramentoFacade> {
private:
    std::unique_ptr<ModuloDominio> moduloDominio;
    std::unique_ptr<ModuloAutenticacao> moduloAutenticacao;
    std::unique_ptr<ModuloServicos> moduloServicos;
    std::unique_ptr<ModuloMonitoramento> moduloMonitoramento;
    std::unique_ptr<ModuloInfraestrutura> moduloInfraestrutura;
    std::unique_ptr<ModuloAlertas> moduloAlertas;
    
public:
    void inicializarSistema();
    void gerarRelatorioConsumo(const std::string& regiao, const std::string& periodo);
    void consultarStatusRede();
    void configurarParametrosAlerta(const std::string& tipo, double valor);
    
    // PADRÃO FACADE IMPLEMENTADO AQUI:
    // Esta classe fornece uma interface simplificada para toda a complexidade
    // do sistema, ocultando os subsistemas internos do cliente
};

#endif
