#include "MonitoramentoFacade.h"
#include <iostream>

int main() {
    // 1. PADRÃO FACADE: Interface unificada para todo o sistema
    MonitoramentoFacade::getInstance().inicializarSistema();
    
    // Exemplo de uso da fachada
    MonitoramentoFacade::getInstance().gerarRelatorioConsumo("Zona_Norte", "2025-12");
    MonitoramentoFacade::getInstance().configurarParametrosAlerta("critico", 200.0);
    
    return 0;
}
