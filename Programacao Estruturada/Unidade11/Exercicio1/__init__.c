// fopen: Abre um arquivo em um modo específico (leitura, gravação, etc.).
// Exemplo: FILE* file = fopen("arquivo.txt", "r");

// fclose: Fecha um arquivo previamente aberto.
// Exemplo: fclose(file);

// fprintf: Escreve dados formatados em um arquivo.
// Exemplo: fprintf(file, "Valor: %d\n", valor);

// fscanf: Lê dados formatados de um arquivo.
// Exemplo: fscanf(file, "%d", &valor);

// fgets: Lê uma linha de texto de um arquivo.
// Exemplo: fgets(buffer, sizeof(buffer), file);

// fputs: Escreve uma linha de texto em um arquivo.
// Exemplo: fputs("Olá, mundo!", file);

// fseek: Define a posição de leitura/gravação em um arquivo.
// Exemplo: fseek(file, offset, SEEK_SET);

// ftell: Retorna a posição atual de leitura/gravação em um arquivo.
// Exemplo: long position = ftell(file);

// rewind: Retorna o ponteiro de arquivo para o início.
// Exemplo: rewind(file);

// feof: Verifica se o final do arquivo foi atingido.
// Exemplo: if (feof(file)) { /* código */ }

// ferror: Verifica se ocorreu algum erro na operação de arquivo.
// Exemplo: if (ferror(file)) { /* código */ }