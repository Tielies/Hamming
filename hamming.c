/*
P0 = D0 + D1 + D3 + D4 + D6 + D8 + D10 + D11 + D13 + D15 + D17 + D19 + D21 + D23 + D25 + D26 + D28 + D30 + D32 + D34 + D36 + D38 + D40 + D42 + D44 + D46 + D48 + D50 + D52 + D54 + D56 + D57 + D59 + D61 + D63
P1 = D0 + D2 + D3 + D5 + D6 + D9 + D10 + D12 + D13 + D16 + D17 + D20 + D21 + D24 + D25 + D27 + D28 + D31 + D32 + D35 + D36 + D39 + D40 + D43 + D44 + D47 + D48 + D51 + D52 + D55 + D56 + D58 + D59 + D62 + D63
P2 = D1 + D2 + D3 + D7 + D8 + D9 + D10 + D14 + D15 + D16 + D17 + D22 + D23 + D24 + D25 + D29 + D30 + D31 + D32 + D37 + D38 + D39 + D40 + D45 + D46 + D47 + D48 + D53 + D54 + D55 + D56 + D60 + D61 + D62 + D63
P3 = D4 + D5 + D6 + D7 + D8 + D9 + D10 + D18 + D19 + D20 + D21 + D22 + D23 + D24 + D25 + D33 + D34 + D35 + D36 + D37 + D38 + D39 + D40 + D49 + D50 + D51 + D52 + D53 + D54 + D55 + D56
P4 = D11 + D12 + D13 + D14 + D15 + D16 + D17 + D18 + D19 + D20 + D21 + D22 + D23 + D24 + D25 + D41 + D42 + D43 + D44 + D45 + D46 + D47 + D48 + D49 + D50 + D51 + D52 + D53 + D54 + D55 + D56
P5 = D26 + D27 + D28 + D29 + D30 + D31 + D32 + D33 + D34 + D35 + D36 + D37 + D38 + D39 + D40 + D41 + D42 + D43 + D44 + D45 + D46 + D47 + D48 + D49 + D50 + D51 + D52 + D53 + D54 + D55 + D56
P6 = D57 + D58 + D59 + D60 + D61 + D62 + D63
*/
#include <stdint.h>
#include <stdio.h>
#define GETBIT(x,y)  ((x >> y) & 0x01)

const uint8_t P0[] = { 0 , 1 , 3 , 4 , 6 , 8 , 10 , 11 , 13 , 15 , 17 , 19 , 21 , 
                    23 , 25 , 26 , 28 , 30 , 32 , 34 , 36 , 38 , 40 , 42 , 44 , 
                    46 , 48 , 50 , 52 , 54 , 56 , 57 , 59 , 61 , 63 };
const uint8_t P1[] = { 0 , 2 , 3 , 5 , 6 , 9 , 10 , 12 , 13 , 16 , 17 , 20 , 21 ,
                    24 , 25 , 27 , 28 , 31 , 32 , 35 , 36 , 39 , 40 , 43 , 44 ,
                    47 , 48 , 51 , 52 , 55 , 56 , 58 , 59 , 62 , 63 };
const uint8_t P2[] = { 1 , 2 , 3 , 7 , 8 , 9 , 10 , 14 , 15 , 16 , 17 , 22 , 23 ,
                     24 , 25 , 29 , 30 , 31 , 32 , 37 , 38 , 39 , 40 , 45 , 46 ,
                     47 , 48 , 53 , 54 , 55 , 56 , 60 , 61 , 62 , 63 };
const uint8_t P3[] = { 4 , 5 , 6 , 7 , 8 , 9 , 10 , 18 , 19 , 20 , 21 , 22 , 23 , 
                    24 , 25 , 33 , 34 , 35 , 36 , 37 , 38 , 39 , 40 , 49 , 50 , 
                    51 , 52 , 53 , 54 , 55 , 56};
