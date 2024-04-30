#include <CAN.h>
#include <CAN_config.h>
#include <ESP32CAN.h>
#include <can_regdef.h>

#include "ESP32CAN.h"
#include <CAN_config.h>

//------------TX Variables Defaut Values------------//


//------------TX Messages Parameters------------//





//------------TX Messages Sender------------//

//------------RX Messages Parameters------------//

typedef struct
{
	uint16_t PDO1_DCU_0 = 0x00;
	uint16_t PDO1_DCU_1 = 0x00;
	uint16_t PDO1_DCU_2 = 0x00;
	uint16_t PDO1_DCU_3 = 0x00;
	uint16_t PDO1_DCU_4 = 0x00;
	uint16_t PDO1_DCU_5 = 0x00;
	uint16_t PDO1_DCU_6 = 0x00;
	uint16_t PDO1_DCU_7 = 0x00;
} PDO1_DCU_Data;

typedef struct
{
	uint16_t Bat_Volts_SDL_Val = 0x00;
	uint16_t Engine_RPM_Val = 0x00;
	uint16_t GPS_Speed_Val = 0x00;
	uint16_t Gear_Val = 0x00;
} PDO1_DCU_Val;

typedef struct
{
	uint16_t PDO2_DCU_0 = 0x00;
	uint16_t PDO2_DCU_1 = 0x00;
	uint16_t PDO2_DCU_2 = 0x00;
	uint16_t PDO2_DCU_3 = 0x00;
	uint16_t PDO2_DCU_4 = 0x00;
	uint16_t PDO2_DCU_5 = 0x00;
	uint16_t PDO2_DCU_6 = 0x00;
	uint16_t PDO2_DCU_7 = 0x00;
} PDO2_DCU_Data;

typedef struct
{
	uint16_t Eng_Oil_Pres_Val = 0x00;
	uint16_t Engine_Temp_Val = 0x00;
	uint16_t Air_Temp_Inlet_Val = 0x00;
	uint16_t ECU_Temp_Val = 0x00;
} PDO2_DCU_Val;

typedef struct
{
	uint16_t PDO3_DCU_0 = 0x00;
	uint16_t PDO3_DCU_1 = 0x00;
	uint16_t PDO3_DCU_2 = 0x00;
	uint16_t PDO3_DCU_3 = 0x00;
	uint16_t PDO3_DCU_4 = 0x00;
	uint16_t PDO3_DCU_5 = 0x00;
	uint16_t PDO3_DCU_6 = 0x00;
	uint16_t PDO3_DCU_7 = 0x00;
} PDO3_DCU_Data;

typedef struct
{
	uint16_t Brake_Pressure_Front_Val = 0x00;
	uint16_t Brake_Pressure_Rear_Val = 0x00;
	uint16_t manifold_Pres_Val = 0x00;
	uint16_t Fuel_Pres_Val = 0x00;
} PDO3_DCU_Val;

typedef struct
{
	uint16_t PDO4_DCU_0 = 0x00;
	uint16_t PDO4_DCU_1 = 0x00;
	uint16_t PDO4_DCU_2 = 0x00;
	uint16_t PDO4_DCU_3 = 0x00;
	uint16_t PDO4_DCU_4 = 0x00;
	uint16_t PDO4_DCU_5 = 0x00;
	uint16_t PDO4_DCU_6 = 0x00;
	uint16_t PDO4_DCU_7 = 0x00;
} PDO4_DCU_Data;

typedef struct
{
	uint16_t Exhaust_Temperature_Cylinder_1_Val = 0x00;
	uint16_t Exhaust_Temperature_Cylinder_2_Val = 0x00;
	uint16_t Exhaust_Temperature_Cylinder_3_Val = 0x00;
	uint16_t SDL_Temp_Val = 0x00;
} PDO4_DCU_Val;

typedef struct
{
	uint16_t PDO5_DCU_0 = 0x00;
	uint16_t PDO5_DCU_1 = 0x00;
	uint16_t PDO5_DCU_2 = 0x00;
	uint16_t PDO5_DCU_3 = 0x00;
	uint16_t PDO5_DCU_4 = 0x00;
	uint16_t PDO5_DCU_5 = 0x00;
	uint16_t PDO5_DCU_6 = 0x00;
	uint16_t PDO5_DCU_7 = 0x00;
} PDO5_DCU_Data;

typedef struct
{
	uint16_t Lambda_1_Val = 0x00;
	uint16_t G_Force_Lat_Val = 0x00;
	uint16_t G_Force_Long_Val = 0x00;
	uint16_t G_Force_Vert_Val = 0x00;
} PDO5_DCU_Val;

typedef struct
{
	uint16_t PDO6_DCU_0 = 0x00;
	uint16_t PDO6_DCU_1 = 0x00;
	uint16_t PDO6_DCU_2 = 0x00;
	uint16_t PDO6_DCU_3 = 0x00;
	uint16_t PDO6_DCU_4 = 0x00;
	uint16_t PDO6_DCU_5 = 0x00;
	uint16_t PDO6_DCU_6 = 0x00;
	uint16_t PDO6_DCU_7 = 0x00;
} PDO6_DCU_Data;

typedef struct
{
	uint16_t Throttle_Pos_Val = 0x00;
	uint16_t Fuel_Used_Val = 0x00;
	uint16_t Beacon_Val = 0x00;
	uint16_t GPS_Altitude_Val = 0x00;
} PDO6_DCU_Val;

typedef struct
{
	uint16_t PDO7_DCU_0 = 0x00;
	uint16_t PDO7_DCU_1 = 0x00;
	uint16_t PDO7_DCU_2 = 0x00;
	uint16_t PDO7_DCU_3 = 0x00;
	uint16_t PDO7_DCU_4 = 0x00;
	uint16_t PDO7_DCU_5 = 0x00;
	uint16_t PDO7_DCU_6 = 0x00;
	uint16_t PDO7_DCU_7 = 0x00;
} PDO7_DCU_Data;

typedef struct
{
	uint16_t GPS_Latitude_Val = 0x00;
	uint16_t GPS_Longitude_Val = 0x00;
} PDO7_DCU_Val;

//----------------RX Variables Values----------------//

/*
// PDO1_DCU Message:
int Bat_Volts_SDL = 0x00;
int Engine_RPM = 0x00;
int GPS_Speed = 0x00;
int Gear = 0x00;

// PDO2_DCU Message:
int Eng_Oil_Pres = 0x00;
int Engine_Temp = 0x00;
int Air_Temp_Inlet = 0x00;
int ECU_Temp = 0x00;

// PDO3_DCU Message:
int Brake_Pressure_Front = 0x00;
int Brake_Pressure_Rear = 0x00;
int manifold_Pres = 0x00;
int Fuel_Pres = 0x00;

// PDO4_DCU Message:
int Exhaust_Temperature_Cylinder_1 = 0x00;
int Exhaust_Temperature_Cylinder_2 = 0x00;
int Exhaust_Temperature_Cylinder_3 = 0x00;
int SDL_Temp = 0x00;

// PDO5_DCU Message:
int Lambda_1 = 0x00;
int G_Force_Lat = 0x00;
int G_Force_Long = 0x00;
int G_Force_Vert = 0x00;

// PDO6_DCU Message:
int Throttle_Pos = 0x00;
int Fuel_Used = 0x00;
int Beacon = 0x00;
int GPS_Altitude = 0x00;

// PDO7_DCU Message:
int GPS_Latitude = 0x00;
int GPS_Longitude = 0x00;

*/


