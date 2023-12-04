valor = float(input())

centavos = int(valor * 100)

notas_moedas = [10000, 5000, 2000, 1000, 500, 200, 100, 50, 25, 10, 5, 1]

print("NOTAS:")
for nota_moeda in notas_moedas[:6]:
    notas = centavos // nota_moeda
    centavos %= nota_moeda
    print(f"{notas} nota(s) de R$ {nota_moeda / 100:.2f}")

print("MOEDAS:")
for nota_moeda in notas_moedas[6:]:
    moedas = centavos // nota_moeda
    centavos %= nota_moeda
    print(f"{moedas} moeda(s) de R$ {nota_moeda / 100:.2f}")
