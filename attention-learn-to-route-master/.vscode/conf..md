Para gerar dados com tsplib:
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "Python Debugger: Current File with Arguments",
            "type": "debugpy",
            "request": "launch",
            "program": "${file}",
            "console": "integratedTerminal",
            "args": [
                "--problem",
                "tsp",
                "--name",
                "tsplib",
                "--seed",
                "4321",
            ]
        }
    ]
}



Para avaliar treinar um modelo de tsp com 4 nos:
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "Python Debugger: Current File with Arguments",
            "type": "debugpy",
            "request": "launch",
            "program": "${file}",
            "console": "integratedTerminal",
            "args": [
                "--graph_size",
                "4",
                "--baseline",
                "rollout",
                "--run_name",
                "acharpi",
                "--val_dataset",
                "data/tsp/tsp4_tsp_seed1234.pkl",
                "--epoch_size",
                "100",
                "--batch_size",
                "100",
                "-val_size",
                "100"
            ]
        }
    ]
}

