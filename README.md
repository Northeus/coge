# LLM-based Functional Coverage Generation and Auto-Evaluation Framework
Requirements:
 1. Install `Python3.13`.
 1. Create `venv` + install requirements via `pip install -r requirements.txt`.
 1. Run `Ollama` server with a model of your choice.
 1. Generate data using `python pipeline.py [model name] -o [result file]`.
 1. Evaluate results by `python evaluation.py [dir containing results files]`

## Dataset
The input into the framework is dataset consisting of verification
requirements coupled with the desired functional coverage implied by
them and the designs. The `top` must be unique among all instances!
Specification to each design is stored in `[top].md`. In addition, each
design contains port and code related to the statement coverage capture
with comments that ensure they are excluded in the computed statement
coverage.

The format of the dataset is:
```json
[
  {
    "top": "(str) Name of the top module, design file is than '{top}.sv'",
    "requirements": [
      {
        "description": "(str) description of the verification requirement",
        "coverpoints": [
          {
            "port": "(str) name of the port."
            "values": [
              {
                "all": "([int, int]) Require all values from given range."
              },
              {
                "one": "([int, int]) Require at least one value in given range."
              }
            ]
            "illegal_values": "Illegal values defined in the same way as 'values'."
            "sequences": "(list[list[int]]) Targeted sequences for the port.",
            "at_least": "(int) Optional, describes the required number of hits."
          },
          {
            "cross": [
              {
                "port": "(str) Name of the port."
                "values": "See 'coverpoints.values' above."
              }
            ]
          }
        ]
      }
    ]
  }
]```
