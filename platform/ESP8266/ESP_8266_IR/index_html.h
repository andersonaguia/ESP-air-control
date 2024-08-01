const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="pt-BR">
  <head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>IOT LAB</title>
    <link rel="icon" href="https://softexlabs.com.br/static/images/SOFTLABS.svg" type ="image/x-icon" />
    <style>
      * {
        margin: 0;
        padding: 0;
        box-sizing: border-box;
      }
      body {
        font-family: Poppins, sans-serif;
        background-color: #f9fafd;
      }
      header {
        width: 100%;
        display: flex;
        justify-content: center;
        align-items: center;
      }
      img {
        width: 10rem;
        height: auto;
      }
      h1 {
        font-size: 2.5rem;
      }
      ul {
        width: 20%;
        list-style-type: none;
        display: flex;
        flex-direction: column;
        gap: 1rem;
      }     
      button {
        width: 100%;
        height: 100%;
        padding: 1rem;
        background-color: #0170b9;
        color: #ffffff;
        font-size: 1rem;
        cursor: pointer;
        border-radius: 10px; 
        border: none;       
      }
      button:hover {
          opacity: 0.8;
      }
      .buttonOff{
        background-color: #3a3a3a;
      }
      main {
        width: 100%;
        min-height: 75vh;
        display: flex;
        justify-content: center;
        align-items: center;
      }
      footer {
        width: 100%;
        display: flex;
        flex-direction: column;
        justify-content: center;
        align-items: center;
        gap: 1rem;
      }
      .footer-img {
        width: 10rem;
        padding: 0 2rem;
      }
      span {
        font-size: .8rem;
      }
      @media (max-width: 768px) {
        ul {
          width: 80%;
        }
        header {
          flex-direction: column;
          justify-content: center;
          align-items: center;
        }
        h1 {
          font-size: 1rem;
          margin-top: 1rem;
        }
        .footer-img {
          width: 6rem;
        }
        span {
          font-size: .3rem;
        }
      }
    </style>
    <script>
        function powerOn() {
            fetch('/on').then(response => {
                if (response.ok) {
                    console.log("Enviado comando para ligar o ar");
                }else{
                    console.log("Comando falhou, tente novamente!");
                }
            });
        }
        function powerOff() {
            fetch('/off').then(response => {
                if (response.ok) {
                    console.log("Enviado comando para desligar o ar");
                }else{
                    console.log("Comando falhou, tente novamente!");
                }
            });
        }
    </script>
  </head>
  <body>
    <header>
      <img src="https://softexlabs.com.br/static/images/SOFTLABS.svg" alt="Logo SOFTEX Labs" />
      <h1>IOT LAB</h1>
    </header>
    <main>
      <ul>
        <li><button onclick="powerOn()">LIGAR</button></li>
        <li><button onclick="powerOff()" class="buttonOff">DESLIGAR</button></li>
      </ul>
    </main>
    <footer>
      <div>
        <img class="footer-img" src="https://softexlabs.com.br/static/images/softexPE.svg" alt="Logo SOFTEX" />
      </div>
      <span>&copy; 2024 IOT LAB. Todos os direitos reservados.</span>
    </footer>
  </body>
</html>
)rawliteral";
