# Usando o ESP-PROG para debug inline com Platform.io e ESP32

<div style="text-align: justify">
Trabalho já há alguns anos com desenvolvimento de software para embarcados e já me deparei com ferramentas bem caras. O J-Link é uma ferramenta indispensável, mas muito cara para quem está aprendendo. 

A alternativa mais barata é buscar pelos programadores de cada fabricante, e assim como a ST possui o STLINK a Espressif possui o ESP-PROG.

O ESP_PROG é uma alternativa bem interessante ao JLINK, principalmente pelo custo. Um JLINK original custa entorno de U$ 1000 enquanto o ESP-PROG encontrei na casa dos U$20 (cerca de R$100,00 quando comprei).

A questão é que não é só comprar e plugar numa USB do computador. Passei bons dias olhando na internet, mas muitos tutoriais estavam antigos e defasados. 
</div>

## 1 - Onde comprar o ESP-PROG?
<div style="text-align: justify">
Já começo dizendo que não vou deixar nenhum link de onde comprar, mas você pode pesquisar rapidamente em sites comuns. Recomendo procurar no Mercado Livre ou Aliexpress.

Buscando no Mercado Livre vi varias opções variando entre R$160,00 e R$260,00. Se atente se é um envio nacional ou internacional, pois se estiver com pressa vai cair do cavalo. 

Já no Aliexpress você pode encontrar entre R$60,00 e R$120,00, além do frete em alguns anuncios e também da remessa conforme. Cabe a você encontrar o equilibrio e comprar na opção que melhor te atende.
</div>

## 2 - O que precisa ser feito para começar a usar?
### 2.1 - Baixe o Zadig
<div style="text-align: justify">
https://zadig.akeo.ie

Esse programinha serve para modificar os drivers no seu computador. Sem ele, deve aparecer duas portas COM no Gerenciador de Dispositivos:
</div>

<br>

<div align="center">
<img src = "https://github.com/aleclima14/Platform_Debug_With_ESP-PROG/blob/main/README_files/image.png?raw=true"/>
</div>

<br>

<div style="text-align: justify">
Após baixar, abra o programa. Ele tem essa cara:
</div>

<br>

<div align="center">
<img src = "https://github.com/aleclima14/Platform_Debug_With_ESP-PROG/blob/main/README_files/image-1.png?raw=true"/>
</div>

<br>

<div style="text-align: justify">
Vá em Options > List ALL Devices:
</div>

<br>

<div align="center">
<img src = "https://github.com/aleclima14/Platform_Debug_With_ESP-PROG/blob/main/README_files/image-2.png?raw=true"/>
</div>

<br>

<div style="text-align: justify">
Selecione o device "Dual RS232-HS (Interface 0) e clique em Replace Driver. O processo vai levar um certo tempo, coisa de alguns minutos dependendo da sua internet e computador.

OBS: Só faça esse procedimento no device "Interface 0", o outro deixe como está.
</div>

<br>

<div align="center">
<img src = "https://github.com/aleclima14/Platform_Debug_With_ESP-PROG/blob/main/README_files/image-3.png?raw=true"/>
</div>

<br>

<div style="text-align: justify">
Ao final deve aparecer um pop-up dizendo se deu certo ou se deu errado. Em caso positivo, no Gerenciador de Dispositivos você terá uma porta COM referente ao ESP-PROG e um Dispositivo de Barramento Serial Universal:
</div>

<br>

<div align="center">
<img src = "https://github.com/aleclima14/Platform_Debug_With_ESP-PROG/blob/main/README_files/image-4.png?raw=true"/>
<img src = "https://github.com/aleclima14/Platform_Debug_With_ESP-PROG/blob/main/README_files/image-5.png?raw=true"/>
</div> 


### 2.2 - 
