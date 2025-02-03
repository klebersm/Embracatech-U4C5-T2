# Embarcatech U4C5-T2

Este código implementa a Tarefa 2 da atividade da Unidade 4, capítulo 5.
Neste exercício, o botão A, quando pressionado, liga 3 leds, verde, vermelho e amarelo, ligados às saídas 11, 12 e 13 e, a cada 3 segundos, desliga os leds sequencialmente. Durante esse ciclo, se o botão a for pressionado, não deve interferir no ciclo que está em execução.

## GPIO 🕹️

| LED/Botão    | Funcionalidade     | GPIO |
| ------------ | ------------------ | ---- |
| Botão A      | Inicializa o ciclo | 5    |
| Led Verde    |                    | 11   |
| Led Amarelo  |                    | 12   |
| Led Vermelho |                    | 13   |

## Hardware 🛠️

- Microcontrolador RP2040 (Raspberry Pi Pico).
- Botão tipo Switch.
- Display NeoPixel RGB 5x5.

## Software 💻

- **SDK do Raspberry Pi Pico:** O SDK (Software Development Kit) do Pico, que inclui as bibliotecas e ferramentas necessárias para desenvolver e compilar o código. [Instruções de instalação](https://www.raspberrypi.com/documentation/pico/getting-started/)
- **CMake:** Um sistema de construção multiplataforma usado para gerar os arquivos de construção do projeto.
- **Compilador C/C++:** Um compilador C/C++ como o GCC (GNU Compiler Collection).
- **Git:** (Opcional) Para clonar o repositório do projeto.

### O código está dividido em vários arquivos para melhor organização:

- **`U4C5-T2.C`**: Código com a função de loop principal: lê as teclas e chama as funções de animação.
- **`CMakeLists.txt`:** Define a estrutura do projeto para o CMake.
- **`diagram.json`:** Diagramas de conexões.
  |

## Como Compilar e Executar ⚙️

1. **Instale o SDK do Raspberry Pi Pico:** Siga as instruções no site oficial do Raspberry Pi.
2. **Clone este repositório:** `git clone git@github.com:klebersm/embarcatech-U4C5-T2.git`
3. **Navegue até o diretório do projeto:** `cd Embarcatech-U4C4`
4. **Compile o projeto:** `cmake -B build && cmake --build build`
5. **Copie para o Pico:** Copie o arquivo `U4C5-T2.uf2` da pasta `build` (gerada após a compilação) para o Raspberry Pi Pico. O programa iniciará automaticamente.

## Tratamento do botão - Interrupção e Alarme ⏱️

O botão A foi inicializado como entrada em PULL UP e é monitorado por interrupção com uma função para o tratamento desta interrupção. À medida que ocorre uma interrupção, a função de tratamento verifica qual o tipo de evento. Se o evento foi de FALL EDGE (borda de descida), significa que o botão foi pressionado e um alarme é gerado para ser disparado em 100ms (Tempo configurado para debounce). Se qualquer outro evento acontecer no mesmo botão, esse alarme é cancelado. Sendo assim, o alarme só é realmente disparado se o botão for pressionado e ficar 100ms sem sofrer qualquer alteração.

Se a função do alarme é chamada, ela liga todos os leds e inicia o ciclo de desligamento, setando um timer com callback. Durante a execução deste ciclo, a finção de interrupção do botão deixa de tratar os alarmes, impedindo o reinício do ciclo antes do mesmo ser finalizado.

## 📞 Contato

- 👤 **Autor**: Kleber Marçal

- 📧 **E-mail**:kleber.sm@gmail.com

---
