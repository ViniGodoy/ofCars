/******************************************************************************
*
* COPYRIGHT Vin�cius G. Mendon�a ALL RIGHTS RESERVED.
*
* This software cannot be copied, stored, distributed without  
* Vin�cius G.Mendon�a prior authorization.
*
* This file was made available on http://www.pontov.com.br and it is free 
* to be restributed or used under Creative Commons license 2.5 br: 
* http://creativecommons.org/licenses/by-sa/2.5/br/
*
*******************************************************************************
* Este software nao pode ser copiado, armazenado, distribuido sem autoriza��o 
* a priori de Vin�cius G. Mendon�a
*
* Este arquivo foi disponibilizado no site http://www.pontov.com.br e esta 
* livre para distrui��o seguindo a licen�a Creative Commons 2.5 br: 
* http://creativecommons.org/licenses/by-sa/2.5/br/
*
******************************************************************************/
#ifndef GAMESTEPS_H_INCLUDED
#define GAMESTEPS_H_INCLUDED

union SDL_Event;

class GameSteps
{
    public:
        virtual void setup() = 0;
    
        virtual void update() = 0;
        virtual void draw() const = 0;

        virtual bool ended() = 0;

        virtual void teardown() = 0;
        virtual ~GameSteps() {};
};

#endif // GAMESTEPS_H_INCLUDED
