#include "CUTE/cute/cute.h"
#include "CUTE/cute/ide_listener.h"
#include "CUTE/cute/cute_runner.h"
#include "Orlov_MathTask.h"

using namespace cute;

void test_inputAndValidateDouble_valid() {
    mockCinInput("3.14\n");
    double result = inputAndValidateDouble("Введите число: ");
    ASSERT_EQUAL(3.14, result);
}

void test_inputAndValidateDouble_invalid_then_valid() {
    mockCinInput("abc\n2.5\n");
    double result = inputAndValidateDouble("Введите число: ");
    ASSERT_EQUAL(2.5, result);
}

void test_inputAndValidateDouble_negative() {
    mockCinInput("-0.001\n");
    double result = inputAndValidateDouble("Введите число: ");
    ASSERT_EQUAL(-0.001, result);
}


void test_inputAndValidateNatural_valid() {
    mockCinInput("5\n");
    int result = inputAndValidateNatural("Введите число: ");
    ASSERT_EQUAL(5, result);
}

void test_inputAndValidateNatural_negative_then_valid() {
    mockCinInput("-3\n2\n");
    int result = inputAndValidateNatural("Введите число: ");
    ASSERT_EQUAL(2, result);
}

void test_inputAndValidateNatural_non_numeric_then_valid() {
    mockCinInput("test\n1\n");
    int result = inputAndValidateNatural("Введите число: ");
    ASSERT_EQUAL(1, result);
}


void test_inputAndValidateInRange_valid() {
    mockCinInput("3\n");
    int result = inputAndValidateInRange("Введите число: ", 1, 5);
    ASSERT_EQUAL(3, result);
}

void test_inputAndValidateInRange_out_of_range_then_valid() {
    mockCinInput("0\n2\n");
    int result = inputAndValidateInRange("Введите число: ", 1, 5);
    ASSERT_EQUAL(2, result);
}

void test_inputAndValidateInRange_non_numeric_then_valid() {
    mockCinInput("a\n4\n");
    int result = inputAndValidateInRange("Введите число: ", 1, 5);
    ASSERT_EQUAL(4, result);
}


void test_roundToDigits_positive() {
    double result = roundToDigits(3.14159, 3);
    ASSERT_EQUAL_DELTA(3.14, result, 0.0001);
}

void test_roundToDigits_large_number() {
    double result = roundToDigits(123.456, 4);
    ASSERT_EQUAL_DELTA(123.5, result, 0.0001);
}

void test_roundToDigits_small_number() {
    double result = roundToDigits(0.0012345, 2);
    ASSERT_EQUAL_DELTA(0.0012, result, 0.0001);
}

void test_roundToDigits_negative() {
    double result = roundToDigits(-2.71828, 3);
    ASSERT_EQUAL_DELTA(-2.72, result, 0.0001);
}


void test_dropIntegerPart_positive() {
    double result = dropIntegerPart(3.14159);
    ASSERT_EQUAL_DELTA(0.14159, result, 0.0001);
}

void test_dropIntegerPart_negative() {
    double result = dropIntegerPart(-2.718);
    ASSERT_EQUAL_DELTA(-0.718, result, 0.0001);
}

void test_dropIntegerPart_integer() {
    double result = dropIntegerPart(123.0);
    ASSERT_EQUAL_DELTA(0.0, result, 0.0001);
}


void runAllTests(int argc, char const *argv[]) {
    cute::suite s;
    
    s += CUTE(test_inputAndValidateDouble_valid);
    s += CUTE(test_inputAndValidateDouble_invalid_then_valid);
    s += CUTE(test_inputAndValidateDouble_negative);
    
    s += CUTE(test_inputAndValidateNatural_valid);
    s += CUTE(test_inputAndValidateNatural_negative_then_valid);
    s += CUTE(test_inputAndValidateNatural_non_numeric_then_valid);
    
    s += CUTE(test_inputAndValidateInRange_valid);
    s += CUTE(test_inputAndValidateInRange_out_of_range_then_valid);
    s += CUTE(test_inputAndValidateInRange_non_numeric_then_valid);
    
    s += CUTE(test_roundToDigits_positive);
    s += CUTE(test_roundToDigits_large_number);
    s += CUTE(test_roundToDigits_small_number);
    s += CUTE(test_roundToDigits_negative);
    
    s += CUTE(test_dropIntegerPart_positive);
    s += CUTE(test_dropIntegerPart_negative);
    s += CUTE(test_dropIntegerPart_integer);
    
    cute::ide_listener<> lis;
    cute::makeRunner(lis, argc, argv)(s, "All Tests");
}

int main(int argc, char const *argv[]) {
    runAllTests(argc, argv);
    return 0;
}