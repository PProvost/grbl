/*
  cpu_map_at90usb.h - CPU and pin mapping configuration file
  Part of Grbl

  Copyright (c) 2012-2015 Sungeun K. Jeon

  Grbl is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Grbl is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Grbl.  If not, see <http://www.gnu.org/licenses/>.
*/

/* This cpu_map file serves as a central pin mapping settings file for AVR Mega 2560 */


#ifdef GRBL_PLATFORM
#error "cpu_map already defined: GRBL_PLATFORM=" GRBL_PLATFORM
#endif


#define GRBL_PLATFORM "AT90USB1286"

// Serial port pins
#define SERIAL_RX USART0_RX_vect
#define SERIAL_UDRE USART0_UDRE_vect

// Increase Buffers to make use of extra SRAM
//#define RX_BUFFER_SIZE		256
//#define TX_BUFFER_SIZE		128
//#define BLOCK_BUFFER_SIZE	36
//#define LINE_BUFFER_SIZE	100

// Define step pulse output pins. NOTE: All step bit pins must be on the same port.
#define STEP_DDR      DDRA
#define STEP_PORT     PORTA
#define STEP_PIN      PINA
#define X_STEP_BIT    0
#define Y_STEP_BIT    2
#define Z_STEP_BIT    4
#define STEP_MASK ((1<<X_STEP_BIT)|(1<<Y_STEP_BIT)|(1<<Z_STEP_BIT)) // All step bits

// Define step direction output pins. NOTE: All direction pins must be on the same port.
#define DIRECTION_DDR     DDRA
#define DIRECTION_PORT    PORTA
#define DIRECTION_PIN     PINA
#define X_DIRECTION_BIT   1
#define Y_DIRECTION_BIT   3
#define Z_DIRECTION_BIT   5
#define DIRECTION_MASK ((1<<X_DIRECTION_BIT)|(1<<Y_DIRECTION_BIT)|(1<<Z_DIRECTION_BIT)) // All direction bits

// Define stepper driver enable/disable output pin.
#define STEPPERS_DISABLE_DDR   DDRB
#define STEPPERS_DISABLE_PORT  PORTB
#define STEPPERS_DISABLE_BIT   0
#define STEPPERS_DISABLE_MASK (1<<STEPPERS_DISABLE_BIT)

#define X_DISABLE_DDR      DDRE
#define X_DISABLE_PORT     PORTE
#define X_DISABLE_BIT      7
#define Y_DISABLE_DDR      DDRE
#define Y_DISABLE_PORT     PORTE
#define Y_DISABLE_BIT      6
#define Z_DISABLE_DDR      DDRC
#define Z_DISABLE_PORT     PORTC
#define Z_DISABLE_BIT      7

// Define homing/hard limit switch input pins and limit interrupt vectors. 
// NOTE: All limit bit pins must be on the same port
#define LIMIT_DDR       DDRB
#define LIMIT_PORT      PORTB
#define LIMIT_PIN       PINB
#define X_LIMIT_BIT     5
#define Y_LIMIT_BIT     6
#define Z_LIMIT_BIT     7
#define LIMIT_INT       PCIE0  // Pin change interrupt enable pin
#define LIMIT_INT_vect  PCINT0_vect 
#define LIMIT_PCMSK     PCMSK0 // Pin change interrupt register
#define LIMIT_MASK ((1<<X_LIMIT_BIT)|(1<<Y_LIMIT_BIT)|(1<<Z_LIMIT_BIT)) // All limit bits

// Define spindle enable and spindle direction output pins.
#define SPINDLE_ENABLE_DDR      DDRC
#define SPINDLE_ENABLE_PORT     PORTC
#define SPINDLE_ENABLE_BIT      4
#define SPINDLE_DIRECTION_DDR   DDRC
#define SPINDLE_DIRECTION_PORT  PORTC
#define SPINDLE_DIRECTION_BIT   5

// Define flood and mist coolant enable output pins.
// NOTE: Uno analog pins 4 and 5 are reserved for an i2c interface, and may be installed at
// a later date if flash and memory space allows.
#define COOLANT_FLOOD_DDR     DDRC 
#define COOLANT_FLOOD_PORT    PORTC
#define COOLANT_FLOOD_BIT     5    
#ifdef ENABLE_M7 // Mist coolant disabled by default. See config.h to enable/disable.
#define COOLANT_MIST_DDR    DDRB    // FIXME
#define COOLANT_MIST_PORT   PORTB   // FIXME
#define COOLANT_MIST_BIT    6
#endif  

// Define user-control CONTROLs (cycle start, reset, feed hold) input pins.
// NOTE: All CONTROLs pins must be on the same port and not on a port with other input pins (limits).
/*
#define CONTROL_DDR       DDRC  // FIXME
#define CONTROL_PIN       PINC  // FIXME
#define CONTROL_PORT      PORTC  // FIXME
#define RESET_BIT         6
#define FEED_HOLD_BIT     6
#define CYCLE_START_BIT   6
#define SAFETY_DOOR_BIT   6
#define CONTROL_INT       PCIE0  // Pin change interrupt enable pin
#define CONTROL_INT_vect  PCINT1_vect
#define CONTROL_PCMSK     PCMSK0 // Pin change interrupt register
#define CONTROL_MASK ((1<<RESET_BIT)|(1<<FEED_HOLD_BIT)|(1<<CYCLE_START_BIT)|(1<<SAFETY_DOOR_BIT))
*/

// Define probe switch input pin.
#define PROBE_DDR       DDRD  
#define PROBE_PIN       PIND  
#define PROBE_PORT      PORTD  
#define PROBE_BIT       6
#define PROBE_MASK      (1<<PROBE_BIT)

// Start of PWM & Stepper Enabled Spindle
#ifdef VARIABLE_SPINDLE
  // Advanced Configuration Below You should not need to touch these variables
  // Set Timer up to use TIMER4B which is attached to Digital Pin 7
  #define PWM_MAX_VALUE       65535.0
  #define TCCRA_REGISTER		TCCR4A
  #define TCCRB_REGISTER		TCCR4B
  #define OCR_REGISTER		OCR4B
  
  #define COMB_BIT			COM4B1
  #define WAVE0_REGISTER		WGM40
  #define WAVE1_REGISTER		WGM41
  #define WAVE2_REGISTER		WGM42
  #define WAVE3_REGISTER		WGM43
  
  #define SPINDLE_PWM_DDR		DDRB  // FIXME
  #define SPINDLE_PWM_PORT    PORTB  // FIXME
  #define SPINDLE_PWM_BIT		4 // MEGA2560 Digital Pin 97
#endif // End of VARIABLE_SPINDLE
