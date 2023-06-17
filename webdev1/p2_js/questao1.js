//1 - Crie uma função que receba um número como parâmetro e determine se ele é primo ou não. Um número primo é aquele que é divisível apenas por 1 e por ele mesmo. Liste todos os números primos entre 1 e 1000.


function checkprimo(num) {
    if (num <= 1) {
      return false;
    }
  
    for (let i = 2; i <= Math.sqrt(num); i++) {
      if (num % i === 0) {
        return false;
      }
    }
  
    return true;
  }
  
  const number = parseInt(prompt("Digite um numero:"));
  
  if (checkprimo(number)) {
    console.log(number + " é um número primo.");
  } else {
    console.log(number + " não é um número primo.");
  }
  
  console.log("Números primos entre 1 e 1000:");
  const primos = [];
  for (let i = 2; i <= 1000; i++) {
    if (checkprimo(i)) {
      primos.push(i);
    }
  }
  console.log(primos.join("\n"));
