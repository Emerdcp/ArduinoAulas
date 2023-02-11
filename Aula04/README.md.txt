Estrutura de decisão

if - se

Operador de Atribuição
	= pega o que está do lado direito do sinal e coloca dentro do que está do lado esquerdo. Ex: led = 13
	
Operadores relacionais
	> maior
	>= maior ou igual
	< menor
	<= menor ou igual
	== igual (comparação)
	!= diferente

if(condição){
	bloco de comando quando a condição for verdadeira
	comandos
	comandos
}else{
	bloco de comando quando a condição for falsa
	comando
	comando
}

if(idade >= 18){
	pode dirigir
}else{
	volte daqui alguns anos
}

4
if(media >= 7){
	Aprovado
}else if(media >= 4){
	recuperação
}