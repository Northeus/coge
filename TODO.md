# TODO
There are following separate sections to do:
 1. Create dataset.
 1. Implement testbench.
 1. Implement testbench runner.
 1. Evaluate test results.
 1. Generate code.

 ## Create dataset
There will be various designs to cover different types of circuits, but for now just:
 - [x] ALU (sequential, moderate)

For each design, we will have to do the following:
 - Create short description - specification.
 - Create some requirements - short sentences targeting verification focus.
 - Create some desired bins and sequences for requirements in json format:
```json
[
    { "type": "bin",         "values": { "from": 0, "to": 14 }, "description": "..." },
    { "type": "illegal bin", "value": 50,                       "description": "..." },
    { "type": "sequence",    "sequence": [1, 0, 1, 1, 0],       "description": "..." },
]
```
 - Create short documentation of the dataset format and content.

After that finish it by:
 - [x] Create `dataset` folder, store there `dataset.json`
 - [x] Add there all the designs code and store paths into `dataset.json`.
 - [x] Create function to load and print out dataset content in reasonable manner.

## Implement testbench
Keep all the code in the `testbench.py` file for now.

Before we start, coverage must be implemented:
 - [ ] Take the current implementation and possibly do tiny refactor.
 - [ ] Add illegal bins.
 - [ ] Add at_least kwarg.

First we need simple testbanch that can run on one of the designs:
 - [x] Hardcode seed.
 - [x] Hardcode reset and clock hooks to the DUT.
 - [x] Generate random stimuli on hardcoded input ports of the design.
 - [x] Add some coverage (hardcoded) into the testbench.
 - [x] Create simple runner (hardcoded) in python and run code.
 - [x] Store coverage results into some json file with hardcoded path.

Now make it more general:
 - [ ] Seed using ENV variable.
 - [ ] Find automatically clock and reset ports, use them if you find them.
 - [ ] Find ports direction via string parsing of module and possibly names from cocotb.
       (you might be able to get module path from SV).
 - [ ] Automatically generate random stimuli just to the include ports.
 - [ ] Add small probability to reset during run (based on ENV variable - ON / OFF).
 - [ ] Add to results used ports for clock, reset and random stimuli generation.

Now lets improve the testbench by automatic coverage:
 - [ ] Functional coverage will be stored in some other file with path in ENV.
 - [ ] Load that file and check for possible syntax check, store them in results file.
 - [ ] Compile code from that file and put it into the testbench.
 - [ ] Find generated coverage stuff using exec namespace and access generated stuff.
 - [ ] Sample all the covergroups at certain point in the program.

Create guardrails to minimize risk connected with running LLMs code:
 - [ ] Remove unsafe builtins, such as: import, open, ...
 - [ ] Add timeout to the code coverage code runtime.
 - [ ] Limit number of created bins (use ENV variable).
 - [ ] Limit size of cross (based on input size) (use ENV variable).
 - [ ] Check for MemoryError.

And the most importat, document it:
 - [ ] Testbench API (including coverage and all the public functions).
 - [ ] How to use testbench with examples.
 - [ ] How to use coverage with examples.

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
