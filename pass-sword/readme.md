C dilinde şifre uygulamaları programı.

Özellikler :
Şifre oluşturma (dosyalı/dosyasız)
Brute force simulasyonu
Şifre güvenlik kontrolu
Şifreleme (Sezar şifrelemesi)

Notlar :
Brute force'u dosya yükleyerek çalıştırmak için text'inizi password klasöründe mypasswords ismini (mypasswords.txt) vererek çalıştırın.

Derleme :
Derlemek için compile.bat 'i çalıştırın veya build içindeki derlenmiş exeyi kullanın.
Manuel derleme için >> gcc src/main.c src/utilities/bruteforce.c src/utilities/mainlib.c src/utilities/sifrekontrol.c src/utilities/sifreleme.c src/utilities/sifreolustur.c -I include -o exe-ismi

   