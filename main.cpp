def calfp(frates, fac_rate):
    # Jednostki funkcyjne (opcjonalne do opisu, ale zachowane dla spójności)
    fun_units = [
        "External Inputs",
        "External Outputs",
        "External Inquiries",
        "Internal Logical Files",
        "External Interface Files"
    ]

    # Współczynniki wagowe (Weight Factors)
    wt_factors = [
        [3, 4, 6],   # External Inputs
        [4, 5, 7],   # External Outputs
        [3, 4, 6],   # External Inquiries
        [7, 10, 15], # Internal Logical Files
        [5, 7, 10]   # External Interface Files
    ]

    ufp = 0

    # Obliczanie UFP (Unadjusted Function Point)
    for i in range(5):
        for j in range(3):
            freq = frates[i][j]
            ufp += freq * wt_factors[i][j]

    # W tym kodzie sumujemy 14 czynników, każdy o tej samej wartości fac_rate
    sum_f = 14 * fac_rate

    # Obliczanie CAF (Complexity Adjustment Factor)
    caf = 0.65 + 0.01 * sum_f

    # Obliczanie Function Point (FP)
    fp = ufp * caf

    # Wyświetlanie wyników
    print("Function Point Analysis :-")
    print(f"Unadjusted Function Points (UFP) : {ufp}")
    print(f"Complexity Adjustment Factor (CAF) : {caf:.2f}")
    print(f"Function Points (FP) : {fp:.2f}")

# Funkcja główna (driver function)
if __name__ == "__main__":
    # Dane wejściowe (ilości poszczególnych elementów)
    frates = [
        [0, 1, 0], # EI
        [0, 1, 0], # EO
        [0, 3, 0], # EQ
        [0, 1, 0], # ILF
        [0, 3, 0]  # EIF
    ]

    # Stała ocena dla wszystkich 14 czynników
    fac_rate = 3

    calfp(frates, fac_rate)
