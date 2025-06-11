# Projeto---Playlist

## O que o código faz?

O código é um **programa para gerenciar uma playlist de músicas**. Ele permite:

✅ Adicionar músicas à playlist
✅ Listar todas as músicas organizadas em ordem alfabética
✅ Criar uma playlist personalizada com tempo máximo ou por gênero musical
✅ Salvar e carregar as músicas de um arquivo para manter os dados entre execuções

---

## Como funciona?

### 1️⃣ **Estrutura das músicas**

* Cada música tem:

  * Um **nome** (por exemplo, "Bohemian Rhapsody").
  * Um **gênero** (como "Rock", "Pop" etc.).
  * Uma **duração** (em segundos).

---

### 2️⃣ **Funções principais**

O programa é dividido em várias partes chamadas **funções**, que são como “tarefas” específicas. Aqui vão algumas delas:

* **Trocar músicas de lugar**
  Serve para ajudar a organizar as músicas em ordem alfabética.

* **Ordenar a playlist**
  Organiza a lista de músicas para ficar em ordem alfabética pelo nome.

* **Salvar músicas no arquivo**
  Grava todas as músicas em um arquivo chamado "playlist.txt" para que possam ser carregadas depois.

* **Carregar músicas do arquivo**
  Lê o arquivo "playlist.txt" e coloca as músicas na memória para que possam ser usadas novamente.

---

### 3️⃣ **O menu interativo**

Quando o programa é executado, ele mostra um **menu** na tela com as seguintes opções:

1️⃣ **Adicionar música**
👉 Você pode digitar o nome da música, escolher o gênero e informar a duração em minutos. O programa converte isso em segundos e adiciona à playlist.

2️⃣ **Listar músicas**
👉 Mostra todas as músicas na playlist, organizadas em ordem alfabética, com nome, gênero e duração.

3️⃣ **Montar playlist por tempo máximo**
👉 Você escolhe o tempo máximo total (em minutos), e o programa mostra quais músicas cabem dentro desse limite.

4️⃣ **Montar playlist por gênero**
👉 Você escolhe um ou mais gêneros e o programa mostra as músicas que pertencem a esses estilos.

5️⃣ **Sair**
👉 Fecha o programa.

---

### 4️⃣ **Músicas padrão**

Se não houver arquivo salvo, o programa começa com uma lista padrão de 10 músicas de diversos gêneros.

---

## Resumindo

✅ O programa permite criar e gerenciar uma playlist de músicas.
✅ É interativo, ou seja, você escolhe o que quer fazer no menu.
✅ As músicas são salvas para que você não perca os dados.
✅ É organizado em funções para facilitar a manutenção e a legibilidade do código.
