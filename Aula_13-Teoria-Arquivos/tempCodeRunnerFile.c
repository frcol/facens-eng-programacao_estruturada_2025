  if ((fptr = fopen("matriz.bin", "ab")) == NULL)
    printf("\nErro");
  else
    fwrite(mat, sizeof(int), 10, fptr);

  fclose(fptr); // fora do else = wb, ab, rb+