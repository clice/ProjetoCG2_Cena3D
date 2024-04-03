# Computação Gráfica

**Equipe:** 
 - Alexandre Marques Cabral
 - Clice Bezerra Brito Romão

## Construção de "Renderização de uma Cena 3D"

### Instruções para execução do projeto

Com o OpenGL instalado, é possível utilizar tanto o Code::Blocks como o WSL (Windows Subsystem for Linux) instalado no Windows para a compilação do projeto.

#### 1. Code::Blocks

É necessário primeiramente fazer algumas alterções no compilador do programa para que seja possível compilar o OpenGL. Fazendo as alterações corretamente, a execução do programa ocorre como outros projetos usando o Codë::Blocks são executados e testados.

#### 2. WSL (Windows Subsystem for Linux)

Para a utilização do WSL, podesse compilar o projeto utilizando o comando:
```bash
g++ main.c funcoes.c cena_1.c cena_2.c -o main -lglut -lGLU -lGL
```

Para rodar o projeto, utilizasse o comando:
```bash
./main
```

OBS: Lembrando que esses comandos devem ser executados dentro da pasta do projeto.

Também é possível utilizar o Code::Blocks para a compilar e testar o projeto, porém configurações são necessárias para compilação e a utilização do OpenGL.

### Instruções para uso do programa

É necessário escolher visualizar umas das duas opções de cenas disponíveis no "menu". O programa somente executa uma cena por vez, sendo a opção 1 da cena com os três objetos (bule, bola e toro) e a opção 2 da cena com os quatro bules rotacionando. Quando uma cena é selecionada ela abre e ao fechar a tela o programa fecha, então para abrir outra cena tem que executar novamente o programa.