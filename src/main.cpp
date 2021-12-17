#include <iostream>
#include <conio.h>
using namespace std;

struct queue
{
    int data[5];
    int tail, head;
};
queue antrian;

void inisialisasi()
{
    antrian.head = 0;
    antrian.tail = -1;
}
bool isEmpty()
{
    if (antrian.tail < antrian.head)
        return true;
    else
        return false;
}

bool isFull()
{
    if (antrian.tail == 4)
        return true;
    else
        return false;
}

void Enqueue()
{
    if (isFull())
        cout << "Antrian Sudah PENUH !" << endl;
    else
    {
        int bil;
        cout << "masukan sebuah bilangan : ";
        cin >> bil;
        antrian.tail++;
        antrian.data[antrian.tail] = bil;
        cout << "Bilangan " << bil << " terletak pada index ke -  " << antrian.tail << endl;
    }
}

void Dequeque()
{
    if (isEmpty())
        cout << "Antrian masih KOSONG " << endl;
    else
    {
        cout << "Bilangan yang keluar dari antrian : " << antrian.data[antrian.head] << endl;
        for (int indeks = 1; indeks <= antrian.tail; indeks++)
            antrian.data[indeks - 1] = antrian.data[indeks];
        antrian.tail--;
        cout << "Antrian telah dirubah.." << endl;
    }
}

void print()
{
    if (isEmpty())
        cout << "antrian masih kosong !" << endl;
    else
    {
        cout << "jumlah data pada antrian : " << antrian.tail + 1 << endl;
        for (int indeks = antrian.head; indeks <= antrian.tail; indeks++)
            cout << antrian.data[indeks] << " ";
        cout << endl;
    }
}

void Clear()
{
    if (isEmpty())
        cout << "Antrian masih KOSONG!" << endl;
    else
    {
        char hapus;
        cout << "Apakah anda yakin hapus antrian[y/t]? : ";
        cin >> hapus;
        if (hapus == 'y' || hapus == 'Y')
        {
            antrian.tail = -1;
            cout << "antrian berhasil di hapus" << endl;
        }
        else
            cout << "hapus data dibatalkan" << endl;
    }
}
int main()
{

    inisialisasi();
    int pilihan;
    do
    {

        system("cls");
        cout << "1.Enqueue" << endl;
        cout << "2.Dequeue" << endl;
        cout << "3.print" << endl;
        cout << "4.Clear" << endl;
        cout << "5.Keluar" << endl;
        cout << "================" << endl;
        cout << "pilihan menu : ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
        {
            Enqueue();
            break;
        }
        case 2:
        {
            Dequeque();
            break;
        }
        case 3:
        {
            print();
            break;
        }
        case 4:
        {
            Clear();
            break;
        }
        case 5:
        {
            cout << endl
                 << " Terima kasih telah menggunakan sistem ini ";
            cout << endl
                 << "Tekan Enter untuk keluar";
            break;
        }
        default:
        {
            cout << "tidak ada dalam pilihan !!" << endl;
        }
        }
        getch();
    } while (pilihan != 5);

    cin.get();
    return 0;
}