void atualizaRX_PDO1_DCU (PDO1_DCU_Val *PDO1_DCU_Val, PDO1_DCU_Data *PDO1_DCU_Data)
{
	bitWrite(PDO1_DCU_Val->Gear_Val, 8, bitRead(PDO1_DCU_Data->PDO1_DCU_0, 0));
	bitWrite(PDO1_DCU_Val->Gear_Val, 9, bitRead(PDO1_DCU_Data->PDO1_DCU_0, 1));
	bitWrite(PDO1_DCU_Val->Gear_Val, 10, bitRead(PDO1_DCU_Data->PDO1_DCU_0, 2));
	bitWrite(PDO1_DCU_Val->Gear_Val, 11, bitRead(PDO1_DCU_Data->PDO1_DCU_0, 3));
	bitWrite(PDO1_DCU_Val->Gear_Val, 12, bitRead(PDO1_DCU_Data->PDO1_DCU_0, 4));
	bitWrite(PDO1_DCU_Val->Gear_Val, 13, bitRead(PDO1_DCU_Data->PDO1_DCU_0, 5));
	bitWrite(PDO1_DCU_Val->Gear_Val, 14, bitRead(PDO1_DCU_Data->PDO1_DCU_0, 6));
	bitWrite(PDO1_DCU_Val->Gear_Val, 15, bitRead(PDO1_DCU_Data->PDO1_DCU_0, 7));
	bitWrite(PDO1_DCU_Val->Gear_Val, 0, bitRead(PDO1_DCU_Data->PDO1_DCU_1, 0));
	bitWrite(PDO1_DCU_Val->Gear_Val, 1, bitRead(PDO1_DCU_Data->PDO1_DCU_1, 1));
	bitWrite(PDO1_DCU_Val->Gear_Val, 2, bitRead(PDO1_DCU_Data->PDO1_DCU_1, 2));
	bitWrite(PDO1_DCU_Val->Gear_Val, 3, bitRead(PDO1_DCU_Data->PDO1_DCU_1, 3));
	bitWrite(PDO1_DCU_Val->Gear_Val, 4, bitRead(PDO1_DCU_Data->PDO1_DCU_1, 4));
	bitWrite(PDO1_DCU_Val->Gear_Val, 5, bitRead(PDO1_DCU_Data->PDO1_DCU_1, 5));
	bitWrite(PDO1_DCU_Val->Gear_Val, 6, bitRead(PDO1_DCU_Data->PDO1_DCU_1, 6));
	bitWrite(PDO1_DCU_Val->Gear_Val, 7, bitRead(PDO1_DCU_Data->PDO1_DCU_1, 7));
	bitWrite(PDO1_DCU_Val->GPS_Speed_Val, 8, bitRead(PDO1_DCU_Data->PDO1_DCU_2, 0));
	bitWrite(PDO1_DCU_Val->GPS_Speed_Val, 9, bitRead(PDO1_DCU_Data->PDO1_DCU_2, 1));
	bitWrite(PDO1_DCU_Val->GPS_Speed_Val, 10, bitRead(PDO1_DCU_Data->PDO1_DCU_2, 2));
	bitWrite(PDO1_DCU_Val->GPS_Speed_Val, 11, bitRead(PDO1_DCU_Data->PDO1_DCU_2, 3));
	bitWrite(PDO1_DCU_Val->GPS_Speed_Val, 12, bitRead(PDO1_DCU_Data->PDO1_DCU_2, 4));
	bitWrite(PDO1_DCU_Val->GPS_Speed_Val, 13, bitRead(PDO1_DCU_Data->PDO1_DCU_2, 5));
	bitWrite(PDO1_DCU_Val->GPS_Speed_Val, 14, bitRead(PDO1_DCU_Data->PDO1_DCU_2, 6));
	bitWrite(PDO1_DCU_Val->GPS_Speed_Val, 15, bitRead(PDO1_DCU_Data->PDO1_DCU_2, 7));
	bitWrite(PDO1_DCU_Val->GPS_Speed_Val, 0, bitRead(PDO1_DCU_Data->PDO1_DCU_3, 0));
	bitWrite(PDO1_DCU_Val->GPS_Speed_Val, 1, bitRead(PDO1_DCU_Data->PDO1_DCU_3, 1));
	bitWrite(PDO1_DCU_Val->GPS_Speed_Val, 2, bitRead(PDO1_DCU_Data->PDO1_DCU_3, 2));
	bitWrite(PDO1_DCU_Val->GPS_Speed_Val, 3, bitRead(PDO1_DCU_Data->PDO1_DCU_3, 3));
	bitWrite(PDO1_DCU_Val->GPS_Speed_Val, 4, bitRead(PDO1_DCU_Data->PDO1_DCU_3, 4));
	bitWrite(PDO1_DCU_Val->GPS_Speed_Val, 5, bitRead(PDO1_DCU_Data->PDO1_DCU_3, 5));
	bitWrite(PDO1_DCU_Val->GPS_Speed_Val, 6, bitRead(PDO1_DCU_Data->PDO1_DCU_3, 6));
	bitWrite(PDO1_DCU_Val->GPS_Speed_Val, 7, bitRead(PDO1_DCU_Data->PDO1_DCU_3, 7));
	bitWrite(PDO1_DCU_Val->Engine_RPM_Val, 8, bitRead(PDO1_DCU_Data->PDO1_DCU_4, 0));
	bitWrite(PDO1_DCU_Val->Engine_RPM_Val, 9, bitRead(PDO1_DCU_Data->PDO1_DCU_4, 1));
	bitWrite(PDO1_DCU_Val->Engine_RPM_Val, 10, bitRead(PDO1_DCU_Data->PDO1_DCU_4, 2));
	bitWrite(PDO1_DCU_Val->Engine_RPM_Val, 11, bitRead(PDO1_DCU_Data->PDO1_DCU_4, 3));
	bitWrite(PDO1_DCU_Val->Engine_RPM_Val, 12, bitRead(PDO1_DCU_Data->PDO1_DCU_4, 4));
	bitWrite(PDO1_DCU_Val->Engine_RPM_Val, 13, bitRead(PDO1_DCU_Data->PDO1_DCU_4, 5));
	bitWrite(PDO1_DCU_Val->Engine_RPM_Val, 14, bitRead(PDO1_DCU_Data->PDO1_DCU_4, 6));
	bitWrite(PDO1_DCU_Val->Engine_RPM_Val, 15, bitRead(PDO1_DCU_Data->PDO1_DCU_4, 7));
	bitWrite(PDO1_DCU_Val->Engine_RPM_Val, 0, bitRead(PDO1_DCU_Data->PDO1_DCU_5, 0));
	bitWrite(PDO1_DCU_Val->Engine_RPM_Val, 1, bitRead(PDO1_DCU_Data->PDO1_DCU_5, 1));
	bitWrite(PDO1_DCU_Val->Engine_RPM_Val, 2, bitRead(PDO1_DCU_Data->PDO1_DCU_5, 2));
	bitWrite(PDO1_DCU_Val->Engine_RPM_Val, 3, bitRead(PDO1_DCU_Data->PDO1_DCU_5, 3));
	bitWrite(PDO1_DCU_Val->Engine_RPM_Val, 4, bitRead(PDO1_DCU_Data->PDO1_DCU_5, 4));
	bitWrite(PDO1_DCU_Val->Engine_RPM_Val, 5, bitRead(PDO1_DCU_Data->PDO1_DCU_5, 5));
	bitWrite(PDO1_DCU_Val->Engine_RPM_Val, 6, bitRead(PDO1_DCU_Data->PDO1_DCU_5, 6));
	bitWrite(PDO1_DCU_Val->Engine_RPM_Val, 7, bitRead(PDO1_DCU_Data->PDO1_DCU_5, 7));
	bitWrite(PDO1_DCU_Val->Bat_Volts_SDL_Val, 8, bitRead(PDO1_DCU_Data->PDO1_DCU_6, 0));
	bitWrite(PDO1_DCU_Val->Bat_Volts_SDL_Val, 9, bitRead(PDO1_DCU_Data->PDO1_DCU_6, 1));
	bitWrite(PDO1_DCU_Val->Bat_Volts_SDL_Val, 10, bitRead(PDO1_DCU_Data->PDO1_DCU_6, 2));
	bitWrite(PDO1_DCU_Val->Bat_Volts_SDL_Val, 11, bitRead(PDO1_DCU_Data->PDO1_DCU_6, 3));
	bitWrite(PDO1_DCU_Val->Bat_Volts_SDL_Val, 12, bitRead(PDO1_DCU_Data->PDO1_DCU_6, 4));
	bitWrite(PDO1_DCU_Val->Bat_Volts_SDL_Val, 13, bitRead(PDO1_DCU_Data->PDO1_DCU_6, 5));
	bitWrite(PDO1_DCU_Val->Bat_Volts_SDL_Val, 14, bitRead(PDO1_DCU_Data->PDO1_DCU_6, 6));
	bitWrite(PDO1_DCU_Val->Bat_Volts_SDL_Val, 15, bitRead(PDO1_DCU_Data->PDO1_DCU_6, 7));
	bitWrite(PDO1_DCU_Val->Bat_Volts_SDL_Val, 0, bitRead(PDO1_DCU_Data->PDO1_DCU_7, 0));
	bitWrite(PDO1_DCU_Val->Bat_Volts_SDL_Val, 1, bitRead(PDO1_DCU_Data->PDO1_DCU_7, 1));
	bitWrite(PDO1_DCU_Val->Bat_Volts_SDL_Val, 2, bitRead(PDO1_DCU_Data->PDO1_DCU_7, 2));
	bitWrite(PDO1_DCU_Val->Bat_Volts_SDL_Val, 3, bitRead(PDO1_DCU_Data->PDO1_DCU_7, 3));
	bitWrite(PDO1_DCU_Val->Bat_Volts_SDL_Val, 4, bitRead(PDO1_DCU_Data->PDO1_DCU_7, 4));
	bitWrite(PDO1_DCU_Val->Bat_Volts_SDL_Val, 5, bitRead(PDO1_DCU_Data->PDO1_DCU_7, 5));
	bitWrite(PDO1_DCU_Val->Bat_Volts_SDL_Val, 6, bitRead(PDO1_DCU_Data->PDO1_DCU_7, 6));
	bitWrite(PDO1_DCU_Val->Bat_Volts_SDL_Val, 7, bitRead(PDO1_DCU_Data->PDO1_DCU_7, 7));
}

