import random

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


    print(f"Results after {iterations} iterations: ")

    two_simples_prob = f"{(results['Two simples']/iterations) * 100:.2f}"
    two_difficult_prob = f"{(results['Two difficult']/iterations) * 100:.2f}"
    one_and_one_prob = f"{(results['One and one']/iterations) * 100:.2f}"
    difficult_after_simple_prob = f"{(results['Difficult after simple']/iterations) * 100:.2f}"
    
    print(f"Two simples: {two_simples_prob}%.")
    print(f"Two difficult: {two_difficult_prob}%.")
    print(f"One and one: {one_and_one_prob}%.")
    print(f"Difficult after simple: {difficult_after_simple_prob}%.")

simulate_experiment()