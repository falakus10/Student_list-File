#include <stdio.h>
#include <stdlib.h>

typedef enum {
    Erkek,
    Kadin

} Cinsiyet;
typedef struct {
    int ogrNo;
    char ogrAd[10];
    float ogrNot;
    Cinsiyet cinsiyet;
} Ogrenci;

void ogrenciYaz(Ogrenci ogrenci, FILE *Dosya);
void ogrenciOku(Ogrenci *ogrenci, FILE *Dosya);


int main() {
    FILE *Dosya = fopen("dosya.txt", "w");
    if (Dosya == NULL) {
        printf("Başarısız dosya oluşturma isteği!\n");
        exit(1);
    }
    int i = 1;
    char karar;
    Ogrenci ogrenci;
    do {
        printf("%d. Ogrencinin Numarasi:", i);
        scanf("%d", &ogrenci.ogrNo);
        printf("%d. Ogrencinin Adi:", i);
        scanf("%9s", ogrenci.ogrAd);
        printf("%d. Ogrencinin Notu:", i);
        scanf("%f", &ogrenci.ogrNot);
        printf("%d. Ogrenci Cinsiyeti(Erkek=0, Kadin=1):", i);
        int cinsiyet;
        scanf("%d", &cinsiyet);
        ogrenci.cinsiyet = (Cinsiyet)cinsiyet;
        ogrenciYaz(ogrenci, Dosya);
        printf("Devam etmek istermisiniz (E/e veya H/h)?");
        getchar();
        scanf(" %c", &karar);
        i++;
    } while (karar == 'E' || karar == 'e');
    fclose(Dosya);
    printf("Kayit islemleri tamamlandi !\n\n");

    Dosya = fopen("dosya.txt", "r");
    if (Dosya == NULL) {
        printf("Başarısız dosya okuma istegi!\n");
        exit(1);
    }
    i=1;
    while (!feof(Dosya)){
        ogrenciOku(&ogrenci, Dosya);

        printf("%d. Ogrencinin:\n", i);
        printf("Numarasi: %d\n", ogrenci.ogrNo);
        printf("Adi: %s\n", ogrenci.ogrAd);
        printf("Notu: %.2f\n", ogrenci.ogrNot);
        printf("Cinsiyet: %s\n", ogrenci.cinsiyet==Erkek?"Erkek":"Kadin");
        printf("---------------\n");
        i++;
    }
    fclose(Dosya);

    return 0;
}

void ogrenciYaz(Ogrenci ogrenci, FILE *Dosya){
    fprintf(Dosya, "%5d %10s %.2f %d\n", ogrenci.ogrNo,
            ogrenci.ogrAd, ogrenci.ogrNot, ogrenci.cinsiyet);
}
void ogrenciOku(Ogrenci *ogrenci, FILE *Dosya){
    fscanf(Dosya, "%5d %10s %f %d\n", &(ogrenci->ogrNo),
           ogrenci->ogrAd, &(ogrenci->ogrNot),
           &(ogrenci->cinsiyet));
}