void atualizaRX_PDO2_DCU (PDO2_DCU_Val *PDO2_DCU_Val, PDO2_DCU_Data *PDO2_DCU_Data)
{
	bitWrite(PDO2_DCU_Val->ECU_Temp_Val, 8, bitRead(PDO2_DCU_Data->PDO2_DCU_0, 0));
	bitWrite(PDO2_DCU_Val->ECU_Temp_Val, 9, bitRead(PDO2_DCU_Data->PDO2_DCU_0, 1));
	bitWrite(PDO2_DCU_Val->ECU_Temp_Val, 10, bitRead(PDO2_DCU_Data->PDO2_DCU_0, 2));
	bitWrite(PDO2_DCU_Val->ECU_Temp_Val, 11, bitRead(PDO2_DCU_Data->PDO2_DCU_0, 3));
	bitWrite(PDO2_DCU_Val->ECU_Temp_Val, 12, bitRead(PDO2_DCU_Data->PDO2_DCU_0, 4));
	bitWrite(PDO2_DCU_Val->ECU_Temp_Val, 13, bitRead(PDO2_DCU_Data->PDO2_DCU_0, 5));
	bitWrite(PDO2_DCU_Val->ECU_Temp_Val, 14, bitRead(PDO2_DCU_Data->PDO2_DCU_0, 6));
	bitWrite(PDO2_DCU_Val->ECU_Temp_Val, 15, bitRead(PDO2_DCU_Data->PDO2_DCU_0, 7));
	bitWrite(PDO2_DCU_Val->ECU_Temp_Val, 0, bitRead(PDO2_DCU_Data->PDO2_DCU_1, 0));
	bitWrite(PDO2_DCU_Val->ECU_Temp_Val, 1, bitRead(PDO2_DCU_Data->PDO2_DCU_1, 1));
	bitWrite(PDO2_DCU_Val->ECU_Temp_Val, 2, bitRead(PDO2_DCU_Data->PDO2_DCU_1, 2));
	bitWrite(PDO2_DCU_Val->ECU_Temp_Val, 3, bitRead(PDO2_DCU_Data->PDO2_DCU_1, 3));
	bitWrite(PDO2_DCU_Val->ECU_Temp_Val, 4, bitRead(PDO2_DCU_Data->PDO2_DCU_1, 4));
	bitWrite(PDO2_DCU_Val->ECU_Temp_Val, 5, bitRead(PDO2_DCU_Data->PDO2_DCU_1, 5));
	bitWrite(PDO2_DCU_Val->ECU_Temp_Val, 6, bitRead(PDO2_DCU_Data->PDO2_DCU_1, 6));
	bitWrite(PDO2_DCU_Val->ECU_Temp_Val, 7, bitRead(PDO2_DCU_Data->PDO2_DCU_1, 7));
	bitWrite(PDO2_DCU_Val->Air_Temp_Inlet_Val, 8, bitRead(PDO2_DCU_Data->PDO2_DCU_2, 0));
	bitWrite(PDO2_DCU_Val->Air_Temp_Inlet_Val, 9, bitRead(PDO2_DCU_Data->PDO2_DCU_2, 1));
	bitWrite(PDO2_DCU_Val->Air_Temp_Inlet_Val, 10, bitRead(PDO2_DCU_Data->PDO2_DCU_2, 2));
	bitWrite(PDO2_DCU_Val->Air_Temp_Inlet_Val, 11, bitRead(PDO2_DCU_Data->PDO2_DCU_2, 3));
	bitWrite(PDO2_DCU_Val->Air_Temp_Inlet_Val, 12, bitRead(PDO2_DCU_Data->PDO2_DCU_2, 4));
	bitWrite(PDO2_DCU_Val->Air_Temp_Inlet_Val, 13, bitRead(PDO2_DCU_Data->PDO2_DCU_2, 5));
	bitWrite(PDO2_DCU_Val->Air_Temp_Inlet_Val, 14, bitRead(PDO2_DCU_Data->PDO2_DCU_2, 6));
	bitWrite(PDO2_DCU_Val->Air_Temp_Inlet_Val, 15, bitRead(PDO2_DCU_Data->PDO2_DCU_2, 7));
	bitWrite(PDO2_DCU_Val->Air_Temp_Inlet_Val, 0, bitRead(PDO2_DCU_Data->PDO2_DCU_3, 0));
	bitWrite(PDO2_DCU_Val->Air_Temp_Inlet_Val, 1, bitRead(PDO2_DCU_Data->PDO2_DCU_3, 1));
	bitWrite(PDO2_DCU_Val->Air_Temp_Inlet_Val, 2, bitRead(PDO2_DCU_Data->PDO2_DCU_3, 2));
	bitWrite(PDO2_DCU_Val->Air_Temp_Inlet_Val, 3, bitRead(PDO2_DCU_Data->PDO2_DCU_3, 3));
	bitWrite(PDO2_DCU_Val->Air_Temp_Inlet_Val, 4, bitRead(PDO2_DCU_Data->PDO2_DCU_3, 4));
	bitWrite(PDO2_DCU_Val->Air_Temp_Inlet_Val, 5, bitRead(PDO2_DCU_Data->PDO2_DCU_3, 5));
	bitWrite(PDO2_DCU_Val->Air_Temp_Inlet_Val, 6, bitRead(PDO2_DCU_Data->PDO2_DCU_3, 6));
	bitWrite(PDO2_DCU_Val->Air_Temp_Inlet_Val, 7, bitRead(PDO2_DCU_Data->PDO2_DCU_3, 7));
	bitWrite(PDO2_DCU_Val->Engine_Temp_Val, 8, bitRead(PDO2_DCU_Data->PDO2_DCU_4, 0));
	bitWrite(PDO2_DCU_Val->Engine_Temp_Val, 9, bitRead(PDO2_DCU_Data->PDO2_DCU_4, 1));
	bitWrite(PDO2_DCU_Val->Engine_Temp_Val, 10, bitRead(PDO2_DCU_Data->PDO2_DCU_4, 2));
	bitWrite(PDO2_DCU_Val->Engine_Temp_Val, 11, bitRead(PDO2_DCU_Data->PDO2_DCU_4, 3));
	bitWrite(PDO2_DCU_Val->Engine_Temp_Val, 12, bitRead(PDO2_DCU_Data->PDO2_DCU_4, 4));
	bitWrite(PDO2_DCU_Val->Engine_Temp_Val, 13, bitRead(PDO2_DCU_Data->PDO2_DCU_4, 5));
	bitWrite(PDO2_DCU_Val->Engine_Temp_Val, 14, bitRead(PDO2_DCU_Data->PDO2_DCU_4, 6));
	bitWrite(PDO2_DCU_Val->Engine_Temp_Val, 15, bitRead(PDO2_DCU_Data->PDO2_DCU_4, 7));
	bitWrite(PDO2_DCU_Val->Engine_Temp_Val, 0, bitRead(PDO2_DCU_Data->PDO2_DCU_5, 0));
	bitWrite(PDO2_DCU_Val->Engine_Temp_Val, 1, bitRead(PDO2_DCU_Data->PDO2_DCU_5, 1));
	bitWrite(PDO2_DCU_Val->Engine_Temp_Val, 2, bitRead(PDO2_DCU_Data->PDO2_DCU_5, 2));
	bitWrite(PDO2_DCU_Val->Engine_Temp_Val, 3, bitRead(PDO2_DCU_Data->PDO2_DCU_5, 3));
	bitWrite(PDO2_DCU_Val->Engine_Temp_Val, 4, bitRead(PDO2_DCU_Data->PDO2_DCU_5, 4));
	bitWrite(PDO2_DCU_Val->Engine_Temp_Val, 5, bitRead(PDO2_DCU_Data->PDO2_DCU_5, 5));
	bitWrite(PDO2_DCU_Val->Engine_Temp_Val, 6, bitRead(PDO2_DCU_Data->PDO2_DCU_5, 6));
	bitWrite(PDO2_DCU_Val->Engine_Temp_Val, 7, bitRead(PDO2_DCU_Data->PDO2_DCU_5, 7));
	bitWrite(PDO2_DCU_Val->Eng_Oil_Pres_Val, 8, bitRead(PDO2_DCU_Data->PDO2_DCU_6, 0));
	bitWrite(PDO2_DCU_Val->Eng_Oil_Pres_Val, 9, bitRead(PDO2_DCU_Data->PDO2_DCU_6, 1));
	bitWrite(PDO2_DCU_Val->Eng_Oil_Pres_Val, 10, bitRead(PDO2_DCU_Data->PDO2_DCU_6, 2));
	bitWrite(PDO2_DCU_Val->Eng_Oil_Pres_Val, 11, bitRead(PDO2_DCU_Data->PDO2_DCU_6, 3));
	bitWrite(PDO2_DCU_Val->Eng_Oil_Pres_Val, 12, bitRead(PDO2_DCU_Data->PDO2_DCU_6, 4));
	bitWrite(PDO2_DCU_Val->Eng_Oil_Pres_Val, 13, bitRead(PDO2_DCU_Data->PDO2_DCU_6, 5));
	bitWrite(PDO2_DCU_Val->Eng_Oil_Pres_Val, 14, bitRead(PDO2_DCU_Data->PDO2_DCU_6, 6));
	bitWrite(PDO2_DCU_Val->Eng_Oil_Pres_Val, 15, bitRead(PDO2_DCU_Data->PDO2_DCU_6, 7));
	bitWrite(PDO2_DCU_Val->Eng_Oil_Pres_Val, 0, bitRead(PDO2_DCU_Data->PDO2_DCU_7, 0));
	bitWrite(PDO2_DCU_Val->Eng_Oil_Pres_Val, 1, bitRead(PDO2_DCU_Data->PDO2_DCU_7, 1));
	bitWrite(PDO2_DCU_Val->Eng_Oil_Pres_Val, 2, bitRead(PDO2_DCU_Data->PDO2_DCU_7, 2));
	bitWrite(PDO2_DCU_Val->Eng_Oil_Pres_Val, 3, bitRead(PDO2_DCU_Data->PDO2_DCU_7, 3));
	bitWrite(PDO2_DCU_Val->Eng_Oil_Pres_Val, 4, bitRead(PDO2_DCU_Data->PDO2_DCU_7, 4));
	bitWrite(PDO2_DCU_Val->Eng_Oil_Pres_Val, 5, bitRead(PDO2_DCU_Data->PDO2_DCU_7, 5));
	bitWrite(PDO2_DCU_Val->Eng_Oil_Pres_Val, 6, bitRead(PDO2_DCU_Data->PDO2_DCU_7, 6));
	bitWrite(PDO2_DCU_Val->Eng_Oil_Pres_Val, 7, bitRead(PDO2_DCU_Data->PDO2_DCU_7, 7));
}

