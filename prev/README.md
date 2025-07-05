# CoGe

```
# ───────────────────────────────[ ⚙️  .  ⚙️ ]───────────────────────────────
```

# Workflow
 1. Provide interface, spec, and requirements (focus of verification).
 1. Generate **single** testbench per DUT.
 1. Find reset and clock, use them.
 1. Generate some coverage using LLMs.
 1. Syntax check.
 1. Run simulation, terminate if time reach x * desired length,
    reset with very low probability during run.
 1. Evaluation:
    * Functional coverage is geraeter than code coverage => lower points.
    * Check that some specific value is in the Bin / Sequence.
    * Illegal bins were not hit without simulation stop.

# Ensure
 - Same seed produce same values.

# Hints
 - Cross usually on control flow.
 - Different distributions for each signal.

# Additional work
 - Create our coverage that is good and compare results with the LLMs coverage.



---

# Testbench generation
Evaluate cappablities of LLMs to generate testbench prototype based on DUT
code and its specification.

## Process
**Inputs are:**
 - Interface of the DUT with signal width.
 - Specification of the DUT.

**The algorithm in python is:**
 1. Requirements + LLMs -> Coverage.
 1. Check whether the code is executable.
 1. Obtain code and functional coverage during multiple runs (plot them).
 1. Evaluate generated code with metric capturing:
    * Functional coverage is not absolutely trivial.
    * Overall functional coverage was slowly increasing.
    * Functional coverage related nicely to the code coverage.

**Outcome is:** Generated test that includes (not best) functional coverage.

## Experiments
 -
 - Compare the accuracy of two approaches:
   * LLMs -> CoCoTB -> UVM
   * LLMs -> UVM
 - Test whole pipeline on various LLMs to propose the best LLM for our task.

## Requirements
 - [x] Access to various LLMs.
 - [ ] Functional coverage in CoCoTB testbench.
 - [ ] Code coverage in CoCoTB testbench.
 - [ ] Syntax checker for CoCoTB testbenche.
 - [ ] Syntax checker for UVM testbenche.
 - [ ] Generator for CoCoTB testbench.
 - [ ] Generator for UVM testbench.
 - [ ] Simulator for UVM testbench.
 - [ ] Transformator CoCoTB to UVM testbench.

## To Check
 - [ ] Current tools to generate UVM and CoCoTB testbenches.
 - [ ] Functional coverage in CoCoTB testbench.
 - [ ] Generation of functional coverage using LLMs.
 - [ ] Generation of functional coverage using other approaches.
 - [ ] LLMs per token thinking ability.
 - [ ] Code at this [repo](https://github.com/lhorse010/llm_specificaiton_extraction).
 - [ ] Adding some special information (e.g., common bugs) to LLM.
 - [ ] Set seed for LLM to ensure experiment reproducability.
 - [ ] Chain of thouthts and other strategies.

## Things to mention
 - [ ] Research questions, aka. hypothesis.

## Articles
**[Extracting Formal Specifications from Documents Using LLMs for Automated Testing](https://arxiv.org/abs/2504.01294):**
 - Similar approach on general software requirements - no HDL.
 - Mention need of specific approach, not just LLMs -> result.
 - Compare LLMs approach to aproaches used before LLM era.
 - They made everything open soure at this [repo](https://github.com/lhorse010/llm_specificaiton_extraction).
 - They put research questions and bullet points into introduction,
   including the "current state not good -> need for better solution".
 - Workflow:
   1. Document preprocessing (remove rst syntax and highlighting).
   1. **Ground truth** (extracted formal information that is required).
   1. Proposed prompt engineering for LLM utilization.
 - Also shown some possibility in ambiguity.
 - Mention and explain hallucinations, does not provide solution to prevent it!
 - Provide name to the process they introcuce, to make text more readable.
 - The final result contain also some explanation to verify the result.
 - **Could be a source for articles we want (e.g., for prompt engineering).**
 - Add references back to the original text.
 - Include section with related work, but at the end ?!
