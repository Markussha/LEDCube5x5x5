 /*
 * Created: 04.09.2017 08:07:54
 *  Author: uidn5332
 */
 
 //Einbinden aller benötigten Bibliotheken
 #include <avr/io.h>
 #include <avr/interrupt.h>
 #include "spi.h"

//----------------------------------------------------------------------------------------------
//Funktion: SPI_MasterInit
//Initialisiert den SPI-Bus für die LED-Treiber
//Aufgerufene Funktionen: keine
//Zurückgegebene Werte	: keine
//----------------------------------------------------------------------------------------------
 void SPI_MasterInit(void)
 {
 /* Set MOSI and SCK output, all others input */
 DDRB |= (1<<PB3)|(1<<PB5);
 PORTB |= (1<<PB3)|(1<<PB5);
 /* Enable SPI, Master, set clock rate fck/16 */
 SPCR |= (1<<SPE)|(1<<MSTR)|(1<<SPR1)|(1<<SPI2X);
 }
 
 //----------------------------------------------------------------------------------------------
 //Funktion: SPI_Send
 //Sendet Daten auf den SPI-Bus
 //Aufgerufene Funktionen: keine
 //Zurückgegebene Werte	: keine
 //----------------------------------------------------------------------------------------------
 void SPI_Send(char cData)
 {
 /* Start transmission */
 SPDR = cData;
 /* Wait for transmission complete */
 while(!(SPSR & (1<<SPIF)));
 }