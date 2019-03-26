# Praktikum-2-SD
Demo Praktikum 2 StrukDat

# SOAL

1. [AHHA](#ahha)
4. [TDL](#tdl)

## AHHA 
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
### Source Code AHHA [di sini](https://github.com/sheinnayendri/Praktikum-2-SD/blob/master/ahha4.c)

1. Scan n dan k, yaitu banyak jenis mie, serta banyak pilihan mie untuk setiap harinya.
2. Scan angka sebanyak n sekaligus pre-compute untuk proses mencari mie dengan nilai tertinggi dengan teknik sliding window sejauh k.
* Buat 2 deque, yang pertama sebagai tempat penampungan value yang diinput sementara (Qi), sedangkan deque yang kedua (st) sebagai tempat penampungan mie yang diambil setiap harinya.*
* Terdapat variabel c untuk menghitung banyaknya input yang dilakukan agar dpat membatasi sampai kapan proses mengambil terus berlanjut.
* Setiap angka yang diinputkan, di push back ke Qi, tetapi jika Qi tidak kosong, maka akan dicek apakah value end dari deque lebih kecil dari angka yang baru saja diinputkan atau tidak. Jika iya, maka akan terus di pop back hingga value yang lebih besar dari inputan baru / sampai deque habis. 
* Jika c sudah lebih dari k, dan ukuran st lebih kecil dari jumlah hari maksimum (n-k+1), memasukkan front dari Qi ke st.
* Jika ukuran Qi lebih kecil dari k, maka push back value front dari Qi ke st.
* Jika tidak, maka push back value front dari Qi ke st, kemudian pop front Qi.
3. Scan hari(h) dan query(u), dan looping terus hingga h=-1 dan u=-1. Jika stm (deque baru, untuk menyimpan stok mie maksimum sampai pada hari tertentu) tidak kosong, maka mx = front dari stm. Jika kosong, mx = 0.
* Looping sebanyak h-hari, untuk ambil stok dari st sesuai hari inputan, kemudian hari menjadi h.
* Setiap looping, jika front st lebih besar daripada mx, maka nilai mx diganti menjadi front st yang baru, dan value front st dipush back ke stm.
4. Scan command sebanyak u.
5. Jika command 1:
* Jika st2 kosong print "Stok abis".
* Jika tidak kosong, pop back st2, simpan pada m, jika m == back stm, pop back stm.
* Cetak "Nyam".
6. Jika command 2:
* Jika st2 kosong print "Stok abis".
* Jika tidak kosong, print back stm.


## TDL
## (Thanus Dalam Labirin)
Soal
---
Karena trailer endgame yang sudah keluar kemarin (lihat : Trailer kekalahan Thanus ),  Thanus sangatlah ketakutan apabila dia kalah. Oleh karena itu Ia lari ke sebuah labirin sebesar N x N agar ia tidak bisa dikejar oleh para Evenjer. Dengan kekuatan batu pikiran, dia bisa mencari tahu apakah ia bisa melewati labirin tersebut. Posisi Thanus sekarang adalah di pojok kiri bawah labirin, dan jalan keluar labirin tersebut ada pada pojok kanan atas labirin. Karena Thanus masih jantungan hasil serangan dewa petir Gundala, ia hanya bisa bergerak ke 4 arah, atas, kanan, bawah, kiri. Bantulah Thanus mencari tahu apakah ia bisa melewati jalan tersebut.

Clue bisa menggunakan stack atau queue untuk menampung koordinat.

Input Format
Input pertama baris pertama adalah N yang menyatakan besar labirin

Dan N-baris selanjutnya menotasikan apakah koordinat tersebut bisa dilewati, 0 berarti tidak bisa dilewati, 1 berarti bisa dilewati

(x,y) 0 berarti tidak bisa dilewati

(x,y) 1 berati bisa dilewati

Output Format
Apabila ada jalan, maka outputkan "Ada jalan yaa Thanus"

Apabila tidak ada jalan maka outputkan "Buntu yaa Thanus"

Setiap output diakhiri dengan "\n"

Sample Input 1
4
0 0 1 1
0 0 1 0
0 0 1 0
1 1 1 0
 

Sample Output 1
Ada jalan yaa Thanus

 

Sample Input 2
4
0 0 0 1
0 0 1 0
0 0 1 0
1 1 1 0
 

Sample Output 2
Buntu yaa Thanus

 

Explanation
Pada sample input 1, diketahui bahwa labirinnya sebesar 4

dan terdiri atas

0 0 1 1

0 0 1 0

0 0 1 0

1 1 1 0
Karena ada jalan yang bisa dilewati mulai dari start-nya yang ada pada labirin pojok kiri bawah, 
hingga finishnya pada pojok kanan atas, dengan Thanus hanya boleh bergerak ke 4 arah, maka ada jalan.

 

Pada sample input 2, diketahui bahwa tidak ada jalan yang bisa menuju ke finish karena terpotong pada koordinat (2,3)

Constraints
2 ≤ N ≤ 300
0 ≤ arr[x][y] ≤ 1

Jawab
---
### Source Code TDL [di sini](https://github.com/sheinnayendri/Praktikum-2-SD/blob/master/tdl2.c)

Dikarenakan ini praktikum mengenai Struktur Data, sehingga proses DFS (Depth First Search) dilakukan secara rekursif melalui stack. Ide dari penyelesaian soal ini adalah dengan memasukkan (push) koordinat yang dilalui ke dalam sebuah stack. Stack pada awalnya diisi koordinat start (n-1,0). Selama stack masih berisi, top value dari stack akan dicek untuk bergerak ke 4 koordinat di sekitarnya, yaitu (x+1,y), (x-1,y), (x,y+1), serta (x,y-1), dan kemudian dipop. Jika koordinat-koordinat tersebut bernilai 1 dan masih dalam batas range labirin, maka koordinat yang baru tersebut akan dipush ke stack. Dan proses akan berlangsung terus. Setiap mengambil top value dari stack, jika ditemukan koordinat finish (0,n-1), maka variabel untuk cek (default diset 0), dibuat bernilai 1, dan break dari looping.

Setelah pemanggilan fungsi ceklabirin, akan dicek nilai variabel cek=1 atau tidak. Jika bernilai 1, maka labirin dapat dilalui, cetak "Ada jalan yaa Thanus", sebaliknya cetak "Buntu yaa Thanus".
