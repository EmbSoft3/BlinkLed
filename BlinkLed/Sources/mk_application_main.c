/**
*
* @copyright Mk - Copyright (C) 2017-2026 RENARD Mathieu.
*
* This file is part of Mk.
*
* Mk is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* Mk is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with Mk.  If not, see <https://www.gnu.org/licenses/>.
*
* @file mk_main.c
* @brief Déclaration de la fonction main.
* @date 2 janv. 2024
*
*/

#include "mk.h"
#include "mk_application_main.h"

/**
 * @internal
 * @brief
 * @endinternal
 */

uint32_t var = 1;

/**
 * @internal
 * @brief
 * @endinternal
 */

static void gpio_toogle ( void )
{
   if ( var == 0 )
   {
      mk_gpio_set ( K_MK_GPIO_SYSID, K_MK_GPIO_PIN_LED1, 0, K_MK_NULL );
      var = 1;
   }
   else
   {
      mk_gpio_set ( K_MK_GPIO_SYSID, K_MK_GPIO_PIN_LED1, 1, K_MK_NULL );
      var = 0;
   }

   /* Retour */
   return;
}

/**
 * @internal
 * @brief
 * @endinternal
 */

void main ( T_mkAddr p_param )
{
   /* Compiler Miscalenous : -fPIC -mlong-calls */
   /* Linker : -shared -z max-page-size=65536 */

   /* Déclaration d'une variable de travail */
   uint32_t l_rate;

   /* Déclaration d'un tableau contenant la fréquence de clignotement en ASCII */
   uint8_t l_argv [ 16 ] = { 0 };

   /* Déclaration d'un pointeur de chaine de caractères */
   T_str8 l_arguments = K_MK_NULL;

   /* Déclaration d'une structure de configuration */
   T_mkGPIOSetting l_setting = { K_MK_GPIO_OUTPUT, K_MK_GPIO_PUSHPULL, K_MK_GPIO_PULLUP };

   /* Déclaration d'un pointeur d'application */
   T_mkApplication* l_application = ( T_mkApplication* ) p_param;

   /* Récupération de l'argument saisi en ligne de commande */
   ( void ) mk_application_getCmdLine ( ( T_mkApplication* ) l_application, &l_arguments );

   /* Récupération du premier argument */
   ( void ) mk_application_getArgv ( l_arguments, &l_arguments, ( T_str8 ) l_argv, 16, K_MK_FONT_ASCII );

   /* Conversion du paramètre en entier */
   l_rate = ( uint32_t ) mk_utils_atoi ( ( T_str8 ) l_argv, 10 );

   /* Configuration de la broche connectée au voyant en sortie */
   mk_gpio_setup ( K_MK_GPIO_SYSID, K_MK_GPIO_PIN_LED1, &l_setting, K_MK_NULL );

   /* Boucle pour toujours */
   while (1)
   {
     gpio_toogle ( );
     mk_task_sleep ( l_rate );
   }

   /* Retour */
   return;
}



