Reviewing JavaScript Tutorials
-----------------------------


JavaScript uses prototypical inheritance as opposed to classical inheritance (Java, C++)

The parser takes a seemingly bunch of meaningless text and then adds value to it

### CLOSURES!!!
* functions that have access to variables that are outside the function (hmm); essentially dragging around its 'environment'
* a function that keeps track of the environment it was declared in
example:
```
var incrementOwnTimer = function(t) { 
     return function() {
	t += 1; return t } 
     }
```

#### The function above will keep incrementing by one regardless if you pass another argument to the declared instance of incrementOwnTimer().

Stack Languages
---------------
A language that maniplulates a stack, for example there is [Factor](http://factorcode.org/), [PostScript](http://ghostscript.com/doc/current/Ps2pdf.htm)


### Turing Machines

Not a physical machine, but a concept on the way things operate
* can do any kind of computation
* manipulates symbols
*if your system can simulate a turing machine then you are **TURING COMPLETE*** ==> a programming language

* Infinite Tape
* Alphabet which is finite
* A Head which is a marker
* Rules/States

RN says that arithmetic is not necessary for computation within the Turing Machine

Analogies to current programming languages
- linear storage
- conditionals
- functions, a way of grouping code and being able to execute

there aren't any loops, classes, or objects inherent in the Turing Machine model

??What about writing a language that was only rules and states??
