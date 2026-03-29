#define zero  0b1111110
#define um  0b0110000
#define dois  0b1101101
#define tres  0b1111001
#define quatro 0b0110011
#define cinco  0b1011011
#define seis  0b1011111
#define sete  0b1110000
#define oito  0b1111111
#define nove  0b1110011
#define buzzer GPIO_ODR_ODR_8;
#define detonador GPIO_ODR_ODR_10;
#define desarme GPIO_ODR_ODR_9;
#include "stm32f4xx.h"

uint8_t start=0;
int valor=999;
uint8_t i=0;
uint8_t crt=1;
uint8_t acelera=0;
int chave[]={0,0,0,0,0,0,0,0};
uint8_t tempo[]={5,9};
int display[]={zero,zero};
uint8_t aciona=0;
uint8_t suffle=0;

void conversor(void);
void multiplexa(void);


int main(void)
{
	RCC->AHB1ENR=0x87;
	RCC->APB2ENR|=RCC_APB2ENR_TIM9EN;
	RCC->APB2ENR|=RCC_APB2ENR_TIM10EN;
	RCC->APB2ENR|=RCC_APB2ENR_TIM11EN;
	RCC->APB1ENR|=RCC_APB1ENR_TIM3EN;

	GPIOC->MODER&=~GPIO_MODER_MODER0;//chaves ativação da bomba
	GPIOC->MODER&=~GPIO_MODER_MODER0_0;

	GPIOC->MODER&=~GPIO_MODER_MODER1;
	GPIOC->MODER&=~GPIO_MODER_MODER1_0;

	GPIOC->MODER&=~GPIO_MODER_MODER2;
	GPIOC->MODER&=~GPIO_MODER_MODER2_0;

	GPIOC->MODER&=~GPIO_MODER_MODER3;
	GPIOC->MODER&=~GPIO_MODER_MODER3_0;

	GPIOC->MODER&=~GPIO_MODER_MODER4;
	GPIOC->MODER&=~GPIO_MODER_MODER4_0;

	GPIOC->MODER&=~GPIO_MODER_MODER5;
	GPIOC->MODER&=~GPIO_MODER_MODER5_0;

	GPIOC->MODER&=~GPIO_MODER_MODER6;
	GPIOC->MODER&=~GPIO_MODER_MODER6_0;

	GPIOC->MODER&=~GPIO_MODER_MODER7;
	GPIOC->MODER&=~GPIO_MODER_MODER7_0;

	GPIOC->MODER&=~GPIO_MODER_MODER8; //buzzer
	GPIOC->MODER|=GPIO_MODER_MODER8_0;

	GPIOC->MODER&=~GPIO_MODER_MODER9;//led verde
	GPIOC->MODER|=GPIO_MODER_MODER9_0;

	GPIOC->MODER&=~GPIO_MODER_MODER10;//led amarelo
	GPIOC->MODER|=GPIO_MODER_MODER10_0;

	GPIOC->MODER&=~GPIO_MODER_MODER11;//ativa1
	GPIOC->MODER|=GPIO_MODER_MODER11_0;

	GPIOC->MODER&=~GPIO_MODER_MODER12;//ativa2
	GPIOC->MODER|=GPIO_MODER_MODER12_0;

	GPIOC->MODER&=~GPIO_MODER_MODER13;//botão start
	GPIOC->MODER&=~GPIO_MODER_MODER13_0;



	GPIOC->PUPDR&=~GPIO_PUPDR_PUPDR0;
	GPIOC->PUPDR|=GPIO_PUPDR_PUPDR0_1;

	GPIOC->PUPDR&=~GPIO_PUPDR_PUPDR1;
	GPIOC->PUPDR|=GPIO_PUPDR_PUPDR1_1;

	GPIOC->PUPDR&=~GPIO_PUPDR_PUPDR2;
	GPIOC->PUPDR|=GPIO_PUPDR_PUPDR2_1;

	GPIOC->PUPDR&=~GPIO_PUPDR_PUPDR3;
	GPIOC->PUPDR|=GPIO_PUPDR_PUPDR3_1;

	GPIOC->PUPDR&=~GPIO_PUPDR_PUPDR4;
	GPIOC->PUPDR|=GPIO_PUPDR_PUPDR4_1;

	GPIOC->PUPDR&=~GPIO_PUPDR_PUPDR5;
	GPIOC->PUPDR|=GPIO_PUPDR_PUPDR5_1;

	GPIOC->PUPDR&=~GPIO_PUPDR_PUPDR6;
	GPIOC->PUPDR|=GPIO_PUPDR_PUPDR6_1;

	GPIOC->PUPDR&=~GPIO_PUPDR_PUPDR7;
	GPIOC->PUPDR|=GPIO_PUPDR_PUPDR7_1;

	GPIOC->PUPDR&=~GPIO_PUPDR_PUPDR13;
	GPIOC->PUPDR|=GPIO_PUPDR_PUPDR13_1;



	GPIOB->MODER&=~GPIO_MODER_MODER0;
	GPIOB->MODER|=GPIO_MODER_MODER0_0;

	GPIOB->MODER&=~GPIO_MODER_MODER1;
	GPIOB->MODER|=GPIO_MODER_MODER1_0;

	GPIOB->MODER&=~GPIO_MODER_MODER2;
	GPIOB->MODER|=GPIO_MODER_MODER2_0;

	GPIOB->MODER&=~GPIO_MODER_MODER3;
	GPIOB->MODER|=GPIO_MODER_MODER3_0;

	GPIOB->MODER&=~GPIO_MODER_MODER4;
	GPIOB->MODER|=GPIO_MODER_MODER4_0;

	GPIOB->MODER&=~GPIO_MODER_MODER5;
	GPIOB->MODER|=GPIO_MODER_MODER5_0;

	GPIOB->MODER&=~GPIO_MODER_MODER6;
	GPIOB->MODER|=GPIO_MODER_MODER6_0;

	GPIOB->MODER&=~GPIO_MODER_MODER7;
	GPIOB->MODER|=GPIO_MODER_MODER7_0;

	GPIOB->MODER&=~GPIO_MODER_MODER8;
	GPIOB->MODER|=GPIO_MODER_MODER8_0;

	TIM11->PSC|=15999;
	TIM11->ARR|=999;

	TIM10->PSC|=15999;
	TIM10->ARR|=1;
	TIM10->CR1|=TIM_CR1_CEN;

	TIM9->PSC|=15999;
	TIM9->ARR|=1;
	TIM9->CR1|=TIM_CR1_CEN;

	TIM3->PSC|=7999;
	TIM3->ARR|=1;
	TIM3->CR1|=TIM_CR1_CEN;


  while (1)
  {
	  GPIOC->ODR&=~buzzer;
	  GPIOC->ODR&=~detonador;
	  GPIOC->ODR&=~desarme;
	  acelera=0;


	  if(!(GPIOC->IDR&GPIO_ODR_ODR_13))//Espera o Start
		  start=1;

	  if(TIM10->SR&TIM_SR_UIF){
		  TIM10->CR1&=~TIM_CR1_CEN;
		  suffle++;
		  if(suffle>7)
			 suffle=0;}

	  	  chave[suffle]=8;

	  if(TIM3->SR&TIM_SR_UIF){
		  TIM3->CR1&=~TIM_CR1_CEN;
		  chave[suffle]=4;
		  }





	  while((start))
	  {
			  if(chave[0]+chave[1]+chave[2]+chave[3]+chave[4]+chave[5]+chave[6]+chave[7]!=12)
			  {
				  	chave[0]=0;
					chave[1]=0;
					chave[2]=0;
					chave[3]=0;
					chave[4]=0;
					chave[5]=0;
					chave[6]=0;
					chave[7]=0;
					chave[suffle]=8;
					suffle++;
					if(suffle>7)
						suffle=0;
					chave[suffle]=4;
			  }



		  multiplexa();
		  if(crt>0)//parâmetros iniciais
		  {
			  tempo[0]=5;
			  tempo[1]=9;
			  conversor();
			  TIM11->CR1|=TIM_CR1_CEN;
			  crt--;
			  multiplexa();
		  }


		  if(acelera==0)//acelera o contador de tempo
			  valor=999;
		  if(acelera==1)
			  valor=499;
		  if(acelera==2)
			  valor=249;


		  if(TIM11->SR&TIM_SR_UIF)
		  {
			 TIM11->SR&=~TIM_SR_UIF;
			 TIM11->ARR|=valor;
			 tempo[1]--;
			 conversor();

			 if(tempo[1]<0)
			 {
				 tempo[0]--;
				 tempo[1]=9;
				 conversor();
			 };

			 GPIOC->ODR^=buzzer;

		  };


			if(tempo[0]==0 && tempo[1]==0)
			{
				 TIM11->CR1&=~TIM_CR1_CEN;
				 conversor();
				 GPIOC->ODR|=buzzer;
				 crt=1;
				 start=0;
			 };


		  if(GPIOC->IDR&GPIO_ODR_ODR_0){//usado para verificar se uma chave foi acionada
		  	chave[0]+=1;
		  	acelera++;}
		  if(GPIOC->IDR&GPIO_ODR_ODR_1){
		  	chave[1]+=1;
		  	acelera++;}
		  if(GPIOC->IDR&GPIO_ODR_ODR_2){
		  	chave[2]+=1;
		  	acelera++;}
		  if(GPIOC->IDR&GPIO_ODR_ODR_3){
		  	chave[3]+=1;
		  	acelera++;}
		  if(GPIOC->IDR&GPIO_ODR_ODR_4){
		  	chave[4]+=1;
		  	acelera++;}
		  if(GPIOC->IDR&GPIO_ODR_ODR_5){
		  	chave[5]+=1;
		  	acelera++;}
		  if(GPIOC->IDR&GPIO_ODR_ODR_6){
		  	chave[6]+=1;
		  	acelera++;}
		  if(GPIOC->IDR&GPIO_ODR_ODR_7){
		  	chave[7]+=1;
		  	acelera++;}

		  if((chave[0]==5)||(chave[1]==5)||(chave[2]==5)||(chave[3]==5)||(chave[4]==5)||(chave[5]==5)||(chave[6]==5)||(chave[7]==5))
		  {
			  TIM11->CR1&=~TIM_CR1_CEN;
			  GPIOC->ODR|=buzzer;
			  tempo[0]=0;
			  tempo[1]=0;
			  conversor();
			  crt=1;
			  start=0;
		  }

		  if((chave[0]==9)||(chave[1]==9)||(chave[2]==9)||(chave[3]==9)||(chave[4]==9)||(chave[5]==9)||(chave[6]==9)||(chave[7]==9))
		  {
			  TIM11->CR1&=~TIM_CR1_CEN;
			  GPIOC->ODR&=~buzzer;
			  crt=1;
			  start=0;
		  }



//-------------------------------------------------------------------------------------------



		  if(chave[0]==1 && chave[1]==4)
			  GPIOC->ODR|=detonador;

		  if(chave[0]==1 && chave[7]==4)
			  GPIOC->ODR|=detonador;

		  if(chave[1]==1 && chave[0]==4)
			  GPIOC->ODR|=detonador;

		  if(chave[1]==1 && chave[2]==4)
			  GPIOC->ODR|=detonador;

		  if(chave[2]==1 && chave[1]==4)
			  GPIOC->ODR|=detonador;

		  if(chave[2]==1 && chave[3]==4)
			  GPIOC->ODR|=detonador;

		  if(chave[3]==1 && chave[2]==4)
			  GPIOC->ODR|=detonador;

		  if(chave[3]==1 && chave[4]==4)
			  GPIOC->ODR|=detonador;

		  if(chave[4]==1 && chave[3]==4)
			  GPIOC->ODR|=detonador;

		  if(chave[4]==1 && chave[5]==4)
			  GPIOC->ODR|=detonador;

		  if(chave[5]==1 && chave[4]==4)
			  GPIOC->ODR|=detonador;

		  if(chave[5]==1 && chave[6]==4)
			  GPIOC->ODR|=detonador;

		  if(chave[6]==1 && chave[5]==4)
			  GPIOC->ODR|=detonador;

		  if(chave[6]==1 && chave[7]==4)
			  GPIOC->ODR|=detonador;

		  if(chave[7]==1 && chave[6]==4)
			  GPIOC->ODR|=detonador;

		  if(chave[7]==1 && chave[0]==4)
			  GPIOC->ODR|=detonador;


//------------------------------------------------------------------------------------------


		  if(chave[0]==1 && chave[1]==8)
			  GPIOC->ODR|=desarme;

		  if(chave[0]==1 && chave[7]==8)
			  GPIOC->ODR|=desarme;

		  if(chave[1]==1 && chave[0]==8)
			  GPIOC->ODR|=desarme;

		  if(chave[1]==1 && chave[2]==8)
			  GPIOC->ODR|=desarme;

		  if(chave[2]==1 && chave[1]==8)
			  GPIOC->ODR|=desarme;

		  if(chave[2]==1 && chave[3]==8)
			  GPIOC->ODR|=desarme;

		  if(chave[3]==1 && chave[2]==8)
			  GPIOC->ODR|=desarme;

		  if(chave[3]==1 && chave[4]==8)
			  GPIOC->ODR|=desarme;

		  if(chave[4]==1 && chave[3]==8)
			  GPIOC->ODR|=desarme;

		  if(chave[4]==1 && chave[5]==8)
			  GPIOC->ODR|=desarme;

		  if(chave[5]==1 && chave[4]==8)
			  GPIOC->ODR|=desarme;

		  if(chave[5]==1 && chave[6]==8)
			  GPIOC->ODR|=desarme;

		  if(chave[6]==1 && chave[5]==8)
			  GPIOC->ODR|=desarme;

		  if(chave[6]==1 && chave[7]==8)
			  GPIOC->ODR|=desarme;

		  if(chave[7]==1 && chave[6]==8)
			  GPIOC->ODR|=desarme;

		  if(chave[7]==1 && chave[0]==8)
			  GPIOC->ODR|=desarme;

	  }
  }
}

