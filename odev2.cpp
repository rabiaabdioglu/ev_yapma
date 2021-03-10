

    #include <iostream>
    #include <string>
    #include <conio.h>
    #include <stdlib.h>
    #include <Windows.h>

    using namespace std;
    void gotoxy(int x, int y)
        //consolde istenilen konuma gidilmesi için bir fonksiyon
    {
                COORD coord;
                coord.X = x;
                coord.Y = y;

                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
       }
            
        //bir çok yerde kullanılan değişkenleri en dışta tanımlayıp varsayılan değerler verdim. 

            int ev_genislik=0, ev_yukseklik=0, cati_yukseklik=0, x=0, y=0, kapi_x=0, kapi_y=0, kapi_genislik=1,kapi_yukseklik=1,  dongu_say=0;
          
            char kapi_karakter, kat_karakter, cati_karakter;



    
    /// //////////////////////////////////////////////////KAPI//////////////////////////////////////////////////////////////////////////////////////////
    
    class Kapi {
    public:  void kapi_ciz(int kapi_x, int kapi_y,int x,int y,int ev_genislik,int ev_yukseklik,int cati_yukseklik, char kapi_karakter) {

        //kapi yukseklik ve genislik için rastgele değer ataması 
                kapi_yukseklik = 2 + rand() % (ev_yukseklik - 3);
                kapi_genislik = 2 + rand() % (ev_genislik - 3);
                
                boolean tasma = true;

                // atanan rastgele değer eğer kat sınırları dışına taşıyorsa tekrar rastgele bir değer atanır.
                while (y + ev_genislik < kapi_y + kapi_genislik || ev_yukseklik + x + cati_yukseklik < kapi_x + kapi_yukseklik)
                {        
                           kapi_yukseklik =2+rand() % (ev_yukseklik-3);
                           kapi_genislik =2+ rand() % (ev_genislik-3);
                 }

                // kat dışına taşmayan bir değer alındıktan sonra kapı içiçe for döngüsüyle yazdırılır
                for (int i =0; i < kapi_genislik; i++) {
                           for (int m = 0; m < kapi_yukseklik; m++) {
                                gotoxy(kapi_y+i, kapi_x+ m);
                                cout << kapi_karakter;       }
                   
                      cout <<"\n";    }

     }
     };


    /// //////////////////////////////////////////////////CATI//////////////////////////////////////////////////////////////////////////////////////////



    class Cati {

    public:  void cati_ciz(int cati_yukseklik, int ev_genislik, int y,char cati_karakter,int x) {

        int cati_genislik = ev_genislik;
        int yedek_yukseklik = cati_yukseklik;
        for (int i = 0, j = 0; i < cati_yukseklik; i++) {
            //çatı yüksekliği kadar  döngü 
            //if içinde dikdörtgeni, else içinde üstteki üçgeni çizecek


                    // istenilen çatı yüksekliğini ev genişliğini dikkate alarak uzunlamasına yapmaya çalıştım..
                    if (yedek_yukseklik > (ev_genislik / 2) + 1) {
                            gotoxy(y - 1, x + cati_yukseklik - 1 - i);
                            for (int k = 0; k <= cati_genislik; k++)
                                cout << cati_karakter;
                            yedek_yukseklik--;

                    }
                    // catinin en üst üçgen kısmı için 
                    else {

                            gotoxy(y + j - 1, x + cati_yukseklik - i - 1);
                            for (int k = 0; k <= cati_genislik; k++)   cout << cati_karakter;
                             j++;
                            cati_genislik -= 2;
                            Sleep(100);
                    }

           cout << "\n";
        }
    }};


    /// //////////////////////////////////////////////////KAT//////////////////////////////////////////////////////////////////////////////////////////


    class Kat {
    public:   void kat_ciz(int ev_yukseklik, int ev_genislik,int y,int x,int cati_yukseklik, char kat_karakter) {
        //kat çizerken

        //sağ ve sol duvarları çizen bir döngü 
      
        for (int i = 0; i <=ev_yukseklik; i++) {

                  for (int m = 0; m < y + 1; m++)  	cout << " ";//Yan bosluklar için döngü

                        gotoxy(y-1, x+ cati_yukseklik + i);
                        cout << kat_karakter <<endl;
                        gotoxy(y+ ev_genislik-1, x  + cati_yukseklik+ i);
                        cout << kat_karakter << endl;  }

        //üst ve alt duvarları çizen döngü 
        for (int i = 0; i <=ev_genislik; i++) {
                        gotoxy(y+i-1,x + cati_yukseklik);
                        cout << kat_karakter;
                        gotoxy(y +i-1,x+ ev_yukseklik+cati_yukseklik);
                        cout << kat_karakter;     }  
    }


        //her iki döngüde gotoxy kullanarak istenilen karakteri yazdırdı.
     };


    /// //////////////////////////////////////////////////EV//////////////////////////////////////////////////////////////////////////////////////////



    class Ev { //Ev sınıfı ve diger sınıfların fonksiyonlarını kullanabilmek için kapi çati ve kat  nesneleri
        Kapi kapi;
        Cati cati;
        Kat kat;

  
    public: void ev_ciz() {
        system("cls"); // eğer başa dönerse  diye  consol ekranındaki verileri siler .


                    if (dongu_say == 0) {
                        //Kullanıcının sonradan değiştirebileceği özellikler için dışarıda tanımlı bir dongu değişkeni tanımladım
                        //ev ciz fonksiyonu tekrar çağırıldığı zaman kullanıcıdan tekrar değer almasını önlemek  ve varolan değişkenleri bozmadan yenilemek amacıyla
                
                        cout << "Genislik:";
                        cin >> ev_genislik;
                        cout << "Yukseklik:";
                        cin >> ev_yukseklik;
                        cout << "Cati yukseklik:";
                        cin >> cati_yukseklik;
                        cout << "x:";
                        cin >> x;
                        cout << "y:";
                        cin >> y;
   
                     kapi_x=x+cati_yukseklik+(ev_yukseklik/2), kapi_y=y+(ev_genislik/2);

                    //Sonradan değişebilen kapı koordinatlarına varsayılan bir değer atadım.

                     kapi_karakter = '#', kat_karakter = 219, cati_karakter = '*';       
                    } 


                    int sayac = 0; // hata mesajı vermek için 

                    system("cls");//Console temizlendi




                //istenilen konuma gitmek için gotox() den farklı bir yöntem kullandım
        for (int p = 0; p <=x; p++) { 

               for (int m =0; m < y; m++) cout << " ";
               cout << "\n";  }



                
                    /// Ev çizimi için diğer classlardaki fonksiyonlar
                    // oluşturduğumuz nesnelerin fonksiyon çağrısı

                            cati.cati_ciz(cati_yukseklik, ev_genislik, y,cati_karakter,x);
                            kat.kat_ciz(ev_yukseklik, ev_genislik, y, x, cati_yukseklik,kat_karakter);
                            kapi.kapi_ciz(kapi_x, kapi_y, x, y, ev_genislik, ev_yukseklik, cati_yukseklik,kapi_karakter);


                    // Değiştirilmesi istenen özellikler  için bir menu tasarımı
     
                    int menu_secim;
                    char secim;

                    // menünün ev in konumları dışında bir yerde olması için
                    gotoxy(5,x + cati_yukseklik + ev_yukseklik + 10);

                    cout << "\n\n\n\n\nDegistirmek Istediginiz Bir Sey Var Mı?(E/H)\n";
                    cin >> secim;
                    cout << endl;

                   if (secim == 'E' || secim=='e') {

                        cout << "\n1-Karakter Degis:";
                        cout << "\n2-Kapi Koordinat Degis:";
                        cout << "\n3-Bastan Basla:";
                        cin >> menu_secim;


                        switch (menu_secim) {
                               case 1://Karakter Degisimi 
                                                menu_secim = 0;
            
                                                cout << "\n\nDegistirmek Istediginiz Ozelligi Seciniz:\n";
                                                cout << "1-Cati:\n";
                                                cout << "2-Kapi:\n";
                                                cout << "3-Kat:\n";
                                                cin >> menu_secim;
                                                cout << "Karakter Giriniz\n";

                                                //istenilenin dışında girilen menu değerleri için doğru girilene kadar dönen while
                                                while (menu_secim != 1 && menu_secim != 2 && menu_secim != 3) {

                                                    cout << "Yanlis Secim Yaptiniz. Tekrar Deneyiniz.\n"; cin >> menu_secim;
                                                }
                                                //Secime göre evin parçalarından birinin karakteri değişir..

                                                if (menu_secim == 1) { cin >> cati_karakter;  }
                                                else if (menu_secim == 2) { cin >> kapi_karakter;  }
                                                else if (menu_secim == 3) { cin >> kat_karakter;  }
                                                dongu_say = 1;
                                ; break;



                                case 2:

                                                do {//Kapi koordinat degisimi

                                                    if (sayac != 0)  cout << "\n\nGirdiginiz kapi koordinatlari, evin koordinatinin disinda. \n Lutfen tekrar giriniz.\n";
                                                    
                                                    //kapı koordinatı için sınır değerler

                                                    cout << "\nkapi x koordinati icin " << x + cati_yukseklik << " - " << x + cati_yukseklik + ev_yukseklik << " arasında bir deger giriniz:";
                                                    cin >> kapi_x;

                                                    cout << "\nkapi y koordinati icin " << y << " - " << y + ev_genislik << " arasında bir deger giriniz:";
                                                    cin >> kapi_y;

                                                    sayac++;// ilk seferinde doğru girilirse döngüden çıkacak
                                                    // yanlış girilirse hata mesajını yukarıdaki if ile göstermiş olur
                                                }
                                                

                                                // girilen koordinat değerleri uygun aralıkta ise döngüden çıkar
                                               while (kapi_x< x + cati_yukseklik || kapi_x > x + cati_yukseklik + ev_yukseklik || kapi_y<y || kapi_y> ev_genislik + y);
                                                dongu_say = 1;
                                ; break;


                                // başa dönülünce kullanıcıdan ilk alınan değerler tekrar alınabilsin diye dongu sayı 0 yapıyor.
                                // her şey sıfırlanmış gibi olduğundan  tekrardan veri alınabiliecek

                                case 3: dongu_say = 0; ev_ciz(); ; break;// basa dönmek için fonksiyonu içinde tekrar çağırıyorum
                        }
                    }

                   // eğer kullanıcı seçimini Hayır yaparsa  iyi günler mesajıyla program sonlanır.
                   else if (secim == 'H'|| secim=='h') {
                        cout << "\n\nIyi gunler\n\n\n";
                        Sleep(100);
                        exit(0);  }
                  
                   else {
                      
                        cout << "\n\nYanlis karakter girdiniz..\n\n";
                        dongu_say = 1;
                        Sleep(500);
                        ev_ciz();  }



                    // Seçimler sonunda ev çizimini baştan yapıp menuyu gösteriyor
                   ev_ciz();

    }

     

    };






    int main()
    {
        Ev ev;
        ev.ev_ciz(); // menu de sonradan degistirilebildiği için varsayılan karakterler ile ev ciz fonksiyonunu çağırdım.

        system("PAUSE");    return(0);
    }
