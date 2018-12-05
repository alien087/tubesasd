#include<bits/stdc++.h>
#include<conio.h>
#include<cstdlib>
using namespace std;

#define REPup(i, a, p)  for(int (i) = int (a); i<int (p); i++)
#define REPdown(i, a, p)  for(int (i) = int (a); i>=int (p); i--)

typedef char infotype;
typedef struct TElmtList *address;
typedef struct TElmtList{
 infotype info;
 address next;
 address prev;
} ElmtList;

typedef struct {
 address first;
 address last;
}List ;

 //SELEKTOR 
#define Info(P) (P)->info
#define Next(P) (P)->next
#define Prev(P) (P)->prev
#define First(L) ((L).first)
#define Last(L) ((L).last)

//KONSTANTA
#define Nil NULL
#define Infinity 99999


/****************** TEST LIST KOSONG ******************/
bool IsEmpty(List L) {
/* Mengirim true jika list kosong. Lihat definisi di atas. */
 return (First(L) == NULL && Last(L) == NULL);
}


/****************** PEMBUATAN LIST KOSONG ******************/
void createList(List *L) {
 First(*L) = NULL;
 Last(*L) = NULL;
}

/****************** Manajemen Memori ******************/
address Allocation(infotype x) {

 address NewElmt;
 NewElmt = (ElmtList*) malloc (sizeof(ElmtList));
 Info(NewElmt) = x;
 Next(NewElmt) = Nil;
 Prev(NewElmt) = Nil;
 return NewElmt;
}

void Deallocation(address hapus) {
 free(hapus);
}


/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search1(List L, infotype X, infotype y){
	address P = First(L);
	while (P != Nil){
		if ( Prev(P) != Nil && (Next(P)->info == y && Prev(P)->info == X) && Info(P) == '_' ){
			return P;
		}
		P = Next(P);
	}
	return Nil;
}

void InsertFirst(List *L, infotype x) {

 address NewElmt;
 NewElmt = Allocation(x);
 if (NewElmt != NULL) {
	if(IsEmpty(*L)){
		First(*L) = NewElmt;
		Last(*L) = NewElmt;
	}
	else{
		Next(NewElmt) = First(*L);
		Prev(First(*L)) = NewElmt;
		First(*L) = NewElmt;
	}
}
}

void InsertLast(List *L, infotype x) {

 address NewElmt;
 NewElmt = Allocation(x);
 if (NewElmt != NULL) {
 if(IsEmpty(*L)){
 InsertFirst(L,x);
 } else{
 Next(Last(*L)) = NewElmt;
 Prev(NewElmt) = Last(*L);
 Last(*L) = NewElmt;
 }
 }
}


/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P){
/* I.S. Sembarang, P sudah dialokasi */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
	if(IsEmpty(*L)){
 First(*L) = P;
 Last(*L) = P;
 } else{
 Next(P) = First(*L);
 Prev(First(*L)) = P;
 First(*L) = P;
 }
}

void InsertLast (List *L, address P){
/* I.S. Sembarang, P sudah dialokasi */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
	if(IsEmpty(*L)){
 InsertFirst(L,P);
 } else{
 Next(Last(*L)) = P;
 Prev(P) = Last(*L);
 Last(*L) = P;
 }
}

void InsertAfter (List *L, address P, address Prec){

	if(Next(Prec) == Nil){
		InsertLast(L,P);
	}
	else{
		Next(P) = Next(Prec);
		Prev(P) = Prec;
		Prev(Next(Prec))= P;
		Next(Prec) = P;
	}
}

void InsertBefore (List *L, address P, address Succ){
	if(Succ == First(*L)){
	InsertFirst(L,P);
	}else{
	Next(Prev(Succ)) = P;
	Prev(P) = Prev(Succ);
	Next(P) = Succ;
	Prev(Succ) = P;
	}
}


/*** PENGHAPUSAN SEBUAH ELEMEN ***/

void DelFirst (List *L, address *P){
	*P = First(*L);
	First(*L) = Next(*P);
	Prev(First(*L)) = Nil;
	Deallocation(*P);
}

void DelLast (List *L, address *P){
	*P = Last(*L);
	Last(*L) = Prev(*P);
	Next(Last(*L)) = Nil;
	Prev(*P) = Nil;
	Deallocation(*P);
}



void DelAfter (List *L, address *Pdel, address Prec){
	*Pdel = Next(Prec);
	Next(Prec) = Next(*Pdel);
	Prev(Next(*Pdel)) = Prec;
	Prev(*Pdel) = Nil;
	Next(*Pdel)= Nil;
	Deallocation(*Pdel);
}

void DelBefore (List *L, address *Pdel, address Succ){
	*Pdel = Prev(Succ);
	Next(Prev(*Pdel)) = Succ;
	Prev(Succ) = Prev(*Pdel);
	Prev(*Pdel) = Nil;
	Next(*Pdel) = Nil;
	Deallocation(*Pdel);
}