void atualizaRX_PDO3_DCU (PDO3_DCU_Val *PDO3_DCU_Val, PDO3_DCU_Data *PDO3_DCU_Data)
{
	bitWrite(PDO3_DCU_Val->Fuel_Pres_Val, 8, bitRead(PDO3_DCU_Data->PDO3_DCU_0, 0));
	bitWrite(PDO3_DCU_Val->Fuel_Pres_Val, 9, bitRead(PDO3_DCU_Data->PDO3_DCU_0, 1));
	bitWrite(PDO3_DCU_Val->Fuel_Pres_Val, 10, bitRead(PDO3_DCU_Data->PDO3_DCU_0, 2));
	bitWrite(PDO3_DCU_Val->Fuel_Pres_Val, 11, bitRead(PDO3_DCU_Data->PDO3_DCU_0, 3));
	bitWrite(PDO3_DCU_Val->Fuel_Pres_Val, 12, bitRead(PDO3_DCU_Data->PDO3_DCU_0, 4));
	bitWrite(PDO3_DCU_Val->Fuel_Pres_Val, 13, bitRead(PDO3_DCU_Data->PDO3_DCU_0, 5));
	bitWrite(PDO3_DCU_Val->Fuel_Pres_Val, 14, bitRead(PDO3_DCU_Data->PDO3_DCU_0, 6));
	bitWrite(PDO3_DCU_Val->Fuel_Pres_Val, 15, bitRead(PDO3_DCU_Data->PDO3_DCU_0, 7));
	bitWrite(PDO3_DCU_Val->Fuel_Pres_Val, 0, bitRead(PDO3_DCU_Data->PDO3_DCU_1, 0));
	bitWrite(PDO3_DCU_Val->Fuel_Pres_Val, 1, bitRead(PDO3_DCU_Data->PDO3_DCU_1, 1));
	bitWrite(PDO3_DCU_Val->Fuel_Pres_Val, 2, bitRead(PDO3_DCU_Data->PDO3_DCU_1, 2));
	bitWrite(PDO3_DCU_Val->Fuel_Pres_Val, 3, bitRead(PDO3_DCU_Data->PDO3_DCU_1, 3));
	bitWrite(PDO3_DCU_Val->Fuel_Pres_Val, 4, bitRead(PDO3_DCU_Data->PDO3_DCU_1, 4));
	bitWrite(PDO3_DCU_Val->Fuel_Pres_Val, 5, bitRead(PDO3_DCU_Data->PDO3_DCU_1, 5));
	bitWrite(PDO3_DCU_Val->Fuel_Pres_Val, 6, bitRead(PDO3_DCU_Data->PDO3_DCU_1, 6));
	bitWrite(PDO3_DCU_Val->Fuel_Pres_Val, 7, bitRead(PDO3_DCU_Data->PDO3_DCU_1, 7));
	bitWrite(PDO3_DCU_Val->manifold_Pres_Val, 8, bitRead(PDO3_DCU_Data->PDO3_DCU_2, 0));
	bitWrite(PDO3_DCU_Val->manifold_Pres_Val, 9, bitRead(PDO3_DCU_Data->PDO3_DCU_2, 1));
	bitWrite(PDO3_DCU_Val->manifold_Pres_Val, 10, bitRead(PDO3_DCU_Data->PDO3_DCU_2, 2));
	bitWrite(PDO3_DCU_Val->manifold_Pres_Val, 11, bitRead(PDO3_DCU_Data->PDO3_DCU_2, 3));
	bitWrite(PDO3_DCU_Val->manifold_Pres_Val, 12, bitRead(PDO3_DCU_Data->PDO3_DCU_2, 4));
	bitWrite(PDO3_DCU_Val->manifold_Pres_Val, 13, bitRead(PDO3_DCU_Data->PDO3_DCU_2, 5));
	bitWrite(PDO3_DCU_Val->manifold_Pres_Val, 14, bitRead(PDO3_DCU_Data->PDO3_DCU_2, 6));
	bitWrite(PDO3_DCU_Val->manifold_Pres_Val, 15, bitRead(PDO3_DCU_Data->PDO3_DCU_2, 7));
	bitWrite(PDO3_DCU_Val->manifold_Pres_Val, 0, bitRead(PDO3_DCU_Data->PDO3_DCU_3, 0));
	bitWrite(PDO3_DCU_Val->manifold_Pres_Val, 1, bitRead(PDO3_DCU_Data->PDO3_DCU_3, 1));
	bitWrite(PDO3_DCU_Val->manifold_Pres_Val, 2, bitRead(PDO3_DCU_Data->PDO3_DCU_3, 2));
	bitWrite(PDO3_DCU_Val->manifold_Pres_Val, 3, bitRead(PDO3_DCU_Data->PDO3_DCU_3, 3));
	bitWrite(PDO3_DCU_Val->manifold_Pres_Val, 4, bitRead(PDO3_DCU_Data->PDO3_DCU_3, 4));
	bitWrite(PDO3_DCU_Val->manifold_Pres_Val, 5, bitRead(PDO3_DCU_Data->PDO3_DCU_3, 5));
	bitWrite(PDO3_DCU_Val->manifold_Pres_Val, 6, bitRead(PDO3_DCU_Data->PDO3_DCU_3, 6));
	bitWrite(PDO3_DCU_Val->manifold_Pres_Val, 7, bitRead(PDO3_DCU_Data->PDO3_DCU_3, 7));
	bitWrite(PDO3_DCU_Val->Brake_Pressure_Rear_Val, 8, bitRead(PDO3_DCU_Data->PDO3_DCU_4, 0));
	bitWrite(PDO3_DCU_Val->Brake_Pressure_Rear_Val, 9, bitRead(PDO3_DCU_Data->PDO3_DCU_4, 1));
	bitWrite(PDO3_DCU_Val->Brake_Pressure_Rear_Val, 10, bitRead(PDO3_DCU_Data->PDO3_DCU_4, 2));
	bitWrite(PDO3_DCU_Val->Brake_Pressure_Rear_Val, 11, bitRead(PDO3_DCU_Data->PDO3_DCU_4, 3));
	bitWrite(PDO3_DCU_Val->Brake_Pressure_Rear_Val, 12, bitRead(PDO3_DCU_Data->PDO3_DCU_4, 4));
	bitWrite(PDO3_DCU_Val->Brake_Pressure_Rear_Val, 13, bitRead(PDO3_DCU_Data->PDO3_DCU_4, 5));
	bitWrite(PDO3_DCU_Val->Brake_Pressure_Rear_Val, 14, bitRead(PDO3_DCU_Data->PDO3_DCU_4, 6));
	bitWrite(PDO3_DCU_Val->Brake_Pressure_Rear_Val, 15, bitRead(PDO3_DCU_Data->PDO3_DCU_4, 7));
	bitWrite(PDO3_DCU_Val->Brake_Pressure_Rear_Val, 0, bitRead(PDO3_DCU_Data->PDO3_DCU_5, 0));
	bitWrite(PDO3_DCU_Val->Brake_Pressure_Rear_Val, 1, bitRead(PDO3_DCU_Data->PDO3_DCU_5, 1));
	bitWrite(PDO3_DCU_Val->Brake_Pressure_Rear_Val, 2, bitRead(PDO3_DCU_Data->PDO3_DCU_5, 2));
	bitWrite(PDO3_DCU_Val->Brake_Pressure_Rear_Val, 3, bitRead(PDO3_DCU_Data->PDO3_DCU_5, 3));
	bitWrite(PDO3_DCU_Val->Brake_Pressure_Rear_Val, 4, bitRead(PDO3_DCU_Data->PDO3_DCU_5, 4));
	bitWrite(PDO3_DCU_Val->Brake_Pressure_Rear_Val, 5, bitRead(PDO3_DCU_Data->PDO3_DCU_5, 5));
	bitWrite(PDO3_DCU_Val->Brake_Pressure_Rear_Val, 6, bitRead(PDO3_DCU_Data->PDO3_DCU_5, 6));
	bitWrite(PDO3_DCU_Val->Brake_Pressure_Rear_Val, 7, bitRead(PDO3_DCU_Data->PDO3_DCU_5, 7));
	bitWrite(PDO3_DCU_Val->Brake_Pressure_Front_Val, 8, bitRead(PDO3_DCU_Data->PDO3_DCU_6, 0));
	bitWrite(PDO3_DCU_Val->Brake_Pressure_Front_Val, 9, bitRead(PDO3_DCU_Data->PDO3_DCU_6, 1));
	bitWrite(PDO3_DCU_Val->Brake_Pressure_Front_Val, 10, bitRead(PDO3_DCU_Data->PDO3_DCU_6, 2));
	bitWrite(PDO3_DCU_Val->Brake_Pressure_Front_Val, 11, bitRead(PDO3_DCU_Data->PDO3_DCU_6, 3));
	bitWrite(PDO3_DCU_Val->Brake_Pressure_Front_Val, 12, bitRead(PDO3_DCU_Data->PDO3_DCU_6, 4));
	bitWrite(PDO3_DCU_Val->Brake_Pressure_Front_Val, 13, bitRead(PDO3_DCU_Data->PDO3_DCU_6, 5));
	bitWrite(PDO3_DCU_Val->Brake_Pressure_Front_Val, 14, bitRead(PDO3_DCU_Data->PDO3_DCU_6, 6));
	bitWrite(PDO3_DCU_Val->Brake_Pressure_Front_Val, 15, bitRead(PDO3_DCU_Data->PDO3_DCU_6, 7));
	bitWrite(PDO3_DCU_Val->Brake_Pressure_Front_Val, 0, bitRead(PDO3_DCU_Data->PDO3_DCU_7, 0));
	bitWrite(PDO3_DCU_Val->Brake_Pressure_Front_Val, 1, bitRead(PDO3_DCU_Data->PDO3_DCU_7, 1));
	bitWrite(PDO3_DCU_Val->Brake_Pressure_Front_Val, 2, bitRead(PDO3_DCU_Data->PDO3_DCU_7, 2));
	bitWrite(PDO3_DCU_Val->Brake_Pressure_Front_Val, 3, bitRead(PDO3_DCU_Data->PDO3_DCU_7, 3));
	bitWrite(PDO3_DCU_Val->Brake_Pressure_Front_Val, 4, bitRead(PDO3_DCU_Data->PDO3_DCU_7, 4));
	bitWrite(PDO3_DCU_Val->Brake_Pressure_Front_Val, 5, bitRead(PDO3_DCU_Data->PDO3_DCU_7, 5));
	bitWrite(PDO3_DCU_Val->Brake_Pressure_Front_Val, 6, bitRead(PDO3_DCU_Data->PDO3_DCU_7, 6));
	bitWrite(PDO3_DCU_Val->Brake_Pressure_Front_Val, 7, bitRead(PDO3_DCU_Data->PDO3_DCU_7, 7));
}

