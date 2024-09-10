function testesenha(password) {
    const minuscula = /[a-z]/;
    const maiuscula = /[A-Z]/;
    const numeros = /[0-9]/;
    const oitocaracteres = 8;
  
    const testeminuscula = minuscula.test(password);
    const testemaiuscula = maiuscula.test(password);
    const testenumeros = numeros.test(password);
    const testencaracteres = password.length >= oitocaracteres;
  
    return testeminuscula && testemaiuscula && testenumeros && testencaracteres;
  }
  
    const minuscula = /[a-z]/;
    const maiuscula = /[A-Z]/;
    const numeros = /[0-9]/;



    const inputPassword = prompt("Digite sua senha:");
    const isPasswordValid = testesenha(inputPassword);
  
    if (isPasswordValid) {
        console.log("Senha valida!");
    } else {
        console.log("Senha invalida!");
  
        if (inputPassword.length < 8) {
            console.log("A senha deve ter pelo menos 8 caracteres.");
        }
        if (!minuscula.test(inputPassword)) {
            console.log("A senha deve conter pelo menos uma letra minuscula.");
        }
        if (!maiuscula.test(inputPassword)) {
            console.log("A senha deve conter pelo menos uma letra maiuscula.");
        }
        if (!numeros.test(inputPassword)) {
            console.log("A senha deve conter pelo menos um numero.");
        }
    }
