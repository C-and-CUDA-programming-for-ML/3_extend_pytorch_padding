# Exercise three - extending Pytorch

In this exercise, you will use setuptools to compile a Pytorch extension with PyTorch's `cpp_extension`
module. 


The task is to implement `symmetric` padding extension for PyTorch. Symmetric padding, for example, is the default in `pywt` (https://pywavelets.readthedocs.io). PyTorch's [pad](https://pytorch.org/docs/stable/generated/torch.nn.functional.pad.html) lacks this functionality. In this exercise, we will provide it.

### Testing and Verification

Follow these steps:

1. Clone the repository: `git clone https://github.com/your-username/cpp_pad.git`.
2. Navigate to the project directory: `cd sympad_pytorch `.
3. Run the tests with `nox -s test`.


### Implementing your module in c++.

Symmetric padding extends a signal by mirroring samples. This mode is also known as half-sample symmetric [[pywt-docs](https://pywavelets.readthedocs.io/en/latest/ref/signal-extension-modes.html) ]. 
The idea is to repeat samples in reverse order at the boundary.

```
... x2 x1 | x1 x2 ... xn | xn xn-1 ...
```

Implement this boundary extension mode in the `src/sympad.cpp` file's `_pad_symmetric_1d`-function by resolving the `TODO`'s in the code.


### Using your Pytorch module

1. create a virtual environment `python -m venv virtual_env` or a conda environment.
2. activate the environment `source virtual_env/bin/activate`
3. Install your module
	- pip install torch numpy build
	- python -m build --no-isolation
	- pip install dist/sympad-0.0.1-cp312-cp312-linux_x86_64.whl

4. To run your module, start the Python interpreter with `python`.
5. `import torch, sympad` and `import numpy as np`.
6. Pad a tensor using your own method.
	- Run `array = np.arange(9).reshape(3,3)`
	- `print(array)`
	- Run `sympad.pad_symmetric(torch.from_numpy(array), [(1,1), (1,1)])`


