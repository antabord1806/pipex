<h1 align="center">Pipex</h1>

<p align="center">
  <em>Projeto da 42 que replica o comportamento do pipe <code>|</code> do shell Unix.</em><br>
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c"/>
  <img src="https://img.shields.io/badge/School-42-black?style=for-the-badge"/>
  <img src="https://img.shields.io/badge/Unix-System-orange?style=for-the-badge&logo=linux"/>
</p>
</p>

<hr>

<h2>Descrição</h2>

<p>
  O <strong>Pipex</strong> é um projeto em C que visa reproduzir o comportamento do <em>pipe</em> (<code>|</code>) no shell Unix, permitindo a comunicação entre dois comandos através de <em>file descriptors</em>.<br>
  A ideia é recriar este comportamento:
</p>

<pre><code>&lt; infile cmd1 | cmd2 &gt; outfile
</code></pre>

<p>
  Ou seja, o programa deve ler de um ficheiro, executar dois comandos em cadeia e escrever o resultado num ficheiro de saída.
</p>

<hr>

<h2>Compilação</h2>

<pre><code>make        # Compila o executável pipex
make clean  # Remove arquivos .o
make fclean # Remove objetos e executável
make re     # Recompila tudo do zero
</code></pre>

<hr>

<h2>Execução</h2>

<pre><code>./pipex infile "ls -l" "wc -l" outfile
</code></pre>

<p>Este comando deve replicar o comportamento:</p>

<pre><code>&lt; infile ls -l | wc -l &gt; outfile
</code></pre>

<h3>Argumentos:</h3>
<ul>
  <li><strong>infile</strong> — ficheiro de entrada</li>
  <li><strong>cmd1</strong> — primeiro comando a executar</li>
  <li><strong>cmd2</strong> — segundo comando, que recebe a saída do primeiro</li>
  <li><strong>outfile</strong> — ficheiro de saída</li>
</ul>

<hr>

<h2>Conceitos-Chave</h2>

<ul>
  <li><code>fork()</code> → Criação de um novo processo (filho), cópia exata do pai que executa em paralelo.</li>
  <li><code>pipe()</code> → Cria um canal de comunicação unidirecional (read -> write).</li>
  <li><code>dup2()</code> → Redireciona file descriptors, simulando <code>&lt;</code> e <code>&gt;</code>.</li>
  <li><code>execve()</code> → Substitui o processo atual por um novo programa.</li>
  <li><code>waitpid()</code> → Garante que o processo pai espera pelos filhos terminarem.</li>
  <li><strong>File Descriptors (FDs)</strong> → Referências inteiras a recursos de I/O (<code>stdin=0</code>, <code>stdout=1</code>, <code>stderr=2</code>).</li>
</ul>

<hr>

<h2>Maiores Desafios</h2>

<p>
  O ponto mais complexo foi <strong>entender profundamente os file descriptors (FDs)</strong> e como o sistema Unix os utiliza.
</p>

<p>
  Cada processo possui a sua própria tabela de descritores. Quando criamos um <em>pipe</em>, o kernel fornece dois descritores:
</p>

<ul>
  <li><code>fd[0]</code>: extremidade de leitura</li>
  <li><code>fd[1]</code>: extremidade de escrita</li>
</ul>

<p>
  Com o <code>dup2(fd[x], STDIN_FILENO)</code> ou <code>dup2(fd[x], STDOUT_FILENO)</code>, redirecionamos as entradas e saídas de um processo.
  O desafio está em compreender que <strong>duplicar um FD não copia os dados, apenas aponta para o mesmo recurso</strong> — e isso pode gerar confusão se não forem fechadas as extremidades corretas em cada processo.
</p>

<h3>A solução:</h3>
<p>
  Esquematizar o que acontece com os fds duante o processo sabendo assim quando eq eles deixam de ser utilzados
</p>

<table align="center">
  <tr>
    <th>Infile</th>
    <th>StdIn/StdOut - default</th>
    <th>fd_In</th>
    <th>fd_Out</th>
    <th>pipe (read/write)</th>
  </tr>

  <tr>
    <td>cmd1</td>
    <td>cmd2</td>
    <td>cmd3</td>
  </tr>

  <tr>
    <td>0/1</td>
    <td>0/1</td>
    <td>0/1</td>
  </tr>

  <tr>
    <td>infile_fd</td>
    <td>4</td>
    <td>6</td>
  </tr>
</table>
<p>
  <img src="Diagrama sem nome.drawio.svg" alt="Esquema de fds" width="600"/>
  <br>
  <em>Figura 1 — Fluxo de execução e comunicação via pipe</em>
</p>

<hr>

<h2>🧪 Testes</h2>

<h3>Testes básicos:</h3>

<pre><code>./pipex infile "cat" "grep text" outfile
./pipex infile "grep a" "wc -l" outfile
./pipex /dev/null "echo hello" "cat" outfile
</code></pre>

<h3>Comparar com o comportamento real do shell:</h3>

<pre><code>diff &lt;(./pipex infile "cmd1" "cmd2" outfile) &lt;(&lt; infile cmd1 | cmd2 &gt; outfile)
</code></pre>

<hr>

<pre><code>lsof -p &lt;pid&gt;
</code></pre>

<p>
  Dominar estas ferramentas foi essencial para entender o ciclo de vida dos <em>file descriptors</em> e garantir que o programa se comportasse exatamente como o shell.
</p>

<ul>
  <li>Versão <strong>bonus</strong> com múltiplos comandos (pipeline completo).</li>
  <li>Suporte a <em>heredoc</em> (<code>&lt;&lt;</code>).</li>
  <li>Tratamento avançado de erros e mensagens personalizadas.</li>
</ul>

<hr>

