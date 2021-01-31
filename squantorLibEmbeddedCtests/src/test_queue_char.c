/*
MIT License

Copyright (c) 2019 Bart Bilos

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
/*
*/
#include <MinUnit.h>
#include <queue.h>

#define TESTQUEUECHARSIZE   6
char testQueueCharBuf[TESTQUEUECHARSIZE];
queueChar_t testQueueChar = {
    TESTQUEUECHARSIZE,
    0,
    0,
    testQueueCharBuf,
    };

static void testQueueSetup(void) 
{
    queueInit(&testQueueChar);
}

static void testQueueTeardown(void) 
{

}

MINUNIT_ADD(testQueueEmpty) 
{
    char c;
    testQueueSetup();
    minUnitCheck(queueDequeue(&testQueueChar, &c) == queueEmpty);
    testQueueTeardown();
}

MINUNIT_ADD(testQueueEnqDeq) 
{
    char in = 'a';
    char out = 'q';
    testQueueSetup();
    for(int i = 0; i < TESTQUEUECHARSIZE-1; i++)
    {
        minUnitCheck(queueEnqueue(&testQueueChar, in + i) == noError);
    }
    minUnitCheck(queueState(&testQueueChar) == queueFull);
    minUnitCheck(queueEnqueue(&testQueueChar, in) == queueFull);
    
    for(int i = 0; i < TESTQUEUECHARSIZE-1; i++)
    {
        minUnitCheck(queueDequeue(&testQueueChar, &out) == noError);
        minUnitCheck(out == in + i);
    }
    minUnitCheck(queueDequeue(&testQueueChar, &out) == queueEmpty);
    // check if out has been unmodified
    minUnitCheck(out == in + TESTQUEUECHARSIZE-2);
    
    // We do again a test, but now we will cross the max boundary
    minUnitCheck(queueState(&testQueueChar) == queueEmpty);
    minUnitCheck(queueEnqueue(&testQueueChar, in) == noError);
    minUnitCheck(queueState(&testQueueChar) == queueNotEmpty);
    minUnitCheck(queueDequeue(&testQueueChar, &out) == noError);   
    minUnitCheck(queueState(&testQueueChar) == queueEmpty); 
    minUnitCheck(queueDequeue(&testQueueChar, &out) == queueEmpty);
    minUnitCheck(out == in);
    testQueueTeardown();
}