#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *fp1 = NULL, *fp2 = NULL;
    char *source = argv[1], *dest = argv[2];
    char buffer[4000] = {0};
    
    fp1 = fopen(source, "rb");
    fp2 = fopen(dest, "wb");
    if(fp1 == NULL || fp2 == NULL) return 0;
    
    fseek(fp1, 0, SEEK_END);
    long fsize = ftell(fp1);
    fseek(fp1, 0, SEEK_SET);
    
    while(feof(fp1) == 0)
    {
        
        fread(buffer, sizeof(buffer), 4000, fp1);
        fwrite(buffer, sizeof(buffer), 4000, fp2);
        memset(buffer, 0, sizeof(buffer));
        printf("%.2f %%\n", ((float)ftell(fp1) / (float)fsize) * (float)100);
    }

    fclose(fp1);
    fclose(fp2);
 
    return 0;
}