void atualizaRX_PDO4_DCU (PDO4_DCU_Val *PDO4_DCU_Val, PDO4_DCU_Data *PDO4_DCU_Data)
{
	bitWrite(PDO4_DCU_Val->SDL_Temp_Val, 8, bitRead(PDO4_DCU_Data->PDO4_DCU_0, 0));
	bitWrite(PDO4_DCU_Val->SDL_Temp_Val, 9, bitRead(PDO4_DCU_Data->PDO4_DCU_0, 1));
	bitWrite(PDO4_DCU_Val->SDL_Temp_Val, 10, bitRead(PDO4_DCU_Data->PDO4_DCU_0, 2));
	bitWrite(PDO4_DCU_Val->SDL_Temp_Val, 11, bitRead(PDO4_DCU_Data->PDO4_DCU_0, 3));
	bitWrite(PDO4_DCU_Val->SDL_Temp_Val, 12, bitRead(PDO4_DCU_Data->PDO4_DCU_0, 4));
	bitWrite(PDO4_DCU_Val->SDL_Temp_Val, 13, bitRead(PDO4_DCU_Data->PDO4_DCU_0, 5));
	bitWrite(PDO4_DCU_Val->SDL_Temp_Val, 14, bitRead(PDO4_DCU_Data->PDO4_DCU_0, 6));
	bitWrite(PDO4_DCU_Val->SDL_Temp_Val, 15, bitRead(PDO4_DCU_Data->PDO4_DCU_0, 7));
	bitWrite(PDO4_DCU_Val->SDL_Temp_Val, 0, bitRead(PDO4_DCU_Data->PDO4_DCU_1, 0));
	bitWrite(PDO4_DCU_Val->SDL_Temp_Val, 1, bitRead(PDO4_DCU_Data->PDO4_DCU_1, 1));
	bitWrite(PDO4_DCU_Val->SDL_Temp_Val, 2, bitRead(PDO4_DCU_Data->PDO4_DCU_1, 2));
	bitWrite(PDO4_DCU_Val->SDL_Temp_Val, 3, bitRead(PDO4_DCU_Data->PDO4_DCU_1, 3));
	bitWrite(PDO4_DCU_Val->SDL_Temp_Val, 4, bitRead(PDO4_DCU_Data->PDO4_DCU_1, 4));
	bitWrite(PDO4_DCU_Val->SDL_Temp_Val, 5, bitRead(PDO4_DCU_Data->PDO4_DCU_1, 5));
	bitWrite(PDO4_DCU_Val->SDL_Temp_Val, 6, bitRead(PDO4_DCU_Data->PDO4_DCU_1, 6));
	bitWrite(PDO4_DCU_Val->SDL_Temp_Val, 7, bitRead(PDO4_DCU_Data->PDO4_DCU_1, 7));
	bitWrite(PDO4_DCU_Val->Exhaust_Temperature_Cylinder_3_Val, 8, bitRead(PDO4_DCU_Data->PDO4_DCU_2, 0));
	bitWrite(PDO4_DCU_Val->Exhaust_Temperature_Cylinder_3_Val, 9, bitRead(PDO4_DCU_Data->PDO4_DCU_2, 1));
	bitWrite(PDO4_DCU_Val->Exhaust_Temperature_Cylinder_3_Val, 10, bitRead(PDO4_DCU_Data->PDO4_DCU_2, 2));
	bitWrite(PDO4_DCU_Val->Exhaust_Temperature_Cylinder_3_Val, 11, bitRead(PDO4_DCU_Data->PDO4_DCU_2, 3));
	bitWrite(PDO4_DCU_Val->Exhaust_Temperature_Cylinder_3_Val, 12, bitRead(PDO4_DCU_Data->PDO4_DCU_2, 4));
	bitWrite(PDO4_DCU_Val->Exhaust_Temperature_Cylinder_3_Val, 13, bitRead(PDO4_DCU_Data->PDO4_DCU_2, 5));
	bitWrite(PDO4_DCU_Val->Exhaust_Temperature_Cylinder_3_Val, 14, bitRead(PDO4_DCU_Data->PDO4_DCU_2, 6));
	bitWrite(PDO4_DCU_Val->Exhaust_Temperature_Cylinder_3_Val, 15, bitRead(PDO4_DCU_Data->PDO4_DCU_2, 7));
	bitWrite(PDO4_DCU_Val->Exhaust_Temperature_Cylinder_3_Val, 0, bitRead(PDO4_DCU_Data->PDO4_DCU_3, 0));
	bitWrite(PDO4_DCU_Val->Exhaust_Temperature_Cylinder_3_Val, 1, bitRead(PDO4_DCU_Data->PDO4_DCU_3, 1));
	bitWrite(PDO4_DCU_Val->Exhaust_Temperature_Cylinder_3_Val, 2, bitRead(PDO4_DCU_Data->PDO4_DCU_3, 2));
	bitWrite(PDO4_DCU_Val->Exhaust_Temperature_Cylinder_3_Val, 3, bitRead(PDO4_DCU_Data->PDO4_DCU_3, 3));
	bitWrite(PDO4_DCU_Val->Exhaust_Temperature_Cylinder_3_Val, 4, bitRead(PDO4_DCU_Data->PDO4_DCU_3, 4));
	bitWrite(PDO4_DCU_Val->Exhaust_Temperature_Cylinder_3_Val, 5, bitRead(PDO4_DCU_Data->PDO4_DCU_3, 5));
	bitWrite(PDO4_DCU_Val->Exhaust_Temperature_Cylinder_3_Val, 6, bitRead(PDO4_DCU_Data->PDO4_DCU_3, 6));
	bitWrite(PDO4_DCU_Val->Exhaust_Temperature_Cylinder_3_Val, 7, bitRead(PDO4_DCU_Data->PDO4_DCU_3, 7));
	bitWrite(PDO4_DCU_Val->Exhaust_Temperature_Cylinder_2_Val, 8, bitRead(PDO4_DCU_Data->PDO4_DCU_4, 0));
	bitWrite(PDO4_DCU_Val->Exhaust_Temperature_Cylinder_2_Val, 9, bitRead(PDO4_DCU_Data->PDO4_DCU_4, 1));
	bitWrite(PDO4_DCU_Val->Exhaust_Temperature_Cylinder_2_Val, 10, bitRead(PDO4_DCU_Data->PDO4_DCU_4, 2));
	bitWrite(PDO4_DCU_Val->Exhaust_Temperature_Cylinder_2_Val, 11, bitRead(PDO4_DCU_Data->PDO4_DCU_4, 3));
	bitWrite(PDO4_DCU_Val->Exhaust_Temperature_Cylinder_2_Val, 12, bitRead(PDO4_DCU_Data->PDO4_DCU_4, 4));
	bitWrite(PDO4_DCU_Val->Exhaust_Temperature_Cylinder_2_Val, 13, bitRead(PDO4_DCU_Data->PDO4_DCU_4, 5));
	bitWrite(PDO4_DCU_Val->Exhaust_Temperature_Cylinder_2_Val, 14, bitRead(PDO4_DCU_Data->PDO4_DCU_4, 6));
	bitWrite(PDO4_DCU_Val->Exhaust_Temperature_Cylinder_2_Val, 15, bitRead(PDO4_DCU_Data->PDO4_DCU_4, 7));
	bitWrite(PDO4_DCU_Val->Exhaust_Temperature_Cylinder_2_Val, 0, bitRead(PDO4_DCU_Data->PDO4_DCU_5, 0));
	bitWrite(PDO4_DCU_Val->Exhaust_Temperature_Cylinder_2_Val, 1, bitRead(PDO4_DCU_Data->PDO4_DCU_5, 1));
	bitWrite(PDO4_DCU_Val->Exhaust_Temperature_Cylinder_2_Val, 2, bitRead(PDO4_DCU_Data->PDO4_DCU_5, 2));
	bitWrite(PDO4_DCU_Val->Exhaust_Temperature_Cylinder_2_Val, 3, bitRead(PDO4_DCU_Data->PDO4_DCU_5, 3));
	bitWrite(PDO4_DCU_Val->Exhaust_Temperature_Cylinder_2_Val, 4, bitRead(PDO4_DCU_Data->PDO4_DCU_5, 4));
	bitWrite(PDO4_DCU_Val->Exhaust_Temperature_Cylinder_2_Val, 5, bitRead(PDO4_DCU_Data->PDO4_DCU_5, 5));
	bitWrite(PDO4_DCU_Val->Exhaust_Temperature_Cylinder_2_Val, 6, bitRead(PDO4_DCU_Data->PDO4_DCU_5, 6));
	bitWrite(PDO4_DCU_Val->Exhaust_Temperature_Cylinder_2_Val, 7, bitRead(PDO4_DCU_Data->PDO4_DCU_5, 7));
	bitWrite(PDO4_DCU_Val->Exhaust_Temperature_Cylinder_1_Val, 8, bitRead(PDO4_DCU_Data->PDO4_DCU_6, 0));
	bitWrite(PDO4_DCU_Val->Exhaust_Temperature_Cylinder_1_Val, 9, bitRead(PDO4_DCU_Data->PDO4_DCU_6, 1));
	bitWrite(PDO4_DCU_Val->Exhaust_Temperature_Cylinder_1_Val, 10, bitRead(PDO4_DCU_Data->PDO4_DCU_6, 2));
	bitWrite(PDO4_DCU_Val->Exhaust_Temperature_Cylinder_1_Val, 11, bitRead(PDO4_DCU_Data->PDO4_DCU_6, 3));
	bitWrite(PDO4_DCU_Val->Exhaust_Temperature_Cylinder_1_Val, 12, bitRead(PDO4_DCU_Data->PDO4_DCU_6, 4));
	bitWrite(PDO4_DCU_Val->Exhaust_Temperature_Cylinder_1_Val, 13, bitRead(PDO4_DCU_Data->PDO4_DCU_6, 5));
	bitWrite(PDO4_DCU_Val->Exhaust_Temperature_Cylinder_1_Val, 14, bitRead(PDO4_DCU_Data->PDO4_DCU_6, 6));
	bitWrite(PDO4_DCU_Val->Exhaust_Temperature_Cylinder_1_Val, 15, bitRead(PDO4_DCU_Data->PDO4_DCU_6, 7));
	bitWrite(PDO4_DCU_Val->Exhaust_Temperature_Cylinder_1_Val, 0, bitRead(PDO4_DCU_Data->PDO4_DCU_7, 0));
	bitWrite(PDO4_DCU_Val->Exhaust_Temperature_Cylinder_1_Val, 1, bitRead(PDO4_DCU_Data->PDO4_DCU_7, 1));
	bitWrite(PDO4_DCU_Val->Exhaust_Temperature_Cylinder_1_Val, 2, bitRead(PDO4_DCU_Data->PDO4_DCU_7, 2));
	bitWrite(PDO4_DCU_Val->Exhaust_Temperature_Cylinder_1_Val, 3, bitRead(PDO4_DCU_Data->PDO4_DCU_7, 3));
	bitWrite(PDO4_DCU_Val->Exhaust_Temperature_Cylinder_1_Val, 4, bitRead(PDO4_DCU_Data->PDO4_DCU_7, 4));
	bitWrite(PDO4_DCU_Val->Exhaust_Temperature_Cylinder_1_Val, 5, bitRead(PDO4_DCU_Data->PDO4_DCU_7, 5));
	bitWrite(PDO4_DCU_Val->Exhaust_Temperature_Cylinder_1_Val, 6, bitRead(PDO4_DCU_Data->PDO4_DCU_7, 6));
	bitWrite(PDO4_DCU_Val->Exhaust_Temperature_Cylinder_1_Val, 7, bitRead(PDO4_DCU_Data->PDO4_DCU_7, 7));
}

