# 42_push_swap

# Push Swap

## Summary

This project involves sorting data on a stack using a limited set of instructions and achieving the lowest possible number of actions. The goal is to write a program in C called push_swap that calculates and displays the smallest program, made of Push Swap language instructions, to sort the integers received as arguments.

## Introduction

The Push Swap project is a straightforward algorithm project where the task is to sort a set of integer values using two stacks (a and b) and a set of instructions.

## Mandatory Part

### Rules

- **Stacks:**
  - You have two stacks named a and b.
  - At the beginning:
    - Stack a contains a random amount of negative and/or positive numbers that cannot be duplicated.
    - Stack b is empty.

- **Operations:**
  - `sa` (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
  - `sb` (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
  - `ss`: `sa` and `sb` at the same time.
  - `pa` (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
  - `pb` (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
  - `ra` (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
  - `rb` (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
  - `rr`: `ra` and `rb` at the same time.
  - `rra` (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
  - `rrb` (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
  - `rrr`: `rra` and `rrb` at the same time.

## Getting Started

Explain how users can get started with your project. Include instructions on compiling and running the `push_swap` program.

## Usage

Provide examples and explanations on how to use the program. Include any command-line arguments and expected output.

## Contributing

If you're open to contributions, outline how users can contribute to your project. Include information on bug reporting and submitting pull requests.

## License

Specify the license under which your project is distributed.

## Acknowledgments

Give credit to any libraries, tools, or resources you used or were inspired by during the development of this project.
