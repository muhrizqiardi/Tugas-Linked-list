#include <iostream>
using namespace std;

// Pendeklarasian dan inisialisasi linked list Mahasiswa (berurutan dari yang paling kecil (head) ke yang paling besar (tail))
struct Mahasiswa
{
    string nama;
    int NIM;
    Mahasiswa *next;
};
Mahasiswa *head;

void buat() 
{
    head = NULL;
}

// Fungsi untuk menambahkan data mahasiswa (secara berurutan)
void isi(string nama, int NIM) {
    Mahasiswa *prev = new Mahasiswa;
    Mahasiswa *baru = new Mahasiswa;
    Mahasiswa *cur = new Mahasiswa; 
    baru->nama = nama;
    baru->NIM = NIM;

    if (head == NULL)
    {
        head = baru;
        baru->next = NULL;
    }
    else
    {   
        cout << "\n >masuk1 \n";
        prev = NULL;
        cout << "\n >masuk1.1 \n";
        cur = head;
        cout << "\n >masuk1.2 \n";

        while (cur != NULL && cur->NIM > baru->NIM ) {
            cout << "\n >masuk2 \n";
            prev = cur;
            cur = cur->next;
            // cur = baru;
            // string testtt = (prev == NULL) ? "NULL" : prev->nama;
            // string testtt2 = (cur->next == NULL) ? "NULL" : cur->next->nama;
            // cout << "\n >masuk2.1 "
                // << " " << testtt << " " << cur->nama << " " << testtt2 << " \n";
            // cout << "\n >masuk2.2 \n";
        }
        
        prev->next = baru;
        baru->next = cur->next;

        // if (baru->NIM <= head->NIM) {
        //     baru->next = head;
        //     head = baru;
        // }
        // else
        // {
        //     head->next = baru;
        // }

        // baru->next = head;
        // head = baru;
    }
}

void isi_old(string nama, int NIM)
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
void hapus(string nama, int NIM)
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
    char menu;
    cout
        << "\n\n\n"
        << "Halo, selamat datang. ";
    while (true)
    {
        // Print menu
        cout
            << "\nPilih menu di bawah ini: "
            << "\n1. Isi data mahasiswa"
            << "\n2. Hapus data mahasiswa"
            << "\n3. Lihat data mahasiswa"
            << "\nKetik x untuk keluar dari program\n>> ";
        cin >> menu;

        // Pilih menu
        string input_nama; int input_NIM;
        switch (menu)
        {
        case '1':
            cout << "Isi nama: \n>> ";
            cin >> input_nama;
            cout << "Isi NIM: \n>> ";
            cin >> input_NIM;
            cin.ignore();
            isi(input_nama, input_NIM);
            break;

        case '2':
            cout << "Isi nama: \n>> ";
            cin >> input_nama;
            cout << "Isi NIM: \n>> ";
            cin >> input_NIM;
            hapus(input_nama, input_NIM);
            break;

        case '3':
            cout << "\n\n";
            lihat();
            break;

        case 'x':
        case 'X':
            cout << "\nSampai Jumpa :)";
            break;

        default:
            cout << "\nIsi dengan benar.";
            break;
        }
    }

    return 0;
}
