This project has been created as part of the 42 curriculum by musipit.*

# ft_printf

## Tanım

ft_printf projesinin amacı, C standart kütüphanesinde bulunan `printf()` fonksiyonunu
yeniden yazmaktır. Bu proje, biçimlendirilmiş çıktı üretiminin temel mantığını
anlamayı ve C dilinde değişken sayıda argüman alan fonksiyonların nasıl çalıştığını öğrenmeyi hedefler.

Bu implementasyon, orijinal `printf` fonksiyonunun davranışını taklit eder;
ancak buffer yönetimi uygulanmaz. Fonksiyonun çıktısı ve dönüş değeri,
standart `printf` fonksiyonu ile karşılaştırılarak test edilmiştir.

## İçerik

#### Kullanılan Yardımcı Fonksiyonlar

* ft_putchar    - Tek bir karakter yazdırmak için kullanılır.
* ft_putstr     - Bir karakter dizisi yazdırmak için kullanılır.
* ft_putdec     - Ondalık sayıları yazdırmak içi kullanılır.
* ft_puthex     - Onaltılık sayı sistemindeki sayıları yazdırmak için kullanılır.

## Kullanım

#### Makefile Kurallar (Targets)

* make veya make all - libft.a kütüphanesini derleyin
* make clean - Tüm nesne dosyalarını .o temizleyin
* make fclean - Tüm nesne dosyalarını .o ve libft.a kütüphanesini temizleyin


## Kaynakça

* Linux man-pages
* GNU libc printf documentation
* ft_printf Subject(PDF)
* cppreference – printf
* ChatGPT: bazı kodların kullanım çeşitliliğini öğrenmek için