void atualizaRX_PDO5_DCU (PDO5_DCU_Val *PDO5_DCU_Val, PDO5_DCU_Data *PDO5_DCU_Data)
{
	bitWrite(PDO5_DCU_Val->G_Force_Vert_Val, 8, bitRead(PDO5_DCU_Data->PDO5_DCU_0, 0));
	bitWrite(PDO5_DCU_Val->G_Force_Vert_Val, 9, bitRead(PDO5_DCU_Data->PDO5_DCU_0, 1));
	bitWrite(PDO5_DCU_Val->G_Force_Vert_Val, 10, bitRead(PDO5_DCU_Data->PDO5_DCU_0, 2));
	bitWrite(PDO5_DCU_Val->G_Force_Vert_Val, 11, bitRead(PDO5_DCU_Data->PDO5_DCU_0, 3));
	bitWrite(PDO5_DCU_Val->G_Force_Vert_Val, 12, bitRead(PDO5_DCU_Data->PDO5_DCU_0, 4));
	bitWrite(PDO5_DCU_Val->G_Force_Vert_Val, 13, bitRead(PDO5_DCU_Data->PDO5_DCU_0, 5));
	bitWrite(PDO5_DCU_Val->G_Force_Vert_Val, 14, bitRead(PDO5_DCU_Data->PDO5_DCU_0, 6));
	bitWrite(PDO5_DCU_Val->G_Force_Vert_Val, 15, bitRead(PDO5_DCU_Data->PDO5_DCU_0, 7));
	bitWrite(PDO5_DCU_Val->G_Force_Vert_Val, 0, bitRead(PDO5_DCU_Data->PDO5_DCU_1, 0));
	bitWrite(PDO5_DCU_Val->G_Force_Vert_Val, 1, bitRead(PDO5_DCU_Data->PDO5_DCU_1, 1));
	bitWrite(PDO5_DCU_Val->G_Force_Vert_Val, 2, bitRead(PDO5_DCU_Data->PDO5_DCU_1, 2));
	bitWrite(PDO5_DCU_Val->G_Force_Vert_Val, 3, bitRead(PDO5_DCU_Data->PDO5_DCU_1, 3));
	bitWrite(PDO5_DCU_Val->G_Force_Vert_Val, 4, bitRead(PDO5_DCU_Data->PDO5_DCU_1, 4));
	bitWrite(PDO5_DCU_Val->G_Force_Vert_Val, 5, bitRead(PDO5_DCU_Data->PDO5_DCU_1, 5));
	bitWrite(PDO5_DCU_Val->G_Force_Vert_Val, 6, bitRead(PDO5_DCU_Data->PDO5_DCU_1, 6));
	bitWrite(PDO5_DCU_Val->G_Force_Vert_Val, 7, bitRead(PDO5_DCU_Data->PDO5_DCU_1, 7));
	bitWrite(PDO5_DCU_Val->G_Force_Long_Val, 8, bitRead(PDO5_DCU_Data->PDO5_DCU_2, 0));
	bitWrite(PDO5_DCU_Val->G_Force_Long_Val, 9, bitRead(PDO5_DCU_Data->PDO5_DCU_2, 1));
	bitWrite(PDO5_DCU_Val->G_Force_Long_Val, 10, bitRead(PDO5_DCU_Data->PDO5_DCU_2, 2));
	bitWrite(PDO5_DCU_Val->G_Force_Long_Val, 11, bitRead(PDO5_DCU_Data->PDO5_DCU_2, 3));
	bitWrite(PDO5_DCU_Val->G_Force_Long_Val, 12, bitRead(PDO5_DCU_Data->PDO5_DCU_2, 4));
	bitWrite(PDO5_DCU_Val->G_Force_Long_Val, 13, bitRead(PDO5_DCU_Data->PDO5_DCU_2, 5));
	bitWrite(PDO5_DCU_Val->G_Force_Long_Val, 14, bitRead(PDO5_DCU_Data->PDO5_DCU_2, 6));
	bitWrite(PDO5_DCU_Val->G_Force_Long_Val, 15, bitRead(PDO5_DCU_Data->PDO5_DCU_2, 7));
	bitWrite(PDO5_DCU_Val->G_Force_Long_Val, 0, bitRead(PDO5_DCU_Data->PDO5_DCU_3, 0));
	bitWrite(PDO5_DCU_Val->G_Force_Long_Val, 1, bitRead(PDO5_DCU_Data->PDO5_DCU_3, 1));
	bitWrite(PDO5_DCU_Val->G_Force_Long_Val, 2, bitRead(PDO5_DCU_Data->PDO5_DCU_3, 2));
	bitWrite(PDO5_DCU_Val->G_Force_Long_Val, 3, bitRead(PDO5_DCU_Data->PDO5_DCU_3, 3));
	bitWrite(PDO5_DCU_Val->G_Force_Long_Val, 4, bitRead(PDO5_DCU_Data->PDO5_DCU_3, 4));
	bitWrite(PDO5_DCU_Val->G_Force_Long_Val, 5, bitRead(PDO5_DCU_Data->PDO5_DCU_3, 5));
	bitWrite(PDO5_DCU_Val->G_Force_Long_Val, 6, bitRead(PDO5_DCU_Data->PDO5_DCU_3, 6));
	bitWrite(PDO5_DCU_Val->G_Force_Long_Val, 7, bitRead(PDO5_DCU_Data->PDO5_DCU_3, 7));
	bitWrite(PDO5_DCU_Val->G_Force_Lat_Val, 8, bitRead(PDO5_DCU_Data->PDO5_DCU_4, 0));
	bitWrite(PDO5_DCU_Val->G_Force_Lat_Val, 9, bitRead(PDO5_DCU_Data->PDO5_DCU_4, 1));
	bitWrite(PDO5_DCU_Val->G_Force_Lat_Val, 10, bitRead(PDO5_DCU_Data->PDO5_DCU_4, 2));
	bitWrite(PDO5_DCU_Val->G_Force_Lat_Val, 11, bitRead(PDO5_DCU_Data->PDO5_DCU_4, 3));
	bitWrite(PDO5_DCU_Val->G_Force_Lat_Val, 12, bitRead(PDO5_DCU_Data->PDO5_DCU_4, 4));
	bitWrite(PDO5_DCU_Val->G_Force_Lat_Val, 13, bitRead(PDO5_DCU_Data->PDO5_DCU_4, 5));
	bitWrite(PDO5_DCU_Val->G_Force_Lat_Val, 14, bitRead(PDO5_DCU_Data->PDO5_DCU_4, 6));
	bitWrite(PDO5_DCU_Val->G_Force_Lat_Val, 15, bitRead(PDO5_DCU_Data->PDO5_DCU_4, 7));
	bitWrite(PDO5_DCU_Val->G_Force_Lat_Val, 0, bitRead(PDO5_DCU_Data->PDO5_DCU_5, 0));
	bitWrite(PDO5_DCU_Val->G_Force_Lat_Val, 1, bitRead(PDO5_DCU_Data->PDO5_DCU_5, 1));
	bitWrite(PDO5_DCU_Val->G_Force_Lat_Val, 2, bitRead(PDO5_DCU_Data->PDO5_DCU_5, 2));
	bitWrite(PDO5_DCU_Val->G_Force_Lat_Val, 3, bitRead(PDO5_DCU_Data->PDO5_DCU_5, 3));
	bitWrite(PDO5_DCU_Val->G_Force_Lat_Val, 4, bitRead(PDO5_DCU_Data->PDO5_DCU_5, 4));
	bitWrite(PDO5_DCU_Val->G_Force_Lat_Val, 5, bitRead(PDO5_DCU_Data->PDO5_DCU_5, 5));
	bitWrite(PDO5_DCU_Val->G_Force_Lat_Val, 6, bitRead(PDO5_DCU_Data->PDO5_DCU_5, 6));
	bitWrite(PDO5_DCU_Val->G_Force_Lat_Val, 7, bitRead(PDO5_DCU_Data->PDO5_DCU_5, 7));
	bitWrite(PDO5_DCU_Val->Lambda_1_Val, 8, bitRead(PDO5_DCU_Data->PDO5_DCU_6, 0));
	bitWrite(PDO5_DCU_Val->Lambda_1_Val, 9, bitRead(PDO5_DCU_Data->PDO5_DCU_6, 1));
	bitWrite(PDO5_DCU_Val->Lambda_1_Val, 10, bitRead(PDO5_DCU_Data->PDO5_DCU_6, 2));
	bitWrite(PDO5_DCU_Val->Lambda_1_Val, 11, bitRead(PDO5_DCU_Data->PDO5_DCU_6, 3));
	bitWrite(PDO5_DCU_Val->Lambda_1_Val, 12, bitRead(PDO5_DCU_Data->PDO5_DCU_6, 4));
	bitWrite(PDO5_DCU_Val->Lambda_1_Val, 13, bitRead(PDO5_DCU_Data->PDO5_DCU_6, 5));
	bitWrite(PDO5_DCU_Val->Lambda_1_Val, 14, bitRead(PDO5_DCU_Data->PDO5_DCU_6, 6));
	bitWrite(PDO5_DCU_Val->Lambda_1_Val, 15, bitRead(PDO5_DCU_Data->PDO5_DCU_6, 7));
	bitWrite(PDO5_DCU_Val->Lambda_1_Val, 0, bitRead(PDO5_DCU_Data->PDO5_DCU_7, 0));
	bitWrite(PDO5_DCU_Val->Lambda_1_Val, 1, bitRead(PDO5_DCU_Data->PDO5_DCU_7, 1));
	bitWrite(PDO5_DCU_Val->Lambda_1_Val, 2, bitRead(PDO5_DCU_Data->PDO5_DCU_7, 2));
	bitWrite(PDO5_DCU_Val->Lambda_1_Val, 3, bitRead(PDO5_DCU_Data->PDO5_DCU_7, 3));
	bitWrite(PDO5_DCU_Val->Lambda_1_Val, 4, bitRead(PDO5_DCU_Data->PDO5_DCU_7, 4));
	bitWrite(PDO5_DCU_Val->Lambda_1_Val, 5, bitRead(PDO5_DCU_Data->PDO5_DCU_7, 5));
	bitWrite(PDO5_DCU_Val->Lambda_1_Val, 6, bitRead(PDO5_DCU_Data->PDO5_DCU_7, 6));
	bitWrite(PDO5_DCU_Val->Lambda_1_Val, 7, bitRead(PDO5_DCU_Data->PDO5_DCU_7, 7));
}

