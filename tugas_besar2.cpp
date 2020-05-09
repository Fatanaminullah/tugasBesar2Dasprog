#include <iostream>
#include<string> 
#include <vector>

using namespace std;

std::vector<string> dataMahasiswa;

void view() {
	cout << "                           LIHAT DATA                             " << endl;
	cout << "                                                                  " << endl;
	cout << "         | No  | NIM - Nama                            |          " << endl;
	cout << "         ===============================================          " << endl;
	if (dataMahasiswa.size() == 0) {
	cout << "         |                                             |          " << endl;
	cout << "         |                                             |          " << endl;
	cout << "         |                                             |          " << endl;
	cout << "         |   Data tidak tersedia, silahkan ke menu     |          " << endl;
	cout << "         |    tambah data untuk menambahkan data!      |          " << endl;
	cout << "         |                                             |          " << endl;
	cout << "         |                                             |          " << endl;
	cout << "         |                                             |          " << endl;
	cout << "         -----------------------------------------------          " << endl;
	} else {
		for (int i = 0; i < dataMahasiswa.size(); i++) {
			cout << "         | " << i+1 << "   | " << dataMahasiswa[i] << endl; 
		}	
	}
}
void input() {
	string nim, namaDepan, namaBelakang;
	cout << "                          TAMBAH DATA                             " << endl;
	cout << "                                                                  " << endl;
	cout << "   Masukkan NIM : ";
	cin >> nim;
	cout << "   Masukkan Nama Depan: ";
	cin >> namaDepan;
	cout << "   Masukkan Nama Belakang: ";
	cin >> namaBelakang;
	dataMahasiswa.push_back(nim + " - " + namaDepan + " " + namaBelakang);
	cout << "                                                                  " << endl;
	cout << " Data berhasil dimasukkan!                                        " << endl;
	cout << " Silahkan ke menu 1 (lihat data) untuk memastikan data yang baru  " << endl;
	cout << " dimasukkan!                                                      " << endl;
}
void update() {
	int index;
	if (dataMahasiswa.size() != 0) {
		cout << "                          PERBARUI DATA                           " << endl;
		cout << "                                                                  " << endl;
		view();
		cout << "                                                                  " << endl;
		cout << " Masukkan no. data yang ingin diperbarui : ";
		cin >> index;
		cout << " Data yang akan diperbarui adalah : " << dataMahasiswa[index - 1] << endl;
		string nim, namaDepan, namaBelakang;
		cout << "                                                                  " << endl;
		cout << "   Masukkan NIM : ";
		cin >> nim;
		cout << "   Masukkan Nama Depan: ";
		cin >> namaDepan;
		cout << "   Masukkan Nama Belakang: ";
		cin >> namaBelakang;
		dataMahasiswa[index - 1] = nim + " - " + namaDepan + " " + namaBelakang;
		cout << " Data berhasil diperbarui!                                        " << endl;
		cout << " Silahkan ke menu 1 (lihat data) untuk memastikan data yang baru  " << endl;
		cout << " diperbarui!                                                      " << endl;	
	} else {
		cout << " Data masih kosong, silahkan ke menu 2 (tambah data) untuk        " << endl;
		cout << " menambahkan data!                                                " << endl;
	}
}
void deleteData() {
	int index;
	vector<string>::iterator it;
	if (dataMahasiswa.size() != 0) {
		cout << "                          HAPUS DATA                              " << endl;
		cout << "                                                                  " << endl;
		view();
		cout << "                                                                  " << endl;
		cout << " Masukkan no. data yang ingin dihapus : ";
		cin >> index;
		cout << " Data yang akan dihapus adalah : " << dataMahasiswa[index - 1] << endl;
		it = dataMahasiswa.begin() + (index - 1);
		dataMahasiswa.erase(it);
		cout << " Data berhasil dihapus!                                           " << endl;
		cout << " Silahkan ke menu 1 (lihat data) untuk memastikan data yang baru  " << endl;
		cout << " dihapus!                                                         " << endl;	
	} else {
		cout << " Data masih kosong, silahkan ke menu 2 (tambah data) untuk        " << endl;
		cout << " menambahkan data!                                                " << endl;
	}
	
}

int main() {
	int pilihMenu, pilihLagi;
	menuUtama:
	cout << endl;
	cout << "          Selamat Datang di Aplikasi Pendataan Mahasiswa!         " << endl;
	cout << "                 Silahkan pilih menu dibawah ini                  " << endl;
	cout << "                                                                  " << endl;
	cout << "                           1. Lihat Data                          " << endl;
	cout << "                           2. Tambah Data                         " << endl;
	cout << "                           3. Perbarui Data                       " << endl;
	cout << "                           4. Hapus Data                          " << endl;
	cout << "                           5. Keluar                              " << endl;
	cout << "    Masukkan pilihan : ";
	cin >> pilihMenu;
	
	switch(pilihMenu) {
		case 1:
			view();
			break;
		case 2:
			input();
			break;
		case 3:
			update();
			break;
		case 4:
			deleteData();
			break;
		case 5:
			cout << "                                                                  " << endl;
			cout << "           Terimakasih, Sampai jumpa kembali! :)                  " << endl; 
			return 0;
			break;
		default:
			cout << " Oops... menu " << pilihMenu << " tidak tersedia, silahkan pilih kembali! " << endl;
			goto menuUtama;
	}
	cout << "                                                                  " << endl; 
	cout << "                                                                  " << endl; 
	cout << "                  Kembali ke menu utama?                          " << endl;
	cout << "                                                                  " << endl; 
	cout << "                        1. Ya                                     " << endl;
	cout << "                        2. Tidak                                  " << endl;
	cout << "    Masukkan pilihan : ";
	cin >> pilihLagi;
	switch(pilihLagi) {
		case 1:
			goto menuUtama;
		case 2:
			cout << "                                                                  " << endl;
			cout << "           Terimakasih, Sampai jumpa kembali! :)                  " << endl; 
			return 0;
			break;
		default:
			cout << "                                                                  " << endl;
			cout << "            Mohon maaf terjadi kesalahan teknis                   " << endl;
			
	}
	
}
