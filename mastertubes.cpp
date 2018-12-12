#include<bits/stdc++.h>
#include<conio.h>
#include<cstdlib>
#include<windows.h>
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

void pilihMenuu(List *data, List data2, int *nyawa);

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
		if ( Prev(P) != Nil && Next(P) != Nil && (Next(P)->info == y && Prev(P)->info == X) && Info(P) == '_' ){
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


void Outputdata(List L){
    address temp = (L).first;
    while(temp!=NULL){
        cout<<temp->info<<" ";
        temp = temp->next;
    }

}



void iinterface(){
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
	return (Prev(temp)!=NULL && Next(temp)!=NULL && Info(temp) == Info(Next(temp)) && Info(temp) == Info(Prev(temp)) );
}

void pushangka(int x, List *L){
        if(x == 1){
            InsertLast(&(*L), '1');
        }else if( x == 2){
            InsertLast(&(*L), '2');
        }else if( x == 3){
            InsertLast(&(*L), '3');
        }else if( x == 4){
            InsertLast(&(*L), '4');
        }else if( x == 5){
            InsertLast(&(*L), '5');
        }else if( x == 6){
            InsertLast(&(*L), '6');
        }else if( x == 7){
            InsertLast(&(*L), '7');
        }else if( x == 8){
            InsertLast(&(*L), '8');
        }else if( x == 9){
            InsertLast(&(*L), '9');
        }else{
            InsertLast(&(*L), '0');
        }

}

void randomLIST(List *L, int i){
    int x,y,z = 0,z2 = 0;
	if(i == 0){
		srand(time(0));
	}
    REPup(j, 0, 10){
        x = rand()%10;
        y = rand()%2;

        if(y == 1){
          if(z < 5)pushangka(x, &(*L));
          else InsertLast(&(*L), '_');
          z++;
        }else{
          if(z2 > 4)pushangka(x, &(*L));
          else InsertLast(&(*L), '_');
          z2++;
        }
    }

}

void interface1(){
	cout<<"Selama Datang Di Game Zuma\n";
	cout<<"1. Pilih soal\n2. Tentukan Kesempatan Menembak\n3. Mulai Game\n4. Keluar\n";
	cout<<"Masukkan Pilihan Anda: ";
}

void pilihSoal(List *data, List data2, int *nyawa){
	system("cls");
	cout<<"Pilihan Soal: \n";
	char pilih;
	cout<<"a. "; Outputdata(*data); cout<<"\n";
	cout<<"b. "; Outputdata(data2); cout<<"\n";
	cout<<"Masukkan Pilihan Soal: "; cin>>pilih;
	if(pilih == 'b') *data=data2;
	pilihMenuu(data, data2, nyawa);

}
void pilihMenuu(List *data, List data2, int *nyawa){
	system("cls");
	interface1();
	char pilih;
	cin>>pilih;
	switch (pilih){
		case '1' : pilihSoal(data, data2, nyawa); break;
		case '2' : system("cls"); cout<<"Masukkan Nyawa : "; cin>>*nyawa; pilihMenuu(data, data2, nyawa); break;
		case '3' : break;
		case '4' : exit(0); break;
		default  : cout<<"Masukkan Salah!, Silahkan Masukkan Pilihan Lagi: "; pilihMenuu(data, data2, nyawa); 
	}
	system("cls");
}


int main(){
	address temp;
	List data, data2;
	int nyawa; // Variabel banyaknya kesempatan USER untuk menembak angka
	char pilih;
	infotype x, n, y;
	createList(&data); //Membuat List Kosong
	createList(&data2);
	
	randomLIST(&data,0);
	// Sleep(100);
	randomLIST(&data2,1);

	pilihMenuu(&data, data2, &nyawa);
	
	

	//cobaisi(&data); // Mengisi angka Random Kedalam List
	while(nyawa>0){
		
		system("cls");
		// play:
		Outputdata(data); // Menampilkan Susunan Angka
		cout<<"\nKesempatan Menembak: "<<nyawa; // Menampilkan sisa Kesempatan Menembak
		cout<<"\nMasukkan Angka Tebakan anda: "; cin>>n; // Meminta user menginputkan Angka yang akan ditembak
		
		iinterface(); // Memanggil fungsi Interface
		
		play:
		cin>>pilih; // User Memasukkan Pilihan Posisi
		switch(pilih){ // Case untuk Pilihan Posisi
			case 'a' :	cout<<"Angka: "; cin>>x; // Meminta user memasukkan Posisi Sebelum
						cout<<"Setelah Angka: "; cin>>y; //Meminta user memasukkan Posisi Setelah
						temp = Search1(data, y, x); // Proses pencarian posisi
						if(temp!=Nil) Info(temp) = n; // Proses reWrite/replace Info dengan angka pilihan user
						break;
			case 'b' :	cout<<"Angka: "; cin>>x; // Meminta user memasukkan Posisi Setelah
						cout<<"Sebelum Angka: "; cin>>y; // Meminta user memasukkan Posisi Sebelum
						temp = Search1(data, x, y); // Proses pencarian posisi
						if(temp!=Nil) Info(temp) = n; // Proses reWrite/replace Info dengan angka pilihan user
						break;
 			case 'c' :	First(data)->info = n; // Proses reWrite/replace Info elemen pertama dengan angka pilihan user
						temp = First(data);
						break;
			case 'd' : 	Last(data)->info = n; // Proses reWrite/replace Info elemen terakhir dengan angka pilihan user
						temp = Last(data);
						break;
			default  : cout<<"Masukkan salah! Silahkan masukkan Lagi: "; goto play; break;
		}
		
		Outputdata(data);

		if(temp != Nil && (cekPrev(data, temp) || cekNext(data, temp) || cekBetween(data, temp))){ // Pengecekan kondisi apakah sudah berjejer 3 atau lebih angka yang sama
			cout<<"\nAnda Beruntung"; // Jika sudah makan akan output "Anda Beruntung" dan
			break; 					  // proses perulangan dihentikan
		}
		nyawa--; // jika belom dapat posisi angka berjejer >= 3 maka kesempatan menembak berkurang
		system("cls");

	}

	if(nyawa<1) {
		Outputdata(data); cout<<endl;
		cout<<"Anda Kurang Beruntung"; // Jika kesempatan menembak habis (daalam hal ini <1) maka
    											   // Output "anda Kurang Beruntung"
	}
	
	getche();

	
}
