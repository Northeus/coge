# Informatios
**Thesis statement:**
LLMs are a promising candidate to generate functional coverage code from requirements written in natural language.

**Audience:**
Mostly verification engineers with interest in research.

**Paper content:**
 - Do not speculate! Only in results section, if it is necessary to justify
   why we transitioned between experiments.
 - Presentation is in narratiwe flow with no logical leaps.
 - Narrative builds to some take-home message.
 - Everything should be presented so it feels obvious.
 - Use passive instead "We" to emphatize the experiments.
 - Justify why we chose this and not that.
 - Show only the strongest data, not everything (quality > quantity).
 - At the end, braden the content of the art
 - In the conclusion again broaden the picture, reeastablish connection with
   the current state of the field. It should be not summary! Conclusion should
   evoke pitch (sell it). Remind reader what he read but do not repeat words.
   Feel free to add implications and ideas. Do not introduce anything new.

**General paragraph structure:**
 1. Topic sentence: idea behind the paragraph that is connected to the
    article and should nicely follows after the previous paragraph.
    If it is almost direct continuation of the previous paragraph, you
    can use transition word, but do not over do it!
 1. Evidence: concrete information (not speculations) from us or other
    source that we citate afterwards. Might start with some content if
    it needs to give more information so the text has nice flow.
 1. Conclusion: tiny conclusion that was made based on evidence from
    the topic. Reader should have motivation and insights, we he need that
    information we have just gave him in the context of our work.

**Results paragraph structure:**
 1. Start with a topic sentence that explains rationale for performing
    experiment. For example:
    "In order to determine X, Y was performed, showing Z major results."
 1. Describe data and conclusion learned from it in a logical order, not
    chronological, thus: pro then con, most to least significant.
 1. Conclude with transition sentece that sums up the findings and if
    necessary justify whe moved to the next experiment.

**Introduction content:**
 - [ ] The top of hourglass structure: take broader audience to your topic.
 - [ ] Ensure the motivation for the reader (verification engineer) is there.
 - [ ] Content:
   1. General background - introduce the general area, highlight understanding
      of the current status.
   1. Specific background - narrow down to the subarea we address and again
      highlight our understanding of the current status. Goal is to give the
      reader technical details to understand the system, not show of your
      knowledge.
   1. Knowledge gap - now show what we do not know and motivation for this work.
      Prior two points are stepping point for this part.
   1. Here we show ... - show what you have done in condensed manner, including
      used methods and findings. Might add some implications in the last
      sentence or two.

---

# Meeting.
 - [ ] Some statistics for number of requirements, so I can say it is lot of them.

---

# \[Name\]

\[Abstract\]
 - [ ] First finish rest of the article ffs.
 - [ ] Write down all the information we provide in the article.
 - [ ] Start joining and crossing the information.
 - [ ] Describe all the information in easy to understood language.
 - [ ] Content:
   1. General background - introduce general area and state of knowladge in it.
      (1 sentence)
   1. Specific background - narrow down to a relevant topic persued in this
      paper. (1 sentence)
   1. Knowledge gap - state the missing information in this area. (1 sentence)
   1. Here we show ... - state what we did to answer question from the knowledge
      gap sentence. (1 sentence)
   1. Experimental approach & results - describe shortly most important methods
      and results. How did we get to "Here we show ..." content?
      (1 - 3 sentences)
   1. Implications - how we influence understanding within the field and / or
      implications to the future studies. (1 sentence)

---

## Introduction
**Functional coverage is importan matric -> used to tell when verification is done if specification is done properly.**
Tells when the functionality described in specification is implemented and tested (Coverage cookbook).
Functional coverage model needs intentification of functionality and (Coverage cookbook).
Manual implementation can cause some holes made by humans (Coverage cookbook).

**Current trends in application of LLMs in code generation -> LLMs should be promising for code coverage generation (transform NL to code).**
There is trend in applications LLMs and they are more and more accurate (LLM BS).
The llms are really good at solving coding task with specification in natural language (LLM BS).
Functional coverage is definec in short requirement using natural language (Coverage cookbook **Check**).

**LLMs accuracy code generation depends on training data -> they are not yet fully optimal for code coverage generation in HDL.**
Good ammount of data is needed to train a good LLM (Data is all you need **Check**).
One of the problem with training LLMs is that we are slowly running out of data (Lack of data **check**).
There is really low number of thins happening in verilog and systemverilo at github (git stats **check**)
As can be seen in this evaluation, LLMs have still some problems with HDL (VHDL LLM eval).
There are emerging models to generate RTL (LLM for RTL).
There is also an ongoing research on TB generation, but it misses coverage (LLM for naive TB).

**EXPERIMENTS:**
 - [ ] Goal of this thesis is to evaluate LLMs for functinoal coverage -> under some constrains we propose, it can be evaluated automatically.
 - [ ] LLMs are better for python than verilog -> we checked if it will be stronger in generation of python coverage code - cocotb.
 - [ ] We also noticed better generation of python coverage rather than verilog -> python coverage can by transformed to verilog one.

**Implications - if everything will go as planned**
 - [ ] It was shown that LLMs work in python better -> we propose approach of transformation task into more suitable environmet - python.
 - [ ] There are still gaps in LLM generation for functional coverage -> this article give nice starting ground - evaluation and approach.

## Large Language Models
...

## Dataset
...

## Method
...

## Results
...

## Future work
...

## Conclusion
...

In the future, we can further improve this process by filtering.

---

# Bibliography
 1. [Coverage cookbook](https://verificationacademy.com/cookbook/coverage/)
 1. [VHDL LLM eval](https://ieeexplore.ieee.org/document/10691836)
 1. [LLM for RTL](https://ieeexplore.ieee.org/document/10720939)
 1. [LLM for naive TB](https://ieeexplore.ieee.org/document/10992873)
 1. [LLM BS](https://arxiv.org/abs/2406.00515)
 1. [Data is all you need](https://dl.acm.org/doi/abs/10.1145/3649329.3657356)
 1. [Lack of data](https://openreview.net/forum?id=ViZcgDQjyG)
 1. [git stats](https://madnight.github.io/githut/#/pull_requests/2024/1)
