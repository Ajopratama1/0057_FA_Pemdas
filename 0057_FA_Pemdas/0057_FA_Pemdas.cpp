#include <iostream>

using namespace std;

/**
 * \class MataKuliah
 * \brief Kelas dasar yang mengabstraksi perilaku umum dari semua mata kuliah.
 *
 * Kelas ini memiliki atribut-atribut yang dienkapsulasi yaitu presensi, activity, exercise, dan tugas akhir.
 * Setiap atribut ini memiliki metode getter dan setter yang sesuai untuk mengakses dan memodifikasi nilai mereka.
 */
class MataKuliah {
private:
    float presensi;
    float activity;
    float exercise;
    float tugasAkhir;

public:
    void setPresensi(float nilai) {
        presensi = nilai;
    }

    float getPresensi() {
        return presensi;
    }

    void setActivity(float nilai) {
        activity = nilai;
    }

    float getActivity() {
        return activity;
    }

    void setExercise(float nilai) {
        exercise = nilai;
    }

    float getExercise() {
        return exercise;
    }

    void setTugasAkhir(float nilai) {
        tugasAkhir = nilai;
    }

    float getTugasAkhir() {
        return tugasAkhir;
    }

    virtual string namaMataKuliah() = 0;
    virtual void inputNilai() = 0;
    virtual float hitungNilaiAkhir() = 0;
    virtual void cekKelulusan() = 0;
};

/**
 * \class Pemrograman
 * \brief Kelas Pemrograman yang mewarisi dari MataKuliah.
 *
 * Kelas ini mengimplementasikan metode inputNilai untuk menerima nilai presensi, activity, exercise, dan tugasAkhir.
 * Mengimplementasikan metode hitungNilaiAkhir yang menghitung nilai akhir.
 * Mengimplementasikan metode cekKelulusan yang menampilkan pesan kelulusan berdasarkan nilai akhir yang dihitung.
 */
class Pemrograman : public MataKuliah {
public:
    string namaMataKuliah() override {
        return "Pemrograman";
    }

    void inputNilai() override {
        float presensi, activity, exercise, tugasAkhir;

        cout << "Masukkan nilai presensi: ";
        cin >> presensi;
        setPresensi(presensi);

        cout << "Masukkan nilai activity: ";
        cin >> activity;
        setActivity(activity);

        cout << "Masukkan nilai exercise: ";
        cin >> exercise;
        setExercise(exercise);

        cout << "Masukkan nilai tugas akhir: ";
        cin >> tugasAkhir;
        setTugasAkhir(tugasAkhir);
    }

    float hitungNilaiAkhir() override {
        return (getPresensi() * 0.1) + (getActivity() * 0.2) + (getExercise() * 0.3) + (getTugasAkhir() * 0.4);
    }

    void cekKelulusan() override {
        float nilaiAkhir = hitungNilaiAkhir();
        if (nilaiAkhir >= 75) {
            cout << "Lulus" << endl;
        }
        else {
            cout << "Tidak Lulus" << endl;
        }
    }
};

/**
 * \class Jaringan
 * \brief Kelas Jaringan yang mewarisi dari MataKuliah.
 *
 * Kelas ini hanya menghitung nilai activity dan exercise pada metode inputNilai.
 * Mengimplementasikan metode hitungNilaiAkhir dan metode cekKelulusan yang menampilkan pesan kelulusan berdasarkan nilai akhir yang dihitung.
 */
class Jaringan : public MataKuliah {
public:
    string namaMataKuliah() override {
        return "Jaringan";
    }

    void inputNilai() override {
        float activity, exercise;

        cout << "Masukkan nilai activity: ";
        cin >> activity;
        setActivity(activity);

        cout << "Masukkan nilai exercise: ";
        cin >> exercise;
        setExercise(exercise);
    }

    float hitungNilaiAkhir() override {
        return (getActivity() * 0.5) + (getExercise() * 0.5);
    }

    void cekKelulusan() override {
        float nilaiAkhir = hitungNilaiAkhir();
        if (nilaiAkhir >= 75) {
            cout << "Lulus" << endl;
        }
        else {
            cout << "Tidak Lulus" << endl;
        }
    }
};

/**
 * \brief Fungsi utama untuk menjalankan program.
 *
 * Menampilkan menu untuk memilih mata kuliah, kemudian menghitung nilai dan menampilkan hasil kelulusan.
 */
int main() {
    int pilihan;

    cout << "Pilih Mata Kuliah:" << endl;
    cout << "1. Pemrograman" << endl;
    cout << "2. Jaringan" << endl;
    cout << "Masukkan pilihan Anda (1/2): ";
    cin >> pilihan;

    MataKuliah* mataKuliah;

    if (pilihan == 1) {
        mataKuliah = new Pemrograman();
    }
    else if (pilihan == 2) {
        mataKuliah = new Jaringan();
    }
    else {
        cout << "Pilihan tidak valid" << endl;
        return 1;
    }

    cout << "Anda memilih mata kuliah: " << mataKuliah->namaMataKuliah() << endl;
    mataKuliah->inputNilai();
    mataKuliah->cekKelulusan();

    delete mataKuliah;
    return 0;
}