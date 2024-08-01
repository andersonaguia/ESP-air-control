const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="pt-BR">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>IOT LAB</title>
    <style>
        body {
            display: flex;
            flex-direction: column;
            justify-content: space-between;
            align-items: center;
            min-height: 100vh;
            margin: 0;
            background-color: #aaaaaa; 
            font-family: Arial, sans-serif;
            text-align: center;
        }
        .header, .footer {
            display: flex;
            justify-content: center;
            align-items: center;
            flex-direction: column;
        }
        .header img {
            width: 200px; 
            height: auto;
            margin-top: 20px;
        }
        .title {
            display: flex;
            flex-direction: column;
            align-items: center;
            margin: 20px 0;
        }
        .title h1 {
            margin: 20px 0;
        }
        .buttons {
            display: flex;
            flex-direction: column;
            gap: 10px;
        }
        .button {
            padding: 15px 30px;
            font-size: 16px;
            color: #000;
            background-color: #fff;
            border: none;
            border-radius: 25px; 
            cursor: pointer;
            text-transform: uppercase;
            font-weight: bold;
            width: 150px;
            transition: background-color 0.3s;
        }
        .button.ligar-verde {
            background-color: green;
            color: white;
        }
        .button.desligar-vermelho {
            background-color: red;
            color: white;
        }
        .footer {
            margin-bottom: 20px;
        }
        .footer img {
            width: 150px; 
            height: auto;
        }
        .footer p {
            margin-top: 10px;
            font-size: 12px;
            color: #000;
        }
    </style>
</head>
<body>
    <header class="header">
        <div class="title">
            <img src="https://softexlabs.com.br/static/images/softexPE.svg" alt="Logo SOFTEX">
            <h1>IOT LAB</h1>
            <h3>CONTROLE AUTOMAÇÃO <br> AR CONDICIONADO</h3>
        </div>
    </header>
    <div class="buttons">
        <button class="button" id="ligarButton" onclick="ligar()">Ligar</button>
        <button class="button" id="desligarButton" onclick="desligar()">Desligar</button>
    </div>
    <footer class="footer">
        <img src="https://softexlabs.com.br/static/images/SOFTLABS.svg" alt="Logo SOFTEX">
        <p>© 2024 IOT LAB. Todos os direitos reservados.</p>
    </footer>
    <script>
        function ligar() {
            fetch('/on').then(response => {
                if (response.ok) {
                    const ligarButton = document.getElementById('ligarButton');
                    const desligarButton = document.getElementById('desligarButton');
                    ligarButton.classList.add('ligar-verde');
                    desligarButton.classList.remove('desligar-vermelho');
                }
            });
        }
        function desligar() {
            fetch('/off').then(response => {
                if (response.ok) {
                    const ligarButton = document.getElementById('ligarButton');
                    const desligarButton = document.getElementById('desligarButton');
                    desligarButton.classList.add('desligar-vermelho');
                    ligarButton.classList.remove('ligar-verde');
                }
            });
        }
    </script>
</body>
</html>
)rawliteral";
