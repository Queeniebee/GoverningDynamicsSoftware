More on Language Design
=======================

You don't need if statements, your language just needs to have the ability to do that.

Rewriting languages like Mathematica


Language grammar rules are called *productions*
* the productions has a **name** and a **body**

* the **body** itself is made of two parts, the first is the **sequence**, the second the **action** 

* Sequence: a list of things that that production matches, things or terminals (no additional processing to do)

* The action is the JavaScript code to make ish happen.

### Symbol Tables

use JS objects to create symbol tables. In Rejoyce Nasser set up a dictionary that holds all the ?keys and values?
	Declare an object and pass it a string