void DelP (List *L, infotype X){

	address P = Searchh(*L,X);
	address prec = Prev(P);
	if (P != Nil){
		if(P == First(*L)){
			DelFirst(L,&P);
		}else if(P == Last(*L)){
			DelLast(L,&P);
		}else{
			DelAfter(L,&P,prec);
		}
	}
}


/****************** PROSES SEMUA ELEMEN LIST ******************/


void PrintBackward (List L){
	cout<<"[";
	if(!IsEmpty(L)){
		address temp =Last(L);
		while(Prev(temp)!=NULL){
			cout<<Info(temp) <<", ";
			temp = Prev(temp);
		}
		cout<<Info(temp);
	}
	cout<<"]"<<endl;
}

void Outputdata(List L){
    address temp = (L).first;
    while(temp!=NULL){
        cout<<temp->info<<" ";
        temp = temp->next;
    }

}

void cobaisi(List *data){
	address temp;
	temp = (*data).first;
	temp->info = '9';
	(temp->next)->info = '2';
	REPup(i, 0, 5){
		temp = temp->next;
	}
	temp->info = '1';
	(temp->next)->info = '1';

	REPup(i, 0, 3){
		temp = temp->next;
	}

	temp->info = '2';
}

void interface(){
	cout<<"Posisi Tebakkan Anda: \n";
	cout<<"a. Sebelum \nb. Setelah \nc. Awal \nd. Akhir\n";
	cout<<"Masukkan Posisi: ";

}

bool cekPrev(List L, address temp){
	return (Prev(temp)!=NULL && Info(temp) == Info(Prev(temp)) && Info(temp) == Info(Prev(Prev(temp))));
}

bool cekNext(List L, address temp){
	return (Next(temp)!=NULL && Info(temp) == Info(Next(temp)) && Info(temp) == Info(Next(Next(temp))));
}

bool cekBetween(List L, address temp){
	return (Prev(temp)!=NULL && Next(temp)!=NULL && Info(temp) == Info(Next(temp)) && Info(temp) == Info(Prev(temp)) && Next(temp) != NULL);
}


int main(){
	address temp;
	List data;
	int nyawa=4; // Variabel banyaknya kesempatan USER untuk menembak angka
	char pilih;
	infotype x, n, y;
	
	createList(&data); //Membuat List Kosong
	
	REPup(i, 0, 10){
        InsertLast(&data, '_' ); // Memasukkan "_" kedalam List
    }

	cobaisi(&data); // Mengisi angka Random Kedalam List
	while(nyawa>0){
		Outputdata(data); // Menampilkan Susunan Angka
		cout<<"\nKesempatan Menembak: "<<nyawa; // Menampilkan sisa Kesempatan Menembak
		cout<<"\nMasukkan Angka Tebakan anda: "; cin>>n; // Meminta user menginputkan Angka yang akan ditembak
		interface(); // Memanggil fungsi Interface
		
		cin>>pilih; // User Memasukkan Pilihan Posisi
		switch(pilih){ // Case untuk Pilihan Posisi
			case 'a' :	cout<<"Angka: "; cin>>x; // Meminta user memasukkan Posisi Sebelum
						cout<<"Setelah Angka: "; cin>>y; //Meminta user memasukkan Posisi Setelah
						temp = Search1(data, y, x); // Proses pencarian posisi
						Info(temp) = n; // Proses reWrite/replace Info dengan angka pilihan user
						break;
			case 'b' :	cout<<"Angka: "; cin>>x; // Meminta user memasukkan Posisi Setelah
						cout<<"Sebelum Angka: "; cin>>y; // Meminta user memasukkan Posisi Sebelum
						temp = Search1(data, x, y); // Proses pencarian posisi
						Info(temp) = n; // Proses reWrite/replace Info dengan angka pilihan user
						break;
 			case 'c' :	First(data)->info = n; // Proses reWrite/replace Info elemen pertama dengan angka pilihan user
						temp = First(data);
						break;
			case 'd' : 	Last(data)->info = n; // Proses reWrite/replace Info elemen terakhir dengan angka pilihan user
						temp = Last(data);
						break;
		}
		
		Outputdata(data);
		if(cekPrev(data, temp) || cekNext(data, temp) || cekBetween(data, temp)){ // Pengecekan kondisi apakah sudah berjejer 3 atau lebih angka yang sama
			cout<<"\nAnda Beruntung"; // Jika sudah makan akan output "Anda Beruntung" dan
			break; 					  // proses perulangan dihentikan
		}
		nyawa--; // jika belom dapat posisi angka berjejer >= 3 maka kesempatan menembak berkurang
		system("cls");

	}

	if(nyawa<1) cout<<"Anda Kurang Beruntung"; // Jika kesempatan menembak habis (daalam hal ini <1) maka
    											   // Output "anda Kurang Beruntung"
	
	getche();

	
}
