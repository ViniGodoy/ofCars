#ifndef __ALUNOCARRO1_H__
#define __ALUNOCARRO1_H__

#include "car.h"
#include "World.h"

class AlunoCarro1 : public Car
{
	public:
		//Criacao de um novo carro. As dimenscoes do carro sao 20x40
		AlunoCarro1() : Car(
			Blue,			//Cor. Pode ser: Black, Red, Green, Orange, Blue, Pink ou LightBlue
			Vector2D(0,0),	//Posicao inicial. A tela vai em x de -400 ate 400 e em y de 300 ate -300. (0,0) e o centro.
			0)				//Angulo em que o veículo esta posicionado, em graus
		{
		}			
		
		//Deve calcular o steering behavior para esse carro
		//
		//O parametro world contem diversos metodos utilitarios
		//
		//world.isClicked(): Indica se houve um click do usuario
		//world.getClickPos(): Retorna um vector2D com a posicao do último click
		//world.getMousePos(): Retorna um vector2D com a posicao do cursor do mouse
		//world.getNeighbors(): Retorna os carros vizinhos. Nao inclui o proprio carro.
		//      opcionalmente, voce pode passar o raio da vizinhanca. Se o raio nao for
		//      fornecido retornara todos os demais carros.
		//world.getSecs(): Indica quantos segundos transcorreram desde o ultimo gameloop
		//world.isKeyPressed(int): Indica se a tecla esta ou nao pressionada.
		//
		//Adicionalmente, você ainda podera chamar os seguintes metodos para obter informacoes
		//dos carros:
		//getDirection(): Retorna um vetor unitario com a direcao do veículo
		//getPosition(): Retorna um vetor com a posicao do carro
		//getMass(): Retorna a massa do carro
		//getMaxSpeed(): Retorna a velocidade de deslocamento maxima do carro em pixels / s
		//getMaxForce(): Retorna a forca maxima que pode ser aplicada sobre o carro
		//

		virtual Vector2D calculateSteering(const World& world)
		{
			return Vector2D(0,0);
		}
};

#endif //__ALUNOCARRO1_H__
