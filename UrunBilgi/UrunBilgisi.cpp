#include <iostream>
#include <string>


using namespace std;

class Urun {
private:
	int birimFiyat;
	int urunSayisi;
	int urunId;
public:
	void BilgiAl() {
		cout << "Urun bilgilerini giriniz:" << endl;
		cout << "Urun id:";
		cin >> urunId;
		cout << "Birim fiyat:";
		cin >> birimFiyat;
		cout << "Urun sayisi:";
		cin >> urunSayisi;
	}
	void BilgiVer() {
		cout << "***Urun Bilgileri***" << endl;
		cout << "Urun id:" << urunId;
		cout << " Birim fiyat:" << birimFiyat;
		cout << "Urun sayisi:" << urunSayisi;

	}

	int GetBirimFiyat() const {
		return birimFiyat;
	}

	int GetUrunSayisi() const {

		return urunSayisi;
	}

	int GetUrunId() const {
		return urunId;
	}

};
class Uretim : public Urun {
private:
	int uretimTarihi;
	int uretimParti;
	int uretimId;
public:
	void BilgiAl() {
		cout << "Uretim bilgilerini giriniz:" << endl;
		cout << "Uretim Id:";
		cin >> uretimId;
		cout << "Uretim Parti sayisi:";
		cin >> uretimParti;
		cout << "Uretim tarihi:";
		cin >> uretimTarihi;
	}
	void BilgiVer() {
		cout << "***Uretim Bilgileri***" << endl;
		cout << "Uretim id:" << uretimId;
		cout << "Uretim parti sayisi:" << uretimParti;
		cout << "Uretim tarihi:" << uretimTarihi;

	}
	int GetUretimId() const {

		return uretimId;
	}

	int GetUretimParti() const {
		return uretimParti;
	}

	int GetUretimTarihi() const {

		return uretimTarihi;
	}

};
class Satis : public Urun {
private:
	int satisFiyat;
	int satisSayi;
	int satisId;
public:
	void BilgiAl() {
		cout << "Satis bilgilerini giriniz:";
		cout << "Satis id:";
		cin >> satisId;
		cout << "Satýs sayisi:";
		cin >> satisSayi;
		cout << "Satis fiyati:";
		cin >> satisFiyat;
	}
	void BilgiVer() {
		cout << "***Satis Bilgileri***" << endl;
		cout << "Satis id:" << satisId;
		cout << "Satis sayisi:" << satisSayi;
		cout << "Satis fiyati:" << satisFiyat;

	}
	int  GetSatisId() const {

		return satisId;
	}

	int GetSatisSayi() const {
		return satisSayi;
	}

	int GetSatisFiyat() const {
		return satisFiyat;
	}


};

class MaliDurum : public Urun {
private:
	int uretimSayisi;
	int maliyet;
	int kazanc;
public:
	void hesapla(const Urun& urun, const Uretim& uretim, const Satis& satis) {
		uretimSayisi = uretim.GetUretimParti() * urun.GetUrunSayisi();
		maliyet = urun.GetUrunSayisi() * urun.GetBirimFiyat();
		kazanc = satis.GetSatisSayi() * satis.GetSatisFiyat();
	}

	void BilgiVer() {
		cout << "***Mali Durum Bilgileri***";
		cout << "Toplam uretim:" << uretimSayisi << "adet";
		cout << "Toplam maliyet:" << maliyet << "tl";
		cout << "Toplam kazanc:" << kazanc << "tl";
	}
};

int main() {
	Urun urun;
	Uretim uretim;
	Satis satis;
	MaliDurum maliDurum;
	urun.BilgiAl();
	uretim.BilgiAl();
	satis.BilgiAl();
	maliDurum.hesapla(urun, uretim, satis);

	urun.BilgiVer();
	uretim.BilgiVer();
	satis.BilgiVer();
	maliDurum.BilgiVer();

	return 0;

}