const uint8_t P4[] = { 11 , 12 , 13 , 14 , 15 , 16 , 17 , 18 , 19 , 20 , 21 , 22 ,
                     23 , 24 , 25 , 41 , 42 , 43 , 44 , 45 , 46 , 47 , 48 , 49 ,
                     50 , 51 , 52 , 53 , 54 , 55 , 56 };
const uint8_t P5[] = { 26 , 27 , 28 , 29 , 30 , 31 , 32 , 33 , 34 , 35 , 36 , 37 ,
                     38 , 39 , 40 , 41 , 42 , 43 , 44 , 45 , 46 , 47 , 48 , 49 ,
                      50 , 51 , 52 , 53 , 54 , 55 , 56 };
const uint8_t P6[] = {57 , 58 , 59 , 60 , 61 , 62 , 63 };

const uint8_t parity_pos[] = {0, 1, 3, 7, 15, 31, 63};

void load_data(uint8_t* datap, uint16_t len, uint8_t* destp, uint16_t dest_len)
{
    for (int i = 0; i < len; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if ((i * 8 + j) < dest_len)
                destp[i * 8 + j] = GETBIT(*(datap + i), j);
            else 
                return;
        }
    }
}

void print_data(uint8_t* datap, uint16_t len)
{
    for (int i = len - 1; i >= 0; --i)
    {
        printf("%d", datap[i]);
    }
    printf("\n");
}

uint8_t calc_parity(uint8_t* datap, uint16_t len, const uint8_t *parity_vect_p,
                     uint16_t parity_vect_len)
{
    uint8_t parity = 0;
    uint8_t data_index = 0;
    for(int i = 0; i < parity_vect_len; ++i) 
    {
        data_index =  parity_vect_p[i];
        if (data_index < len)
            parity ^= datap[data_index];
        else 
            break;
    }
    return parity;
}
uint8_t calc_overall_parity(uint8_t* datap, uint16_t len)
{
    uint8_t parity = 0;
    for(int i = 0; i < len; ++i) 
    {
        parity = parity ^ datap[i]; 
    }
    return parity;
}

/**
 * @brief 
 * 
 * @param datap pointer to the buffer holding only the data bits
 * @param len length of actual data (excluding parity bits)
 * @param parity_p pointer to buffer holding the calculated parity bits
 * @param dest_p pointer to buffer which will hold the packet + hamming bits
 */
uint16_t pack_packet(const uint8_t* datap, const uint16_t len, uint8_t* parity_p, 
                        uint8_t* dest_p, uint16_t dest_len)
{
    uint8_t parity_index = 0;// counts of parity bits added
    uint8_t i = 0;
    while (i < dest_len) 
    {
        if (i == parity_pos[parity_index]) {
            //printf("Parity bit inserted at %d = %d\n", i, parity_p[parity_index]);
            dest_p[i] = parity_p[parity_index];
            ++parity_index;
        } else {
            dest_p[i] = datap[i - parity_index];
        }
        i++;
    }
    dest_p[dest_len - 1] = calc_overall_parity(dest_p, dest_len);
    return i;
}

/**
 * @brief 
 * 
 * @param datap pointer to buffer which holds the packet + hamming bits
 * @param len length of actual data (including parity bits)
 * @param parity_p ponter to buffer holding the received parity bits
 * @param dest_p pointer to the buffer holding only the data bits
 */
uint16_t unpack_packet(const uint8_t* datap, const uint16_t len, uint8_t* parity_p, 
                        uint8_t* dest_p, uint8_t *overall_parity)
{
    uint8_t parity_index = 0;
    for (int i = 0; i < len; ++i) 
    {
        if (i == parity_pos[parity_index]) {
            parity_p[parity_index] = datap[i];
            ++parity_index;
        } else {
            dest_p[i - parity_index] = datap[i];
        }
    }
    *overall_parity = calc_overall_parity(datap, len);
    return len - parity_index - 1;
}

