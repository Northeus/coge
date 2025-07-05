# TODO
 - [ ] Improve dataset.
 - [ ] Add small chance to trigger reset during simulation (do not exclude it).
 - [ ] Mention that code can run only on linux.
 - [ ] Document limits for coverage size stored in testbench.py.
 - [ ] Create testbench result file.
 - [ ] Document code.
 - [ ] Cache build via hash.

```
# ───────────────────────────────[ ⚙️  .  ⚙️ ]───────────────────────────────
```

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
