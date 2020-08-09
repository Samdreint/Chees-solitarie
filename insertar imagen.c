#include <alloc.h>
#include <conio.h>
#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
  char Type[2];           /*Tipo de archivo. establecido en "BM".*/
  unsigned long Size;     /*Tamano en BYTES del archivo*/
  unsigned long Reserved;      /*Reservado. establecido en cero*/
  unsigned long OffSet;   /*Desplazamiento hacia datos*/
  unsigned long headsize; /*Tamaño de la cabecera del bitmap. establecido en 40.*/
  unsigned long Width;     /*Anchura en  pixeles.*/
  unsigned long Height;     /* Altura en pixeles.*/
  unsigned int  Planes;    /*Numero de Planos. establecido en 1.*/
  unsigned int  BitsPerPixel;       /*Numero de Bits por pixeles.*/
  unsigned long Compression;   /*Compresion. Usually establecido en 0.*/
  unsigned long SizeImage;  /*Tamano en BYTES del bitmap.*/
  unsigned long XPixelsPreMeter;     /*Pixeles Horizontales por metro.*/
  unsigned long YPixelsPreMeter;     /*Pixeles Verticales por metro.*/
  unsigned long ColorsUsed;   /*Numero de colores utilizados.*/
  unsigned long ColorsImportant;  /*Numero de colores "Importantes".*/
}BMP;
int muestraBMP(int x, int y, char* NomArchivo);
void main()
{
int color;
int gd , gm ;
gd = VGA ; gm = VGAHI;
initgraph(&gd,&gm,"");
muestraBMP(0,0,"C:\Users\samue\OneDrive\Imágenes\30b6641b305e4d4f03730bce267631e2.png"); /* Ingresa el nombre y direccion del archivo aqui */
getch();
closegraph();

}
int muestraBMP(int x, int y, char* NomArchivo)
{
    int b,a;
    BMP Obj;
    unsigned char* Datas;
    int in=0;
    unsigned char c=0;
    FILE * fp;
    fp = fopen(NomArchivo,"rb");
    if(!fp){
    printf("Error : No se puede abrir el archivo ...");
 getch();
    exit(0);
    }
    fread(&Obj, sizeof(Obj), 1, fp);
    if(Obj.BitsPerPixel!=4)  /* Este NO es un bmp de 16 colores que podamos leer*/
    {
     fclose(fp);
     printf("Error : Formato de archivo no soportado...");
  getch();
     exit(0);
    };
    fseek(fp,Obj.OffSet,SEEK_SET);
    Datas=(unsigned char*) calloc(Obj.Width/2+1, sizeof(unsigned char));
    for(b=Obj.Height;b>=0;b--)
    {
     fread(Datas, sizeof(unsigned char), Obj.Width/2, fp);
     c=0;
     in=0;
     for(a=0;a<=Obj.Width;a+=2)
     {
   c = (Datas[in] | 0xF0) & 0x0F;
         putpixel(a+1+x,b+y,c);
         c = (Datas[in] | 0x00) >>4;
         putpixel(a+x,b+y,c);
         in++;
     }
    }
    free (Datas);
    fclose(fp);
    return 1;
}