void atualizaRX_PDO6_DCU (PDO6_DCU_Val *PDO6_DCU_Val, PDO6_DCU_Data *PDO6_DCU_Data)
{
	bitWrite(PDO6_DCU_Val->GPS_Altitude_Val, 8, bitRead(PDO6_DCU_Data->PDO6_DCU_0, 0));
	bitWrite(PDO6_DCU_Val->GPS_Altitude_Val, 9, bitRead(PDO6_DCU_Data->PDO6_DCU_0, 1));
	bitWrite(PDO6_DCU_Val->GPS_Altitude_Val, 10, bitRead(PDO6_DCU_Data->PDO6_DCU_0, 2));
	bitWrite(PDO6_DCU_Val->GPS_Altitude_Val, 11, bitRead(PDO6_DCU_Data->PDO6_DCU_0, 3));
	bitWrite(PDO6_DCU_Val->GPS_Altitude_Val, 12, bitRead(PDO6_DCU_Data->PDO6_DCU_0, 4));
	bitWrite(PDO6_DCU_Val->GPS_Altitude_Val, 13, bitRead(PDO6_DCU_Data->PDO6_DCU_0, 5));
	bitWrite(PDO6_DCU_Val->GPS_Altitude_Val, 14, bitRead(PDO6_DCU_Data->PDO6_DCU_0, 6));
	bitWrite(PDO6_DCU_Val->GPS_Altitude_Val, 15, bitRead(PDO6_DCU_Data->PDO6_DCU_0, 7));
	bitWrite(PDO6_DCU_Val->GPS_Altitude_Val, 0, bitRead(PDO6_DCU_Data->PDO6_DCU_1, 0));
	bitWrite(PDO6_DCU_Val->GPS_Altitude_Val, 1, bitRead(PDO6_DCU_Data->PDO6_DCU_1, 1));
	bitWrite(PDO6_DCU_Val->GPS_Altitude_Val, 2, bitRead(PDO6_DCU_Data->PDO6_DCU_1, 2));
	bitWrite(PDO6_DCU_Val->GPS_Altitude_Val, 3, bitRead(PDO6_DCU_Data->PDO6_DCU_1, 3));
	bitWrite(PDO6_DCU_Val->GPS_Altitude_Val, 4, bitRead(PDO6_DCU_Data->PDO6_DCU_1, 4));
	bitWrite(PDO6_DCU_Val->GPS_Altitude_Val, 5, bitRead(PDO6_DCU_Data->PDO6_DCU_1, 5));
	bitWrite(PDO6_DCU_Val->GPS_Altitude_Val, 6, bitRead(PDO6_DCU_Data->PDO6_DCU_1, 6));
	bitWrite(PDO6_DCU_Val->GPS_Altitude_Val, 7, bitRead(PDO6_DCU_Data->PDO6_DCU_1, 7));
	bitWrite(PDO6_DCU_Val->Beacon_Val, 8, bitRead(PDO6_DCU_Data->PDO6_DCU_2, 0));
	bitWrite(PDO6_DCU_Val->Beacon_Val, 9, bitRead(PDO6_DCU_Data->PDO6_DCU_2, 1));
	bitWrite(PDO6_DCU_Val->Beacon_Val, 10, bitRead(PDO6_DCU_Data->PDO6_DCU_2, 2));
	bitWrite(PDO6_DCU_Val->Beacon_Val, 11, bitRead(PDO6_DCU_Data->PDO6_DCU_2, 3));
	bitWrite(PDO6_DCU_Val->Beacon_Val, 12, bitRead(PDO6_DCU_Data->PDO6_DCU_2, 4));
	bitWrite(PDO6_DCU_Val->Beacon_Val, 13, bitRead(PDO6_DCU_Data->PDO6_DCU_2, 5));
	bitWrite(PDO6_DCU_Val->Beacon_Val, 14, bitRead(PDO6_DCU_Data->PDO6_DCU_2, 6));
	bitWrite(PDO6_DCU_Val->Beacon_Val, 15, bitRead(PDO6_DCU_Data->PDO6_DCU_2, 7));
	bitWrite(PDO6_DCU_Val->Beacon_Val, 0, bitRead(PDO6_DCU_Data->PDO6_DCU_3, 0));
	bitWrite(PDO6_DCU_Val->Beacon_Val, 1, bitRead(PDO6_DCU_Data->PDO6_DCU_3, 1));
	bitWrite(PDO6_DCU_Val->Beacon_Val, 2, bitRead(PDO6_DCU_Data->PDO6_DCU_3, 2));
	bitWrite(PDO6_DCU_Val->Beacon_Val, 3, bitRead(PDO6_DCU_Data->PDO6_DCU_3, 3));
	bitWrite(PDO6_DCU_Val->Beacon_Val, 4, bitRead(PDO6_DCU_Data->PDO6_DCU_3, 4));
	bitWrite(PDO6_DCU_Val->Beacon_Val, 5, bitRead(PDO6_DCU_Data->PDO6_DCU_3, 5));
	bitWrite(PDO6_DCU_Val->Beacon_Val, 6, bitRead(PDO6_DCU_Data->PDO6_DCU_3, 6));
	bitWrite(PDO6_DCU_Val->Beacon_Val, 7, bitRead(PDO6_DCU_Data->PDO6_DCU_3, 7));
	bitWrite(PDO6_DCU_Val->Fuel_Used_Val, 8, bitRead(PDO6_DCU_Data->PDO6_DCU_4, 0));
	bitWrite(PDO6_DCU_Val->Fuel_Used_Val, 9, bitRead(PDO6_DCU_Data->PDO6_DCU_4, 1));
	bitWrite(PDO6_DCU_Val->Fuel_Used_Val, 10, bitRead(PDO6_DCU_Data->PDO6_DCU_4, 2));
	bitWrite(PDO6_DCU_Val->Fuel_Used_Val, 11, bitRead(PDO6_DCU_Data->PDO6_DCU_4, 3));
	bitWrite(PDO6_DCU_Val->Fuel_Used_Val, 12, bitRead(PDO6_DCU_Data->PDO6_DCU_4, 4));
	bitWrite(PDO6_DCU_Val->Fuel_Used_Val, 13, bitRead(PDO6_DCU_Data->PDO6_DCU_4, 5));
	bitWrite(PDO6_DCU_Val->Fuel_Used_Val, 14, bitRead(PDO6_DCU_Data->PDO6_DCU_4, 6));
	bitWrite(PDO6_DCU_Val->Fuel_Used_Val, 15, bitRead(PDO6_DCU_Data->PDO6_DCU_4, 7));
	bitWrite(PDO6_DCU_Val->Fuel_Used_Val, 0, bitRead(PDO6_DCU_Data->PDO6_DCU_5, 0));
	bitWrite(PDO6_DCU_Val->Fuel_Used_Val, 1, bitRead(PDO6_DCU_Data->PDO6_DCU_5, 1));
	bitWrite(PDO6_DCU_Val->Fuel_Used_Val, 2, bitRead(PDO6_DCU_Data->PDO6_DCU_5, 2));
	bitWrite(PDO6_DCU_Val->Fuel_Used_Val, 3, bitRead(PDO6_DCU_Data->PDO6_DCU_5, 3));
	bitWrite(PDO6_DCU_Val->Fuel_Used_Val, 4, bitRead(PDO6_DCU_Data->PDO6_DCU_5, 4));
	bitWrite(PDO6_DCU_Val->Fuel_Used_Val, 5, bitRead(PDO6_DCU_Data->PDO6_DCU_5, 5));
	bitWrite(PDO6_DCU_Val->Fuel_Used_Val, 6, bitRead(PDO6_DCU_Data->PDO6_DCU_5, 6));
	bitWrite(PDO6_DCU_Val->Fuel_Used_Val, 7, bitRead(PDO6_DCU_Data->PDO6_DCU_5, 7));
	bitWrite(PDO6_DCU_Val->Throttle_Pos_Val, 8, bitRead(PDO6_DCU_Data->PDO6_DCU_6, 0));
	bitWrite(PDO6_DCU_Val->Throttle_Pos_Val, 9, bitRead(PDO6_DCU_Data->PDO6_DCU_6, 1));
	bitWrite(PDO6_DCU_Val->Throttle_Pos_Val, 10, bitRead(PDO6_DCU_Data->PDO6_DCU_6, 2));
	bitWrite(PDO6_DCU_Val->Throttle_Pos_Val, 11, bitRead(PDO6_DCU_Data->PDO6_DCU_6, 3));
	bitWrite(PDO6_DCU_Val->Throttle_Pos_Val, 12, bitRead(PDO6_DCU_Data->PDO6_DCU_6, 4));
	bitWrite(PDO6_DCU_Val->Throttle_Pos_Val, 13, bitRead(PDO6_DCU_Data->PDO6_DCU_6, 5));
	bitWrite(PDO6_DCU_Val->Throttle_Pos_Val, 14, bitRead(PDO6_DCU_Data->PDO6_DCU_6, 6));
	bitWrite(PDO6_DCU_Val->Throttle_Pos_Val, 15, bitRead(PDO6_DCU_Data->PDO6_DCU_6, 7));
	bitWrite(PDO6_DCU_Val->Throttle_Pos_Val, 0, bitRead(PDO6_DCU_Data->PDO6_DCU_7, 0));
	bitWrite(PDO6_DCU_Val->Throttle_Pos_Val, 1, bitRead(PDO6_DCU_Data->PDO6_DCU_7, 1));
	bitWrite(PDO6_DCU_Val->Throttle_Pos_Val, 2, bitRead(PDO6_DCU_Data->PDO6_DCU_7, 2));
	bitWrite(PDO6_DCU_Val->Throttle_Pos_Val, 3, bitRead(PDO6_DCU_Data->PDO6_DCU_7, 3));
	bitWrite(PDO6_DCU_Val->Throttle_Pos_Val, 4, bitRead(PDO6_DCU_Data->PDO6_DCU_7, 4));
	bitWrite(PDO6_DCU_Val->Throttle_Pos_Val, 5, bitRead(PDO6_DCU_Data->PDO6_DCU_7, 5));
	bitWrite(PDO6_DCU_Val->Throttle_Pos_Val, 6, bitRead(PDO6_DCU_Data->PDO6_DCU_7, 6));
	bitWrite(PDO6_DCU_Val->Throttle_Pos_Val, 7, bitRead(PDO6_DCU_Data->PDO6_DCU_7, 7));
}

