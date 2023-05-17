#include <stdio.h>
#include <stdlib.h>

int main() {
    // PIN awal
    int pin = 125800;
    // saldo awal
    float balance = 1000000000;
    // Inisialisasi variabel-variabel lain yang dibutuhkan
    int choice, login_attempt = 0;
    int transfer_account_number;
    float transfer_amount, top_up_dana, top_up_gopay, withdrawal_amount;

    // Loop while untuk mengulang login hingga maksimal 3 kali percobaan
    while (login_attempt < 3) {
        // Meminta pengguna memasukkan PIN
        int input_pin;
        printf("SELAMAT DATANG DIBANK PEKANBARU SEJAHTERA \n");
        printf("PIN ANDA: ");
        scanf("%d", &input_pin);
        
        // Jika PIN benar, tampilkan menu opsi
        if (input_pin == pin) {
            printf("LOGIN SUKSES!\n");
            while (1) {
                printf("\nATM Menu\n");
                printf("1. LIHAT SALDO ANDA\n");
                printf("2. ISI SALDO\n");
                printf("3. PENARIKAN\n");
                printf("4. KIRIM\n");
                printf("5. TOP UP\n");
                printf("6. KELUAR\n");
                printf("MASUKKAN MENU YANG ANDA INGINKAN: ");
                scanf("%d", &choice);
                
                // Switch case untuk setiap opsi pada menu
                switch (choice) {
                    case 1:
                        printf("SALDO ANDA SAAT INI: %.2f\n", balance);
                        break;
                    case 2:
                        printf("MASUKKAN JUMLAH SALDO: ");
                        float deposit_amount;
                        scanf("%f", &deposit_amount);
                        balance += deposit_amount;
                        printf("ISI SALDO BERHASIL. SALDO ANDA: %.2f\n", balance);
                        break;
                    case 3:
                        printf("JUMLAH YANG DIKIRIM:: ");
                        scanf("%f", &withdrawal_amount);
                        if (withdrawal_amount > balance) {
                            printf("Insufficient funds.\n");
                        } else {
                            balance -= withdrawal_amount;
                            printf("PENARIKAN SUKSES: %.2f\n", balance);
                        }
                        break;
                    case 4:
                        printf("NOMOR REKENING YANG DITUJU: ");
                        scanf("%d", &transfer_account_number);
                        printf("MASUKKAN JUMLAH: ");
                        scanf("%f", &transfer_amount);
                        if (transfer_amount > balance) {
                            printf("Insufficient funds.\n");
                        } else {
                            balance -= transfer_amount;
                            printf("SALDO ANDA:: %.2f\n", balance);
                        }
                        break;
                    case 5:
                        printf("Top up menu\n");
                        printf("1. TOP UP DANA\n");
                        printf("2. TOP UP GAME\n");
                        printf("MASUKKAN PILIHAN: ");
                        int top_up_choice;
                        scanf("%d", &top_up_choice);
                        switch (top_up_choice) {
                            case 1:
                                printf("MASUKKAN JUMLAH SALDO: ");
                                scanf("%f", &top_up_dana);
                                printf("PIN ANDA: ");
                                scanf("%d", &pin);
                                printf("OPSI SUKSES.SISA SALDO ANDA: %.2f\n", balance + top_up_dana);
                                break;
                            case 2:
                                printf("MASUKKAN JUMLAH SALDO YANG AKAN DIISI: ");
                                scanf("%f", &top_up_gopay);
                                printf("Masukkan PIN: ");
                                scanf("%d", &pin);
                                printf("ISI SALDO SUKSES. SALDO ANDA: %.2f", balance += top_up_gopay);
                                printf("SALDO ANDA: %.2f\n", balance);
                                break;
                            default:
                                printf("INVALID.\n");
                                break;
                        }
                        break;
                    case 6:
                        // Keluar dari menu dan kembali ke menu login
                        printf("SUKSES.\n");
                        login_attempt = 3;
                        break;
                    default:
                        printf("INVALID.\n");
                        break;
                }
            }
        } else {
            // Jika PIN salah, tampilkan pesan error dan tingkatkan jumlah percobaan
            printf("LOGIN GAGAL, SILAHKAN COBA LAGI.\n");
            login_attempt++;
        }
    }
    // Jika sudah 3 kali percobaan login dan masih gagal, keluar dari program
    if (login_attempt == 3) {
        printf("PERCOBAAN MELEBIH BATAS . AKUN ANDA TERBLOKIR.\n");
    }
    return 0;
}