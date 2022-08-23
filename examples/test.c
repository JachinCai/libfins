#This demo only writes and reads one word, my node is 13 and my PLC's node is 10   

#include "fins.h"
#include <stdio.h>

#define  num  1
int main(){
    struct fins_sys_tp *TcpFins;
    // PLC address
    char address[] = {"192.168.1.10"};
    int erro=0;
    int16_t data[num]= {0xFFFF};
    printf("----------------------------------------------\n");
    TcpFins = finslib_tcp_connect(0, address, 9600, 0, 13, 0, 0, 10, 0, &erro, 0);
    TcpFins->plc_mode = 1;
    char start[] = {"DM1000.0"};
    printf("------------------------------------------------\n");

    if(finslib_memory_area_write_uint16(TcpFins,start, data, num) != FINS_RETVAL_SUCCESS){
         printf("write failure\n");
    }
    int i = finslib_memory_area_read_int16(TcpFins,start, data, num);
    if(i==FINS_RETVAL_SUCCESS){
       printf("%x\t",data[0]);
    }else{
        printf("%x", i);
    }
    return 0;
    
}




