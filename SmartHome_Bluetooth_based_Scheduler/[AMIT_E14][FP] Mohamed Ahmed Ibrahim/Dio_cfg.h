
#ifndef DIO_CFG_H_
#define DIO_CFG_H_

typedef enum
{
    PORTA_0=0,       /* PORTA0 */
    PORTA_1,         /* PORTA1 */
    PORTA_2,         /* PORTA2 */
    PORTA_3,         /* PORTA3 */
    PORTA_4,         /* PORTA4 */
    PORTA_5,         /* PORTA5 */
    PORTA_6,         /* PORTA6 */
    PORTA_7,         /* PORTA7 */
    PORTB_0,         /* PORTB0 */
    PORTB_1,         /* PORTB1 */
    PORTB_2,         /* PORTB2 */
    PORTB_3,         /* PORTB3 */
    PORTB_4,         /* PORTB4 */
    PORTB_5,         /* PORTB5 */
    PORTB_6,         /* PORTB6 */
    PORTB_7,         /* PORTB7 */
    PORTC_0,         /* PORTC0 */
    PORTC_1,         /* PORTC1 */
    PORTC_2,         /* PORTC2 */
    PORTC_3,         /* PORTC3 */
    PORTC_4,         /* PORTC4 */
    PORTC_5,         /* PORTC5 */
    PORTC_6,         /* PORTC6 */
    PORTC_7,         /* PORTC7 */
    PORTD_0,         /* PORTD0 */
    PORTD_1,         /* PORTD1 */
    PORTD_2,         /* PORTD2 */
    PORTD_3,         /* PORTD3 */
    PORTD_4,         /* PORTD4 */
    PORTD_5,         /* PORTD5 */
    PORTD_6,         /* PORTD6 */
    PORTD_7,         /* PORTD7 */
    LAST_PIN
}Dio_pin_t;


typedef enum
{
    PA=0,        /* PORTA */
    PB,          /* PORTB */
    PC,          /* PORTC */
    PD           /* PORTD */
}Dio_port_t;


typedef enum
{   
    OUTPUT = 0,
    INPULLUP,
    INFREE
}Dio_pin_state_t;


#endif 
