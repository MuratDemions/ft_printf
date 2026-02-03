*This project has been created as part of the 42 curriculum by musipit.*

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
* ft_putnbr     - Ondalık sayıları yazdırmak içi kullanılır.
* ft_hex        - Onaltılık sayı sistemindeki sayıları yazdırmak için kullanılır.
* checker       - Gönderilen argümanın flaglarim arasında olup olmadığını kontrol edemek için kullanılır.
* f_stringer_and_len_returner   - Flaglarıma göre yönlendirme yapmam için kullanılır.

## Kullanım

#### Makefile Kurallar (Targets)

* make veya make all - ft_printf.a kütüphanesini derleyin
* make clean - Tüm nesne dosyalarını .o temizleyin
* make fclean - Tüm nesne dosyalarını .o ve ft_printf.a kütüphanesini temizleyin
* make re - make ile derlenen ft_printf.a kütüphanesini ve tüm nesne dosyalarını siler ve tekrardan derler

## Kaynakça

* Linux man-pages
* GNU libc printf documentation
* ft_printf Subject(PDF)
* cppreference – printf
* ChatGPT: bazı kodların kullanım çeşitliliğini öğrenmek için