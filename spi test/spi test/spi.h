/*
 * spi.h
 *
 * Created: 04.09.2017 08:08:09
 *  Author: uidn5332
 */ 

//initialisiert den SPI-Bus
void SPI_MasterInit(void);
//sendet Daten auf den SPI-Bus
void SPI_Send(char cData);
