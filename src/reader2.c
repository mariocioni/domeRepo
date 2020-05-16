/*
 * reader.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "distance_calculator.h"
#include <time.h>
#define MAX_I 800


double haversine_dist(double lat1, double long1, double lat2, double long2);
void substring(char [], char[], int, int);
long tosec(long k);

int main(int argc, char **argv) {
    FILE *fp;
    char *line = NULL;
    char lat_st[10], longit_st[11], times_st[7]; //to store latitude, long. and time
    double lat, longit, prev_lat, prev_longit, dist;
    long times, prev_times;
	size_t len = 0;
	int i=1;
    if (argc != 2){
    if ((fp = fopen("G18.txt", "r")) == NULL) {
        printf("Error! opening file");
        // Program exits if file pointer returns NULL.
        exit(1);}
	}
	else{
		fp = fopen(argv[1], "r");
		}
	
	
    while(getline(&line, &len, fp) != -1) {	
		char fileString[7]; 
		char ourString[]="$GPGLL";
		strncpy(fileString, line, 6);
		if(strcmp(fileString, ourString)==0){
			//Extract info from line read: lat. long and time	
			substring(line,lat_st,8,9);
			substring(line,longit_st,20,10);
			lat=atof(lat_st)/100.0;
			longit=atof(longit_st)/100.0;
			substring(line,times_st,33,6);
			times=atol(times_st);
			
			if(i>1){
				dist=haversine_dist(lat,longit,prev_lat,prev_longit);
				double speed = dist/(times-prev_times);
				printf("Lat.=%f Long.=%f Distance in mt=%f Speed=%f \n",lat,longit,dist, speed);
			}
			prev_lat=lat; prev_longit=longit; prev_times=times;// to be used next round
			if(++i>MAX_I) break;		//reads up to MAX_I rows of input
		}	
	}
	
	fclose(fp);
	free(line);
    return 0;
}


// C substring function definition
void substring(char s[], char sub[], int p, int l) {
   int c = 0;
   
   while (c < l) {
      sub[c] = s[p+c-1];
      c++;
   }
   sub[c] = '\0';
}

long tosec(long k){
	long tmp=k/10000;
	long h=tmp*3600;
	tmp*=10000;
	tmp=k-tmp;
	long m=tmp/100; 
	long sec = tmp-m*100;
	m*=60;
	return (sec+h+m);
}
