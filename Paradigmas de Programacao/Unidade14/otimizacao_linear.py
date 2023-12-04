import pulp

# Crie um problema de otimização linear
problem = pulp.LpProblem("ProblemaDeMaximizacao", pulp.LpMaximize)

# Defina as variáveis de decisão
x1 = pulp.LpVariable("x1", lowBound=0)
x2 = pulp.LpVariable("x2", lowBound=0)

# Defina a função objetivo
problem += 10 * x1 + 7 * x2

# Defina as restrições
problem += 2 * x1 + x2 <= 5000
problem += 4 * x1 + 5 * x2 <= 15000

# Resolva o problema
problem.solve()

# Exiba o status da solução
print("Status:", pulp.LpStatus[problem.status])

# Exiba os valores ótimos das variáveis de decisão
print("Valor ótimo de x1:", x1.varValue)
print("Valor ótimo de x2:", x2.varValue)

# Exiba o valor ótimo da função objetivo
print("Valor ótimo da função objetivo:", pulp.value(problem.objective))