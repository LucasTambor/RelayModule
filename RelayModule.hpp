/*******************************************************************************
%        ____ ___   ______   ______                      __            _
%       / __ \__ \ / ____/  /_  __/__  _________  ____  / /___  ____ _(_)___ _
%      / / / /_/ // / __     / / / _ \/ ___/ __ \/ __ \/ / __ \/ __ `/ / __ `/
%     / /_/ / __// /_/ /    / / /  __/ /__/ / / / /_/ / / /_/ / /_/ / / /_/ /
%    /_____/____/\____/    /_/  \___/\___/_/ /_/\____/_/\____/\__, /_/\__,_/
%                                                            /____/
%                    Diego Pinto, Diego Von e Grégory Gusberti @ 2016
%
% Abstração de hardware para módulos relé - 4 relés
%
% Autor: Diego Pinto
%
% *****************************************************************************/

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
