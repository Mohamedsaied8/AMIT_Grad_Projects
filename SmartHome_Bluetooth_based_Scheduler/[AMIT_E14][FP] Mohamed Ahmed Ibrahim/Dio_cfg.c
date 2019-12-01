
#include "Types.h"
#include "Dio_cfg.h"

const Dio_pin_state_t Pin_state[LAST_PIN] = {
    INFREE,           /* PORTA_0 */
    INFREE,           /* PORTA_1 */
    INFREE,           /* PORTA_2 */
    INFREE,           /* PORTA_3 */
    OUTPUT,           /* PORTA_4 */
    OUTPUT,           /* PORTA_5 */
    OUTPUT,           /* PORTA_6 */
    OUTPUT,           /* PORTA_7 */
    OUTPUT,           /* PORTB_0 */ 
    OUTPUT,           /* LCD_RS */
    OUTPUT,           /* LCD_RW */
    OUTPUT,           /* LCD_E */
    INFREE,           /* PORTB_4 */
    INFREE,           /* PORTB_5 */
    INFREE,           /* PORTB_6 */
    INFREE,           /* PORTB_7 */
    INFREE,           /* PORTC_0 */
    INFREE,           /* PORTC_1 */
    OUTPUT,           /* PORTC_2 */
    OUTPUT,           /* PORTC_3 */
    OUTPUT,           /* PORTC_4 */
    OUTPUT,           /* PORTC_5 */
    OUTPUT,           /* PORTC_6 */
    OUTPUT,           /* PORTC_7 */
    INFREE,           /* PORTD_0 */
    INFREE,           /* PORTD_1 */
    INFREE,           /* PORTD_2 */
    OUTPUT,           /* PORTD_3 */
    OUTPUT,           /* PORTD_4 */
    OUTPUT,           /* PORTD_5 */
    OUTPUT,           /* PORTD_6 */
    OUTPUT           /* PORTD_7 */
};
