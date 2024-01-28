# Usando o ESP-PROG para debug inline com Platform.io e ESP32

<div align="justify">
Trabalho já há alguns anos com desenvolvimento de software para embarcados e já me deparei com ferramentas bem caras. O J-Link é uma ferramenta indispensável, mas muito cara para quem está aprendendo. 

A alternativa mais barata é buscar pelos programadores de cada fabricante, e assim como a ST possui o STLINK a Espressif possui o ESP-PROG.
<br>
<div align="center">
<img src = "https://docs.platformio.org/en/latest/_images/esp-prog.jpg"/>
</div>
<br>
O ESP_PROG é uma alternativa bem interessante ao JLINK, principalmente pelo custo. Um JLINK original custa entorno de U$ 1000 enquanto o ESP-PROG encontrei na casa dos U$20 (cerca de R$100,00 quando comprei).

A questão é que não é só comprar e plugar numa USB do computador. Passei bons dias olhando na internet, mas muitos tutoriais estavam antigos e defasados. 
</div>

## 1 - Onde comprar o ESP-PROG?
<div align="justify">
Já começo dizendo que não vou deixar nenhum link de onde comprar, mas você pode pesquisar rapidamente em sites comuns. Recomendo procurar no Mercado Livre ou Aliexpress.

Buscando no Mercado Livre vi varias opções variando entre R$160,00 e R$260,00. Se atente se é um envio nacional ou internacional, pois se estiver com pressa vai cair do cavalo. 

Já no Aliexpress você pode encontrar entre R$60,00 e R$120,00, além do frete em alguns anuncios e também da remessa conforme. Cabe a você encontrar o equilibrio e comprar na opção que melhor te atende.
</div>

## 2 - O que precisa ser feito para começar a usar?
### 2.1 - Baixe o Zadig
<div align="justify">
https://zadig.akeo.ie

Esse programinha serve para modificar os drivers no seu computador. Sem ele, deve aparecer duas portas COM no Gerenciador de Dispositivos:
</div>

<br>

<div align="center">
<img src = "https://github.com/aleclima14/Platform_Debug_With_ESP-PROG/blob/main/README_files/image.png?raw=true" />
</div>

<br>

<div align="justify">
Após baixar, abra o programa. Vá em Options > List ALL Devices:
</div>

<br>

<div align="center">
<img src = "https://github.com/aleclima14/Platform_Debug_With_ESP-PROG/blob/main/README_files/image-1.png?raw=true" width="500"/>
<img src = "https://github.com/aleclima14/Platform_Debug_With_ESP-PROG/blob/main/README_files/image-2.png?raw=true" width="500"/>
</div>

<br>

<div align="justify">
Selecione o device "Dual RS232-HS (Interface 0) e clique em Replace Driver. O processo vai levar um certo tempo, coisa de alguns minutos dependendo da sua internet e computador.

OBS: Só faça esse procedimento no device "Interface 0", o outro deixe como está.
</div>

<br>

<div align="center">
<img src = "https://github.com/aleclima14/Platform_Debug_With_ESP-PROG/blob/main/README_files/image-3.png?raw=true" width="500"/>
</div>

<br>

<div align="justify">
Ao final deve aparecer um pop-up dizendo se deu certo ou se deu errado. Em caso positivo, no Gerenciador de Dispositivos você terá uma porta COM referente ao ESP-PROG e um Dispositivo de Barramento Serial Universal:
</div>

<br>

<div align="center">
<img src = "https://github.com/aleclima14/Platform_Debug_With_ESP-PROG/blob/main/README_files/image-4.png?raw=true"/>
<img src = "https://github.com/aleclima14/Platform_Debug_With_ESP-PROG/blob/main/README_files/image-5.png?raw=true"/>
</div> 


### 2.2 - Configure o Platform.io
<div align="justify">
Essa é a etapa mais simples, mas também muito importante. Será necessário adicionar algumas linhas no arquivo "platformio.ini"
</div>

<br>

<div align="center">
  
![image](https://github.com/aleclima14/Platform_Debug_With_ESP-PROG/assets/93883349/239f50de-a8fb-4271-a577-54b81524b0aa)
</div>

#### 0 - Board
<div align="justify">
Aqui é bem importante. O Platform.io não suporta todas as placas e você deve se atentar a isso. Na documentação oficial mostra quais são suportadas:
  <br> <br>
https://docs.platformio.org/en/latest/plus/debug-tools/esp-prog.html#wiring-connections
  <br> <br>
Mas do jeit que está na imagem (board = esp32dev) vai atender aqueles modulos vendidos na internet aqui no Brasil e vem funcionando com o Lolin32 Lite que originalmente é uma placa não suportada.
</div>

#### 1 - upload_port = COM12
<div align="justify">
Configura a porta que vai usar. Aqui é opcional, mas recomendo deixar caso você tenha outros devices espetados no computador.
</div>

#### 2 - debug_tool = esp-prog
<div align="justify">
Define qual ferramenta será usada para o debug, no nosso caso é o próprio ESP-PROG
</div>

#### 3 - upload_protocol = esp-prog
<div align="justify">
Aqui é opcional. Define como será feito o upload do código (quando você não quiser entrar em debug, por exemplo). Eu deixo configurado dessa forma, assim não preciso usar a USB do ESP32. É bom para placas customizadas.
</div>

#### 4 - debug_init_break = tbreak setup
<div align="justify">
Aqui define onde será o primeiro break point ao iniciar o debug. Eu deixo no setup mesmo, mas você pode deixar em outra função como a Loop, por exemplo.
</div>

## 3 - Quais pinos usar?
<div align="justify">
Procure pelo conector maior, de 10 vias. Usando jumpers (aqueles de Arduino mesmo) você pode conectar aos pinos do ESP32.
<br><br>
E não se esqueça da alimentação. GND com GND e VDD (ou VCC) com VCC. Lembre-se que o ESP32 é 3.3V.
<div align="center">
<img src = "https://docs.platformio.org/en/latest/_images/esp-prog_jtag_connector.png"/>


|Pino no ESP-PROG	|Pino no ESP32|
|-----------------|-----------------|
|ESP_TMS	|14|
|ESP_TCK	|13|
|ESP_TDO	|15|
|ESP_TDI	|12|
</div>
<br>

</div>
