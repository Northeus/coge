# TODO
 - [ ] Improve dataset.
 - [ ] Add small chance to trigger reset during simulation (do not exclude it).
 - [ ] Mention that code can run only on linux.
 - [ ] Document limits for coverage size stored in testbench.py.
 - [ ] Create testbench result file.
 - [ ] Document code.

```
# ───────────────────────────────[ ⚙️  .  ⚙️ ]───────────────────────────────
```

## Implement testbench runner
Keep all the code in the `runner.py` file for now.

Add basic functionality:
 - [ ] Check results of simulation (e.g., whether an error has occured).
 - [ ] Read and print final out functional coverage data.
 - [ ] Gather and print code coverage data.
 - [ ] Create result file containing:
   * Error info.
   * Functional coverage results.
   * Code coverage results.
   * Used ports in simulation ports.
   * Duration of the test in both time and number of generations.

Now lets improve the naive runner:
 - [ ] Make runner to create some sort of an workspace (dir) to ensure encapsulation.
 - [ ] Add imput parameters specifying design, coverage code, simulation duration.
 - [ ] Create code that parse dataset and run test on various designs from the dataset.
 - [ ] Add cleanup scripts.
 - [ ] Create aggregate results for runs with same seed but different duration.

And prepare it for full run:
 - [ ] Make multithreaded runner.
 - [ ] Test running whole dataset.

And the most importat, document it:
 - [ ] Runner API.
 - [ ] Runner usage with examples.

## Evaluate test results
Keep all the code in the `evaluation.py` file for now.

Prepare data from evaluateion:
 - [ ] Load data produced from the datatest.
 - [ ] Make run function to process dataset.
 - [ ] Load data produced from the testbenches.
 - [ ] Mark ground truth (our) data and generated (for now again our) data.
 - [ ] Check that proposed requirements in dataset are in our and generated data.
 - [ ] Gather statistics about complexity including:
   * Number of bins and sequences including their size or length.
   * Size of the cross.
   * Number of cross inputs.
   * Counts per port (including name and direction).
 - [ ] Statistic about syntax and other errors causing problems.
 - [ ] Do not forget about code and functional coverage total statistic (counts).

Prepare for LLM evaluation:
 - [ ] Add callback to generate data, for now just copy our data.

Present the data:
 - [ ] Plot code vs functional coverage for each evalued thing.
 - [ ] Create table containing all numeric and categoric stuff.
 - [ ] Create evaluation function, that take statistics and return value.
 - [ ] Create graph from the evaluation function.

Document the results:
 - [ ] Final results structure.

## Generate code
Keep all the code in the `generation.py` file for now.

Prepare LLM stuff:
 - [ ] Create hooks to Ollama.
 - [ ] Add parametrization for model, address, etc.

Create simple pipeline for our dataset:
 - [ ] Propose prototype prompt that is tested in Ollama to ensure accuracy.
 - [ ] Inputs and outputs format into given file.

Run on whole dataset:
 - [ ] Generate coverage code.
 - [ ] Rerun evaluation pipeline.

Document the results:
 - [ ] API documentation.
 - [ ] Running Ollama on remote, local, and tunneling.

## Finalization
Final steps:
 - [ ] Create `main.py` that glue everything.
 - [ ] Create simple presetation of the results.
 - [ ] Brainstorm with Marcela what now (LLM prompting, additional stuff, etc.).
