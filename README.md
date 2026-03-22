<h1 align="center">Pipex</h1>

<p align="center">
  <em>42 project that replicates the behavior of the Unix shell <code>|</code> pipe.</em><br>
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c"/>
  <img src="https://img.shields.io/badge/School-42-black?style=for-the-badge"/>
  <img src="https://img.shields.io/badge/Unix-System-orange?style=for-the-badge&logo=linux"/>
</p>

<hr>

<h2>Description</h2>

<p>
  <strong>Pipex</strong> is a C project that aims to reproduce the behavior of the <em>pipe</em> (<code>|</code>) in Unix shell, allowing communication between two commands through <em>file descriptors</em>.<br>
  The idea is to recreate this behavior:
</p>

<pre><code>&lt; infile cmd1 | cmd2 &gt; outfile
</code></pre>

<p>
  In other words, the program should read from a file, execute two chained commands, and write the result to an output file.
</p>

<hr>

<h2>Compilation</h2>

<pre><code>make        # Compiles the pipex executable
make clean  # Removes .o files
make fclean # Removes objects and the executable
make re     # Recompiles everything from scratch
</code></pre>

<hr>

<h2>Execution</h2>

<pre><code>./pipex infile "ls -l" "wc -l" outfile
</code></pre>

<p>This command should replicate the behavior:</p>

<pre><code>&lt; infile ls -l | wc -l &gt; outfile
</code></pre>

<h3>Arguments:</h3>
<ul>
  <li><strong>infile</strong> — input file</li>
  <li><strong>cmd1</strong> — first command to execute</li>
  <li><strong>cmd2</strong> — second command, receives the output of the first</li>
  <li><strong>outfile</strong> — output file</li>
</ul>

<hr>

<h2>Key Concepts</h2>

<ul>
  <li><code>fork()</code> → Creation of a new process (child), a copy of the parent executing in parallel.</li>
  <li><code>pipe()</code> → Creates a communication channel (read -> write).</li>
  <li><code>dup2()</code> → Redirects file descriptors <code>&lt;</code> and <code>&gt;</code>.</li>
  <li><code>execve()</code> → Replaces the current process with a new program.</li>
  <li><code>waitpid()</code> → Ensures that the parent process waits for children to finish.</li>
  <li><strong>File Descriptors (FDs)</strong> → Integer references to I/O resources (<code>stdin=0</code>, <code>stdout=1</code>, <code>stderr=2</code>).</li>
</ul>

<hr>

<h2>Major Challenges</h2>

<p>
  The most complex part was <strong>understanding file descriptors (FDs)</strong> and how the Unix system uses them.
</p>

<p>
  Each process has its own descriptor table. When we create a <em>pipe</em>, the kernel provides two descriptors:
</p>

<ul>
  <li><code>fd[0]</code>: read end</li>
  <li><code>fd[1]</code>: write end</li>
</ul>

<p>
  With <code>dup2(fd[x], STDIN_FILENO)</code> or <code>dup2(fd[x], STDOUT_FILENO)</code>, we redirect the input and output of a process.
  The challenge is to understand that <strong>duplicating an FD does not copy the data, it only points to the same resource</strong> — and this can cause confusion if the correct ends are not closed in each process.
</p>

<h3>The solution:</h3>
<p>
  Draw schematics of what happens to the FDs during the process to know exactly when they stop being used.
</p>

<table align="center">
  <tr>
    <th>Infile</th>
    <th>StdIn/StdOut - default</th>
    <th>fd_In</th>
    <th>fd_out</th>
    <th>pipe (read/write)</th>
  </tr>

  <tr>
    <td>cmd1</td>
    <td>0/1</td>
    <td>infile_fd</td>
    <td>4</td>
    <td>3/4</td>
  </tr>

  <tr>
    <td>cmd2</td>
    <td>0/1</td>
    <td>3</td>
    <td>4</td>
    <td>5/6</td>
  </tr>

  <tr>
    <td>cmd3</td>
    <td>0/1</td>
    <td>6</td>
    <td>outfile_fd</td>
    <td>  </td>
  </tr>
</table>

<hr>

<h2>🧪 Tests</h2>

<h3>Basic tests:</h3>

<pre><code>./pipex infile "cat" "grep text" outfile
./pipex infile "grep a" "wc -l" outfile
./pipex /dev/null "echo hello" "cat" outfile
</code></pre>

<h3>Compare with actual shell behavior:</h3>

<pre><code>diff &lt;(./pipex infile "cmd1" "cmd2" outfile) &lt;(&lt; infile cmd1 | cmd2 &gt; outfile)
</code></pre>

<hr>

<pre><code>lsof -p &lt;pid&gt;
</code></pre>

<p>
  Mastering these tools was essential to understanding the lifecycle of <em>file descriptors</em> and ensuring the program behaves exactly like the shell.
</p>

<ul>
  <li><strong>Bonus</strong> version with multiple commands (full pipeline).</li>
  <li>Support for <em>heredoc</em> (<code>&lt;&lt;</code>).</li>
  <li>Advanced error handling and custom messages.</li>
</ul>

<hr>