/**
 * @brief 
 * 
 * @param parity_calc 
 * @param parity_rec 
 * @param len 
 * @return uint16_t 
 */
int hamming_calc_fault(uint8_t* parity_calc, uint8_t* parity_rec, uint16_t len)
{
    int faultpos = 0;
    for (int i = 0; i < len; ++i)
    {
        faultpos |= ((parity_calc[i] ^ parity_rec[i]) << i);
    }
    return faultpos - 1;
}

int main(void)
{
    static uint8_t bin_data[32] = {0};
    static uint8_t ham_data[38] = {0};   
    uint8_t overall_parity = 0;
    uint32_t temp = 0xFF;
    load_data(&temp, sizeof(temp), bin_data, sizeof(bin_data));
    printf("Raw data:");
    print_data(bin_data, sizeof(temp) * 8);
    uint8_t parity[] = {
                        calc_parity(bin_data, sizeof(bin_data), P0, sizeof(P0)),
                        calc_parity(bin_data, sizeof(bin_data), P1, sizeof(P1)),
                        calc_parity(bin_data, sizeof(bin_data), P2, sizeof(P2)),
                        calc_parity(bin_data, sizeof(bin_data), P3, sizeof(P3)),
                        calc_parity(bin_data, sizeof(bin_data), P4, sizeof(P4)),
                        calc_parity(bin_data, sizeof(bin_data), P5, sizeof(P5)),
                        calc_parity(bin_data, sizeof(bin_data), P6, sizeof(P6))};
    printf("Parity bits:");
    print_data(parity, sizeof(parity));
    printf("Number of bits packed = %d \n", 
            pack_packet(bin_data, sizeof(temp) * 8, parity, ham_data, sizeof(ham_data)));
    printf("Hamming data :");
    print_data(ham_data, sizeof(ham_data));

     printf("Modded Ham data :");
    ham_data[8] ^= 1;
    //ham_data[7] ^= 1;
    //ham_data[0] ^= 1;
    //ham_data[1] ^= 1;
    //ham_data[2] ^= 1;
    print_data(ham_data, sizeof(ham_data));
    printf("Number bits extracted = %d\n", 
            unpack_packet(ham_data, sizeof(ham_data), parity, bin_data, &overall_parity));
    printf("Extracted data:");
    print_data(bin_data, sizeof(temp) * 8);
    printf("Extracted parity:");
    print_data(parity, sizeof(parity));
    uint8_t mod_parity[] = {
                        calc_parity(bin_data, sizeof(bin_data), P0, sizeof(P0)),
                        calc_parity(bin_data, sizeof(bin_data), P1, sizeof(P1)),
                        calc_parity(bin_data, sizeof(bin_data), P2, sizeof(P2)),
                        calc_parity(bin_data, sizeof(bin_data), P3, sizeof(P3)),
                        calc_parity(bin_data, sizeof(bin_data), P4, sizeof(P4)),
                        calc_parity(bin_data, sizeof(bin_data), P5, sizeof(P5)),
                        calc_parity(bin_data, sizeof(bin_data), P6, sizeof(P6))};
    printf("Mod Parity bits calc:");
    print_data(mod_parity, sizeof(mod_parity));
    int fault_pos = hamming_calc_fault(mod_parity, parity, sizeof(parity));
    if (overall_parity != ham_data[sizeof(ham_data) - 1]) {
        if (fault_pos != -1) {
            printf("Fault pos = %d\n", fault_pos);
            ham_data[fault_pos] ^= 1;
        } else {
            printf("Fault pos = %d\n", sizeof(ham_data) - 1);
            ham_data[sizeof(ham_data) - 1] ^= 1;
        }
        printf("Corrected message:");
        print_data(ham_data, sizeof(ham_data));
    } else if (fault_pos != -1){
        printf("Message has two or more errors\n");
    } else {
        printf("Message has no errors\n");
    }
}