#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<unistd.h> 

void main() {
    int packets[8],clk,bsize,orate,irate,pszrm=0,psz,ptime; 

    for(int i=0;i<5;++i) { 
        packets[i]=rand()%10; 
        if(packets[i]==0) --i; 
    } 

    printf("Enter output rate:"); 
    scanf("%d",&orate); 
    printf("\nEnter bucket size:"); 
    scanf("%d",&bsize); 
    
    for(int i=0;i<5;++i) { 
        
        if((packets[i]+pszrm) >bsize) { 
            if(packets[i]>bsize) 
                printf("\nIncoming packet size greater than bucket capacity\n"); 
            else
                printf("Bucket size exceeded\n"); 
        } else { 
                psz=packets[i]; 
                pszrm+=psz; 
                printf("\n--------------------------------\n"); 
                printf("Incoming packet:%d",psz); 
                printf("\nTransmission left:%d\n",pszrm); 
                ptime=rand()%10; 
                printf("Next packet will come at %d",ptime); 
        
                    for(int clk=0;clk<ptime&&pszrm>0;++clk) { 
                        printf("\nTime left %d---No packets to transmit!!\n",ptime-clk); 

                        if(pszrm) { 
                            printf("Transmitted\n"); 
                            if(pszrm<orate) 
                                pszrm=0; 
                            else 
                                pszrm=pszrm-orate; 
                            printf("Bytes remaining":"%d\n",pszrm); 
                        } else {
                            printf("No packets to transmit\n"); 
                        }
                    } 
        } 
    } 
    getchar();
}
