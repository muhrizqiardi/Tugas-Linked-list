#include <iostream>
using namespace std;

// Pendeklarasian dan inisialisasi linked list
struct Mahasiswa
{
    string nama;
    string NIM;
    Mahasiswa *next;
};
Mahasiswa *head;

void buat() 
{
    head = NULL;
}

// Fungsi untuk menambahkan data mahasiswa
void isi(string nama, string NIM)
{
    Mahasiswa *baru = new Mahasiswa;
    baru->nama = nama;
    baru->NIM = NIM;
    if (head == NULL) 
    {
        head = baru;
        baru->next = NULL;
    } 
    else 
    {
        baru->next = head;
        head = baru;
    } 
}

// Fungsi untuk menghapus data mahasiswa
void hapus(string nama, string NIM)
{
    Mahasiswa *cur;
    Mahasiswa *prev;
    prev = NULL;
    cur = head;

    while (cur != NULL)
    {
        if ( (cur->nama == nama) && (cur->NIM == NIM))
        {
            prev->next = cur->next;
            delete cur;
            break;
        }
        else
        {
            if (cur->next == NULL)
            {
                cout << "\nData requested to be removed could not be found\n";
            }
            prev = cur;
            cur = cur->next;
        }
    }
}

// Fungsi untuk mencetak data mahasiswa
void lihat() 
{
    Mahasiswa *cur;
    cur = head;
    while (cur != NULL)
    {
        cout 
            << "Nama   : " << cur->nama << "\n"
            << "NIM    : " << cur->NIM << "\n\n";
        cur = cur->next;
    }
}

int main()
{
    buat(); // Menginisialisasi linked list
    int menu;
    cout
        << "\n\n\n"
        << "Halo, selamat datang. ";
    while (menu != 4)
    {
        // Print menu
        cout
            << "\nPilih menu di bawah ini: "
            << "\n1. Isi data mahasiswa"
            << "\n2. Hapus data mahasiswa"
            << "\n3. Lihat data mahasiswa"
            << "\n4. Keluar dari program\n>> ";
        cin >> menu;

        // Pilih menu
        string input_nama, input_NIM;
        switch (menu)
        {
        case 1:
            cout << "Isi nama: \n>> ";
            cin >> input_nama;
            cout << "Isi NIM: \n>> ";
            cin >> input_NIM;
            isi(input_nama, input_NIM);
            break;

        case 2:
            cout << "Isi nama: \n>> ";
            cin >> input_nama;
            cout << "Isi NIM: \n>> ";
            cin >> input_NIM;
            hapus(input_nama, input_NIM);
            break;

        case 3:
            cout << "\n\n";
            lihat();
            break;

        case 4:
            cout << "\nSampai Jumpa :)";
            break;

        default:
            cout << "\nIsi dengan benar.";
            break;
        }
    }

    return 0;
}
