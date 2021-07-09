/*
 *  Author: Hassan
 *  Created on: 7/7/2021
 */

#include "../lib/DataTypes.h"
#include "../lib/BIT_Math.h"
#include "DIO_Interface.h"
#include "../lib/Memmap.h"



void DIO_voidSetPinValue(EN_port_num EN_Port, EN_pin_num EN_Pin, EN_value_type EN_Value)
{
    if (EN_Value == LOW)
    {
        switch (EN_Port)
        {
        case PORT_A:
            CLRBIT(PORTA, EN_Pin);
            break;
        case PORT_B:
            CLRBIT(PORTB, EN_Pin);
            break;
        case PORT_C:
            CLRBIT(PORTC, EN_Pin);
            break;
        case PORT_D:
            CLRBIT(PORTD, EN_Pin);
            break;
        }
    }
    else if(EN_Value == HIGH)
    {
        switch (EN_Port)
        {
        case PORT_A:
            SETBIT(PORTA, EN_Pin);
            break;
        case PORT_B:
            SETBIT(PORTB, EN_Pin);
            break;
        case PORT_C:
            SETBIT(PORTC, EN_Pin);
            break;
        case PORT_D:
            SETBIT(PORTD, EN_Pin);
            break;

        }
    }

}

void DIO_voidSetPinDirection(EN_port_num EN_port, EN_pin_num EN_Pin, EN_direction_type EN_Direction)
{
    if(EN_Direction == INPUT)
    {
        switch (EN_port)
        {
        case PORT_A:
            CLRBIT(DDRA, EN_Pin);
            break;
        case PORT_B:
            CLRBIT(DDRB, EN_Pin);
            break;
        case PORT_C:
            CLRBIT(DDRC, EN_Pin);
            break;
        case PORT_D:
            CLRBIT(DDRD, EN_Pin);
            break;
        }
    }
    else if(EN_Direction == OUTPUT)
    {
        switch (EN_port)
        {
        case PORT_A:
            SETBIT(DDRA, EN_Pin);
            break;
        case PORT_B:
            SETBIT(DDRB, EN_Pin);
            break;
        case PORT_C:
            SETBIT(DDRC, EN_Pin);
            break;
        case PORT_D:
            SETBIT(DDRD, EN_Pin);
            break;
        }
    }
}

EN_value_type DIO_u8GetPinValue(EN_port_num EN_Port, EN_pin_num EN_Pin)
{
    EN_value_type EN_ret_val;
    switch (EN_Port)
        {
        case PORT_A:
            EN_ret_val = GETBIT(PINA, EN_Pin);
            break;
        case PORT_B:
            EN_ret_val = GETBIT(PINB, EN_Pin);
            break;
        case PORT_C:
            EN_ret_val = GETBIT(PINC, EN_Pin);
            break;
        case PORT_D:
            EN_ret_val = GETBIT(PIND, EN_Pin);
            break;
        }
        return EN_ret_val;
}

void DIO_voidTogPin(EN_port_num EN_Port, EN_pin_num EN_Pin)
{
    switch (EN_Port)
    {
    case PORT_A:
        TGLBIT(PORTA, EN_Pin);
        break;
    case PORT_B:
        TGLBIT(PORTB, EN_Pin);
        break;
    case PORT_C:
        TGLBIT(PORTC, EN_Pin);
        break;
    case PORT_D:
        TGLBIT(PORTD, EN_Pin);
        break;
    }
}

void DIO_voidSetPortValue(EN_port_num EN_Port, EN_value_type EN_Value)
{
    switch (EN_Port)
    {
    case PORT_A:
        PORTA = EN_Value;
        break;
    case PORT_B:
        PORTB = EN_Value;
        break;
    case PORT_C:
        PORTC = EN_Value;
        break;
    case PORT_D:
        PORTD = EN_Value;
        break;
    }

}

void DIO_voidSetPortDirection(EN_port_num EN_Port, EN_direction_type EN_Direction)
{
    switch (EN_Port)
    {
    case PORT_A:
        DDRA = EN_Direction;
        break;
    case PORT_B:
        DDRB = EN_Direction;
        break;
    case PORT_C:
        DDRC = EN_Direction;
        break;
    case PORT_D:
        DDRD = EN_Direction;
        break;
    }

}


void DIO_voidInpullUp(EN_port_num EN_Port, EN_pin_num EN_Pin)
{
    switch (EN_Port)
    {
    case PORT_A:
        CLRBIT(DDRA, EN_Pin);
        SETBIT(PORTA, EN_Pin);
        break;
    case PORT_B:
        CLRBIT(DDRB, EN_Pin);
        SETBIT(PORTB, EN_Pin);
        break;
    case PORT_C:
        CLRBIT(DDRC, EN_Pin);
        SETBIT(PORTC, EN_Pin);
        break;
    case PORT_D:
        CLRBIT(DDRD, EN_Pin);
        SETBIT(PORTD, EN_Pin);
        break;
    }
}
