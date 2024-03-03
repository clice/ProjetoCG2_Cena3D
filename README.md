# Computa��o Gr�fica

**Equipe:** Alexandre Marques Cabral e Clice Bezerra Brito Rom�o

## Constru��o de "Renderiza��o de uma Cena 3D"

### Instru��es para execu��o do projeto

Com o OpenGL instalado, � poss�vel utilizar tanto o Code::Blocks como o WSL (Windows Subsystem for Linux) instalado no Windows para a compila��o do projeto.

#### 1. Code::Blocks

� necess�rio primeiramente fazer algumas alter��es no compilador do programa para que seja poss�vel compilar o OpenGL. Fazendo as altera��es corretamente, a execu��o do programa ocorre como outros projetos usando o Cod�::Blocks s�o executados e testados.

#### 2. WSL (Windows Subsystem for Linux)

Para a utiliza��o do WSL, podesse compilar o projeto utilizando o comando:
```bash
g++ main.c -o main -lglut -lGLU -lGL
```

Para rodar o projeto, utilizasse o comando:
```bash
./main
```

OBS: Lembrando que esses comandos devem ser executados dentro da pasta do projeto.

Tamb�m � poss�vel utilizar o Code::Blocks para a compilar e testar o projeto, por�m configura��es s�o necess�rias para compila��o e a utiliza��o do OpenGL.

### Instru��es para uso do programa
