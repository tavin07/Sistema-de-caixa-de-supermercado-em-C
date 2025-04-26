# Sistema de Caixa de Supermercado em C

Este projeto é um sistema de caixa simples desenvolvido em C, ideal para operações básicas de supermercado como cadastro de produtos, registro de compras e cálculo de troco.

## Funcionalidades

- Login com autenticação de usuário e senha
- Cadastro de produtos com nome e preço
- Listagem de produtos cadastrados
- Processamento de compras:
  - Seleção de produtos por código
  - Cálculo automático do valor total
  - Recebimento de pagamento e cálculo de troco
- Remoção de produtos do cadastro
- Interface via terminal

## Como executar

```bash
git clone https://github.com/tavin07/SIstema-de-caixa-de-supermercado-em-C.git
cd SIstema-de-caixa-de-supermercado-em-C
gcc -o sistema_caixa main.c
./sistema_caixa
```

## Importante: Desenvolvido para sistemas Linux/Unix

No Windows, substitua system("clear") por system("cls") e adapte unistd.h.

