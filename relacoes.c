#include <stdio.h>
#include <stdlib.h>

int funcao(n)
{
   int funcao = 0;

    if(((n&1)==1 && (n&2)!=2 && (n&4)!=4 && (n&8)!=8) || ((n&1)!=1 && (n&2)==2 && (n&4)!=4 && (n&8)!=8) || ((n&1)!=1 && (n&2)!=2 && (n&4)==4 && (n&8)!=8) || ((n&1)!=1 && (n&2)!=2 && (n&4)!=4 && (n&8)==8))
        if(((n&16)==16 && (n&32)!=32 && (n&64)!=64 && (n&128)!=128) || ((n&16)!=16 && (n&32)==32 && (n&64)!=64 && (n&128)!=128) || ((n&16)!=16 && (n&32)!=32 && (n&64)==64 && (n&128)!=128) || ((n&16)!=16 && (n&32)!=32 && (n&64)!=64 && (n&128)==128))
            if(((n&256)==256 && (n&512)!=512 && (n&1024)!=1024 && (n&2048)!=2048) || ((n&256)!=256 && (n&512)==512 && (n&1024)!=1024 && (n&2048)!=2048) || ((n&256)!=256 && (n&512)!=512 && (n&1024)==1024 && (n&2048)!=2048) || ((n&256)!=256 && (n&512)!=512 && (n&1024)!=1024 && (n&2048)==2048))
                if(((n&4096)==4096 && (n&8192)!=8192 && (n&16384)!=16384 && (n&32768)!=32768) || ((n&4096)!=4096 && (n&8192)==8192 && (n&16384)!=16384 && (n&32768)!=32768) || ((n&4096)!=4096 && (n&8192)!=8192 && (n&16384)==16384 && (n&32768)!=32768) || ((n&4096)!=4096 && (n&8192)!=8192 && (n&16384)!=16384 && (n&32768)==32768))
                    funcao = 1;

    return funcao;
}

int aRb (a,b,n)
{
    int d ;
    d = 1 << (((a-1)*4)+(b-1));
    if ((n&d) == d)
        return 1;
    else
        return 0;
}

int transitiva (n)
{
    int tra=1, a, b, c;
    for(a=1;a<=4;a++)
        for(b=1;b<=4;b++)
            for(c=1;c<=4;c++)
                if (aRb(a,b,n) == 1  && aRb(b,c,n) == 1)
                    if (aRb(a,c,n) == 0)
                        tra=0;
    return tra;
}

int simetrica (n)
{
  int simetrica = 1;

  if((n&16384) == 16384 && (n&2048) != 2048 || (n&16384) != 16384 && (n&2048) == 2048 )
    simetrica = 0;
  if((n&8192) == 8192 && (n&128) != 128 || (n&8192) != 8192 && (n&128) == 128)
    simetrica = 0;
  if((n&4096) == 4096 && (n&8) != 8 || (n&4096) != 4096 && (n&8)  == 8)
    simetrica = 0;
  if((n&512) == 512 && (n&64) != 64 || (n&512) != 512 && (n&64) == 64)
    simetrica = 0;
  if((n&256) == 256 && (n&4) != 4 || (n&256) != 256 && (n&4) == 4)
    simetrica = 0;
  if((n&16) == 16 && (n&2) != 2  || (n&16) != 16 && (n&2) == 2)
    simetrica = 0;

  return simetrica;
}

int reflexiva (n)
{
    int reflex = 1;
    if(((n&16384) == 16384 || (n&8192) == 8192 || (n&4096) == 4096 || (n&2048) == 2048 || (n&128) == 128 || (n&8) == 8) && (n&32768) != 32768)
        reflex = 0;
    if(((n&2048) == 2048 || (n&512) == 512 || (n&256) == 256 || (n&16384) == 16384 || (n&64) == 64 || (n&4) == 4) && (n&1024) != 1024)
        reflex = 0;
    if(((n&128) == 128 || (n&64) == 64 || (n&16) == 16 || (n&8192) == 8192  || (n&512) == 512 || (n&2) == 2) && (n&32) != 32)
        reflex = 0;
    if(((n&8) == 8 || (n&4) == 4 || (n&2) == 2 || (n&4096) == 4096 || (n&256) == 256 || (n&16) == 16) && (n&1) !=1)
        reflex = 0;
    return reflex;
}


int main()
{
    FILE *arquivo;
    int i;

    arquivo = fopen("relacoes.txt","w");

    for(i=65535 ; i>0 ; i--)
    {
        fprintf(arquivo, "{ ");
        if((i&32768) == 32768)
        {
            fprintf(arquivo, "(1,1) ");
        }
        if((i&16384) == 16384)
        {
            fprintf(arquivo, "(1,2) ");
        }
        if((i&8192) == 8192)
        {
            fprintf(arquivo, "(1,3) ");
        }
        if((i&4096) == 4096)
        {
            fprintf(arquivo, "(1,4) ");
        }
        if((i&2048) == 2048)
        {
            fprintf(arquivo, "(2,1) ");
        }
        if((i&1024) == 1024)
        {
            fprintf(arquivo, "(2,2) ");
        }
        if((i&512) == 512)
        {
            fprintf(arquivo, "(2,3) ");
        }
        if((i&256) == 256)
        {
            fprintf(arquivo, "(2,4) ");
        }
        if((i&128) == 128)
        {
            fprintf(arquivo, "(3,1) ");
        }
        if((i&64) == 64)
        {
            fprintf(arquivo, "(3,2) ");
        }
        if((i&32) == 32)
        {
            fprintf(arquivo, "(3,3) ");
        }
        if((i&16) == 16)
        {
            fprintf(arquivo, "(3,4) ");
        }
        if((i&8) == 8)
        {
            fprintf(arquivo, "(4,1) ");
        }
        if((i&4) == 4)
        {
            fprintf(arquivo, "(4,2) ");
        }
        if((i&2) == 2)
        {
            fprintf(arquivo, "(4,3) ");
        }
        if((i&1) == 1)
        {
            fprintf(arquivo, "(4,4) ");
        }

        fprintf(arquivo, "} ");

        if(reflexiva(i) == 0)
            fprintf(arquivo, "I ");
        if(reflexiva(i) == 1)
            fprintf(arquivo, "R ");
        if(simetrica(i) == 1)
            fprintf(arquivo, "S ");
        if(transitiva(i) == 1)
            fprintf(arquivo, "T ");
        if(i>4096)
            if(funcao(i) == 1)
                fprintf(arquivo, "F ");

        fprintf(arquivo, "\n");

    }

    fclose(arquivo);
}
