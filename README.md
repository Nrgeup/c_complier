# c_complier


---

## Introduce 

This is my final work of  Compiler theory course

It is a Simple C compiler.

When this program run, it will translate a C program to  Assembly language program!

You can run this Assembly language program in suitable environment and get the same result as the original C Program!


---

## Input  && Output 

 -  `INPUT`
     
     it will get the input data (a c program ) from `/complier5/Data/input.txt` each run.

 -  `OUTPUT`
    
     it will output the result (a Assembly language program ) in  `/complier5/Data/output.asm` each run.

     And it also print the Address assignment status in `/complier5/Data/print.txt`, so you can see the detail if you needed.

---

###  Some Notes

 1.  I use the tool [Parser Generator](http://parser-generator.updatestar.com/zh-cn) to help me traslate regular expression and Context free grammar to a C++ program which help me a lot.


 2.  I also add same  c complier(cminus,lcc,Tiny-C) in `/other-compliers/` which used to compare with me.

     I think I am bettter than them, because I make same improvements :
   >
     - This program can translate more complex Grammatical structure such as `function structure`

     - I used the Dynamic stack address allocation, so I can achieve same logic structure like `recursion`

	 - I try to output the Assembly language program not directly run the C progrqam because it can transfer to other platforms easily.

   >


---

###  Appendix

  1. The Lexical Structure ( regular expression ) [`c_complier/complier5/mylexer.l`](https://github.com/Nrgeup/c_complier/blob/master/complier5/mylexer.l)
 
  2. The Grammatical structure ( Context free grammar ) [` c_complier/complier5/myparser.y`](https://github.com/Nrgeup/c_complier/blob/master/complier5/myparser.y)

---

