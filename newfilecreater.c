#include <stdio.h>

int main()
{
     int i, j = 0;
     FILE *fpa;
     fpa = fopen("monday.txt", "w");
     for (i = 0; i < 14; i++)
     {
          fprintf(fpa, "%d\n", j);
     }
     fclose(fpa);
     FILE *fpb;
     fpb = fopen("tuesday.txt", "w");
     for (i = 0; i < 14; i++)
     {
          fprintf(fpb, "%d\n", j);
     }
     fclose(fpb);
     FILE *fpc;
     fpc = fopen("wednesday.txt", "w");
     for (i = 0; i < 14; i++)
     {
          fprintf(fpc, "%d\n", j);
     }
     fclose(fpc);
     FILE *fpd;
     fpd = fopen("thursday.txt", "w");
     for (i = 0; i < 14; i++)
     {
          fprintf(fpd, "%d\n", j);
     }
     fclose(fpd);
     FILE *fpe;
     fpe = fopen("friday.txt", "w");
     for (i = 0; i < 14; i++)
     {
          fprintf(fpe, "%d\n", j);
     }
     fclose(fpe);
     FILE *fpf;
     fpf = fopen("saturday.txt", "w");
     for (i = 0; i < 14; i++)
     {
          fprintf(fpf, "%d\n", j);
     }
     fclose(fpf);

     FILE *fpz;
     fpz = fopen("monday1.txt", "w");
     for (i = 0; i < 14; i++)
     {
          fprintf(fpz, "Empty\n");
     }
     fclose(fpz);
     FILE *fpy;
     fpy = fopen("tuesday1.txt", "w");
     for (i = 0; i < 14; i++)
     {
          fprintf(fpy, "Empty\n");
     }
     fclose(fpy);
     FILE *fpx;
     fpx = fopen("wednesday1.txt", "w");
     for (i = 0; i < 14; i++)
     {
          fprintf(fpx, "Empty\n");
     }
     fclose(fpx);
     FILE *fpv;
     fpv = fopen("thursday1.txt", "w");
     for (i = 0; i < 14; i++)
     {
          fprintf(fpv, "Empty\n");
     }
     fclose(fpv);
     FILE *fpu;
     fpu = fopen("friday1.txt", "w");
     for (i = 0; i < 14; i++)
     {
          fprintf(fpu, "Empty\n");
     }
     fclose(fpu);
     FILE *fpw;
     fpw = fopen("saturday1.txt", "w");
     for (i = 0; i < 14; i++)
     {
          fprintf(fpw, "Empty\n");
     }
     fclose(fpw);
     return 0;
}