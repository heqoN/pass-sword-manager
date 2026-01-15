C dilinde şifre uygulamaları programı.

Özellikler : Şifre oluşturma (dosyalı/dosyasız) Brute force simulasyonu Şifre güvenlik kontrolu Şifreleme (Sezar şifrelemesi)

Notlar : Brute force'u dosya yükleyerek çalıştırmak için text'inizi password klasöründe mypasswords ismini (mypasswords.txt) vererek çalıştırın. Şifre oluşturma ile oluşturulan şifreler password klasöründe passwords.txt dosyasında saklanır.

Derleme : Derlemek için compile.bat 'i çalıştırın. Manuel derleme için >> gcc src/main.c src/utilities/bruteforce.c src/utilities/mainlib.c src/utilities/sifrekontrol.c src/utilities/sifreleme.c src/utilities/sifreolustur.c -I include -o exe-ismi

