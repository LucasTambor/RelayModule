/*************************************************
* Biblioteca para controlar módulo relé (4 relés)*
*/************************************************

#ifndef RELAYMODULE_HPP
#define RELAYMODULE_HPP

//---------------------------------------------------------------------------

#include "Arduino.h"

//---------------------------------------------------------------------------

const size_t N_RELAYS = 4;

//---------------------------------------------------------------------------

class RelayModule
{
   public:

      RelayModule(const int pin0, const int pin1, const int pin2, const int pin3, const bool activate_state);

      void set(const size_t index, const bool state);
      void on(const size_t index);
      void off(const size_t index);
      void toggle(const size_t index);

      void setAll(const bool state);
      void onAll(void);
      void offAll(void);
      void toggleAll(void);

   private:

      bool a_state;

      int pins[N_RELAYS];
      bool state[N_RELAYS];

};

//---------------------------------------------------------------------------
#endif // RELAYMODULE_HPP
