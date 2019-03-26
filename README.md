# Praktikum-2-SD
Demo Praktikum 2 StrukDat

# SOAL
<!-- === -->

1. [AHHA](#ahha)
4. [TDL](#tdl)

## AHHA
<!-- --- -->
Bobby adalah penggemar mie instan nomor satu di dunia. Ia menjadi sangat terkenal di media sosial akan hal tersebut. Perusahaan mie terbesar di Indonesia ingin menjadikan Bobby sebagai bintangnya dan Bobby pun sangat senang mendengar hal tersebut. Perusahaan tersebut memiliki N buah jenis mie yang masing - masing memiliki nilai rasa yang akan disupply untuk Bobby. Setiap harinya perusahaan tersebut akan memberikan K jenis mie secara berurut kepada Bobby untuk dipilih oleh Bobby. Karena Bobby adalah seseorang yang perfectionist maka ia akan mengambil mie dengan nilai rasa tertinggi dari K pilihan tersebut.

Contoh

N = 5, K = 3

2 3 4 1 3

Hari pertama supply

2 3 4 1 3

Bobby akan mengambil 4.

Setelah menerima pasokan mie tersebut, Bobby akan langsung menaruhnya didalam tumpukan mie yang ia miliki. Bobby menyadari bahwa makan mie terus menerus setiap hari tidak baik untuk kesehatan sehingga ia akan sehingga ia akan memilih hari hari tertentu untuk makan mie. Bobby memakan mie selalu dengan mengambil mie yang berada paling atas pada tumpukan mie yang ia miliki. Selain makan mie Bobby juga suka pamer kepada temannya di sosial media tentang nilai rasa tertinggi yang ia miliki di dalam tumpukan mienya.

Karena Bobby tidak peduli dengan nilai rasa mie yang ia masukan kedalam tumpukannya, maka anda sebagai admin media sosial akun Bobby sekaligus sekretaris pribadi Bobby diberikan tugas untuk melakukan hal tersebut. Anda memiliki akses terhadap seluruh kegiatan Bobby. Bantulah Bobby untuk menjalani kehidupannya.

Input Format
Sebuah baris berisi bilangan N dan K. N menyatakan banyak jenis supply yang akan dikirimkan dan K adalah jumlah mie yang di supply setiap harinya.

N baris berikutnya berisi nilai - nilai dari supply yang akan dikirimkan.

Baris selanjutnya berisi bilangan H dan Q. H adalah hari keberapa dan Q merupakan jumlah aksi yang akan dilakukan Bobby.

Q baris selanjutnya untuk masing H dan Q berisi bilangan X.

X adalah tipe aksi yang akan dilakukan oleh Bobby.

1 artinya Bobby akan makan mie.

2 artinya Bobby akan pamer kepada temannya.

Inputan berhenti ketika H dan Q bernilai -1.

Output Format
Q baris untuk setiap H dan Q.

Apabila X merupakan 1 keluarkan "Nyam" apabila Bobby sukses makan mie. Apabila persediaan mie tidak ada keluarkan "Stok abis".

Apabila X merupakan 2 keluarkan sebuah bilangan yang menyatakan nilai tertinggi yang dimiliki Bobby dalam tumpukan mienya. Apabila persediaan mie tidak ada keluarkan "Stok abis".

Sample Input
5 3
1 2 3 4 5
1 1
2
3 2
1
2
-1 -1
Sample Output
3
Nyam
4
Explanation
1 2 3 4 5

bilangan yang di bold merupakan supply di hari pertama. 3 merupakan nilai tertinggi pada supply tersebut sehingga Bobby mengambil 3 dan memasukkannya kedalam tumpukan mienya.

Nilai tumpukan: 3

Pada hari pertama Bobby hanya ada 1 aksi yaitu pamer ke media sosial. Sehingga keluarkan 3.

1 2 3 4 5

bilangan yang di bold merupakan supply di hari kedua. 4 merupakan nilai tertinggi pada supply tersebut sehingga Bobby mengambil 4 dan memasukkannya kedalam tumpukan mienya.

nilai tumpukan: 3 4

1 2 3 4 5

bilangan yang di bold merupakan supply di hari ketiga. 5 merupakan nilai tertinggi pada supply tersebut sehingga Bobby mengambil 5 dan memasukkannya kedalam tumpukan mienya.

nilai tumpukan: 3 4 5

Pada hari ketiga Bobby ingin makan mie terlebih dahulu sehingga nilai tumpukan menjadi

3 4

Kemudian ia ingin pamer kepada temannya sehingga nilai tertingginya adalah 4.

Constraints
1 ≤ N ≤ 1.000.000
1 ≤ K ≤ 100.000
1 ≤ Nilai Masing2 Mie ≤ 1.000.000
Bobby dan asistennya immortal jadi dapat hidup sampai hari ke 1.000.000

Jawab
---
### file code [disini](https://gitlab.com/Coll_J/praktikum-2-sda/blob/master/praktikum-2-sda/ahha2.c)

1. Scan n dan k, hitung jumalah hari maksimal (nk) `nk = n-k+1;`
2. scan angka sebanyak n sambil pre-compute biar ga tle, setiap kali input langsung diproses dengan cara:

* buat 2 deque, yang pertama untuk tempat sementara(q1), yang kedua untuk deque fix berisi angka yang diambil setiap hari nya
* buat variabel counting = 1 (c), bertambah setiap kali input
* setiap angka yang diambil push ke q1, tetapi jika q1 tidak kosong dan top nya lebih kecil dari angka yang diinput, pop q1 sebelum push dengan angka yang diinput, berikut implementasinya:
```c
while(q1->head!=NULL && q1->head->data<a)
{
    popf(q1);
}
pushf(q1, a, 0);
```
* jika c sudah lebih dari k, dan ukuran q2 lebih kecil dari nk lakukan proses memasukkan ke q2
* jika ukuran q1 lebih kecil dari k, ambil angka paling belakang q1 tanpa pop, lalu push ke q2
* jika tidak, pop belakang q1, ambil angkanya, push ke q2

berikut code nya:
```c
if(c>=k && q2->size<nk)
{
    if(q1->size<k)
    {
        p = end(q1);
        pushf(q2, p, hr);
        hr++;
    }
    else
    {
        p = popb(q1);
        pushf(q2, p, hr);
        hr++;
    }
}
```
3. inisiasi q1 untuk menyimpan nilai maks, buat deque baru q3 untuk menyimpan stok, hari = 0
4. scan hari(h) dan query(q), looping selama nilainya tidak -1, jika q1 tidak kosong maks = top q1, jika kosong maks = 0
* loop sebanyak h-hari, hari menjadi h
* pop belakang q2, simpan nilainya(p), push ke q3. jika p lebih besar dari maks sekarang, maks = p, push p ke q1

berikut code nya:
```c
if(q1->head!=NULL || q1->size!=0) maks = top(q1);
else maks = 0;
nk = h-hr;
hr = h;
while(nk--)
{
    p = popb(q2);
    pushf(q3, p, 0);
    if(p>=maks) 
    {
        pushf(q1, p, 0);
        maks = p;
    }
}
```
5. scan command sebanyak q
6. jika command 1:
* jika q3 kosong print "Stok abis"
* jika tidak kosong, pop depan q3 simpan pada p, jika p == top q1, pop depan q1
* print Nyam
7. jika command 2:
* jika q3 kosong print "Stok abis"
* jika tidak kosong, print top q1
```c
switch(cmd)
{
    case 1:
    if(q3==NULL || q3->size == 0) printf("Stok abis\n");
    else
    {
        p = popf(q3);
        if(p == top(q1)) popf(q1);
        printf("Nyam\n");
    }
    break;
    case 2:
    if(q3==NULL || q3->size == 0) printf("Stok abis\n");
    else
    {
        printf("%d\n", top(q1));
    }
    break;
}
```
##### balik ke [atas](#soal)

## EZTR
---

Soal
---
kita disuruh mengecek apakah setiap bracket ada pasangannya

contoh:
* (((()))) print :v
* ({} print v:

Jawab
---
### file code [disini](https://gitlab.com/Coll_J/praktikum-2-sda/blob/master/praktikum-2-sda/eztr.c)

1. inputan dalam string, setiap kurung buka **(, {, [** push ke dalam stack
2. setiap kurung tutup, cek apakah top di stack adalah pasangannya. jika iya, pop.
```c
if(input[i]=='(' || input[i]=='{' || input[i]=='[')
{
    push(&stacc, input[i]);
}
else if(input[i]==')' || input[i]=='}' || input[i]==']')
{
    if(input[i]==')' && top(stacc)=='(') pop(&stacc);
    else if(input[i]=='}' && top(stacc)=='{') pop(&stacc);
    else if(input[i]==']' && top(stacc)=='[') pop(&stacc);
}
```
3. cek jika stack kosong atau tidak. jika iya, print :v, jika tidak print v:.

##### balik ke [atas](#soal)

## SDM
Soal
---
disuruh nyari tau itu strukdat stack/queue/keduanya

Jawab
---
### file code [disini](https://gitlab.com/Coll_J/praktikum-2-sda/blob/master/praktikum-2-sda/sdm.c)

1. buat 4 flag untuk stack, queue, error, tidak tau.
2. alokasi strukdat
3. kalo command 1 push
4. kalo command 2:
* stack kosong error = 1
* sama kyk head dan tail, stack = 1, queue = 1
* sama kyk head doang, stack = 1, queue = 0
* sama kyk tail doang, stack = 0, queue = 1
* sama kyk head/tail doang, tp queue/stack ga sama(1 atau 0), tidak tahu = 1
* ga sama kyk dua2 nya, tidak tahu = 1

##### balik ke [atas](#soal)

## TDL
Soal
---
nyari jalan

Jawab
---
### file code [disini](https://gitlab.com/Coll_J/praktikum-2-sda/blob/master/praktikum-2-sda/tdl.c)

pake rekursi aja, tp dibikin strukdat. rekursi nya kyk rat in a maze. pake array of stack.
tapi kalo dipikir2 bisa ga sih mas kalo bikin strukdat tapi linker nya 4 arah tp ga stack dong ekwkwkw. maap.

##### balik ke [atas](#soal)
