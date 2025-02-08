#include <stdio.h>
#include <stdlib.h>
#include <time.h>
	union DateTime{
	time_t epoch; 
	struct tm dateTimeInfo; 
	
};
time_t getTimeValue(){
	union DateTime dateTime; 

	printf("Tarih ve saat giriniz (Yil Ay Gun Saat Dakika Saniye): \n");
	scanf("%d %d %d %d %d %d",&dateTime.dateTimeInfo.tm_year,  &dateTime.dateTimeInfo.tm_mon,  &dateTime.dateTimeInfo.tm_mday,    &dateTime.dateTimeInfo.tm_hour, &dateTime.dateTimeInfo.tm_min,  &dateTime.dateTimeInfo.tm_sec);
	 dateTime.dateTimeInfo.tm_year -=1900; 
	 dateTime.dateTimeInfo.tm_mon -= 1;
	return mktime(&dateTime.dateTimeInfo); 
}


int main(int argc, char *argv[]) {

time_t currentTime=getTimeValue(); //ilk tarih bilgisi
	time_t examTime=getTimeValue(); //ikinci tarih bilgisi 
	printf("Guncel Tarihin Epoch Zamani: %ld \n", currentTime);
    printf("Sinav Tarihin Epoch Zamani: %ld \n", examTime);
	
	double fark=difftime(examTime, currentTime);
	if (fark < 0) {
        printf("Sinav tarihi gecmis! \n");
    } else {
        int days = fark / (60 * 60 * 24);
        int hours = ((int)fark % (60 * 60 * 24)) / (60 * 60);
        int minutes = ((int)fark % (60 * 60)) / 60;
        int seconds = (int)fark % 60;

        printf("Sinava kalan sure: %d gun, %d saat, %d dakika, %d saniye\n",
               days, hours, minutes, seconds);
               printf("Iki tarih arasindaki epoch fark:%.0f saniye \n",fark);

    }


	return 0;
}
