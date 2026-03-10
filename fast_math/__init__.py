from .fast_math_c import multiply

def matmul_entry_point(a, b):
    # You can add Python-side validation here
    return multiply(a, b)
