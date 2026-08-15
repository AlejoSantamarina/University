import random

#Idem 1.
def simulate_experiment (iterations = 100000):
    card_deck = ['S', 'S', 'S', 'S', 'D', 'D']

    results = {
        "Two simples": 0,
        "Two difficult": 0,
        "One and one": 0,
        "Difficult after simple": 0
    }

    for _ in range(iterations):
        card1 = random.choice(card_deck)
        card2 = random.choice(card_deck)

        if card1 == 'S' and card2 == 'S':
            results['Two simples'] += 1
        elif card1 == 'S' and card2 == 'D' or card1 == 'D' and card2 == 'S':
            results['One and one'] += 1
        else:
            results['Two difficult'] += 1
        if card1 == 'S' and card2 == 'D':
            results['Difficult after simple'] += 1


    print(f"Without replacement, results after {iterations} iterations: ")

    two_simples_prob = f"{(results['Two simples']/iterations) * 100:.2f}"
    two_difficult_prob = f"{(results['Two difficult']/iterations) * 100:.2f}"
    one_and_one_prob = f"{(results['One and one']/iterations) * 100:.2f}"
    difficult_after_simple_prob = f"{(results['Difficult after simple']/iterations) * 100:.2f}"
    
    print(f"Two simples: {two_simples_prob}%.")
    print(f"Two difficult: {two_difficult_prob}%.")
    print(f"One and one: {one_and_one_prob}%.")
    print(f"Difficult after simple: {difficult_after_simple_prob}%.")

simulate_experiment()

print("-" * 50)

#Idem 2.

def simulate_experiment2 (iterations = 100000):
    results = {
        "Two simples": 0,
        "Two difficult": 0,
        "One and one": 0,
        "Difficult after simple": 0
    }

    for _ in range(iterations):
        card_deck = ['S', 'S', 'S', 'D', 'D']
        card1 = random.choice(card_deck)
        card_deck.remove(card1)
        card2 = random.choice(card_deck)

        if card1 == 'S' and card2 == 'S':
            results['Two simples'] += 1
        elif card1 == 'S' and card2 == 'D' or card1 == 'D' and card2 == 'S':
            results['One and one'] += 1
        else:
            results['Two difficult'] += 1
        if card1 == 'S' and card2 == 'D':
            results['Difficult after simple'] += 1


    print(f"With replacement, results after {iterations} iterations: ")

    two_simples_prob = f"{(results['Two simples']/iterations) * 100:.2f}"
    two_difficult_prob = f"{(results['Two difficult']/iterations) * 100:.2f}"
    one_and_one_prob = f"{(results['One and one']/iterations) * 100:.2f}"
    difficult_after_simple_prob = f"{(results['Difficult after simple']/iterations) * 100:.2f}"
    
    print(f"Two simples: {two_simples_prob}%.")
    print(f"Two difficult: {two_difficult_prob}%.")
    print(f"One and one: {one_and_one_prob}%.")
    print(f"Difficult after simple: {difficult_after_simple_prob}%.")

simulate_experiment2()

print("-" * 50)

#Idem 4.
def simulate_experiment3 (iterations = 100000):
    sick_people = 0
    healthy_people = 0

    positive_sicks = 0
    positive_totals = 0

    healthy_and_N = 0
    sick_and_P = 0

    negative_test = 0
    positive_test = 0

    for _ in range(iterations):
        sick = random.random() < 0.005
        if sick:
            sick_people+= 1
            test = random.random() < 0.95
            if test:
                positive_sicks+= 1
                sick_and_P+= 1
                positive_test+= 1
            else:
                negative_test+= 1
        else:
            healthy_people+= 1
            test = random.random() < 0.04
            if test:
                positive_totals+= 1
                positive_test+=1
            else:
                negative_test+= 1
                healthy_and_N+= 1

    healthy_and_N_prob = f"{healthy_and_N/negative_test*100:.2f}%"
    sick_and_P_prob = f"{sick_and_P/positive_test*100:.2f}%"
    
    print(f"Healthy and negative {healthy_and_N_prob}")
    print(f"Sick and positive {sick_and_P_prob}")

simulate_experiment3()