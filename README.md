# Computação Gráfica

**Equipe:** Alexandre Marques Cabral e Clice Bezerra Brito Romão

## Construção de "Renderização de uma Cena 3D"

### Instruções para execução do projeto

Com o OpenGL instalado, é possível utilizar tanto o Code::Blocks como o WSL (Windows Subsystem for Linux) instalado no Windows para a compilação do projeto.

#### 1. Code::Blocks

É necessário primeiramente fazer algumas alterções no compilador do programa para que seja possível compilar o OpenGL. Fazendo as alterações corretamente, a execução do programa ocorre como outros projetos usando o Codë::Blocks são executados e testados.

#### 2. WSL (Windows Subsystem for Linux)

Para a utilização do WSL, podesse compilar o projeto utilizando o comando:
```bash
g++ main.c -o main -lglut -lGLU -lGL
```

Para rodar o projeto, utilizasse o comando:
```bash
./main
```

OBS: Lembrando que esses comandos devem ser executados dentro da pasta do projeto.

Também é possível utilizar o Code::Blocks para a compilar e testar o projeto, porém configurações são necessárias para compilação e a utilização do OpenGL.

### Instruções para uso do programa
