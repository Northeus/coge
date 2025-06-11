import testbench


def main() -> None:
    config = testbench.Config(
        name='test_demo',
        imports='import demo',
        seed=42,
        clock_port='porst[\'CLK\']',
        reset_call='await demo.reset(ports)',
        generate_stimuli_call='await demo.gen_stimuli(ports)',
        transaction_start_call='await demo.trans_start(ports)',
        transaction_await_call='await demo.trans_await(ports)')
    testbench.generate('demo_testbench.py', config)
    testbench.run('arithmetic_unit.sv',
                  'arithmetic_unit',
                  'demo_testbench')


if __name__ == '__main__':
    main()
