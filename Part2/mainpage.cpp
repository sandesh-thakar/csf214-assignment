/*! \mainpage CS F214 Assignment Part 2
 * \section Authors
 * 1. Kunal Verma (2017A7PS0120H)
 * 2. Sandesh Thakar (2017A7PS0181H)
 * 3. Kushagra Srivastava (2017A7PS0146H)

 * \section Task
 * Making a propositional logic proof checker, implementing the functionalties of:
 * 1. Premise
 * 2. AND Introduction (^i)
 * 3. AND Elimination  (1 and 2) (^e)
 * 4. OR Introduction (1 and 2) (Vi)
 * 5. Implication Elimination (>e)

 * \section Assumptions
 * 1. The expression should be perfectly paranthesized
 * \n Example 1: (a^b) is perfectly paranthesized while a^b is not
 * \n Example 2: ((~p)^q) is perfectly paranthesized while (~p^q) is not
 * 2. There should be no spaces within any line of proof

 * \section Sample
 * Input
 * \n 2
 * \n a/P
 * \n (aVb)/Vi1/1
 * \n Output
 * \n Valid Proof
 */