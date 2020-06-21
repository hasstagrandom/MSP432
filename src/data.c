#include<stdint.h>


//#include<stdio.h>




int mypow(uint8_t base,uint8_t exp){
	int result=1;
	while(exp!=1){
		result=result*base;
		exp--;
	}
	return result;
}

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){
	uint8_t digit;
	uint32_t num=data;
	uint8_t string[12];
	int i;
	if(data<0){
		num=(-data);
		*ptr='-';
		ptr++;
	}
	for(i=0;num;i++){
		digit = num % base;
		
		//printf("digit %d\n",digit);
		
		num/=base;
		
		//printf("data %d\n",data);
		
		if ((digit>=0) && (digit<=9)){
			*(string+i)='0'+digit;
			//printf("%c\n",*(string+i));
		}
		else if ((digit>=10)&&(digit<=16)){
			*(string+i)='a'+digit;
		}
	}
	for(int j=i-1;j>=0;j--){
		*ptr=*(string+j);
		
		//printf("ptr %c iter %d\n",*ptr,j);
		
		ptr++;
	}
	*ptr='\0';
	if(data<0){
		return i+2;
	}
	else{
		return i+1;
	}
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){
	int placeholder = 1;
	int8_t i = digits-1;
	int sign =1;
	int32_t total = 0;
	if(*ptr == '-'){
		sign=-1;
		i++;
	}

	for(;i>=0;i--){
		uint8_t x = *(ptr+i);
		if((x>='0')&&(x<='9')){
			total += (placeholder*(x-'0'));
			placeholder*=base;
		}
		else if((x>='a')&&(x<='f')){
			total+=placeholder*(x-'a'+10);
			placeholder*=base;
		}
		else if((x>='A')&&(x<='F')){
			total+=placeholder*(x-'A'+10);
			placeholder*=base;
		}
		//printf(" total%d placeholder%d i %d\n",total,placeholder,i);

	}
	//printf(" %d ",sign*total);
	return sign*total;

}

















//FOR TESTING ONLY
/*

int main(void){
	char string[10]="-32a7b";
	char lol[10];
	int num = my_atoi(string,6,16);
	printf(" num %d ",num);
	int x=my_itoa(num,lol,10);
	for(int i=0;i<10;i++){
		printf(".. %c",lol[i]);
		}
	return 0;
}

*/
