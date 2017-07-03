/*************************************************
* Biblioteca para controlar módulo relé (4 relés)*
*/************************************************
 
#include "RelayModule.hpp"

//---------------------------------------------------------------------------

RelayModule::RelayModule(const int pin0, const int pin1, const int pin2, const int pin3, const bool activate_state):
   a_state(activate_state),
   pins{pin0, pin1, pin2, pin3},
   state{false, false, false, false}
{
   for (size_t i = 0; i < N_RELAYS; i++) pinMode(pins[i], OUTPUT);
}

//---------------------------------------------------------------------------

void RelayModule::set(const size_t index, const bool state)
{
   bool s;

   s = state ^ (!a_state);

   this->state[index] = s;
   digitalWrite(pins[index], s);
}

//---------------------------------------------------------------------------

void RelayModule::on(const size_t index)
{
   state[index] = a_state;
   digitalWrite(pins[index], a_state);
}

//---------------------------------------------------------------------------

void RelayModule::off(const size_t index)
{
   state[index] = !a_state;
   digitalWrite(pins[index], !a_state);
}

//---------------------------------------------------------------------------

void RelayModule::toggle(const size_t index)
{
   state[index] = !state[index];
   digitalWrite(pins[index], state[index]);
}

//---------------------------------------------------------------------------

void RelayModule::setAll(const bool state)
{
   for (size_t i = 0; i < N_RELAYS; i++) set(i, state);
}

//---------------------------------------------------------------------------

void RelayModule::onAll(void)
{
   for (size_t i = 0; i < N_RELAYS; i++) on(i);
}

//---------------------------------------------------------------------------

void RelayModule::offAll(void)
{
   for (size_t i = 0; i < N_RELAYS; i++) off(i);
}

//---------------------------------------------------------------------------

void RelayModule::toggleAll(void)
{
   for (size_t i = 0; i < N_RELAYS; i++) toggle(i);
}

//---------------------------------------------------------------------------
