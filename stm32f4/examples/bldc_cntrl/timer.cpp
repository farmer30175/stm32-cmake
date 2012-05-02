/*
    <one line to give the program's name and a brief idea of what it does.>
    Copyright (C) 2012  <copyright holder> <email>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stm32f4xx_rcc.h>
#include <stm32f4xx_tim.h>
#include <misc.h>

#include "timer.h"

Timer::Timer() {
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6, ENABLE);
  TIM_TimeBaseInitTypeDef timer;
  TIM_TimeBaseStructInit(&timer);
  /* Делитель учитывается как TIM_Prescaler + 1, поэтому отнимаем 1 */
  timer.TIM_Prescaler = 168 - 1;
  timer.TIM_Period = 500 - 1;
  TIM_TimeBaseInit(TIM6, &timer);
  TIM_ITConfig(TIM9, TIM_IT_Update, ENABLE);
  TIM_Cmd(TIM9, ENABLE);
  NVIC_EnableIRQ(TIM1_BRK_TIM9_IRQn);
}

Timer::~Timer()
{
  
}