void atualizaRX_PDO7_DCU (PDO7_DCU_Val *PDO7_DCU_Val, PDO7_DCU_Data *PDO7_DCU_Data)
{
	bitWrite(PDO7_DCU_Val->GPS_Longitude_Val, 24, bitRead(PDO7_DCU_Data->PDO7_DCU_0, 0));
	bitWrite(PDO7_DCU_Val->GPS_Longitude_Val, 25, bitRead(PDO7_DCU_Data->PDO7_DCU_0, 1));
	bitWrite(PDO7_DCU_Val->GPS_Longitude_Val, 26, bitRead(PDO7_DCU_Data->PDO7_DCU_0, 2));
	bitWrite(PDO7_DCU_Val->GPS_Longitude_Val, 27, bitRead(PDO7_DCU_Data->PDO7_DCU_0, 3));
	bitWrite(PDO7_DCU_Val->GPS_Longitude_Val, 28, bitRead(PDO7_DCU_Data->PDO7_DCU_0, 4));
	bitWrite(PDO7_DCU_Val->GPS_Longitude_Val, 29, bitRead(PDO7_DCU_Data->PDO7_DCU_0, 5));
	bitWrite(PDO7_DCU_Val->GPS_Longitude_Val, 30, bitRead(PDO7_DCU_Data->PDO7_DCU_0, 6));
	bitWrite(PDO7_DCU_Val->GPS_Longitude_Val, 31, bitRead(PDO7_DCU_Data->PDO7_DCU_0, 7));
	bitWrite(PDO7_DCU_Val->GPS_Longitude_Val, 16, bitRead(PDO7_DCU_Data->PDO7_DCU_1, 0));
	bitWrite(PDO7_DCU_Val->GPS_Longitude_Val, 17, bitRead(PDO7_DCU_Data->PDO7_DCU_1, 1));
	bitWrite(PDO7_DCU_Val->GPS_Longitude_Val, 18, bitRead(PDO7_DCU_Data->PDO7_DCU_1, 2));
	bitWrite(PDO7_DCU_Val->GPS_Longitude_Val, 19, bitRead(PDO7_DCU_Data->PDO7_DCU_1, 3));
	bitWrite(PDO7_DCU_Val->GPS_Longitude_Val, 20, bitRead(PDO7_DCU_Data->PDO7_DCU_1, 4));
	bitWrite(PDO7_DCU_Val->GPS_Longitude_Val, 21, bitRead(PDO7_DCU_Data->PDO7_DCU_1, 5));
	bitWrite(PDO7_DCU_Val->GPS_Longitude_Val, 22, bitRead(PDO7_DCU_Data->PDO7_DCU_1, 6));
	bitWrite(PDO7_DCU_Val->GPS_Longitude_Val, 23, bitRead(PDO7_DCU_Data->PDO7_DCU_1, 7));
	bitWrite(PDO7_DCU_Val->GPS_Longitude_Val, 8, bitRead(PDO7_DCU_Data->PDO7_DCU_2, 0));
	bitWrite(PDO7_DCU_Val->GPS_Longitude_Val, 9, bitRead(PDO7_DCU_Data->PDO7_DCU_2, 1));
	bitWrite(PDO7_DCU_Val->GPS_Longitude_Val, 10, bitRead(PDO7_DCU_Data->PDO7_DCU_2, 2));
	bitWrite(PDO7_DCU_Val->GPS_Longitude_Val, 11, bitRead(PDO7_DCU_Data->PDO7_DCU_2, 3));
	bitWrite(PDO7_DCU_Val->GPS_Longitude_Val, 12, bitRead(PDO7_DCU_Data->PDO7_DCU_2, 4));
	bitWrite(PDO7_DCU_Val->GPS_Longitude_Val, 13, bitRead(PDO7_DCU_Data->PDO7_DCU_2, 5));
	bitWrite(PDO7_DCU_Val->GPS_Longitude_Val, 14, bitRead(PDO7_DCU_Data->PDO7_DCU_2, 6));
	bitWrite(PDO7_DCU_Val->GPS_Longitude_Val, 15, bitRead(PDO7_DCU_Data->PDO7_DCU_2, 7));
	bitWrite(PDO7_DCU_Val->GPS_Longitude_Val, 0, bitRead(PDO7_DCU_Data->PDO7_DCU_3, 0));
	bitWrite(PDO7_DCU_Val->GPS_Longitude_Val, 1, bitRead(PDO7_DCU_Data->PDO7_DCU_3, 1));
	bitWrite(PDO7_DCU_Val->GPS_Longitude_Val, 2, bitRead(PDO7_DCU_Data->PDO7_DCU_3, 2));
	bitWrite(PDO7_DCU_Val->GPS_Longitude_Val, 3, bitRead(PDO7_DCU_Data->PDO7_DCU_3, 3));
	bitWrite(PDO7_DCU_Val->GPS_Longitude_Val, 4, bitRead(PDO7_DCU_Data->PDO7_DCU_3, 4));
	bitWrite(PDO7_DCU_Val->GPS_Longitude_Val, 5, bitRead(PDO7_DCU_Data->PDO7_DCU_3, 5));
	bitWrite(PDO7_DCU_Val->GPS_Longitude_Val, 6, bitRead(PDO7_DCU_Data->PDO7_DCU_3, 6));
	bitWrite(PDO7_DCU_Val->GPS_Longitude_Val, 7, bitRead(PDO7_DCU_Data->PDO7_DCU_3, 7));
	bitWrite(PDO7_DCU_Val->GPS_Latitude_Val, 24, bitRead(PDO7_DCU_Data->PDO7_DCU_4, 0));
	bitWrite(PDO7_DCU_Val->GPS_Latitude_Val, 25, bitRead(PDO7_DCU_Data->PDO7_DCU_4, 1));
	bitWrite(PDO7_DCU_Val->GPS_Latitude_Val, 26, bitRead(PDO7_DCU_Data->PDO7_DCU_4, 2));
	bitWrite(PDO7_DCU_Val->GPS_Latitude_Val, 27, bitRead(PDO7_DCU_Data->PDO7_DCU_4, 3));
	bitWrite(PDO7_DCU_Val->GPS_Latitude_Val, 28, bitRead(PDO7_DCU_Data->PDO7_DCU_4, 4));
	bitWrite(PDO7_DCU_Val->GPS_Latitude_Val, 29, bitRead(PDO7_DCU_Data->PDO7_DCU_4, 5));
	bitWrite(PDO7_DCU_Val->GPS_Latitude_Val, 30, bitRead(PDO7_DCU_Data->PDO7_DCU_4, 6));
	bitWrite(PDO7_DCU_Val->GPS_Latitude_Val, 31, bitRead(PDO7_DCU_Data->PDO7_DCU_4, 7));
	bitWrite(PDO7_DCU_Val->GPS_Latitude_Val, 16, bitRead(PDO7_DCU_Data->PDO7_DCU_5, 0));
	bitWrite(PDO7_DCU_Val->GPS_Latitude_Val, 17, bitRead(PDO7_DCU_Data->PDO7_DCU_5, 1));
	bitWrite(PDO7_DCU_Val->GPS_Latitude_Val, 18, bitRead(PDO7_DCU_Data->PDO7_DCU_5, 2));
	bitWrite(PDO7_DCU_Val->GPS_Latitude_Val, 19, bitRead(PDO7_DCU_Data->PDO7_DCU_5, 3));
	bitWrite(PDO7_DCU_Val->GPS_Latitude_Val, 20, bitRead(PDO7_DCU_Data->PDO7_DCU_5, 4));
	bitWrite(PDO7_DCU_Val->GPS_Latitude_Val, 21, bitRead(PDO7_DCU_Data->PDO7_DCU_5, 5));
	bitWrite(PDO7_DCU_Val->GPS_Latitude_Val, 22, bitRead(PDO7_DCU_Data->PDO7_DCU_5, 6));
	bitWrite(PDO7_DCU_Val->GPS_Latitude_Val, 23, bitRead(PDO7_DCU_Data->PDO7_DCU_5, 7));
	bitWrite(PDO7_DCU_Val->GPS_Latitude_Val, 8, bitRead(PDO7_DCU_Data->PDO7_DCU_6, 0));
	bitWrite(PDO7_DCU_Val->GPS_Latitude_Val, 9, bitRead(PDO7_DCU_Data->PDO7_DCU_6, 1));
	bitWrite(PDO7_DCU_Val->GPS_Latitude_Val, 10, bitRead(PDO7_DCU_Data->PDO7_DCU_6, 2));
	bitWrite(PDO7_DCU_Val->GPS_Latitude_Val, 11, bitRead(PDO7_DCU_Data->PDO7_DCU_6, 3));
	bitWrite(PDO7_DCU_Val->GPS_Latitude_Val, 12, bitRead(PDO7_DCU_Data->PDO7_DCU_6, 4));
	bitWrite(PDO7_DCU_Val->GPS_Latitude_Val, 13, bitRead(PDO7_DCU_Data->PDO7_DCU_6, 5));
	bitWrite(PDO7_DCU_Val->GPS_Latitude_Val, 14, bitRead(PDO7_DCU_Data->PDO7_DCU_6, 6));
	bitWrite(PDO7_DCU_Val->GPS_Latitude_Val, 15, bitRead(PDO7_DCU_Data->PDO7_DCU_6, 7));
	bitWrite(PDO7_DCU_Val->GPS_Latitude_Val, 0, bitRead(PDO7_DCU_Data->PDO7_DCU_7, 0));
	bitWrite(PDO7_DCU_Val->GPS_Latitude_Val, 1, bitRead(PDO7_DCU_Data->PDO7_DCU_7, 1));
	bitWrite(PDO7_DCU_Val->GPS_Latitude_Val, 2, bitRead(PDO7_DCU_Data->PDO7_DCU_7, 2));
	bitWrite(PDO7_DCU_Val->GPS_Latitude_Val, 3, bitRead(PDO7_DCU_Data->PDO7_DCU_7, 3));
	bitWrite(PDO7_DCU_Val->GPS_Latitude_Val, 4, bitRead(PDO7_DCU_Data->PDO7_DCU_7, 4));
	bitWrite(PDO7_DCU_Val->GPS_Latitude_Val, 5, bitRead(PDO7_DCU_Data->PDO7_DCU_7, 5));
	bitWrite(PDO7_DCU_Val->GPS_Latitude_Val, 6, bitRead(PDO7_DCU_Data->PDO7_DCU_7, 6));
	bitWrite(PDO7_DCU_Val->GPS_Latitude_Val, 7, bitRead(PDO7_DCU_Data->PDO7_DCU_7, 7));
}


//------------RX Messages Reader------------//
