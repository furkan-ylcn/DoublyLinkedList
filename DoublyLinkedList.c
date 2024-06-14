#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	int numara;
	char isim[15];
	char soyad[15];
	char bolum[15];
	int sinif;
	struct node *prev;
	struct node *next;
}*head;

void createList(int n);
void traverseList();

// Liste Oluþtur.(Create List)
void createList(int elemanSayisi){
	struct node *newNode, *temp;
	int i, numara, sinif;
	char isim[15], soyad[15], bolum[15];
	printf("Liste Olusturuluyor.\n");
	head = (struct node*)malloc(sizeof(struct node));
	if(head == NULL){
		printf("Hafiza ayrilamadi.\n");
		exit(0);
	}
	printf("Ilk elemanin verinlerini giriniz.\n");
	printf("Numara :");
	scanf("%d", &numara);
	printf("Isim :");
	scanf("%s", &isim);
	printf("Soyad :");
	scanf("%s", &soyad);
	printf("Bolum :");
	scanf("%s", &bolum);
	printf("Sinif :");
	scanf("%d", &sinif);
	head->numara = numara;
	strcpy(head->isim, isim);
	strcpy(head->soyad, soyad);
	strcpy(head->bolum, bolum);
	head->sinif = sinif;
	head->prev = NULL;
	head->next = NULL;
	temp = head;
	
	for(i = 2; i <= elemanSayisi; i++){
		newNode = (struct node*)malloc(sizeof(struct node));
		if(newNode == NULL){
			printf("Hafiza ayrilamadi.\n");
			break;
		}
		printf("%d. elemanin verilerini aralarda birer bosluk birakarak su sira ile girin -> Numara, Isim, Soyad, Bolum, Sinif :", i);
		scanf("%d %s %s %s %d", &numara, &isim, &soyad, &bolum, &sinif);
		newNode->numara = numara;
		strcpy(newNode->isim, isim);
		strcpy(newNode->soyad, soyad);
		strcpy(newNode->bolum, bolum);
		newNode->sinif = sinif;
		newNode->prev = temp;
		newNode->next = NULL;
		temp->next = newNode;
		temp = temp->next;
		printf("%d. eleman olusturuldu.\n", i);
	}
}

// Listede dolaþ.(Display List)
void traverseList(){
	struct node *temp;
	if(head == NULL){
		printf("Liste bos.\n");
		return;
	}
	temp = head;
	while(temp != NULL){
		printf("Ogrenci Numarasi: %d\nOgrencinin Adi: %s\nOgrencinin Soyadi: %s\nOgrencinin Okudugu Bolum: %s\nOgrencinin Sinifi: %d\n\n\n", temp->numara, temp->isim, temp->soyad, temp->bolum, temp->sinif);
		temp = temp->next;
	}
	if(head == NULL){
		printf("Liste Bos.\n");
	}
}

// Listenin baþýna eleman ekle.
void basa_ekle(int numara, char isim[], char soyad[], char bolum[], int sinif){
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	if(head == NULL){
		newNode->numara = numara;
		strcpy(newNode->isim, isim);
		strcpy(newNode->soyad, soyad);
		strcpy(newNode->bolum, bolum);
		newNode->sinif = sinif;
		newNode->prev = NULL;
		newNode->next = NULL;
		head = newNode;
		return;
	}
	if(head != NULL){
		newNode->numara = numara;
		strcpy(newNode->isim, isim);
		strcpy(newNode->soyad, soyad);
		strcpy(newNode->bolum, bolum);
		newNode->sinif = sinif;
		newNode->prev = NULL;
		newNode->next = head;
		head = newNode;
	}
}

// Listenin sonuna eleman ekle.
void sonuna_ekle(int numara, char isim[], char soyad[], char bolum[], int sinif){
	struct node *newNode, *temp;
	newNode = (struct node*)malloc(sizeof(struct node));
	if(head == NULL){
		newNode->numara = numara;
		strcpy(newNode->isim, isim);
		strcpy(newNode->soyad, soyad);
		strcpy(newNode->bolum, bolum);
		newNode->sinif = sinif;
		newNode->prev = NULL;
		newNode->next = NULL;
		head = newNode;
		return;
	}
	temp = head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	newNode->numara = numara;
	strcpy(newNode->isim, isim);
	strcpy(newNode->soyad, soyad);
	strcpy(newNode->bolum, bolum);
	newNode->sinif = sinif;
	newNode->prev = temp;
	newNode->next = NULL;
	temp->next = newNode;
}

