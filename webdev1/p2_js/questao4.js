function testesqrrt(numero) {

    if (numero < 0) {
        return false;
    }

    const raizQuadrada = Math.sqrt(numero);

    if (Number.isInteger(raizQuadrada)) {
        return true;
    } else {
        return false;
    }
}


const n = parseInt(prompt("Digite um número:"));


if (testesqrrt(n)) {
  console.log(`${n} é um quadrado perfeito.`);
} else {
  console.log(`${n} não é um quadrado perfeito.`);
}
