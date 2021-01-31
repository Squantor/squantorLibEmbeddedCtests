/*
 * SPDX-License-Identifier: MIT
 *
 * Copyright (c) 2021 Bart Bilos
 * For conditions of distribution and use, see LICENSE file
 */
/** 
 * \file sqlibembeddec_tests.cpp
 * 
 * Main entrypoint for executing minunit tests
 * 
 */ 
#include <MinUnit.h>
#include <stdio.h>

/** \brief overridden reporting function
 * 
 * Executes the minunit test framework and checks the results
 */
void minunitReport(const char * message)
{
    printf("%s", message);
}

/** \brief main entrypoint
 * 
 * Executes the minunit test framework and checks the results
 */
int main()
{
    minunitRun();
    printf("%d\t tests executed\n", minunitTestState.executed);
    printf("%d\t checks executed\n", minunitTestState.checks);
    printf("%d\t tests failed\n", minunitTestState.failures);
    return 0;
}