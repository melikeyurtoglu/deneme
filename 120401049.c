#include <stdio.h>
#include <stdlib.h>
#define BOYUT 100
//deneme
//void ucgen2(char metin[],int i);
void ucgen(char metin[],int i);
int main()
{
    char metin[BOYUT];
    int i=0;
    char ch=0;
    int harf_sayisi=0;
    int kelime_sayisi=0;
    int kelimedeki_harfsayisi=0;
    int enuzunkelimedekiharf=0;
    int uzun=0;
    int kisa=0;
    int uckelime=0;
    int uckisa=0;
    int cumle_sayisi=0;
    int latin=0;
    float yuzde;



    printf("Bir metin giriniz:\n"); //kullanıcıdan metin girilmesi isteniyor.
    do{ //do-while dongüsüyle karakterler alınacak ve sonlanma karakterine kadar karakte alımı devam edicek.
        fflush(stdin);
        ch=getchar(); //getchar ile karakter alımı yapıp ch degişkenine atıyoruz.
        if(ch<0){ //ch ın degerinin sıfırdan kucuk olup olmadıgına bakıyoruz turkce karakterler ıcın.
            latin++; //sınıfdan kucukse turkce karakterler ıcın arttırım yapıyoruz.
            }
        metin[i]=ch; //karakterleri diziye atıyoruz..
        i++; //index i arttırıyoruz.

        harf_sayisi++; //harf sayisini her girilen karakterde arttırıyoruz..
        kelimedeki_harfsayisi++; //kelimedeki harf sayisini arttırıyoruz.
        if(ch==' '||ch==','||ch==';'){ //karakter boşluğa virgül veya noktalı virgüle gelirse ...
            kelime_sayisi++; //kelime sayisini arttırıyoruz.
            kelimedeki_harfsayisi=0; //kelimedeki harf sayisini sıfırlıyoruz.
            uckelime++;//uc kelimeden az cumleleri bulmak için uc kelime index ini arttırıyoruz.
            harf_sayisi--; // bu karakterleri görünce harf olmadığı için harf sayisini azaltiyoruz.
            }

        if(ch=='.'||ch=='?'||ch=='!'||ch==':'){ //egerch bu karakterlere esit ise...
            kelime_sayisi++;//kelime sayisini yine arttırıyoruz.
            kelimedeki_harfsayisi=0;//kelimedeki harf sayisini sıfırlıyoruz çünkü kelime bitmiş oluyor.
            uckelime++;//uc kelimeyide arttırıyoruz..
            harf_sayisi--;//harf sayisini bu karakterler harf olmasıgı için azaltiyoruz.
            cumle_sayisi++;//bu karakterlerle biterse bir cümle bitmiş olacağı için cümle sayisini arttırıyoruz.
            if(uckelime<3){//cumle bittiğine göre kelime sayisini kontrol ediyoruz uc kelimeden az mı diye..
                uckisa++;// eger az ise uc kelimeden kısa cumlelerin sayisini arttırıyoruz.
                }
            uckelime=0;//cumle bittiği için kelime sayisini sıfırlıyoruz.
            }
        if(kelimedeki_harfsayisi>enuzunkelimedekiharf){//kelimedeki harf sayisi en uzun kelimedeki harf sayisindan büyük ise.
            enuzunkelimedekiharf=kelimedeki_harfsayisi;//enuzun kelimedeki harfe kelimedeki harfi atıyoruz.
            if(kelimedeki_harfsayisi>10){//kelimedeki harf buyuk ise on dan 10 harften uzun kelime sayisini arttırıyoruz.
                uzun++;//uzun kelimedeki harf sayisini arttırıyoruz.
                }
            if(kelimedeki_harfsayisi<4){ //kelimedeki harf sayisi 4 ten kücük ise
                kisa++; //4 harften kucuk olan kelimelerin sayisini arttırıyoruz.
                }

            }

    }while(ch!='#');//ch '#' karakterine eşit ise alma işlemini durduruyoruz..

    ucgen(metin,i);
    //ucgen2(metin,i);

    yuzde=((float)latin*100/((i-1)-kelime_sayisi));//türkçe karakterlerin yüzdesini hesaplıyoruz.
    printf("Metindeki toplam cumle sayisi=%d\n",cumle_sayisi);
    printf("Metindeki toplam kelime sayisi=%d\n",kelime_sayisi);
    printf("Merindeki toplam karakter sayisi=%d\n",i-1);//-1 yapmamızın nedeni '#' karakterini ilk do ya girdiğinde aldığı için.
    printf("Metindeki toplam harf sayisi=%d\n",harf_sayisi-1);
    printf("Metindeki Latin alfabesinde yer almayan harflerin sayısı=%2.2f ve toplam harf sayısı içindeki yuzdesi=%2.2f\n",(float)latin,yuzde);
    printf("cumlelerin ortalama kelime sayisi=%2.2f\n",(float)kelime_sayisi/cumle_sayisi);
    printf("Kelimelerin ortalama harf sayisi=%2.2f\n",(float)harf_sayisi/kelime_sayisi);
    printf("4 harften kisa kelimelerin sayisi=%d\n",kisa);
    printf("10 harften uzun kelimelerin sayisi=%d\n",uzun);
    printf("En üzün kelimelenin harf sayisi=%d\n",enuzunkelimedekiharf);
    printf("3 kelimeden kisa cümlelerin sayisi=%d\n",uckisa);


return 0;
}

void ucgen(char metin[],int i){ //ucgen olusturma fonksiyonudur. //bu fonksiyonda her satırda baştan başlamıyor.
int h=0;
int sutun=0;
int satir=1;
while(h<i-1){
    while((sutun<satir)&&(h<i-1)){//-1 dememizin nedeni # karakterini almaması
        if(metin[h]=='.'||metin[h]=='?'||metin[h]=='!'||metin[h]==':'){//cumleyi bitirince diziyi sıfırlıyoruz..
                metin[h]=0;
                printf("\n");
            }
        if(metin[h]==' '||metin[h]==','||metin[h]==';'){//bu karakterlere gelince atla..
            h++;
            }
                printf("%c",metin[h]);//dizini yazdır..
                h++;
                sutun++;
                }
                printf("\n");
                sutun=0;
                satir++;
            }
    return 0;
}
/*void ucgen2(char metin[],int i){ //bu ücgen her cumle sonunda ucgene tekrar başlıyor fakat her satırda cumlenın basından baslıyor.
    int g=0;
    int l;
    int b;
    char ucgen[BOYUT];
    for(b=0;b<i;b++){
        if(metin[b]!=' '||metin[b]!=','||metin[b]!=';'||metin[b]!='.'||metin[b]!='!'||metin[b]!='?'||metin[b]!=':'){
            ucgen[g]=metin[b];//harfleri ucgen dizisine atıyoruz...
            g++;
            for(l=0;l<g;l++){
                if(ucgen[l]=='.'||ucgen[l]=='!'||ucgen[l]=='?'||ucgen[l]==':'){//ucgen dizisinde bu karakterler var ise atlıyoruz.
                    l++;
                    }
                printf("%c",ucgen[l]);
                }
            printf("\n");
            }
        if(metin[b]=='.'||metin[b]=='!'||metin[b]=='?'||metin[b]==':'){
            ucgen[g]=0;//cümle sonuna gelince diziyi sıfırlayıp diğer dizi için baştan başlıyoruz..
            g=0;
            }
        }
return 0;
}*/
