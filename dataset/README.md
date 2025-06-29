# Dataset
The dataset contains HDL designs in SystemVerilog, their description,
requirements targetting the verification focus and desired functional
coverage for each requirement.

## Format
The structure of the dataset is split into multiple files, where
design file path, description file path and requirements are stored in
the `dataset.json` file that have following format:
```json
[
    {
        "name": "(str) unique name of the design",
        "design_file": "(str) path to the file containing design code",
        "description_file": "(str) path to the file containing design description",
        "requirements": [
            ...
        ]
    },
    ...
]```

Format of the requirements is:
```json
{
    "description": "(str) description of the functional requirement",
    "coverpoints": [
        {
            "port": "(str) name of the port, not used for 'cross'"


            /* One of the following: */
            "value": "([int, int]) range where value must be (including both ends)",
            "values": "(list[int]) list of all values that must occure on the port",
            "sequence": "(list[int]) sequence of values that must occur at given port",
            "cross": [
                {
                    /* Any value or values coverpoint without at_least field. */
                }

            ]

            "at_least": "(int?) optional value telling required number of coverpoint hits"

            /* If value or values was used, bin_type can be optionally added. */
            "bin_type": "('normal', 'illegal', or 'ignore') By default, field is normal"
        },
        {
            "type": "sequence",
            "sequence": [1, 0],
            "at_least": 5
        }
    ]
}```

All the SystemVerilog code should use the style, where direction of the ports
is specified within the module statement, for example:
```sv
// Good.
module OR(
    input logic A,
    input logic B,
    output logic X
);```
