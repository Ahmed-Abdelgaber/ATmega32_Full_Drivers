#include "MTWI.h"
#include "MTWI_Config.h"
#include "LSTD_TYPES.h"
#include "MTWI_Private.h"
void MTWI_Init(void){
	/*config speed SCLK = 400KHZ ,FCPU=8MHZ,PRESCALER=1*/
	MTWI_TWBR=0x02;
	/*config prescaler=1*/
	MTWI_TWSR=0x00;
	/*config address as 1,general call DISABLE in case it's a slave*/
	MTWI_TWAR=0x02;
	/*ENABLE TWI,polling,enable acknowledgement bit*/
	MTWI_TWCR = (1<<TWEN)|(1<<TWEA);
}
void MTWI_u8_SEND_START_BIT(){
	/*clear int flag and enable twi and enable start*/
	MTWI_TWCR=(1<<TWINT)|(1<<TWSTA)|(1<<TWEN);

	while(!(MTWI_TWCR &(1<<TWINT)));//busy waiting
}
void MTWI_u8_SEND_STOP_BIT(){
	/*clear int flag and enable twi and enable stop*/
	MTWI_TWCR=(1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
}
void MTWI_SEND_DATA(u8 data){
	MTWI_TWDR=data;
	MTWI_TWCR=(1<<TWINT)|(1<<TWEN);
	while(!(MTWI_TWCR&(1<<TWINT)));
}
u8 MTWI_READ_DATA_ACK(){
	MTWI_TWCR=(1<<TWINT)|(1<<TWEA)|(1<<TWEN);
	while(!(MTWI_TWCR&(1<<TWINT)));
	return MTWI_TWDR;
}
u8 MTWI_READ_DATA_NACK(){
	MTWI_TWCR=(1<<TWINT)|(1<<TWEN);
	while(!(MTWI_TWCR&(1<<TWINT)));
	return MTWI_TWDR;
}
u8 MTWI_u8_GETSTATUS(){
	u8 status=0;
	status=MTWI_TWSR & 0xF8;
	return status ;
}