// Verilen bir öðrenci numarasýndan sonra bir eleman ekle.
void araya_ekle(int numara, char isim[], char soyad[], char bolum[], int sinif,int keyOgrenciNo){
	if(head == NULL){
		printf("Liste bos oldugundan araya ekleme islemi gerceklestirilemedi.\n");
		return;
	}
	struct node *newNode, *temp;
	newNode = (struct node*)malloc(sizeof(struct node));
	temp = head;
	while(temp->numara != keyOgrenciNo){
		if(temp->next == NULL){
			printf("\nGirmis oldugunuz key ogrenci numarasi listede olmadigindan araya ekleme islemi gerceklestirilemedi.\n");
			return;
		}
		temp = temp->next;
	}
	if(temp->next == NULL){
		printf("\nGirdiginiz key ogrenci numarasi son ogrenciye ait. Lutfen bu ogrenciyi eklemek icin 'sonuna_ekle' fonksiyonunu kullanin.\n");
		return;
	}
	newNode->numara = numara;
	strcpy(newNode->isim, isim);
	strcpy(newNode->soyad, soyad);
	strcpy(newNode->bolum, bolum);
	newNode->sinif = sinif;
	newNode->prev = temp;
	newNode->next = temp->next;
	temp->next->prev = newNode;
	temp->next = newNode;
}

// Bir node' u sil.(Delete Node)
void node_sil(int silinecekNo){
	if(head == NULL)
		return;
	struct node *temp;
	temp = head;
	while(temp->numara != silinecekNo){
		if(temp->next == NULL){
			printf("\n%d nolu ogrenci listede bulunamadigindan silme islemi gerceklestirilemedi.\n", silinecekNo);
			return;
		}
		temp = temp->next;
	}
	if(temp == head){
		head = temp->next;
		head->prev = NULL;
		temp->next = NULL;
		free(temp);
		return;
	}
	if(temp->next == NULL){
		temp->prev->next = NULL;
		temp->prev = NULL;
		free(temp);
		return;
	}
	temp->next->prev = temp->prev;
	temp->prev->next = temp->next;
	temp->prev = NULL;
	temp->next = NULL;
	free(temp);
}

// Listeyi sil.(Delete List)
void listeyi_sil(){
	if(head == NULL){
		printf("Liste bos oldugundan liste silme islemi gerceklestirilemedi.\n");
		return;
	}
	struct node *prevNode, *temp;
	temp = head;
	while(temp->next != NULL){
		prevNode = temp;
		temp = temp->next;
	}
	while(prevNode != head){
		temp->prev = NULL;
		prevNode->next = NULL;
		free(temp);
		temp = prevNode;
		prevNode = prevNode->prev;
	}
	temp->prev = NULL;
	prevNode->next = NULL;
	head->next = NULL;
	free(temp);
	free(prevNode);
	head = NULL;
	free(head);
}

// Numarasý verilen öðrencinin bilgilerine eriþme. (Search Node)
void ogrenci_ara(int aranacakNo){
	if(head == NULL){
		printf("\nListe bos oldugundan arama basarisiz oldu.\n");
		return;
	}
	struct node *temp;
	temp = head;
	while(temp->numara != aranacakNo){
		temp = temp->next;
	}
	printf("%d numarali ogrencinin bilgileri : \n", aranacakNo);
	printf("Ogrenci Numarasi: %d\nOgrencinin Adi: %s\nOgrencinin Soyadi: %s\nOgrencinin Okudugu Bolum: %s\nOgrencinin Sinifi: %d\n\n\n", temp->numara, temp->isim, temp->soyad, temp->bolum, temp->sinif);
}

int main(){
	
	int n;
	
	printf("Olusturacaginiz listenin eleman sayisini girin : ");
	scanf("%d", &n);
	
	createList(n);
	
	basa_ekle(17, "Eren", "Kaya", "Edebiyat", 1);
	sonuna_ekle(22, "Yaren", "Demiral", "Biyokimya", 3);
	araya_ekle(15, "Sevinc", "Acar", "Makine", 1, 17);
	
	printf("\nListedeki elemanlar : \n");
	traverseList();
	
	ogrenci_ara(10);
	
	node_sil(17);
	
	printf("\nListedeki elemanlar : \n");
	traverseList();
	
	listeyi_sil();
	
	printf("\nListedeki elemanlar : \n");
	traverseList();
	
	return 0;
}
