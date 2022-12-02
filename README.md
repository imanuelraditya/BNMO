# Tugas Besar ── BNMO
## IF2111 Algoritma dan Struktur Data STI

> Program membantu Indra dan Doni untuk memprogram 
> robot video game console kesayangan mereka

Dibuat oleh Kelompok 08 K02

- Michael Sihotang (18221054)
- Muhammad Dastin Fauzi (18221062)
- Imanuel Raditya (18221112)
- Miralistya Cahya Fatimah (18221116)
- Seren Elizabeth Siahaan (18221160)

## Deskripsi Singkat Laporan
BNMO (dibaca: Binomo) adalah sebuah robot video game console yang dimiliki oleh Indra dan Doni. Dua bulan yang lalu, ia mengalami kerusakan dan telah berhasil diperbaiki. Sayangnya, setelah diperbaiki ia justru mendapatkan lebih banyak bug dalam sistemnya. Oleh karena itu, Indra dan Doni mencari programmer lain yang lebih handal untuk ulang memprogram robot video game console kesayangannya. Buatlah sebuah permainan berbasis CLI (command-line interface). Sistem ini dibuat dalam bahasa C dengan menggunakan struktur data yang sudah kalian pelajari di mata kuliah ini. 

## Cara Kompilasi Program
> gcc main.c source/command/console.c source/ADT/queue/queue.c source/ADT/queuedinerdash/queue.c source/ADT/stack/stack.c source/ADT/map/map.c source/ADT/mesinkarakter/mesinkarakter.c source/ADT/mesinkata/mesinkata.c source/ADT/array/arraydin.c source/ADT/array/arraymap.c source/ADT/listdp/listdp.c -o a

## Configuration File yang Tersedia
> data/config.txt

## Save File yang Tersedia
> data/save.txt

> data/save2.txt

> data/save3.txt

## Struktur Program
```
.
├── a.exe
├── README.md
├── main.c				     # main program
├── data
│   ├─── BannerRNG.txt 			    
│   ├─── bnmo.txt 			     
│   ├─── config.txt		
│   ├─── DaftarKataHangman.txt	
│   ├─── DinerDash.txt
│   ├─── drivermesinkata.txt		     
│   ├─── hangman.txt		
│   ├─── save.txt			     
│   ├─── save2.txt			     
│   ├─── save3.txt		     
│   ├─── snakeonmeteor.txt			     
│   └─── towerofhanoi.txt	                          
│ 
├── source
│   ├─── boolean.h
│   ├─── ADT				     # folder berisikan main
│   │      ├─── array
│   │      │       ├─── arraydin.h
│   │      │       ├─── arraydin.c
│   │      │       ├─── driver_arraydin.c
│   │      │       ├─── arraymap.h
│   │      │       ├─── arraymap.c
│   │      │       └─── driver_arraymap.c
│   │      │
│   │      ├─── map
│   │      │       ├─── map.h
│   │      │       ├─── map.c
│   │      │       └─── driver_map.c
│   │      │
│   │      ├─── mesinkarakter
│   │      │       ├─── mesinkarakter.h
│   │      │       ├─── mesinkarakter.c
│   │      │       └─── driver_mesinkar.c
│   │      │
│   │      ├─── mesinkata
│   │      │       ├─── mesinkata.h
│   │      │       ├─── mesinkata.c
│   │      │       └─── driver_mesinkar.c
│   │      │
│   │      ├─── queue
│   │      │       ├─── queue.h
│   │      │       ├─── queue.c
│   │      │       └─── driver_queue.c
│   │      │
│   │      ├─── queuedinerdash
│   │      │       ├─── queue.h
│   │      │       ├─── queue.c
│   │      │       └─── driver_queue.c
│   │      │
│   │      └─── stack
│   │      │       ├─── stack.h
│   │      │       ├─── stack.c
│   │      │       └─── driver_stack.c
│   │      └─── listdp
│   │              ├─── listdp.h
│   │              ├─── listdp.c
│   │              └─── driver_listdp.c
│   │
│   └─── command
│          ├─── console.h
│          └─── console.c
│
│
└── docs 
     ├─── Spesifikasi Tugas Besar 1 IF2111 2022_2023.docx
     ├─── IF2111_TB1_02_08.pdf
     ├─── Form Asistensi Tugas Besar_TB1_02_08.pdf
     ├─── Spesifikasi Tugas Besar 2 IF2111 2022_2023.docx
     ├─── IF2111_TB2_02_08.pdf
     └─── Form Asistensi Tugas Besar_TB2_02_08.pdf
 ```