void conversor(void)
{
	  if(tempo[0]==0)
		  display[0]=zero;
	  if(tempo[0]==1)
		  display[0]=um;
	  if(tempo[0]==2)
		  display[0]=dois;
	  if(tempo[0]==3)
		  display[0]=tres;
	  if(tempo[0]==4)
		  display[0]=quatro;
	  if(tempo[0]==5)
		  display[0]=cinco;
	  if(tempo[0]==6)
		  display[0]=seis;
	  if(tempo[0]==7)
		  display[0]=sete;
	  if(tempo[0]==8)
		  display[0]=oito;
	  if(tempo[0]==9)
		  display[0]=nove;

	  if(tempo[1]==0)
		  display[1]=zero;
	  if(tempo[1]==1)
		  display[1]=um;
	  if(tempo[1]==2)
		  display[1]=dois;
	  if(tempo[1]==3)
		  display[1]=tres;
	  if(tempo[1]==4)
		  display[1]=quatro;
	  if(tempo[1]==5)
		  display[1]=cinco;
	  if(tempo[1]==6)
		  display[1]=seis;
	  if(tempo[1]==7)
		  display[1]=sete;
	  if(tempo[1]==8)
		  display[1]=oito;
	  if(tempo[1]==9)
		  display[1]=nove;
}
void multiplexa (void)
{
	if(TIM9->SR&TIM_SR_UIF)
	{	TIM9->SR&=~TIM_SR_UIF;
		aciona++;

		if(aciona==0){
			GPIOB->ODR|=GPIO_ODR_ODR_7;
			GPIOB->ODR&=~GPIO_ODR_ODR_8;
			GPIOB->ODR|=display[aciona];

		}
		if(aciona==1){
			GPIOB->ODR|=GPIO_ODR_ODR_8;
			GPIOB->ODR&=~GPIO_ODR_ODR_1;
			GPIOB->ODR|=display[aciona];

		}
		if(aciona>1)
			aciona=0;
	}
}
